/********************************************************************************
** Form generated from reading UI file 'edit_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_DIALOG_H
#define UI_EDIT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_dialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *id_lb;
    QLabel *timestamp_lb;
    QLabel *predict_lb;
    QLabel *predict_chance_lb;
    QLabel *sync_status_lb;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *id_le;
    QLineEdit *timestamp_le;
    QComboBox *predict_cb;
    QLineEdit *predict_chance_le;
    QLineEdit *sync_status_le;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *edit_dialog)
    {
        if (edit_dialog->objectName().isEmpty())
            edit_dialog->setObjectName(QString::fromUtf8("edit_dialog"));
        edit_dialog->setWindowModality(Qt::ApplicationModal);
        edit_dialog->resize(260, 260);
        edit_dialog->setModal(false);
        layoutWidget = new QWidget(edit_dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 241, 241));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        id_lb = new QLabel(layoutWidget);
        id_lb->setObjectName(QString::fromUtf8("id_lb"));

        verticalLayout->addWidget(id_lb);

        timestamp_lb = new QLabel(layoutWidget);
        timestamp_lb->setObjectName(QString::fromUtf8("timestamp_lb"));

        verticalLayout->addWidget(timestamp_lb);

        predict_lb = new QLabel(layoutWidget);
        predict_lb->setObjectName(QString::fromUtf8("predict_lb"));

        verticalLayout->addWidget(predict_lb);

        predict_chance_lb = new QLabel(layoutWidget);
        predict_chance_lb->setObjectName(QString::fromUtf8("predict_chance_lb"));

        verticalLayout->addWidget(predict_chance_lb);

        sync_status_lb = new QLabel(layoutWidget);
        sync_status_lb->setObjectName(QString::fromUtf8("sync_status_lb"));

        verticalLayout->addWidget(sync_status_lb);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        id_le = new QLineEdit(layoutWidget);
        id_le->setObjectName(QString::fromUtf8("id_le"));
        id_le->setEnabled(false);

        verticalLayout_2->addWidget(id_le);

        timestamp_le = new QLineEdit(layoutWidget);
        timestamp_le->setObjectName(QString::fromUtf8("timestamp_le"));
        timestamp_le->setEnabled(false);

        verticalLayout_2->addWidget(timestamp_le);

        predict_cb = new QComboBox(layoutWidget);
        predict_cb->addItem(QString());
        predict_cb->addItem(QString());
        predict_cb->addItem(QString());
        predict_cb->addItem(QString());
        predict_cb->addItem(QString());
        predict_cb->setObjectName(QString::fromUtf8("predict_cb"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(predict_cb->sizePolicy().hasHeightForWidth());
        predict_cb->setSizePolicy(sizePolicy);
        predict_cb->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        verticalLayout_2->addWidget(predict_cb);

        predict_chance_le = new QLineEdit(layoutWidget);
        predict_chance_le->setObjectName(QString::fromUtf8("predict_chance_le"));
        predict_chance_le->setEnabled(false);

        verticalLayout_2->addWidget(predict_chance_le);

        sync_status_le = new QLineEdit(layoutWidget);
        sync_status_le->setObjectName(QString::fromUtf8("sync_status_le"));
        sync_status_le->setEnabled(false);

        verticalLayout_2->addWidget(sync_status_le);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(edit_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), edit_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), edit_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(edit_dialog);
    } // setupUi

    void retranslateUi(QDialog *edit_dialog)
    {
        edit_dialog->setWindowTitle(QCoreApplication::translate("edit_dialog", "\347\274\226\350\276\221\350\256\260\345\275\225", nullptr));
        id_lb->setText(QCoreApplication::translate("edit_dialog", "ID:", nullptr));
        timestamp_lb->setText(QCoreApplication::translate("edit_dialog", "\346\227\266\351\227\264\346\210\263:", nullptr));
        predict_lb->setText(QCoreApplication::translate("edit_dialog", "\351\242\204\346\265\213\347\261\273\345\210\253:", nullptr));
        predict_chance_lb->setText(QCoreApplication::translate("edit_dialog", "\347\275\256\344\277\241\345\272\246:", nullptr));
        sync_status_lb->setText(QCoreApplication::translate("edit_dialog", "\345\220\214\346\255\245\347\212\266\346\200\201:", nullptr));
        predict_cb->setItemText(0, QCoreApplication::translate("edit_dialog", "test_class", nullptr));
        predict_cb->setItemText(1, QCoreApplication::translate("edit_dialog", "test_class1", nullptr));
        predict_cb->setItemText(2, QCoreApplication::translate("edit_dialog", "test_class2", nullptr));
        predict_cb->setItemText(3, QCoreApplication::translate("edit_dialog", "test_class3", nullptr));
        predict_cb->setItemText(4, QCoreApplication::translate("edit_dialog", "test_class4", nullptr));

    } // retranslateUi

};

namespace Ui {
    class edit_dialog: public Ui_edit_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_DIALOG_H
