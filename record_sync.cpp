#include "record_sync.h"

SyncWork::SyncWork(QObject *parent):QObject(parent)
{

}

SyncWork::~SyncWork()
{

}

RecordSync::RecordSync(Ui::Widget *ui, QWidget *parent)
    :QObject(parent)
{
    this->ui = ui;
    m_tcp = new QTcpSocket(this);
    connect(m_tcp, &QTcpSocket::connected, this, &RecordSync::server_connected);
    connect(m_tcp, &QTcpSocket::disconnected, this, &RecordSync::server_disconnected);

    thread = new QThread(this);
    // don't move this* class to the thread, you should create a new class for working.
    work = new SyncWork();
    work->moveToThread(thread);
    connect(thread, SIGNAL(started()), work, SLOT(syncRecord()));

}


RecordSync::~RecordSync()
{
    if(thread->isRunning())
    {
        work->is_thread_running = false;
        thread->quit();
        thread->wait();
    }
    work->deleteLater();
    thread->deleteLater();
    delete thread;
    delete work;
//    delete m_tcp;

}

record* RecordSync::makeRecord(int id, QPixmap image, QString timestamp, QString classification, QString predict_chance, bool sync_status)
{
    record* ret;
    if(!sync_status)
    {
        ret = new record;
        ret->id = id;
        ret->image = image;
        ret->timestamp = timestamp;
        ret->classification = classification;
        ret->predict_chance = predict_chance;
        return ret;
    }
    return nullptr;
}

void RecordSync::addToSyncQueue(record rcd)
{
    not_synced_record->enqueue(rcd);
}

void SyncWork::syncRecord()
{
    qDebug() << "thread:syncRecord is running on TID:" << QThread::currentThread();
    while(1)
    {
        if(!is_thread_running)
        {
            qDebug() << "thread:syncRecord TID:" << QThread::currentThread() <<" stop!";
            return;
        }
        qDebug() << "1";
        QThread::msleep(500);
    }
}

void RecordSync::uploadRecord()
{
    if(not_synced_record->isEmpty())
    {
        qDebug() << "同步队列为空!";
        return;
    }
    else
    {
        qDebug() << "同步队列剩余:" << not_synced_record->size();
        record rcd = not_synced_record->dequeue();

    }
}

void RecordSync::on_server_connect_btn_clicked()
{
    if(!is_connected)
    {
        qDebug() << "open";
        QString ip = ui->ip_le->text();
        unsigned short port = ui->port_le->text().toInt();
        m_tcp->connectToHost(QHostAddress(ip), port);
        ui->server_connect_btn->setEnabled(false);
    }
    else
    {
        qDebug() << "close";
        m_tcp->close();
    }
    return;
}

void RecordSync::server_connected()
{
    qDebug() << "已和服务器建立连接......";
    is_connected = true;
    ui->connection_status_lb->setText("已连接");
    ui->server_connect_btn->setText("断开连接");
    ui->server_connect_btn->setEnabled(true);

    work->is_thread_running = true;
    thread->start();
}

void RecordSync::server_disconnected()
{
    qDebug() << "已和服务器断开连接......";
    is_connected = false;
    ui->connection_status_lb->setText("未连接");
    ui->server_connect_btn->setText("建立连接");
    ui->server_connect_btn->setEnabled(true);

    thread->quit();
    work->is_thread_running = false;

}




