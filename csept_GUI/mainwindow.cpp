#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);


    setupAlarmTab();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testSlot()
{

}

void MainWindow::setupAlarmTab()
{

    ui->AlarmListWidget->addItem("Wake Up Alarm");
    Alarm a = Alarm();
    a.name = "Wake Up Alarm";
    alarm_list.push_back(a);
    ui->AlarmListWidget->addItem("Class Alarm");
    Alarm b = Alarm();
    b.name = "Class Alarm";
    alarm_list.push_back(b);

    ui->alarmList_mon_checkbox->setVisible(false);
    ui->alarmList_tue_checkbox->setVisible(false);
    ui->alarmList_wed_checkbox->setVisible(false);
    ui->alarmList_thu_checkbox->setVisible(false);
    ui->alarmList_fri_checkbox->setVisible(false);
    ui->alarmList_sat_checkbox->setVisible(false);
    ui->alarmList_sun_checkbox->setVisible(false);
    ui->alarm_customday_label->setVisible(false);

}

void MainWindow::change2calendar_Slot()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::change2todolist_Slot()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::change2memopad_Slot()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::change2eventlist_Slot()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::change2alarmlist_Slot()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::changeddate_Slot()
{
   // ui->test_label->setText("It worked!");
}

void MainWindow::alarmList_changed_slot()
{
    QString tmp = ui->AlarmListWidget->currentItem()->text();
    ui->alarmName_textbox->setText(tmp);
    //load the alarm information
    std::vector<Alarm>::iterator it;
    for ( it=alarm_list.begin() ; it < alarm_list.end(); it++ )
        if (it->name == ui->AlarmListWidget->currentItem()->text())
            break;
    ui->alarmEnabled_checkbox->setChecked(it->enabled);
    //ui->alarmName_textbox->setText(it->name);
    if (it->repeating == true)
    {
        ui->alarm_yes_radiobutton->setChecked(true);
        ui->alarm_no_radiobutton->setChecked(false);
        alarmList_repeatingYes_slot();
    }
    else if (it->repeating == false)
    {
        ui->alarm_yes_radiobutton->setChecked(false);
        ui->alarm_no_radiobutton->setChecked(true);
        alarmList_repeatingNo_slot();
    }
    else
    {
        ui->alarm_yes_radiobutton->setChecked(false);
        ui->alarm_no_radiobutton->setChecked(false);
        alarmList_repeatingYes_slot();
    }
    ui->alarm_time_editor->setTime(it->time);
    ui->alarm_frequency_comboBox->setCurrentIndex(it->frequency);
    ui->alarm_datetime_editor->setTime(it->time);
    if (it->frequency == 4)
        alarmList_newFrequency_slot("Custom");
    //--------------checkboxes----------------------------------
    //std::string temp = it->custom_days.toLocal8Bit().constData();
    std::string temp = it->custom_days.toStdString();
    size_t found;
    found = temp.find('M');
    if (found != std::string::npos)
        ui->alarmList_mon_checkbox->setCheckState(Qt::Checked);
    else
        ui->alarmList_mon_checkbox->setCheckState(Qt::Unchecked);
    found = temp.find('T');
    if (found != std::string::npos)
        ui->alarmList_tue_checkbox->setCheckState(Qt::Checked);
    else
        ui->alarmList_tue_checkbox->setCheckState(Qt::Unchecked);
    found = temp.find('W');
    if (found != std::string::npos)
        ui->alarmList_wed_checkbox->setCheckState(Qt::Checked);
    else
        ui->alarmList_wed_checkbox->setCheckState(Qt::Unchecked);
    found = temp.find('R');
    if (found != std::string::npos)
        ui->alarmList_thu_checkbox->setCheckState(Qt::Checked);
    else
        ui->alarmList_thu_checkbox->setCheckState(Qt::Unchecked);
    found = temp.find('F');
    if (found != std::string::npos)
        ui->alarmList_fri_checkbox->setCheckState(Qt::Checked);
    else
        ui->alarmList_fri_checkbox->setCheckState(Qt::Unchecked);
    found = temp.find('S');
    if (found != std::string::npos)
        ui->alarmList_sat_checkbox->setCheckState(Qt::Checked);
    else
        ui->alarmList_sat_checkbox->setCheckState(Qt::Unchecked);
    found = temp.find('U');
    if (found != std::string::npos)
        ui->alarmList_sun_checkbox->setCheckState(Qt::Checked);
    else
        ui->alarmList_sun_checkbox->setCheckState(Qt::Unchecked);
    //------------------------------------------------------------
    ui->alarm_audiofilepath_textbox->setText(it->audio_file_path);
    ui->alarm_volume_slider->setValue(it->audio_volume);
}

void MainWindow::alarmList_repeatingYes_slot()
{
    ui->alarm_Repating_stackedwidget->setCurrentWidget(ui->repeatingYes);
}

void MainWindow::alarmList_repeatingNo_slot()
{
    ui->alarm_Repating_stackedwidget->setCurrentWidget(ui->repeatingNo);
}

void MainWindow::alarmList_newFrequency_slot(QString new_value)
{
    if (new_value == "Custom")
    {
        //show the check boxes for each day
        ui->alarmList_mon_checkbox->setVisible(true);
        ui->alarmList_tue_checkbox->setVisible(true);
        ui->alarmList_wed_checkbox->setVisible(true);
        ui->alarmList_thu_checkbox->setVisible(true);
        ui->alarmList_fri_checkbox->setVisible(true);
        ui->alarmList_sat_checkbox->setVisible(true);
        ui->alarmList_sun_checkbox->setVisible(true);
        ui->alarm_customday_label->setVisible(true);
    }
    else
    {
        //hide the check boxes for each day
        ui->alarmList_mon_checkbox->setVisible(false);
        ui->alarmList_tue_checkbox->setVisible(false);
        ui->alarmList_wed_checkbox->setVisible(false);
        ui->alarmList_thu_checkbox->setVisible(false);
        ui->alarmList_fri_checkbox->setVisible(false);
        ui->alarmList_sat_checkbox->setVisible(false);
        ui->alarmList_sun_checkbox->setVisible(false);
        ui->alarm_customday_label->setVisible(false);

    }
}

void MainWindow::alarmList_addalarm_slot()
{
    //TODO: enumerate the alarm names i.e. if I click add alarm 5 times
    //the names will be "New Alarm 1", "New Alarm 2",..., "New Alarm 5"

    //add alarm to GUI
    ui->AlarmListWidget->addItem("New Alarm");
    //add alarm to program
    Alarm a = Alarm();
    a.name = "New Alarm";
    alarm_list.push_back(a);
    //add alarm to storage

}

void MainWindow::alarmList_deletealarm_slot()
{
    //PROBLEM: will delete all alarms with the same name.  Possible solutions all have to
    //change the way the alarm is stored in the GUI.  Based on the scope of this program
    //the solution may not be worth the effort so I am leaving it as is for now

    //delete alarm from storage

    //delete alarm from program
    for ( std::vector<Alarm>::iterator it=alarm_list.begin() ; it < alarm_list.end(); it++ )
        if (it->name == ui->AlarmListWidget->currentItem()->text())
        {
            alarm_list.erase(it);
            break;
        }
    //delete alarm from GUI
    delete ui->AlarmListWidget->takeItem(ui->AlarmListWidget->row(ui->AlarmListWidget->currentItem()));
}

void MainWindow::alarmList_editalarm_slot()
{
    //TODO: add a mechanic to prevent people from making multiple alarms
    //with the same name

    //update alarm name in GUI
    if (ui->AlarmListWidget->currentItem() != NULL)
        ui->AlarmListWidget->currentItem()->setText(ui->alarmName_textbox->text());
    else
        ; // no item is selected
    //update alarm information in program
    Alarm a = Alarm();
    a.enabled = ui->alarmEnabled_checkbox->isChecked();
    a.name = ui->alarmName_textbox->text();
    if (ui->alarm_yes_radiobutton->isChecked() == true)
    {
        a.repeating = true;
        a.time = ui->alarm_time_editor->time();
        a.frequency = ui->alarm_frequency_comboBox->currentIndex();
        if (a.frequency == 6)
        {
            //user chose a custom day
            QString c_days = "";
            if (ui->alarmList_mon_checkbox->isChecked())
                c_days += "M";
            if (ui->alarmList_tue_checkbox->isChecked())
                c_days += "T";
            if (ui->alarmList_wed_checkbox->isChecked())
                c_days += "W";
            if (ui->alarmList_thu_checkbox->isChecked())
                c_days += "R";
            if (ui->alarmList_fri_checkbox->isChecked())
                c_days += "F";
            if (ui->alarmList_sat_checkbox->isChecked())
                c_days += "S";
            if (ui->alarmList_sun_checkbox->isChecked())
                c_days += "U";
            a.custom_days = c_days;
        }
        else
            a.custom_days = "";
    }
    else if(ui->alarm_no_radiobutton->isChecked() == true)
    {
        a.repeating = false;
        a.time_and_date = ui->alarm_datetime_editor->time();
    }
    else
        ;//remind user to enter data in all fields
    a.audio_file_path = ui->alarm_audiofilepath_textbox->text();
    a.audio_volume = ui->alarm_volume_slider->value();
    for ( std::vector<Alarm>::iterator it=alarm_list.begin() ; it < alarm_list.end(); it++ )
        if (it->name == ui->AlarmListWidget->currentItem()->text())
        {
            (*it) = a;
            break;
        }
    // update alarm information in storage

    //
    QMessageBox msgBox;
    msgBox.setText("Your Changes Have Been Saved.");
    msgBox.exec();
}
