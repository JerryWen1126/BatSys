#include "sqliteoperator.h"

SqliteOperator::SqliteOperator(Ui::Widget *ui, QWidget *parent)
    :QObject(parent)
{
    this->ui = ui;
}

SqliteOperator::~SqliteOperator()
{
    // don't delete ui here
    if(is_edit_dialog_opened)
    {
        delete edit_ui;
        delete dialog;
    }
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

bool SqliteOperator::removeData(unsigned int id)
{
    open_DB();
    QString delete_data_command = "delete from bat_record where id = :id;";
    QSqlQuery sql_query;
    sql_query.prepare(delete_data_command);
    sql_query.bindValue(":id", id);
    qDebug() << "id:" << id << " try to remove...";
    if(!sql_query.exec())
    {
        qDebug() << "Error:Failed to remove the data." << sql_query.lastError();
        close_DB();
        return false;
    }
    else
    {
        qDebug() << "Data removed!";
        close_DB();
        return true;
    }
}

bool SqliteOperator::updateData()
{
    QString update_data_command = "update bat_record set classification = :classification where id = :id;";
    QSqlQuery sql_query;
    sql_query.prepare(update_data_command);
    sql_query.bindValue(":classification", edit_ui->predict_cb->currentText());
    sql_query.bindValue(":id", edit_ui->id_le->text());

    if(!sql_query.exec())
    {
        qDebug() << "Error:Failed to update the data." << sql_query.lastError();
        return false;
    }
    else
    {
        qDebug() << "Data updated!";
        return true;
    }
}

void SqliteOperator::refreshTable()
{
    ui->bat_record_tw->setRowCount(fetchRecordsNum());
    open_DB();
    QSqlQuery sql_query;
    QString query_command = "select * from bat_record";
    sql_query.prepare(query_command);
    if(!sql_query.exec())
        qDebug() << "Error:Failed to fetch data from the table." << sql_query.lastError();
    else
    {
        qDebug() << "Table refreshed!";
        unsigned int row_id = 0;
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

            qDebug() << "Currrnt row_id is:" << row_id;
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

            connect(edit_btn, SIGNAL(clicked(bool)), this, SLOT(on_edit_item_btn_clicked()));
            connect(delete_btn, SIGNAL(clicked(bool)), this, SLOT(on_delete_item_btn_clicked()));
            row_id++;
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

void SqliteOperator::on_edit_item_btn_clicked()
{
    // get the clicked item's row and column
    QPushButton *btn = dynamic_cast<QPushButton *>(this->sender());
    int x = btn->parentWidget()->frameGeometry().x();
    int y = btn->parentWidget()->frameGeometry().y();
    QModelIndex model_index = ui->bat_record_tw->indexAt(QPoint(x, y));
    unsigned int row = model_index.row();

    // edit interface
    is_edit_dialog_opened = true;
    edit_ui = new Ui::edit_dialog();
    dialog = new QDialog();

    // code below should be put after setupUI
    edit_ui->setupUi(dialog);

    edit_ui->id_le->setText(ui->bat_record_tw->item(row, 0)->text());
    edit_ui->timestamp_le->setText(ui->bat_record_tw->item(row, 2)->text());
    for(int option = 0; option < edit_ui->predict_cb->count(); option++)
    {
        if(QString::compare(edit_ui->predict_cb->itemText(option), ui->bat_record_tw->item(row, 3)->text()) == 0)
        {
            edit_ui->predict_cb->setCurrentIndex(option);
            break;
        }
    }
    edit_ui->sync_status_le->setText(ui->bat_record_tw->item(row, 4)->text());

    edit_ui->id_le->setEnabled(false);
    edit_ui->timestamp_le->setEnabled(false);
    edit_ui->sync_status_le->setEnabled(false);
    edit_ui->buttonBox->button(QDialogButtonBox::Ok)->setText("确认");
    edit_ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("取消");
    connect(edit_ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked(bool)), this, SLOT(on_confirm_edit_btn_clicked()));

    dialog->setFixedSize(dialog->width(), dialog->height());
    dialog->setWindowModality(Qt::WindowModal);
    dialog->show();
}

void SqliteOperator::on_delete_item_btn_clicked()
{
    // get the clicked item's row and column
    QPushButton *btn = dynamic_cast<QPushButton *>(this->sender());
    int x = btn->parentWidget()->frameGeometry().x();
    int y = btn->parentWidget()->frameGeometry().y();
    QModelIndex model_index = ui->bat_record_tw->indexAt(QPoint(x, y));
    unsigned int row = model_index.row();
    unsigned int id = ui->bat_record_tw->item(row, 0)->text().toInt();

    QMessageBox delete_msg(QMessageBox::Question, "删除记录", "真的要删除吗？", QMessageBox::Yes|QMessageBox::No);
    delete_msg.setButtonText(QMessageBox::Yes, "是");
    delete_msg.setButtonText(QMessageBox::No, "否");
    switch (delete_msg.exec()){
    case QMessageBox::Yes:
        qDebug() << "YES";
        removeData(id);
        refreshTable();
        break;

    case QMessageBox::No:
        qDebug() << "NO";
        break;

    default:
        break;
    }
}

void SqliteOperator::on_confirm_edit_btn_clicked()
{
    open_DB();
    if(!updateData())// TODO
        QMessageBox::critical(nullptr, "警告", "数据库连接失败", QMessageBox::Ok);
    else refreshTable();

    close_DB();
    return;
}


