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

#ifndef MAIAUNITCONV_H
#define MAIAUNITCONV_H

#include <QMainWindow>
#include <QAction>
#include <QTabWidget>
#include <QLabel>
#include <QDoubleValidator>
#include <QMenu>

namespace Ui {
class MaiaUnitConv;
}

class MaiaUnitConv : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MaiaUnitConv(QWidget *parent = 0);
    ~MaiaUnitConv();

private slots:
    void m_aboutAndHelp();
    void m_new_();
    void closeEvent(QCloseEvent *ev);

    void m_handleCopies();
    void m_copyToConvertLine();
    void m_copyConvertedLine();

    void m_handleListbox(QString fromUIListBox);
    void m_handleCalculations();


    //##############################################Temperatures
    void m_celsiusToKelvin();
    void m_kelvinToCelsius();
    //...............................
    void m_celsiusToFahrenheit();
    void m_fahrenheitToCelsius();
    //...............................
    void m_celsiusToRankine();
    void m_rankineToCelsius();
    //...............................
    void m_fahrenheitToRankine();
    void m_rankineToFahrenheit();
    //...............................
    void m_fahrenheitToKelvin();
    void m_kelvinToFahrenheit();
    //...............................
    void m_kelvinToRankine();
    void m_rankineToKelvin();
    //##############################################Angles
    void m_degreeToGrad();
    void m_degreeToMinute();
    void m_degreeToRadian();
    void m_degreeToRevolution();
    void m_degreeToSecond();
    //...............................
    void m_GradToDegree();
    void m_GradToMinute();
    void m_GradToRadian();
    void m_GradToRevolution();
    void m_GradToSecond();
    //...............................
    void m_minuteToDegree();
    void m_minuteToGrad();
    void m_minuteToRadian();
    void m_minuteToRevolution();
    void m_minuteToSecond();
    //...............................
    void m_radianToDegree();
    void m_radianToGrad();
    void m_radianToMinute();
    void m_radianToRevolution();
    void m_radianToSecond();
    //...............................
    void m_revolutionToDegree();
    void m_revolutionToGrad();
    void m_revolutionToMinute();
    void m_revolutionToRadian();
    void m_revolutionToSecond();
    //...............................
    void m_secondToDegree();
    void m_secondToGrad();
    void m_secondToMinute();
    void m_secondToRadian();
    void m_secondToRevolution();
    //##############################################Lengths/Speeds
    void m_footToMeter();
    void m_meterToFoot();
    //...............................
    void m_nauticalToKilMeter();
    void m_kiloMeterToNautical();
    //...............................
    void m_inchToMilliMeter();
    void m_milliMeterToInch();
    //...............................
    void m_mileToKiloMeter();
    void m_kiloMeterToMile();
    //...............................
    void m_knotsToMeterPerSec();
    void m_meterPerSecToKnots();
    //...............................
    void m_yardToMeter();
    void m_meterToYard();
    //##############################################

private:

    QAction* att_ActionNew;
    QAction* att_ActionAboutAndHelp;
    QAction* att_ActionCopyToConvertLine;
    QAction* att_ActionCopyConvertedLine;
    QAction* att_ActionQuit;

    QMenu* att_MenuOperations;
    QMenu* att_MenuCopies;
    QMenu* att_MenuAboutAndHelp;

    QTabWidget* att_TabWidget;
    QLabel* att_AboutLab;
    QLabel* att_HelpLab;

    QDoubleValidator* att_Validator;
    
private:
    Ui::MaiaUnitConv *att_ui;
};

#endif // MAIAUNITCONV_H
