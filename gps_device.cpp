#include "gps_device.h"

GPSDevice::GPSDevice(Ui::Widget *ui, QWidget *parent)
    :QObject(parent)
{
    this->ui = ui;
    fetch_serialport_info();
    connect(&timer, &QTimer::timeout, this, &GPSDevice::GPS_read);
    connect(serial, &QSerialPort::readyRead, this, [&]()
    {
       timer.start(100);
       buffer.append(serial->readAll());
    });

}

GPSDevice::~GPSDevice()
{
    if(is_uart_opened)
    {
        serial->close();
        is_uart_opened = false;
    }
    delete serial;
}


void GPSDevice::fetch_serialport_info()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Name\t:" << info.portName();
        qDebug() << "Description:" << info.description();
        if(ui->portname_cb->currentText() != info.portName())
            ui->portname_cb->addItem(info.portName());
    }
    serial = new QSerialPort(this);
}

bool GPSDevice::is_out_of_China(const float &lat, const float &lon)
{
    if((lon < 72.004) || (lon > 137.8347))
        return true;
    if((lat < 0.8293) || (lat > 55.8271))
        return true;
    return false;
}

float GPSDevice::transformLat(const float &x, const float &y)
{
    float ret;
    ret = -100.0 + 2.0 * x + 3.0 * y + 0.2 * y * y + 0.1 * x * y + 0.2 * sqrt(abs(x));
    ret += (20.0 * sin(6.0 * x * PI) + 20.0 * sin(2.0 * x * PI)) * 2.0 / 3.0;
    ret += (20.0 * sin(y * PI) + 40.0 * sin(y / 3.0 * PI)) * 2.0 / 3.0;
    ret += (160.0 * sin(y / 12.0 * PI) + 320 * sin(y * PI / 30.0)) * 2.0 / 3.0;
    return ret;
}

float GPSDevice::transformLon(const float &x, const float &y)
{
    float ret;
    ret = 300.0 + x + 2.0 * y + 0.1 * x * x + 0.1 * x * y + 0.1 * sqrt(abs(x));
    ret += (20.0 * sin(6.0 * x * PI) + 20.0 * sin(2.0 * x * PI)) * 2.0 / 3.0;
    ret += (20.0 * sin(x * PI) + 40.0 * sin(x / 3.0 * PI)) * 2.0 / 3.0;
    ret += (150.0 * sin(x / 12.0 * PI) + 300.0 * sin(x / 30.0 * PI)) * 2.0 / 3.0;
    return ret;
}

float GPSDevice::str_to_GPS84(const QString& data1, const QString& data2)
{
    int len_data1 = data1.length();
    QString str_data2 = QString("%1").arg(data2.toInt(), 5, 10, QLatin1Char('0'));
    int temp_data = data1.toInt();
    int symbol = 1;
    if(temp_data < 0)
        symbol = -1;
    int degree = int(temp_data / 100.0);
    QString str_decimal = QString(data1[len_data1 - 2]) + QString(data1[len_data1 - 1]) + str_data2;
    float f_degree = str_decimal.toInt()/60.0/100000.0;
    float result;
    if(symbol > 0)
        result = degree + f_degree;
    else
        result = degree - f_degree;
    return result;
}

QPair<float, float> GPSDevice::gps84_to_gcj02(const float &lat, const float &lon)
{
    QPair<float, float> ret;
    if(is_out_of_China(lat, lon))
    {
        ret.first = 0.0;
        ret.second = 0.0;
        return ret;
    }
    float dLat = transformLat(lon - 105.0, lat - 35.0);
    float dLon = transformLon(lon - 105.0, lat - 35.0);
    float radLat = lat / 180.0 * PI;
    float magic = sin(radLat);
    magic = 1 - EE * magic * magic;
    float sqrtMagic = sqrt(magic);
    dLat = (dLat * 180.0)/((A * (1 -EE))/(magic * sqrtMagic) * PI);
    dLon = (dLon * 180.0) / (A /sqrtMagic * cos(radLat) * PI);
    float mgLat = lat + dLat;
    float mgLon = lon + dLon;
    ret.first = mgLat;
    ret.second = mgLon;
    return ret;
}

QPair<float, float> GPSDevice::gcj02_to_bd09(const float& gg_lat, const float& gg_lon)
{
    float x = gg_lon;
    float y = gg_lat;
    float z = sqrt(x * x + y * y) + 0.00002 * sin(y * PI);
    float theta = atan2(y, x) + 0.000003 * cos(x * PI);
    float bd_lon = z * cos(theta) + 0.0065;
    float bd_lat = z * sin(theta) + 0.006;
    QPair<float, float> ret;
    ret.first = bd_lat;
    ret.second = bd_lon;
    return ret;
}

void GPSDevice::GPS_read()
{
    timer.stop();
    QByteArray data = buffer;
    buffer.clear();

    QString str_data = QString(data);
    int pos_start = str_data.indexOf("$GNGGA");
    int pos_end = str_data.indexOf("\r\n");
    str_data = str_data.mid(pos_start, pos_end - pos_start);
    qDebug() << str_data << "length:" << str_data.length();
    if(str_data.length() != 71)
    {
        qDebug() << "gps no found.";
        return;
    }
    QStringList split_data = str_data.split(",");

    QString raw_lat = split_data.at(2);
    QString direction_NS = split_data.at(3);
    QString raw_lon = split_data.at(4);
    QString direction_WE = split_data.at(5);

    QString satellite_num = split_data.at(7);
    QString altitude = split_data.at(9);

    QString lat = raw_lat.split(".")[0];
    QString ulat = raw_lat.split(".")[1];
    QString lon = raw_lon.split(".")[0];
    QString ulon = raw_lon.split(".")[1];

    float f_lat = str_to_GPS84(lat, ulat);
    float f_lon = str_to_GPS84(lon, ulon);
    QPair<float, float> ret;
    ret = gps84_to_gcj02(f_lat, f_lon);
    ret = gcj02_to_bd09(ret.first, ret.second);
    qDebug() << "lat:" << QString::number(ret.first, 'f', 6) << " lon:" << QString::number(ret.second, 'f', 6);
    ui->latitude_le->setText(QString::number(ret.first, 'f', 6) + " " + direction_NS);
    ui->longtitude_le->setText(QString::number(ret.second, 'f', 6) + " " + direction_WE);
    ui->satellite_num_le->setText(satellite_num);
    ui->altitude_le->setText(altitude);
}


void GPSDevice::on_openserial_btn_clicked()
{
    if(!is_uart_opened)
    {
        serial->setPortName(ui->portname_cb->currentText());
        serial->open(QIODevice::ReadOnly);
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if(!serial->isOpen())
            qDebug() << QString("Serial %1 opened failed : %2.").arg(ui->portname_cb->currentText(), serial->errorString());
        else
        {
            ui->portname_cb->setEnabled(false);
            qDebug() << QString("Serial %1 opened.").arg(ui->portname_cb->currentText());
            ui->openserial_btn->setText("关闭串口");
            ui->gps_locate_btn->setEnabled(true);
            is_uart_opened = true;
        }
    }
    else
    {
        ui->portname_cb->setEnabled(true);
        ui->openserial_btn->setText("打开串口");
        ui->gps_locate_btn->setEnabled(false);

        is_uart_opened = false;
        serial->close();
        qDebug() << QString("Serial %1 closed.").arg(ui->portname_cb->currentText());
    }
        return;
}


