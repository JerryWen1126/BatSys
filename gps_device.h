#ifndef GPSDevice_H
#define GPSDevice_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <ui_widget.h>
#include <QtMath>


#define PI 3.1415926535897932384626
#define A 6378245.0
#define EE 0.00669342162296594323

class GPSDevice: public QObject
{
    Q_OBJECT
public:
    GPSDevice(Ui::Widget *, QWidget *parent = nullptr);
    ~GPSDevice();
    void fetch_serialport_info();
    void serialport_init();
    bool is_out_of_China(const float&, const float&);
    float transformLat(const float&, const float&);
    float transformLon(const float&, const float&);
    float str_to_GPS84(const QString&, const QString&);
    QPair<float, float> gps84_to_gcj02(const float&, const float&);
    QPair<float, float> gcj02_to_bd09(const float&, const float&);
    void GPS_read();


private slots:
    void on_openserial_btn_clicked();


private:
    Ui::Widget* ui;
    QSerialPort *serial;
    bool is_uart_opened = false;
    QTimer timer;
    QByteArray buffer;
};

#endif // GPSDevice_H
