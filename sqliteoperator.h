#ifndef SQLITEOPERATOR_H
#define SQLITEOPERATOR_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <ui_widget.h>

#define DATABASE_CONNECTION_NAME "qt_sql_default_connection"
#define DATABASE_TYPE "QSQLITE"
#define DATABASE_FILENAME "BatRecord.db"


class SqliteOperator
{
public:
    SqliteOperator(Ui::Widget *);

    // create the database
    void create_DB();
    // create the table to store records
    void createTable();
    // open the database
    bool open_DB();
    // close the database
    void close_DB();
    // insert the record to table
    void insertData(const QByteArray&, const QString);
    // update the record
    void updateData();
    // fetch the record and show in the table widget
    void refreshTable();
    // fetch the records num
    unsigned int fetchRecordsNum();

private:
    QSqlDatabase db;
    Ui::Widget* ui;
    unsigned int count;
};

#endif // SQLITEOPERATOR_H
