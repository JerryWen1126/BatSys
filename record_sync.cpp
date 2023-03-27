#include "record_sync.h"

RecordSync::RecordSync()
{

}


RecordSync::~RecordSync()
{

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
    }
    return ret;
}

//bool RecordSync::addToSyncList(record rcd)
//{
//    not_synced_record->
//}

void RecordSync::syncRecord()
{

}

void RecordSync::uploadRecord()
{

}
