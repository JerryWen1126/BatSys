#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    this->showFullScreen();
    progame_init();
}

Widget::~Widget()
{
    if(is_camera_opened)
    {
        qDebug() << "free the resource";
        camera_get_frame_timer->stop();
        videocaptrue->release();
        delete videocaptrue;
    }
    delete ui;
    delete set_time_timer;
    delete camera_get_frame_timer;
    delete sql_op;
    delete gps_op;
    delete rs_op;

}



void Widget::on_exit_btn_clicked()
{
    QMessageBox quit_msg(QMessageBox::Question, "退出程序", "真的要退出吗？", QMessageBox::Yes|QMessageBox::No);
    quit_msg.setButtonText(QMessageBox::Yes, "是");
    quit_msg.setButtonText(QMessageBox::No, "否");

    switch (quit_msg.exec()){
    case QMessageBox::Yes:
        QApplication::exit();
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }

}


void Widget::progame_init()
{
    // init the basic info
    setWindowTitle("蝙蝠竖琴网智能监测系统");
    setWindowIcon(QIcon("./pic/icon.png"));
    ui->current_program_version_lb->setText("dev");
    ui->connection_status_lb->setText("未连接");

    // set timer to update time
    set_time_timer = new QTimer();
    connect(set_time_timer, SIGNAL(timeout()), this, SLOT(time_update()));
    set_time_timer->start(1000);

    // init the camera widget
    QImage img;
    img.load("./pic/camera_off.png");
    ui->camera_window_lb->setPixmap(QPixmap::fromImage(img));

    // init the camera device
    videocaptrue = nullptr;
    camera_get_frame_timer = new QTimer();
    connect(camera_get_frame_timer, SIGNAL(timeout()), this, SLOT(camera_get_frame()));
    get_camera_index();


    // init the sqlite database
    sql_op = new SqliteOperator(ui);
    sql_op->create_DB();

    // init the tablewidget show style
    ui->bat_record_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->bat_record_tw->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    sql_op->refreshTable();
    connect(ui->check_sync_btn, SIGNAL(clicked(bool)), sql_op->work, SLOT(check_and_make_json()));

    // init the web map
    webmap_init();

    // init the gps device
    gps_op = new GPSDevice(ui);
    connect(ui->openserial_btn, SIGNAL(clicked(bool)), gps_op, SLOT(on_openserial_btn_clicked()));

    // init the network connection
    rs_op = new RecordSync(ui);
    connect(ui->server_connect_btn, SIGNAL(clicked(bool)),rs_op, SLOT(on_server_connect_btn_clicked()));


    return;
}

void Widget::time_update()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->local_time_lb->setText(str);
    return;
}


void Widget::on_camera_open_close_btn_clicked()
{

    if(!is_camera_opened)
    {
        qDebug() << "Camera is opened";
    QString camera_file_name;
        // check if it is csi camera
        if(!is_csi_camera)
        {
            camera_file_name = ui->camera_index_cb->currentText();
            int camera_index = QString(camera_file_name.at(camera_file_name.size() - 1)).toInt();
            videocaptrue = new cv::VideoCapture(camera_index);
        }
        else // start csi camera
        {

        }



        if(!(videocaptrue->isOpened()))
        {
            if(!is_csi_camera)
            {
                qDebug() << "usb camera open failed";
                QMessageBox::critical(this, "警告", QString("摄像头(%1)打开失败").arg(camera_file_name), QMessageBox::Ok);
                return;
            }
            else
            {
                qDebug() << "csi camera open failed";
                QMessageBox::critical(this, "警告", QString("CSI摄像头打开失败"), QMessageBox::Ok);
                return;
            }
        }
        camera_get_frame_timer->start(33);
        ui->camera_open_close_btn->setText("关闭摄像头");
        is_camera_opened = true;
        ui->insert_data_btn->setEnabled(true);
    }
    else if(is_camera_opened)
    {
        QImage img;
        img.load("./pic/camera_off.png");
        ui->camera_window_lb->setPixmap(QPixmap::fromImage(img));

        qDebug() << "Camera is closed";
        camera_get_frame_timer->stop();
        videocaptrue->release();
        delete videocaptrue;
        videocaptrue = nullptr;
        ui->camera_open_close_btn->setText("打开摄像头");
        is_camera_opened = false;
        ui->insert_data_btn->setEnabled(false);
    }
}

QPixmap Mat2Image(cv::Mat src)
{
    QImage img;
    static cv::Mat tmp;
    if(src.channels() == 3)
    {
        cv::cvtColor(src, tmp, cv::COLOR_BGR2RGB);
        img = QImage((uchar*)tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888);
    }
    else img = QImage((uchar*)src.data, src.cols, src.rows, src.step, QImage::Format_Grayscale8);

    QPixmap ret_pixmap = QPixmap::fromImage(img);
    return ret_pixmap;
}


void Widget::camera_get_frame()
{
    static cv::Mat dst;
    videocaptrue->read(frame_mat);
    dst = frame_mat.clone();
    pixmap = Mat2Image(dst);
    ui->camera_window_lb->setPixmap(pixmap);
    return;
}




// temporarily used for testing sqlite database
// should run on new thread
void Widget::on_insert_data_btn_clicked()
{
    QByteArray byte_arr;;
    QBuffer buffer(&byte_arr);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "png", 0);
    QString test_class = "test_class1";
    QString test_chance = "90.00%";
    sql_op->insertData(byte_arr, test_class, test_chance);

}


void Widget::get_camera_index()
{
    QDir dir("/dev");
    QStringList filter = QStringList() << "video*";
    QStringList camera_files = dir.entryList(filter, QDir::System|QDir::Files);
    ui->camera_index_cb->addItems(camera_files);
}


void Widget::webmap_init()
{
    QString map_html_path = QCoreApplication::applicationDirPath() + "/html/map.html";
    qDebug() << map_html_path;

    QFile file(map_html_path);
    if(!file.exists())
    {
        qDebug() << "map html does not exist!";
        QMessageBox::critical(this, "警告", QString("网页地图文件(%1)不存在").arg(map_html_path), QMessageBox::Ok);
        return;
    }
    // build a channel to html
    QWebChannel *webchannel = new QWebChannel(ui->webmap_wev->page());
    ui->webmap_wev->page()->setWebChannel(webchannel);
    webchannel->registerObject(QString("JSInterface"), ui->webmap_wev);


    ui->webmap_wev->page()->load(QUrl("file:///" + map_html_path));

}


void Widget::on_tabWidget_currentChanged(int index)
{
    if(index == 1)
        sql_op->refreshTable();
    return;
}

void Widget::on_is_csi_camera_cb_stateChanged(int arg1)
{
    qDebug() << "arg1:" << arg1;
    if(arg1 == 2)   // checkbox is on
    {
        ui->camera_index_cb->setEnabled(false);
        is_csi_camera = true;
    }
    else
    {
        ui->camera_index_cb->setEnabled(true);
        is_csi_camera = false;
    }
}

void Widget::on_gps_locate_btn_clicked()
{
    qDebug() << "locate clicked!";
    QString lat = ui->latitude_le->text().split(" ")[0];
    QString lng = ui->longtitude_le->text().split(" ")[0];
    QString command = QString("addMarker(%1, %2)").arg(lng, lat);
    qDebug() << command;
    ui->webmap_wev->page()->runJavaScript(command);
}




std::string Widget::gstreamer_pipeline(int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method)
{
    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" + std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) + "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" + std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}


