#include "sqliteoperator.h"

SqliteOperator::SqliteOperator(Ui::Widget *ui)
{
    this->ui = ui;
}




void SqliteOperator::create_DB()
{
    // check the database file
    QString database_path = "./";
    database_path.append(DATABASE_FILENAME);
    if(QFile::exists(database_path))
    {
        qDebug() << "database file exist.";

        // init the sql database connection and file
        if(QSqlDatabase::contains(DATABASE_CONNECTION_NAME))
        {
            qDebug() << "database connection already existed!";
            db = QSqlDatabase::database(DATABASE_CONNECTION_NAME);
        }
        else
        {
            qDebug() << "start a new database connection!";

            db = QSqlDatabase::addDatabase(DATABASE_TYPE);
            db.setDatabaseName(DATABASE_FILENAME);
        }
    }
    else    // database file not exist
    {
        qDebug() << "database file not exist.";

        db = QSqlDatabase::addDatabase(DATABASE_TYPE);
        db.setDatabaseName(DATABASE_FILENAME);

        createTable();
    }
    return;
}

bool SqliteOperator::open_DB()
{
    // open the database
    if(!db.open())
    {
        qDebug() << "Error:Failed to open the database." << db.lastError();
        return false;
    }
    return true;
}

void SqliteOperator::close_DB()
{
    db.close();
}

void SqliteOperator::createTable()
{
    open_DB();
    QSqlQuery sql_query;
    QString create_table_command = "create table bat_record ("
                                   "id integer primary key autoincrement,"
                                   "imagedata blob,"
                                   "timestamp text,"
                                   "classification varchar(255),"
                                   "sync_status int"
                                   ");";
    sql_query.prepare(create_table_command);
    if(!sql_query.exec())
        qDebug() << "Error:Failed to create the table." << sql_query.lastError();
    else
        qDebug() << "Table created!";

    close_DB();
    return;
}



void SqliteOperator::insertData(const QByteArray &arr, const QString predict_class)
{
    open_DB();
    QString insert_data_command = "insert into bat_record (imagedata,timestamp,classification,sync_status) values(?,?,?,?);";
    QSqlQuery sql_query;
    sql_query.prepare(insert_data_command);

    sql_query.addBindValue(arr);
    sql_query.addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    sql_query.addBindValue(predict_class);
    sql_query.addBindValue(false);

    if(!sql_query.exec())
        qDebug() << "Error:Failed to insert the data." << sql_query.lastError();
    else
        qDebug() << "Data inserted!";

    close_DB();
    return;
}


//void SqliteOperator::updateData()
//{
//    QString update_data_command = "update bat_record set classification = :classification where id = :id";
//    QSqlQuery sql_query;
//    sql_query.prepare(update_data_command);
//    sql_query.bindValue(":name", );
//    sql_query.bindValue(":id", );

//    if(!sql_query.exec())
//        qDebug() << "Error:Failed to update the data." << sql_query.lastError();
//    else
//        qDebug() << "Data updated!";

//    return;
//}

void SqliteOperator::refreshTable()
{
    open_DB();
    QSqlQuery sql_query;
    QString query_command = "select * from bat_record";
    sql_query.prepare(query_command);
    if(!sql_query.exec())
        qDebug() << "Error:Failed to fetch data from the table." << sql_query.lastError();
    else
    {
        qDebug() << "Table refreshed!";
        while(sql_query.next())
        {
            // sql_query.value() return a QVariant

            QPixmap pixmap;
            pixmap.loadFromData(sql_query.value("imagedata").toByteArray(), "png");
            pixmap.scaled(200, 200, Qt::KeepAspectRatio);
            QIcon icon(pixmap);

            int id = sql_query.value("id").toInt();
            QString timestamp = sql_query.value("timestamp").toString();
            QString classifation = sql_query.value("classification").toString();
            bool sync_status = sql_query.value("sync_status").toBool();

            int row_id = id - 1;

            ui->bat_record_tw->setItem(row_id, 0, new QTableWidgetItem(QString::number(id)));
            ui->bat_record_tw->item(row_id, 0)->setTextAlignment(Qt::AlignCenter);

            ui->bat_record_tw->setItem(row_id, 1, new QTableWidgetItem(icon, ""));
            ui->bat_record_tw->item(row_id, 1)->setTextAlignment(Qt::AlignCenter);

            ui->bat_record_tw->setItem(row_id, 2, new QTableWidgetItem(timestamp));
            ui->bat_record_tw->item(row_id, 2)->setTextAlignment(Qt::AlignCenter);

            ui->bat_record_tw->setItem(row_id, 3, new QTableWidgetItem(classifation));
            ui->bat_record_tw->item(row_id, 3)->setTextAlignment(Qt::AlignCenter);

            if(sync_status)
            {
                ui->bat_record_tw->setItem(row_id, 4, new QTableWidgetItem("TRUE"));
                ui->bat_record_tw->item(row_id, 4)->setTextAlignment(Qt::AlignCenter);
            }
            else
            {
                ui->bat_record_tw->setItem(row_id, 4, new QTableWidgetItem("FALSE"));
                ui->bat_record_tw->item(row_id, 4)->setTextAlignment(Qt::AlignCenter);
            }


            QWidget *tmp_widget = new QWidget(ui->bat_record_tw);
            QHBoxLayout *tmp_layout = new QHBoxLayout(tmp_widget);
            QPushButton *edit_btn = new QPushButton(tmp_widget);
            QPushButton *delete_btn = new QPushButton(tmp_widget);
            edit_btn->setText("编辑");
            delete_btn->setText("删除");
            tmp_layout->addWidget(edit_btn);
            tmp_layout->addWidget(delete_btn);
            tmp_layout->setMargin(15);
            ui->bat_record_tw->setCellWidget(row_id, 5, tmp_widget);
        }

    }
    close_DB();
    return;
}


unsigned int SqliteOperator::fetchRecordsNum()
{
    open_DB();

    QString fetch_command = "select count(*) from bat_record;";
    QSqlQuery sql_query;
    sql_query.prepare(fetch_command);

    if(!sql_query.exec())
        qDebug() << "Error:Failed to fetch the records num." << sql_query.lastError();
    else
    {
        sql_query.next();
        count = sql_query.value(0).toInt();
        qDebug() << "Records num:" << count;

    }
    close_DB();
    return count;
}
