#ifndef RECORD_SYNC_H
#define RECORD_SYNC_H
#include <QString>
#include <QPixmap>
#include <QList>

typedef struct record
{
  int id;
  QPixmap image;
  QString timestamp;
  QString classification;
  QString predict_chance;

}record;

class RecordSync
{
public:
    RecordSync();
    ~RecordSync();
    record* makeRecord(int, QPixmap, QString, QString, QString, bool);
    bool addToSyncList(record);
    void syncRecord();
    void uploadRecord();


private:
    QList<record>* not_synced_record;
};

#endif // RECORD_SYNC_H
