/********************************************************************************
** Form generated from reading UI file 'maiaunitconv.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIAUNITCONV_H
#define UI_MAIAUNITCONV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaiaUnitConv
{
public:
    QAction *actionNew;
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *listBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineToConv;
    QLabel *lab_unity_to_convert;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineConverted;
    QLabel *lab_unity_converted;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidToConvert;
    QListWidget *listWidConverted;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MaiaUnitConv)
    {
        if (MaiaUnitConv->objectName().isEmpty())
            MaiaUnitConv->setObjectName(QString::fromUtf8("MaiaUnitConv"));
        MaiaUnitConv->resize(615, 766);
        actionNew = new QAction(MaiaUnitConv);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionQuit = new QAction(MaiaUnitConv);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MaiaUnitConv);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        listBox = new QComboBox(centralWidget);
        listBox->addItem(QString());
        listBox->addItem(QString());
        listBox->addItem(QString());
        listBox->setObjectName(QString::fromUtf8("listBox"));

        verticalLayout->addWidget(listBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineToConv = new QLineEdit(centralWidget);
        lineToConv->setObjectName(QString::fromUtf8("lineToConv"));
        lineToConv->setMinimumSize(QSize(0, 28));
        lineToConv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineToConv->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineToConv);

        lab_unity_to_convert = new QLabel(centralWidget);
        lab_unity_to_convert->setObjectName(QString::fromUtf8("lab_unity_to_convert"));
        lab_unity_to_convert->setMinimumSize(QSize(100, 28));
        lab_unity_to_convert->setFrameShape(QFrame::StyledPanel);
        lab_unity_to_convert->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(lab_unity_to_convert);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineConverted = new QLineEdit(centralWidget);
        lineConverted->setObjectName(QString::fromUtf8("lineConverted"));
        lineConverted->setMinimumSize(QSize(0, 28));
        lineConverted->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineConverted->setReadOnly(true);
        lineConverted->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(lineConverted);

        lab_unity_converted = new QLabel(centralWidget);
        lab_unity_converted->setObjectName(QString::fromUtf8("lab_unity_converted"));
        lab_unity_converted->setMinimumSize(QSize(100, 28));
        lab_unity_converted->setFrameShape(QFrame::StyledPanel);
        lab_unity_converted->setFrameShadow(QFrame::Plain);

        horizontalLayout_2->addWidget(lab_unity_converted);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        listWidToConvert = new QListWidget(centralWidget);
        listWidToConvert->setObjectName(QString::fromUtf8("listWidToConvert"));

        horizontalLayout_3->addWidget(listWidToConvert);

        listWidConverted = new QListWidget(centralWidget);
        listWidConverted->setObjectName(QString::fromUtf8("listWidConverted"));

        horizontalLayout_3->addWidget(listWidConverted);


        verticalLayout->addLayout(horizontalLayout_3);

        MaiaUnitConv->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MaiaUnitConv);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 615, 21));
        MaiaUnitConv->setMenuBar(menuBar);

        retranslateUi(MaiaUnitConv);

        QMetaObject::connectSlotsByName(MaiaUnitConv);
    } // setupUi

    void retranslateUi(QMainWindow *MaiaUnitConv)
    {
        MaiaUnitConv->setWindowTitle(QApplication::translate("MaiaUnitConv", "MaiaUnitConv", nullptr));
        actionNew->setText(QApplication::translate("MaiaUnitConv", "New", nullptr));
        actionQuit->setText(QApplication::translate("MaiaUnitConv", "Quit", nullptr));
        listBox->setItemText(0, QApplication::translate("MaiaUnitConv", "Units", nullptr));
        listBox->setItemText(1, QApplication::translate("MaiaUnitConv", "Angles", nullptr));
        listBox->setItemText(2, QApplication::translate("MaiaUnitConv", "Temperatures", nullptr));

        lab_unity_to_convert->setText(QString());
        lab_unity_converted->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MaiaUnitConv: public Ui_MaiaUnitConv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIAUNITCONV_H
