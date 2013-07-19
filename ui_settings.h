/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *label;
    QWidget *page_2;
    QLabel *label_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QFontComboBox *fontComboBox;
    QLabel *label_4;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QString::fromUtf8("settings"));
        settings->resize(400, 290);
        verticalLayout = new QVBoxLayout(settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(settings);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        formLayoutWidget = new QWidget(page);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 20, 351, 211));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(formLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, checkBox);

        checkBox_2 = new QCheckBox(formLayoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, checkBox_2);

        checkBox_3 = new QCheckBox(formLayoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, checkBox_3);

        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 66, 21));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 66, 21));
        formLayoutWidget_2 = new QWidget(page_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(0, 20, 351, 211));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        fontComboBox = new QFontComboBox(formLayoutWidget_2);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, fontComboBox);

        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        spinBox = new QSpinBox(formLayoutWidget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setValue(10);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBox);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        buttonBox = new QDialogButtonBox(settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(settings);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Dialog", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("settings", "Text wrapping", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("settings", "Highlight current line", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("settings", "Highlight matching parens", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("settings", "General", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("settings", "Font", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("settings", "Font", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("settings", "Font Size", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
