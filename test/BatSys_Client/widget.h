#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_connect_server_btn_clicked();

    void on_disconnect_btn_clicked();

    void on_send_msg_btn_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket* m_tcp;
};
#endif // WIDGET_H
