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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *camera_window_lb;
    QVBoxLayout *verticalLayout_2;
    QPushButton *camera_open_close_btn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *camera_index_lb;
    QComboBox *camera_index_cb;
    QCheckBox *is_csi_camera_cb;
    QPushButton *insert_data_btn;
    QSpacerItem *verticalSpacer;
    QWidget *data_record_tab;
    QTableWidget *bat_record_tw;
    QWidget *device_location_tab;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_8;
    QWebEngineView *webmap_wev;
    QVBoxLayout *verticalLayout_4;
    QPushButton *gps_locate_btn;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *latitude_lb;
    QDoubleSpinBox *latitude_dsb;
    QHBoxLayout *horizontalLayout_4;
    QLabel *longtitude_lb;
    QDoubleSpinBox *longtitude_dsb;
    QPushButton *locate_btn;
    QSpacerItem *verticalSpacer_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;

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
        widget = new QWidget(bat_recognition_tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1, 1, 991, 541));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        camera_window_lb = new QLabel(widget);
        camera_window_lb->setObjectName(QString::fromUtf8("camera_window_lb"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(camera_window_lb->sizePolicy().hasHeightForWidth());
        camera_window_lb->setSizePolicy(sizePolicy1);
        camera_window_lb->setScaledContents(true);

        horizontalLayout_9->addWidget(camera_window_lb);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        camera_open_close_btn = new QPushButton(widget);
        camera_open_close_btn->setObjectName(QString::fromUtf8("camera_open_close_btn"));

        verticalLayout_2->addWidget(camera_open_close_btn);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        camera_index_lb = new QLabel(widget);
        camera_index_lb->setObjectName(QString::fromUtf8("camera_index_lb"));

        horizontalLayout_2->addWidget(camera_index_lb);

        camera_index_cb = new QComboBox(widget);
        camera_index_cb->setObjectName(QString::fromUtf8("camera_index_cb"));

        horizontalLayout_2->addWidget(camera_index_cb);


        verticalLayout_2->addLayout(horizontalLayout_2);

        is_csi_camera_cb = new QCheckBox(widget);
        is_csi_camera_cb->setObjectName(QString::fromUtf8("is_csi_camera_cb"));

        verticalLayout_2->addWidget(is_csi_camera_cb);

        insert_data_btn = new QPushButton(widget);
        insert_data_btn->setObjectName(QString::fromUtf8("insert_data_btn"));
        insert_data_btn->setEnabled(false);

        verticalLayout_2->addWidget(insert_data_btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_9->addLayout(verticalLayout_2);

        tabWidget->addTab(bat_recognition_tab, QString());
        data_record_tab = new QWidget();
        data_record_tab->setObjectName(QString::fromUtf8("data_record_tab"));
        bat_record_tw = new QTableWidget(data_record_tab);
        if (bat_record_tw->columnCount() < 7)
            bat_record_tw->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        bat_record_tw->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        bat_record_tw->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        bat_record_tw->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        bat_record_tw->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        bat_record_tw->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        bat_record_tw->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        bat_record_tw->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        bat_record_tw->setObjectName(QString::fromUtf8("bat_record_tw"));
        bat_record_tw->setGeometry(QRect(10, 10, 891, 501));
        bat_record_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
        bat_record_tw->setIconSize(QSize(200, 200));
        bat_record_tw->setSortingEnabled(true);
        bat_record_tw->horizontalHeader()->setVisible(true);
        bat_record_tw->horizontalHeader()->setCascadingSectionResizes(false);
        bat_record_tw->horizontalHeader()->setDefaultSectionSize(100);
        bat_record_tw->horizontalHeader()->setHighlightSections(true);
        bat_record_tw->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        bat_record_tw->horizontalHeader()->setStretchLastSection(false);
        bat_record_tw->verticalHeader()->setVisible(false);
        bat_record_tw->verticalHeader()->setCascadingSectionResizes(false);
        bat_record_tw->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabWidget->addTab(data_record_tab, QString());
        device_location_tab = new QWidget();
        device_location_tab->setObjectName(QString::fromUtf8("device_location_tab"));
        layoutWidget1 = new QWidget(device_location_tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, -1, 991, 551));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        webmap_wev = new QWebEngineView(layoutWidget1);
        webmap_wev->setObjectName(QString::fromUtf8("webmap_wev"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(webmap_wev->sizePolicy().hasHeightForWidth());
        webmap_wev->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(webmap_wev);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gps_locate_btn = new QPushButton(layoutWidget1);
        gps_locate_btn->setObjectName(QString::fromUtf8("gps_locate_btn"));

        verticalLayout_4->addWidget(gps_locate_btn);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        latitude_lb = new QLabel(layoutWidget1);
        latitude_lb->setObjectName(QString::fromUtf8("latitude_lb"));

        horizontalLayout_3->addWidget(latitude_lb);

        latitude_dsb = new QDoubleSpinBox(layoutWidget1);
        latitude_dsb->setObjectName(QString::fromUtf8("latitude_dsb"));
        latitude_dsb->setDecimals(3);
        latitude_dsb->setMaximum(180.000000000000000);
        latitude_dsb->setValue(116.403999999999996);

        horizontalLayout_3->addWidget(latitude_dsb);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        longtitude_lb = new QLabel(layoutWidget1);
        longtitude_lb->setObjectName(QString::fromUtf8("longtitude_lb"));

        horizontalLayout_4->addWidget(longtitude_lb);

        longtitude_dsb = new QDoubleSpinBox(layoutWidget1);
        longtitude_dsb->setObjectName(QString::fromUtf8("longtitude_dsb"));
        longtitude_dsb->setDecimals(3);
        longtitude_dsb->setMaximum(90.000000000000000);
        longtitude_dsb->setValue(39.914999999999999);

        horizontalLayout_4->addWidget(longtitude_dsb);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_7->addLayout(verticalLayout_3);

        locate_btn = new QPushButton(layoutWidget1);
        locate_btn->setObjectName(QString::fromUtf8("locate_btn"));

        horizontalLayout_7->addWidget(locate_btn);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_8->addLayout(verticalLayout_4);

        tabWidget->addTab(device_location_tab, QString());

        verticalLayout->addWidget(tabWidget);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);

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
        camera_index_lb->setText(QCoreApplication::translate("Widget", "\350\256\276\345\244\207\345\217\267:", nullptr));
        is_csi_camera_cb->setText(QCoreApplication::translate("Widget", "CSI\346\221\204\345\203\217\345\244\264", nullptr));
        insert_data_btn->setText(QCoreApplication::translate("Widget", "(\346\217\222\345\205\245\346\225\260\346\215\256)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(bat_recognition_tab), QCoreApplication::translate("Widget", "\350\235\231\350\235\240\350\257\206\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem = bat_record_tw->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = bat_record_tw->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\346\215\225\350\216\267\345\233\276\345\203\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = bat_record_tw->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264\346\210\263", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = bat_record_tw->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "\351\242\204\346\265\213\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = bat_record_tw->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "\347\275\256\344\277\241\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = bat_record_tw->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "\345\220\214\346\255\245\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = bat_record_tw->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Widget", "\346\223\215\344\275\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(data_record_tab), QCoreApplication::translate("Widget", "\346\225\260\346\215\256\350\256\260\345\275\225", nullptr));
        gps_locate_btn->setText(QCoreApplication::translate("Widget", "GPS\345\256\232\344\275\215", nullptr));
        latitude_lb->setText(QCoreApplication::translate("Widget", "\347\273\217\345\272\246:", nullptr));
        longtitude_lb->setText(QCoreApplication::translate("Widget", "\347\272\254\345\272\246:", nullptr));
        locate_btn->setText(QCoreApplication::translate("Widget", "\345\256\232\344\275\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(device_location_tab), QCoreApplication::translate("Widget", "\350\256\276\345\244\207\345\256\232\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
