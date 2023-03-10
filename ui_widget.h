/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *program_title_lb;
    QLabel *program_version_lb;
    QLabel *current_program_version_lb;
    QSpacerItem *horizontalSpacer;
    QLabel *network_lb;
    QLabel *connection_status_lb;
    QLabel *time_lb;
    QLabel *local_time_lb;
    QPushButton *exit_btn;
    QTabWidget *tabWidget;
    QWidget *bat_recognition_tab;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *camera_window_lb;
    QVBoxLayout *verticalLayout_2;
    QPushButton *camera_open_close_btn;
    QPushButton *insert_data_btn;
    QSpacerItem *verticalSpacer;
    QWidget *data_record_tab;
    QTableWidget *bat_record_ti;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1024, 600);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 1021, 591));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        program_title_lb = new QLabel(layoutWidget);
        program_title_lb->setObjectName(QString::fromUtf8("program_title_lb"));

        horizontalLayout->addWidget(program_title_lb);

        program_version_lb = new QLabel(layoutWidget);
        program_version_lb->setObjectName(QString::fromUtf8("program_version_lb"));

        horizontalLayout->addWidget(program_version_lb);

        current_program_version_lb = new QLabel(layoutWidget);
        current_program_version_lb->setObjectName(QString::fromUtf8("current_program_version_lb"));

        horizontalLayout->addWidget(current_program_version_lb);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        network_lb = new QLabel(layoutWidget);
        network_lb->setObjectName(QString::fromUtf8("network_lb"));

        horizontalLayout->addWidget(network_lb);

        connection_status_lb = new QLabel(layoutWidget);
        connection_status_lb->setObjectName(QString::fromUtf8("connection_status_lb"));

        horizontalLayout->addWidget(connection_status_lb);

        time_lb = new QLabel(layoutWidget);
        time_lb->setObjectName(QString::fromUtf8("time_lb"));

        horizontalLayout->addWidget(time_lb);

        local_time_lb = new QLabel(layoutWidget);
        local_time_lb->setObjectName(QString::fromUtf8("local_time_lb"));

        horizontalLayout->addWidget(local_time_lb);

        exit_btn = new QPushButton(layoutWidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exit_btn->sizePolicy().hasHeightForWidth());
        exit_btn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(exit_btn);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);
        bat_recognition_tab = new QWidget();
        bat_recognition_tab->setObjectName(QString::fromUtf8("bat_recognition_tab"));
        layoutWidget1 = new QWidget(bat_recognition_tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 991, 541));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        camera_window_lb = new QLabel(layoutWidget1);
        camera_window_lb->setObjectName(QString::fromUtf8("camera_window_lb"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(camera_window_lb->sizePolicy().hasHeightForWidth());
        camera_window_lb->setSizePolicy(sizePolicy1);
        camera_window_lb->setScaledContents(true);

        horizontalLayout_2->addWidget(camera_window_lb);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        camera_open_close_btn = new QPushButton(layoutWidget1);
        camera_open_close_btn->setObjectName(QString::fromUtf8("camera_open_close_btn"));

        verticalLayout_2->addWidget(camera_open_close_btn);

        insert_data_btn = new QPushButton(layoutWidget1);
        insert_data_btn->setObjectName(QString::fromUtf8("insert_data_btn"));
        insert_data_btn->setEnabled(false);

        verticalLayout_2->addWidget(insert_data_btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        tabWidget->addTab(bat_recognition_tab, QString());
        data_record_tab = new QWidget();
        data_record_tab->setObjectName(QString::fromUtf8("data_record_tab"));
        bat_record_ti = new QTableWidget(data_record_tab);
        if (bat_record_ti->columnCount() < 6)
            bat_record_ti->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        bat_record_ti->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        bat_record_ti->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        bat_record_ti->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        bat_record_ti->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        bat_record_ti->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        bat_record_ti->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        bat_record_ti->setObjectName(QString::fromUtf8("bat_record_ti"));
        bat_record_ti->setGeometry(QRect(10, 10, 891, 501));
        bat_record_ti->horizontalHeader()->setVisible(true);
        bat_record_ti->horizontalHeader()->setCascadingSectionResizes(false);
        bat_record_ti->horizontalHeader()->setHighlightSections(true);
        bat_record_ti->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        bat_record_ti->horizontalHeader()->setStretchLastSection(false);
        bat_record_ti->verticalHeader()->setCascadingSectionResizes(false);
        bat_record_ti->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabWidget->addTab(data_record_tab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        program_title_lb->setText(QCoreApplication::translate("Widget", "\350\235\231\350\235\240\347\253\226\347\220\264\347\275\221\346\231\272\350\203\275\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        program_version_lb->setText(QCoreApplication::translate("Widget", "\347\211\210\346\234\254:", nullptr));
        current_program_version_lb->setText(QString());
        network_lb->setText(QCoreApplication::translate("Widget", "\347\275\221\347\273\234:", nullptr));
        connection_status_lb->setText(QString());
        time_lb->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\227\266\351\227\264:", nullptr));
        local_time_lb->setText(QString());
        exit_btn->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        camera_window_lb->setText(QString());
        camera_open_close_btn->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        insert_data_btn->setText(QCoreApplication::translate("Widget", "(\346\217\222\345\205\245\346\225\260\346\215\256)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(bat_recognition_tab), QCoreApplication::translate("Widget", "\350\235\231\350\235\240\350\257\206\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem = bat_record_ti->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = bat_record_ti->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\346\215\225\350\216\267\345\233\276\345\203\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = bat_record_ti->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264\346\210\263", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = bat_record_ti->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "\351\242\204\346\265\213\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = bat_record_ti->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "\345\220\214\346\255\245\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = bat_record_ti->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "\346\223\215\344\275\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(data_record_tab), QCoreApplication::translate("Widget", "\346\225\260\346\215\256\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
