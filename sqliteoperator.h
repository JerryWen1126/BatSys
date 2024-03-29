#ifndef SQLITEOPERATOR_H
#define SQLITEOPERATOR_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <ui_widget.h>
#include <ui_edit_dialog.h>
#include <QMessageBox>
#include <QThread>

#define DATABASE_CONNECTION_NAME "qt_sql_default_connection"
#define DATABASE_TYPE "QSQLITE"
#define DATABASE_FILENAME "BatRecord.db"



class JsonWork;

class SqliteOperator: public QObject
{
    friend class JsonWork;
    Q_OBJECT
public:
    SqliteOperator(Ui::Widget *, QWidget *parent = nullptr);
    ~SqliteOperator();

    // create the database
    void create_DB();
    // create the table to store records
    void createTable();
    // open the database
    bool open_DB();
    // close the database
    void close_DB();
    // insert the record to table
    void insertData(const QByteArray&, const QString, const QString);
    // update the record
    bool updateData();
    // remove the record
    bool removeData(unsigned int);
    // fetch the record and show in the table widget
    void refreshTable();
    // fetch the records num
    unsigned int fetchRecordsNum();


private slots:
    void on_edit_item_btn_clicked();
    void on_delete_item_btn_clicked();
    void on_confirm_edit_btn_clicked();



private:
    QSqlDatabase db;
    Ui::Widget* ui;
    Ui::edit_dialog* edit_ui;
    QDialog* dialog;
    bool is_edit_dialog_opened = false;
    unsigned int count;
public:
    JsonWork* work;
};

class JsonWork: public QObject
{
    Q_OBJECT
public:
    JsonWork(SqliteOperator *, QObject *parent = nullptr);
    ~JsonWork();

private slots:
    void check_and_make_json();

public:
    SqliteOperator *sql_op;
};


#endif // SQLITEOPERATOR_H
