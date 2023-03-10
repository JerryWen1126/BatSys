#include "sqliteoperator.h"

SqliteOperator::SqliteOperator(Ui::Widget *ui)
{
    this->ui = ui;
}




void SqliteOperator::create_DB()
{
    // init the sql database connection and file
    if(QSqlDatabase::contains(DATABASE_CONNECTION_NAME))
    {
        qDebug() << "database already existed!";
        db = QSqlDatabase::database(DATABASE_CONNECTION_NAME);
    }
    else
    {
        qDebug() << "database not existed!";

        db = QSqlDatabase::addDatabase(DATABASE_TYPE);
        db.setDatabaseName(DATABASE_FILENAME);
        open_DB();
        createTable();
        close_DB();
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
    QSqlQuery sql_query(db);
    QString create_table_command = "create table bat_record ("
                                   "id integer primary key autoincrement,"
                                   "imagedata blob,"
                                   "timestamp text,"
                                   "classification varchar(255),"
                                   "sync_status int"
                                   ");";
    qDebug() << create_table_command;
    sql_query.prepare(create_table_command);
    if(!sql_query.exec())
        qDebug() << "Error:Failed to create the table." << sql_query.lastError();
    else
        qDebug() << "Table created!";

    return;
}



//void SqliteOperator::insertData()
//{
//    QString insert_data_command = "insert into bat_record values(?,?,?,?,?)";
//    QSqlQuery sql_query;
//    sql_query.prepare(insert_data_command);
//    sql_query.addBindValue(sql_query.lastInsertId() + 1);
//    sql_query.addBindValue();
//    sql_query.addBindValue();
//    sql_query.addBindValue();
//    sql_query.addBindValue();
//    if(!sql_query.exec())
//        qDebug() << "Error:Failed to insert the data." << sql_query.lastError();
//    else
//        qDebug() << "Data inserted!";

//    return;
//}


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

}
