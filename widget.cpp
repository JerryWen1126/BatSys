#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <opencv2/core.hpp>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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



    // init the sqlite database
    sql_op = new SqliteOperator(ui);
    sql_op->create_DB();

    // init the tablewidget show style
    ui->bat_record_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bat_record_tw->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bat_record_tw->setRowCount(sql_op->fetchRecordsNum());
    sql_op->refreshTable();



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
        videocaptrue = new cv::VideoCapture(0);
        if(!(videocaptrue->isOpened()))
        {
            qDebug() << "camera open failed";
            QMessageBox::critical(this, "警告", "摄像头打开失败", QMessageBox::Ok);
            return;
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
    QString test_class = "test_class";
    sql_op->insertData(byte_arr, test_class);
}


