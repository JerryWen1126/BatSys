#ifndef RECORD_SYNC_H
#define RECORD_SYNC_H
#include <QString>
#include <QPixmap>
#include <QQueue>
#include <QTcpSocket>
#include <QHostAddress>
#include <ui_widget.h>
#include <QThread>


typedef struct record
{
  int id;
  QPixmap image;
  QString timestamp;
  QString classification;
  QString predict_chance;

}record;

class SyncWork: public QObject
{
    Q_OBJECT
public:
    SyncWork(QObject *parent = nullptr);
    ~SyncWork();

private slots:
    void syncRecord();

public:
    bool is_thread_running = false;
};


class RecordSync: public QObject
{
    Q_OBJECT
public:
    RecordSync(Ui::Widget *, QWidget *parent = nullptr);
    ~RecordSync();
    record* makeRecord(int, QPixmap, QString, QString, QString, bool);
    void addToSyncQueue(record);
    void uploadRecord();


private slots:
    void on_server_connect_btn_clicked();
    void server_connected();
    void server_disconnected();


private:
    Ui::Widget* ui;

    QQueue<record>* not_synced_record;

    bool is_connected = false;
    QTcpSocket* m_tcp;
    QThread* thread;

    SyncWork* work;
};





#endif // RECORD_SYNC_H
