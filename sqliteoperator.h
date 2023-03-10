#ifndef SQLITEOPERATOR_H
#define SQLITEOPERATOR_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "ui_widget.h"

#define DATABASE_CONNECTION_NAME "qt_sql_default_connection"
#define DATABASE_TYPE "QSQLITE"
#define DATABASE_FILENAME "BatRecord.db"


class SqliteOperator
{
public:
    SqliteOperator(Ui::Widget *ui);

    // create the database
    void create_DB();
    // create the table to store records
    void createTable();
    // open the database
    bool open_DB();
    // close the database
    void close_DB();
    // insert the record to table
    void insertData();
    // update the record
    void updateData();
    // fetch the record and show in the Itemtable
    void refreshTable();

private:
    Ui::Widget* ui;
    QSqlDatabase db;

};

#endif // SQLITEOPERATOR_H
