#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("TCP client");
    m_tcp = new QTcpSocket(this);
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
    {
       QByteArray recvMsg = m_tcp->readAll();
       ui->record_pte->appendPlainText("服务器:" + recvMsg);
    });

    connect(m_tcp, &QTcpSocket::connected, this, [=]()
    {
       ui->record_pte->appendPlainText("服务器连接成功...");

    });
    connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
    {
        ui->record_pte->appendPlainText("服务器已断开连接...");
        ui->connect_server_btn->setEnabled(true);
        ui->disconnect_btn->setEnabled(false);
    });
}


Widget::~Widget()
{
    delete ui;
    delete m_tcp;
}


void Widget::on_connect_server_btn_clicked()
{
    QString ip = ui->ip_le->text();
    unsigned short port = ui->port_le->text().toInt();
    m_tcp->connectToHost(QHostAddress(ip), port);
    ui->connect_server_btn->setEnabled(false);
    ui->disconnect_btn->setEnabled(true);
}


void Widget::on_disconnect_btn_clicked()
{
    m_tcp->close();
    ui->connect_server_btn->setEnabled(true);
    ui->disconnect_btn->setEnabled(false);
}


void Widget::on_send_msg_btn_clicked()
{
    QString sendMsg = ui->send_msg_pte->toPlainText();
    m_tcp->write(sendMsg.toUtf8());
    ui->record_pte->appendPlainText("客户端:" + sendMsg);
    ui->send_msg_pte->clear();
}

