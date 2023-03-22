#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <opencv2/opencv.hpp>
#include <sqliteoperator.h>
#include <QBuffer>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <opencv2/core.hpp>
#include <QDir>
#include <QWebChannel>
#include <gps_device.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget;
               class item_edit;
             }
QT_END_NAMESPACE


QPixmap Mat2Image(cv::Mat src);

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void progame_init();
    void get_camera_index();
    void webmap_init();

private slots:
    void on_exit_btn_clicked();

    void time_update();

    void on_camera_open_close_btn_clicked();

    void camera_get_frame();


    void on_insert_data_btn_clicked();
    void on_tabWidget_currentChanged(int);
    void on_is_csi_camera_cb_stateChanged(int);
    void on_gps_locate_btn_clicked();
    void on_server_connect_btn_clicked();


private:
    Ui::Widget *ui;
    QTimer *set_time_timer;  // timer to update the time

    cv::VideoCapture *videocaptrue; // videocaptrue to captrue the camera input
    QTimer *camera_get_frame_timer;
    cv::Mat frame_mat;
    bool is_camera_opened = false;

    QPixmap pixmap; // pixmap to share the img that camera have collected
    SqliteOperator *sql_op;
    GPSDevice *gps_op;

};
#endif // WIDGET_H
