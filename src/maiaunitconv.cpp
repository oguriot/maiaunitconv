/****************************************************************************
 ** This file is part of the MAIA® (Malagasy Artificial Intelligence Art) Open Project.
 **
 ** Copyright (C) 2012, 2013, 2014 ANDRIAMILAMINA Monge.
 ** All rights reserved.
 **
 ** License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007.
 ** Author:  ANDRIAMILAMINA Monge.
 ** Contact: mongemilamina@gmail.com / +261 34 45 062 85.
 ** Year:    2014.
 ** Status:  MAIA® Senior Engineer, Madagasikara, Antananarivo.
 ** Domain:  Automatic.
 **
 ** Commercial Usage
 ** Please contact MAIA®.
 **
 ** GNU General Public License Usage
 ** This file may be used under the terms of the GNU
 ** General Public License version 3.0 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.GPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU General Public License version 3.0 requirements will be
 ** met: http://www.gnu.org/copyleft/gpl.html.
 **
 ** If you have questions regarding the use of this file, please contact
 ** the Author.
 **
 ****************************************************************************/

#include "maiaunitconv.h"
#include "ui_maiaunitconv.h"
#include <QMessageBox>
#include <QString>
#include <QIcon>
#include <QEvent>
#include <QCloseEvent>

MaiaUnitConv::MaiaUnitConv(QWidget *parent) :
    QMainWindow(parent),
    att_ui(new Ui::MaiaUnitConv)
{
    att_ui->setupUi(this);

    att_Validator = new QDoubleValidator(this);

    //##############################################Lines
    att_ui->lineToConv->setText(tr("Value you want to convert..."));
    att_ui->lineToConv->selectAll();
    att_ui->lineConverted->setText(tr("Converted value..."));
    att_ui->lineToConv->setValidator(att_Validator);
    //##############################################Menus
    att_ActionNew = new QAction(QIcon(":/qrc_icons/icons/MAIA_icon_New.png"), tr("&New"), this);
    att_ActionNew->setShortcut(Qt::CTRL+Qt::Key_N);

    att_ActionCopyToConvertLine = new QAction(QIcon(":/qrc_icons/icons/MAIA_icon_Copy.png"), tr("&Copy") + " [ " + att_ui->lineToConv->text() + " ]", this);
    att_ActionCopyToConvertLine->setShortcut(Qt::CTRL+Qt::Key_C);

    att_ActionCopyConvertedLine = new QAction(QIcon(":/qrc_icons/icons/MAIA_icon_Copy.png"), tr("C&opy") + " [ " + att_ui->lineConverted->text() + " ]", this);
    att_ActionCopyConvertedLine->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_C);

    att_ActionAboutAndHelp = new QAction(QIcon(":/qrc_icons/icons/MAIA_icon_About.png"), tr("&About"), this);
    att_ActionAboutAndHelp->setShortcut(Qt::Key_F1);

    att_ActionQuit = new QAction(QIcon(":/qrc_icons/icons/MAIA_icon_Quit.png"), tr("&Quit"), this);
    att_ActionQuit->setShortcut(Qt::CTRL+Qt::Key_Q);
    //##############################################Menus
    att_MenuOperations = new QMenu(tr("Operations"));
    att_MenuOperations->addAction(att_ActionNew);
    att_MenuOperations->addSeparator();
    att_MenuOperations->addAction(att_ActionQuit);

    att_MenuCopies = new QMenu(tr("Copies"));
    att_MenuCopies->addAction(att_ActionCopyToConvertLine);
    att_MenuCopies->addAction(att_ActionCopyConvertedLine);

    att_MenuAboutAndHelp = new QMenu("?");
    att_MenuAboutAndHelp->addAction(att_ActionAboutAndHelp);

    att_ui->menuBar->addMenu(att_MenuOperations);
    att_ui->menuBar->addMenu(att_MenuCopies);
    att_ui->menuBar->addMenu(att_MenuAboutAndHelp);

    //##############################################
    connect(att_ActionNew, SIGNAL(triggered()), this, SLOT(m_new_()));
    connect(att_ActionAboutAndHelp, SIGNAL(triggered()), this, SLOT(m_aboutAndHelp()));
    connect(att_ActionQuit, SIGNAL(triggered()), this, SLOT(close()));

    connect(att_ui->lineToConv, SIGNAL(textChanged(QString)), this, SLOT(m_handleCopies()));
    connect(att_ui->lineConverted, SIGNAL(textChanged(QString)), this, SLOT(m_handleCopies()));

    connect(att_ActionCopyToConvertLine, SIGNAL(triggered()), this, SLOT(m_copyToConvertLine()));
    connect(att_ActionCopyConvertedLine, SIGNAL(triggered()), this, SLOT(m_copyConvertedLine()));

    connect(att_ui->listBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(m_handleListbox(QString)));

    connect(att_ui->listWidToConvert, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(m_handleCalculations()));
    connect(att_ui->listWidConverted, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(m_handleCalculations()));
    //##############################################
    this->m_new_();
}
//##############################################handles
void MaiaUnitConv::m_handleCalculations()
{
    QString currentItemToConvert = att_ui->listWidToConvert->currentItem()->text();//get the current item's text in a QString
    QString currentItemConverted = att_ui->listWidConverted->currentItem()->text();//get the current item's text in a QString

    //*****************************************************************************
    if (currentItemToConvert == tr("Celsius") && currentItemConverted == tr("Kelvin"))
    {
        this->m_celsiusToKelvin();
    }

    else if (currentItemToConvert == tr("Celsius") && currentItemConverted == tr("Fahrenheit"))
    {
        this->m_celsiusToFahrenheit();
    }

    else if (currentItemToConvert == tr("Celsius") && currentItemConverted == tr("Rankine"))
    {
        this->m_celsiusToRankine();
    }
    //..............................................
    else if (currentItemToConvert == tr("Fahrenheit") && currentItemConverted == tr("Celsius"))
    {
        this->m_fahrenheitToCelsius();
    }

    else if (currentItemToConvert == tr("Fahrenheit") && currentItemConverted == tr("Kelvin"))
    {
        this->m_fahrenheitToKelvin();
    }

    else if (currentItemToConvert == tr("Fahrenheit") && currentItemConverted == tr("Rankine"))
    {
        this->m_fahrenheitToRankine();
    }
    //..............................................
    else if (currentItemToConvert == tr("Kelvin") && currentItemConverted == tr("Celsius"))
    {
        this->m_kelvinToCelsius();
    }

    else if (currentItemToConvert == tr("Kelvin") && currentItemConverted == tr("Fahrenheit"))
    {
        this->m_kelvinToFahrenheit();
    }

    else if (currentItemToConvert == tr("Kelvin") && currentItemConverted == tr("Rankine"))
    {
        this->m_kelvinToRankine();
    }
    //..............................................
    else if (currentItemToConvert == tr("Rankine") && currentItemConverted == tr("Celsius"))
    {
        this->m_rankineToCelsius();
    }

    else if (currentItemToConvert == tr("Rankine") && currentItemConverted == tr("Fahrenheit"))
    {
        this->m_rankineToFahrenheit();
    }

    else if (currentItemToConvert == tr("Rankine") && currentItemConverted == tr("Kelvin"))
    {
        this->m_rankineToKelvin();
    }
    //..............................................
    //*****************************************************************************
    //..............................................
    if (currentItemToConvert == tr("degree") && currentItemConverted == tr("grad"))
    {
        this->m_degreeToGrad();
    }

    else if (currentItemToConvert == tr("degree") && currentItemConverted == tr("minute"))
    {
        this->m_degreeToMinute();
    }
    else if (currentItemToConvert == tr("degree") && currentItemConverted == tr("radian"))
    {
        this->m_degreeToRadian();
    }
    else if (currentItemToConvert == tr("degree") && currentItemConverted == tr("revolution"))
    {
        this->m_degreeToRevolution();
    }
    else if (currentItemToConvert == tr("degree") && currentItemConverted == tr("second"))
    {
        this->m_degreeToSecond();
    }
    //..............................................
    else if (currentItemToConvert == tr("grad") && currentItemConverted == tr("degree"))
    {
        this->m_GradToDegree();
    }

    else if (currentItemToConvert == tr("grad") && currentItemConverted == tr("minute"))
    {
        this->m_GradToMinute();
    }

    else if (currentItemToConvert == tr("grad") && currentItemConverted == tr("radian"))
    {
        this->m_GradToRadian();
    }
    else if (currentItemToConvert == tr("grad") && currentItemConverted == tr("revolution"))
    {
        this->m_GradToRevolution();
    }
    else if (currentItemToConvert == tr("grad") && currentItemConverted == tr("second"))
    {
        this->m_GradToSecond();
    }
    //..............................................
    else if (currentItemToConvert == tr("minute") && currentItemConverted == tr("degree"))
    {
        this->m_minuteToDegree();
    }

    else if (currentItemToConvert == tr("minute") && currentItemConverted == tr("grad"))
    {
        this->m_minuteToGrad();
    }

    else if (currentItemToConvert == tr("minute") && currentItemConverted == "radian")
    {
        this->m_minuteToRadian();
    }
    else if (currentItemToConvert == tr("minute") && currentItemConverted == tr("revolution"))
    {
        this->m_minuteToRevolution();
    }
    else if (currentItemToConvert == tr("minute") && currentItemConverted == tr("second"))
    {
        this->m_minuteToSecond();
    }
    //..............................................
    else if (currentItemToConvert == tr("radian") && currentItemConverted == tr("degree"))
    {
        this->m_radianToDegree();
    }

    else if (currentItemToConvert == tr("radian") && currentItemConverted == tr("grad"))
    {
        this->m_radianToGrad();
    }

    else if (currentItemToConvert == tr("radian") && currentItemConverted == tr("minute"))
    {
        this->m_radianToMinute();
    }
    else if (currentItemToConvert == tr("radian") && currentItemConverted == tr("revolution"))
    {
        this->m_radianToRevolution();
    }
    else if (currentItemToConvert == tr("radian") && currentItemConverted == tr("second"))
    {
        this->m_radianToSecond();
    }
    //..............................................
    else if (currentItemToConvert == tr("revolution") && currentItemConverted == tr("degree"))
    {
        this->m_revolutionToDegree();
    }

    else if (currentItemToConvert == tr("revolution") && currentItemConverted == tr("grad"))
    {
        this->m_revolutionToGrad();
    }

    else if (currentItemToConvert == tr("revolution") && currentItemConverted == tr("minute"))
    {
        this->m_revolutionToMinute();
    }
    else if (currentItemToConvert == tr("revolution") && currentItemConverted == tr("radian"))
    {
        this->m_revolutionToRadian();
    }
    else if (currentItemToConvert == tr("revolution") && currentItemConverted == tr("second"))
    {
        this->m_revolutionToSecond();
    }
    //..............................................
    else if (currentItemToConvert == tr("second") && currentItemConverted == tr("degree"))
    {
        this->m_secondToDegree();
    }

    else if (currentItemToConvert == tr("second") && currentItemConverted == tr("grad"))
    {
        this->m_secondToGrad();
    }

    else if (currentItemToConvert == tr("second") && currentItemConverted == tr("minute"))
    {
        this->m_secondToMinute();
    }
    else if (currentItemToConvert == tr("second") && currentItemConverted == tr("radian"))
    {
        this->m_secondToRadian();
    }
    else if (currentItemToConvert == tr("second") && currentItemConverted == tr("revolution"))
    {
        this->m_secondToRevolution();
    }
    //..............................................
    //*****************************************************************************
}
//##############################################
void MaiaUnitConv::m_handleListbox(QString fromUIListBox)
{
    att_ui->listWidToConvert->clear();
    att_ui->listWidConverted->clear();

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
    this->m_handleCopies();

    fromUIListBox = att_ui->listBox->currentText();

    QStringList listTemperature;
    QStringList listAngle;

    listTemperature << tr("Celsius") << tr("Fahrenheit") << tr("Kelvin") << tr("Rankine");
    listAngle << tr("degree") << tr("grad") << tr("minute") << tr("radian") << tr("revolution") << tr("second");


    if (fromUIListBox == tr("Units"))
    {
        this->m_new_();
    }
    else if (fromUIListBox == tr("Angles"))
    {
        att_ui->listWidToConvert->addItems(listAngle);
        att_ui->listWidConverted->addItems(listAngle);

        att_ui->listWidToConvert->setCurrentRow(0);
        att_ui->listWidConverted->setCurrentRow(1);
    }
    else if (fromUIListBox == tr("Temperatures"))
    {
        att_ui->listWidToConvert->addItems(listTemperature);
        att_ui->listWidConverted->addItems(listTemperature);

        att_ui->listWidToConvert->setCurrentRow(0);
        att_ui->listWidConverted->setCurrentRow(1);
    }
}
//##############################################
void MaiaUnitConv::m_handleCopies()
{
    att_ActionCopyToConvertLine->setText(tr("&Copy") + " [ " + att_ui->lineToConv->text() + " ]");
    att_ActionCopyConvertedLine->setText(tr("C&opy") + " [ " + att_ui->lineConverted->text() + " ]");
}
//##############################################
void MaiaUnitConv::m_copyToConvertLine()
{
    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->copy();
}
//##############################################
void MaiaUnitConv::m_copyConvertedLine()
{
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();
}
//##############################################
void MaiaUnitConv::m_aboutAndHelp()
{
    att_AboutLab = new QLabel(this);//create a label object for about dialog
    att_AboutLab->setWordWrap(true);
    att_AboutLab->setMargin(10);
    att_AboutLab->setAlignment(Qt::AlignTop);
    att_AboutLab->setText("\tMAIA Unit Conv. 1.5 is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. \n\n\tMAIA Unit Conv. is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. \n\n\tYou should have received a copy of the GNU General Public License along with MAIA Unit Conv.; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA");

    att_HelpLab = new QLabel(this);//create a label object for help dialog
    att_HelpLab->setWordWrap(true);
    att_HelpLab->setMargin(10);
    att_HelpLab->setAlignment(Qt::AlignTop);
    att_HelpLab->setOpenExternalLinks(true);
    att_HelpLab->setText(tr("<html><head/><body> MAIA Unit Conv. 1.5 helps you to convert a value to another specific one. <br> You, first, need to chose in the units listbox, then put the value you want to convert in the first line edit. After that, you have to chose an unit in the left panel, and then click on another unit in the right one. <br><br> If you want to copy the value you got, Remember: <br> - The program automatically send the result value to the clipboard, so you just need to paste it wherever you want. <br> - Also, you can copy one by one, either the value you converted or the converted value with the copy menu. <br><br><br> Author: <b>ANDRIAMILAMINA Monge</b>.<br>E-mail: <a href='mailto:mongemilamina@gmail.com'> mongemilamina@gmail.com</a>. <br> Web: <a href='https://andriamilamina.wordpress.com'> MAIA</a>.</body></html>"));

    att_TabWidget = new QTabWidget();//no parent, so this is gonna have its own window
    att_TabWidget->setWindowFlags(Qt::WindowStaysOnTopHint);//make the tabwidget above other application windows
    att_TabWidget->setAttribute(Qt::WA_ShowModal, true);//make the TabWidget Modal
    att_TabWidget->insertTab(1, att_AboutLab, QIcon(":/qrc_icons/icons/MAIA_icon_About.png"), tr("&About"));//adding the appropriate label to the tabBar, with its title
    att_TabWidget->insertTab(1, att_HelpLab, QIcon(":/qrc_icons/icons/MAIA_icon_Help.png"), tr("&Help"));//adding the appropriate label to the tabBar, with its title

    att_TabWidget->setWindowTitle(tr("MAIA Unit Conv. 1.5, About and Help"));
    att_TabWidget->resize(510, 340);
    att_TabWidget->setMinimumSize(580, 350);
    att_TabWidget->show();
}
//##############################################
void MaiaUnitConv::m_new_()
{
    att_ui->lineToConv->setText(tr("Value you want to convert..."));

    att_ui->lab_unity_to_convert->clear();
    att_ui->lab_unity_converted->clear();

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
    att_ui->lineConverted->setText(tr("Converted value..."));

    this->m_handleCopies();//reset text of copies menu
}
//##############################################
//CALCULULATIONS start
//##############################################Length
void MaiaUnitConv::m_footToMeter()
{
    double val_foot = att_ui->lineToConv->text().toDouble();
    double val_metre = val_foot*0.304;

    //...........................................................
    if (val_foot <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("foot"));
    }
    else if (val_foot > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("feet"));
    }
    //...........................................................
    if (val_metre <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("meter"));
    }
    else if (val_metre > 1)
    {
        att_ui->lab_unity_converted->setText(tr("meters"));
    }
    //...........................................................

    QString resultat = QString::number(val_metre);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_meterToFoot()
{
    double val_metre = att_ui->lineToConv->text().toDouble();
    double val_foot = val_metre/0.304;
    //...........................................................
    if (val_metre <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("meter"));
    }
    else if (val_metre > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("meters"));
    }
    //...........................................................
    if (val_foot <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("foot"));
    }
    else if (val_foot > 1)
    {
        att_ui->lab_unity_converted->setText(tr("feet"));
    }
    //...........................................................

    QString resultat = QString::number(val_foot);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_nauticalToKilMeter()
{
    double val_nm = att_ui->lineToConv->text().toDouble();
    double val_km = val_nm*1.852;

    //...........................................................
    if (val_nm <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("nautical mile"));
    }
    else if (val_nm > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("nautical miles"));
    }
    //...........................................................
    if (val_km <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("kilometer"));
    }
    else if (val_km > 1)
    {
        att_ui->lab_unity_converted->setText(tr("kilometers"));
    }
    //...........................................................

    QString resultat = QString::number(val_km);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_kiloMeterToNautical()
{
    double val_km = att_ui->lineToConv->text().toDouble();
    double val_nm = val_km/1.852;

    //...........................................................
    if (val_km <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("kilometer"));
    }
    else if (val_km > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("kilometers"));
    }
    //...........................................................
    if (val_nm <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("nautical mile"));
    }
    else if (val_nm > 1)
    {
        att_ui->lab_unity_converted->setText(tr("nautical miles"));
    }
    //...........................................................

    QString resultat = QString::number(val_nm);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_inchToMilliMeter()
{
    double val_inch = att_ui->lineToConv->text().toDouble();
    double val_mm = val_inch*25.4;

    //...........................................................
    if (val_inch <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("inch"));
    }
    else if (val_inch > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("inches"));
    }
    //...........................................................
    if (val_mm <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("millimeter"));
    }
    else if (val_mm > 1)
    {
        att_ui->lab_unity_converted->setText(tr("millimeters"));
    }
    //...........................................................

    QString resultat = QString::number(val_mm);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_milliMeterToInch()
{
    double val_mm = att_ui->lineToConv->text().toDouble();
    double val_inch = val_mm/25.4;

    //...........................................................
    if (val_mm <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("millimeter"));
    }
    else if (val_mm > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("millimeters"));
    }
    //...........................................................
    if (val_inch <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("inch"));
    }
    else if (val_inch > 1)
    {
        att_ui->lab_unity_converted->setText(tr("inches"));
    }
    //...........................................................

    QString resultat = QString::number(val_inch);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################Length
void MaiaUnitConv::m_mileToKiloMeter()
{
    double val_mile = att_ui->lineToConv->text().toDouble();
    double val_km = val_mile*1.609;

    //...........................................................
    if (val_mile <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("mile"));
    }
    else if (val_mile > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("miles"));
    }
    //...........................................................
    if (val_km <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("kilometer"));
    }
    else if (val_km > 1)
    {
        att_ui->lab_unity_converted->setText(tr("kilometers"));
    }
    //...........................................................

    QString resultat = QString::number(val_km);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_kiloMeterToMile()
{
    double val_km = att_ui->lineToConv->text().toDouble();
    double val_mile = val_km/1.609;

    //...........................................................
    if (val_km <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("kilometer"));
    }
    else if (val_km > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("kilometers"));
    }
    //...........................................................
    if (val_mile <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("mile"));
    }
    else if (val_mile > 1)
    {
        att_ui->lab_unity_converted->setText(tr("miles"));
    }
    //...........................................................

    QString resultat = QString::number(val_mile);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_knotsToMeterPerSec()
{
    double val_kts = att_ui->lineToConv->text().toDouble();
    double val_mps = val_kts*0.514;

    //...........................................................
    if (val_kts <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("knot"));
    }
    else if (val_kts > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("knots"));
    }
    //...........................................................
    if (val_mps <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("meter per second"));
    }
    else if (val_mps > 1)
    {
        att_ui->lab_unity_converted->setText(tr("meters per second"));
    }
    //...........................................................

    QString resultat = QString::number(val_mps);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_meterPerSecToKnots()
{
    double val_mps = att_ui->lineToConv->text().toDouble();
    double val_kts = val_mps/0.514;

    //...........................................................
    if (val_mps <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("meter per second"));
    }
    else if (val_mps > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("meters per second"));
    }
    //...........................................................
    if (val_kts <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("knot"));
    }
    else if (val_kts > 1)
    {
        att_ui->lab_unity_converted->setText(tr("knots"));
    }
    //...........................................................

    QString resultat = QString::number(val_kts);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_yardToMeter()
{
    double val_yard = att_ui->lineToConv->text().toDouble();
    double val_m = val_yard*0.914;

    //...........................................................
    if (val_yard <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("yard"));
    }
    else if (val_yard > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("yards"));
    }
    //...........................................................
    if (val_m <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("meter"));
    }
    else if (val_m > 1)
    {
        att_ui->lab_unity_converted->setText(tr("meters"));
    }
    //...........................................................

    QString resultat = QString::number(val_m);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_meterToYard()
{
    double val_m = att_ui->lineToConv->text().toDouble();
    double val_yard = val_m/0.914;

    //...........................................................
    if (val_m <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("meter"));
    }
    else if (val_m > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("meters"));
    }
    //...........................................................
    if (val_yard <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("yard"));
    }
    else if (val_yard > 1)
    {
        att_ui->lab_unity_converted->setText(tr("yards"));
    }
    //...........................................................

    QString resultat = QString::number(val_yard);

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//**********************************************************
//##############################################Temperatures
void MaiaUnitConv::m_celsiusToKelvin()
{
    double temp_deg_c = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_k = temp_deg_c + 273.15; //calcul

    //...........................................................
    if (temp_deg_c <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° celsius"));
    }
    else if (temp_deg_c > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° celsius"));
    }
    //...........................................................
    if (temp_deg_k <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° kelvin"));
    }
    else if (temp_deg_k > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° kelvin"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_k); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_kelvinToCelsius()
{
    double temp_deg_k = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_c = temp_deg_k - 273.15; //calcul

    //...........................................................
    if (temp_deg_k <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° kelvin"));
    }
    else if (temp_deg_k > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° kelvin"));
    }
    //...........................................................
    if (temp_deg_c <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° celsius"));
    }
    else if (temp_deg_c > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° celsius"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_c); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_celsiusToFahrenheit()
{
    double temp_deg_c = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_f = (temp_deg_c * 1.8) + 32; //calcul

    //...........................................................
    if (temp_deg_c <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° celsius"));
    }
    else if (temp_deg_c > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° celsius"));
    }
    //...........................................................
    if (temp_deg_f <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° fahrenheit"));
    }
    else if (temp_deg_f > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° fahrenheit"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_f); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_fahrenheitToCelsius()
{
    double temp_deg_f = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_c = (temp_deg_f - 32) / 1.8; //calcul

    //...........................................................
    if (temp_deg_f <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° fahrenheit"));
    }
    else if (temp_deg_f > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° fahrenheit"));
    }
    //...........................................................
    if (temp_deg_c <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° celsius"));
    }
    else if (temp_deg_c > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° celsius"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_c); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_celsiusToRankine()
{
    double temp_deg_c = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_r = (temp_deg_c * 1.8) + 491.67; //calcul

    //...........................................................
    if (temp_deg_c <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° celsius"));
    }
    else if (temp_deg_c > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° celsius"));
    }
    //...........................................................
    if (temp_deg_r <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° rankine"));
    }
    else if (temp_deg_r > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° rankine"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_r); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_rankineToCelsius()
{
    double temp_deg_r = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_c = (temp_deg_r - 491.67) * 0.555556; //calcul

    //...........................................................
    if (temp_deg_r <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° rankine"));
    }
    else if (temp_deg_r > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° rankine"));
    }
    //...........................................................
    if (temp_deg_c <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° celsius"));
    }
    else if (temp_deg_c > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° celsius"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_c); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_fahrenheitToRankine()
{
    double temp_deg_f = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_r = (temp_deg_f + (491.67 - 32)); //calcul

    //...........................................................
    if (temp_deg_f <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° fahrenheit"));
    }
    else if (temp_deg_f > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° fahrenheit"));
    }
    //...........................................................
    if (temp_deg_r <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° rankine"));
    }
    else if (temp_deg_r > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° rankine"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_r); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_rankineToFahrenheit()
{
    double temp_deg_r = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_f = (temp_deg_r - (491.67 - 32)); //calcul

    //...........................................................
    if (temp_deg_r <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° rankine"));
    }
    else if (temp_deg_r > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° rankine"));
    }
    //...........................................................
    if (temp_deg_f <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° fahrenheit"));
    }
    else if (temp_deg_f > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° fahrenheit"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_f); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_fahrenheitToKelvin()
{
    double temp_deg_f = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_k = (temp_deg_f * 0.555556) + 255.37; //calcul

    //...........................................................
    if (temp_deg_f <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° fahrenheit"));
    }
    else if (temp_deg_f > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° fahrenheit"));
    }
    //...........................................................
    if (temp_deg_k <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° kelvin"));
    }
    else if (temp_deg_k > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° kelvin"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_k); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_kelvinToFahrenheit()
{
    double temp_deg_k = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_f = (temp_deg_k - 255.37) / 0.555556; //calcul

    //...........................................................
    if (temp_deg_k <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° kelvin"));
    }
    else if (temp_deg_k > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° kelvin"));
    }
    //...........................................................
    if (temp_deg_f <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° fahrenheit"));
    }
    else if (temp_deg_f > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° fahrenheit"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_f); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_kelvinToRankine()
{
    double temp_deg_k = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_r = (temp_deg_k / 0.555556); //calcul

    //...........................................................
    if (temp_deg_k <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° kelvin"));
    }
    else if (temp_deg_k > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° kelvin"));
    }
    //...........................................................
    if (temp_deg_r <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° rankine"));
    }
    else if (temp_deg_r > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° rankine"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_r); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_rankineToKelvin()
{
    double temp_deg_r = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double temp_deg_k = (temp_deg_r * 0.555556); //calcul

    //...........................................................
    if (temp_deg_r <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° rankine"));
    }
    else if (temp_deg_r > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("° rankine"));
    }
    //...........................................................
    if (temp_deg_k <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("° kelvin"));
    }
    else if (temp_deg_k > 1)
    {
        att_ui->lab_unity_converted->setText(tr("° kelvin"));
    }
    //...........................................................

    QString resultat = QString::number(temp_deg_k); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################Angles
void MaiaUnitConv::m_degreeToGrad()
{
    double angles_deg = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_grad = angles_deg * 1.111111;

    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degrees"));
    }
    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("grads"));
    }
    //...........................................................

    QString resultat = QString::number(angles_grad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_degreeToMinute()
{
    double angles_deg = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_min = angles_deg * 60;

    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degrees"));
    }
    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_converted->setText(tr("minutes"));
    }
    //...........................................................

    QString resultat = QString::number(angles_min); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_degreeToRadian()
{
    double angles_deg = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rad = angles_deg * 0.0174532;

    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degrees"));
    }
    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("radians"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_degreeToRevolution()
{
    double angles_deg = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rev = angles_deg * 0.00277777;

    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degrees"));
    }
    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolutions"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rev); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_degreeToSecond()
{
    double angles_deg = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_sec = angles_deg * 3600;

    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("degrees"));
    }
    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_converted->setText(tr("seconds"));
    }
    //...........................................................

    QString resultat = QString::number(angles_sec); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_GradToDegree()
{
    double angles_grad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_deg = angles_grad / 1.111111;

    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grads"));
    }
    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_converted->setText(tr("degrees"));
    }
    //...........................................................

    QString resultat = QString::number(angles_deg); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_GradToMinute()
{
    double angles_grad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_min = angles_grad * 54;

    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grads"));
    }
    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_converted->setText(tr("minutes"));
    }
    //...........................................................

    QString resultat = QString::number(angles_min); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_GradToRadian()
{
    double angles_grad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rad = angles_grad * 0.0157079;

    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grads"));
    }
    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("radians"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_GradToRevolution()
{
    double angles_grad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rev = angles_grad * 0.0025;

    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grads"));
    }
    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolutions"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rev); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_GradToSecond()
{
    double angles_grad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_sec = angles_grad * 3240;

    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("grads"));
    }
    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_converted->setText(tr("seconds"));
    }
    //...........................................................

    QString resultat = QString::number(angles_sec); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_minuteToDegree()
{
    double angles_min = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_deg = angles_min / 60;

    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minutes"));
    }
    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_converted->setText(tr("degrees"));
    }
    //...........................................................

    QString resultat = QString::number(angles_deg); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_minuteToGrad()
{
    double angles_min = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_grad = angles_min / 54;

    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minutes"));
    }
    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("grads"));
    }
    //...........................................................

    QString resultat = QString::number(angles_grad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();

}
//##############################################
void MaiaUnitConv::m_minuteToRadian()
{
    double angles_min = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rad = (angles_min * 0.29088820) / 1000;

    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minutes"));
    }
    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("radians"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_minuteToRevolution()
{
    double angles_min = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rev = (angles_min * 0.0462962) / 1000;

    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minutes"));
    }
    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolutions"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rev); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_minuteToSecond()
{
    double angles_min = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_sec = angles_min * 60;

    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("minutes"));
    }
    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_converted->setText(tr("seconds"));
    }
    //...........................................................

    QString resultat = QString::number(angles_sec); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_radianToDegree()
{
    double angles_rad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_deg = angles_rad / 0.0174532;

    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radians"));
    }
    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_converted->setText(tr("degrees"));
    }
    //...........................................................

    QString resultat = QString::number(angles_deg); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_radianToGrad()
{
    double angles_rad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_grad = angles_rad / 0.0157079;

    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radians"));
    }
    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("grads"));
    }
    //...........................................................

    QString resultat = QString::number(angles_grad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_radianToMinute()
{
    double angles_rad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_min = (angles_rad * 1000) / 0.29088820;

    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radians"));
    }
    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_converted->setText(tr("minutes"));
    }
    //...........................................................

    QString resultat = QString::number(angles_min); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_radianToRevolution()
{
    double angles_rad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rev = angles_rad * 0.159154;

    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radians"));
    }
    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolutions"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rev); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_radianToSecond()
{
    double angles_rad = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_sec = angles_rad * 206264.806246;

    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("radians"));
    }
    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_converted->setText(tr("seconds"));
    }
    //...........................................................

    QString resultat = QString::number(angles_sec); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_revolutionToDegree()
{
    double angles_rev = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_deg = angles_rev / 0.00277777;

    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolutions"));
    }
    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_converted->setText(tr("degrees"));
    }
    //...........................................................

    QString resultat = QString::number(angles_deg); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_revolutionToGrad()
{
    double angles_rev = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_grad = angles_rev / 0.0025;

    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolutions"));
    }
    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("grads"));
    }
    //...........................................................

    QString resultat = QString::number(angles_grad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_revolutionToMinute()
{
    double angles_rev = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_min = (angles_rev * 1000) / 0.0462962;

    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolutions"));
    }
    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_converted->setText(tr("minutes"));
    }
    //...........................................................

    QString resultat = QString::number(angles_min); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_revolutionToRadian()
{
    double angles_rev = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rad = angles_rev / 0.159154;

    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolutions"));
    }
    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("radians"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_revolutionToSecond()
{
    double angles_rev = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_sec = (angles_rev * 10000) / 0.00771604;

    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("revolutions"));
    }
    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_converted->setText(tr("seconds"));
    }
    //...........................................................

    QString resultat = QString::number(angles_sec); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_secondToDegree()
{
    double angles_sec = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_deg = angles_sec / 3600;

    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("seconds"));
    }
    //...........................................................
    if (angles_deg <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("degree"));
    }
    else if (angles_deg > 1)
    {
        att_ui->lab_unity_converted->setText(tr("degrees"));
    }
    //...........................................................

    QString resultat = QString::number(angles_deg); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_secondToGrad()
{
    double angles_sec = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_grad = angles_sec / 3240;

    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("seconds"));
    }
    //...........................................................
    if (angles_grad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("grad"));
    }
    else if (angles_grad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("grads"));
    }
    //...........................................................

    QString resultat = QString::number(angles_grad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_secondToMinute()
{
    double angles_sec = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_min = angles_sec / 60;

    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("seconds"));
    }
    //...........................................................
    if (angles_min <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("minute"));
    }
    else if (angles_min > 1)
    {
        att_ui->lab_unity_converted->setText(tr("minutes"));
    }
    //...........................................................

    QString resultat = QString::number(angles_min); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_secondToRadian()
{
    double angles_sec = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rad = angles_sec / 206264.806246;

    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("seconds"));
    }
    //...........................................................
    if (angles_rad <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("radian"));
    }
    else if (angles_rad > 1)
    {
        att_ui->lab_unity_converted->setText(tr("radians"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rad); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//##############################################
void MaiaUnitConv::m_secondToRevolution()
{
    double angles_sec = att_ui->lineToConv->text().toDouble(); //take the LineEdit content and convert it to double for calcul
    double angles_rev = (angles_sec * 0.00771604) / 10000;

    //...........................................................
    if (angles_sec <= 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("second"));
    }
    else if (angles_sec > 1)
    {
        att_ui->lab_unity_to_convert->setText(tr("seconds"));
    }
    //...........................................................
    if (angles_rev <= 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolution"));
    }
    else if (angles_rev > 1)
    {
        att_ui->lab_unity_converted->setText(tr("revolutions"));
    }
    //...........................................................

    QString resultat = QString::number(angles_rev); //convert the result  from double to a QString

    att_ui->lineConverted->setText(resultat);//display the result
    att_ui->lineConverted->selectAll();
    att_ui->lineConverted->copy();//automatically send the result to clipboard

    att_ui->lineToConv->selectAll();
    att_ui->lineToConv->setFocus();
}
//#############################################################
void MaiaUnitConv::closeEvent(QCloseEvent *ev)
{
    if(ev->type() == QEvent::Close)
    {
        QMessageBox::StandardButton reponse;
        reponse = QMessageBox::warning(this, tr("MAIA Unit Conv. 1.5"), tr("Quit the application?"), QMessageBox::No | QMessageBox::Yes);
        if (reponse == QMessageBox::No)
        {
            ev->ignore();
            if(this->isHidden())
                this->show();
        }
        else if (reponse == QMessageBox::Yes)
            this->close();
    }
}
//#############################################################
MaiaUnitConv::~MaiaUnitConv()
{
    delete att_ui;
}
