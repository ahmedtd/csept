#include "addalarm.h"
#include "ui_addalarm.h"

AddAlarm::AddAlarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAlarm)
{
    ui->setupUi(this);
    defaultAudio = true;
    fileName = "/sound.mp3";
}

AddAlarm::~AddAlarm()
{
    delete ui;
}

QDateTime AddAlarm::getDateTime()
{
    return alarmTime;
}

bool AddAlarm::isDefaultAudio()
{
    return defaultAudio;
}

string AddAlarm::getFileName()
{
    return fileName;
}

void AddAlarm::on_browseButton_clicked()
{

}

void AddAlarm::on_alarmBox_accepted()
{
    alarmTime = ui->dateTimeEdit->dateTime();
    if (ui->defaultButton->isChecked())
    {
        defaultAudio = true;
    }else
    {
        defaultAudio = false;
    }

    if (defaultAudio)
    {
        fileName = "/alarm.mp3";
    }else
    {
        fileName = ui->fileEdit->text().toStdString();
    }

    this->close();
}

void AddAlarm::on_alarmBox_rejected()
{
    this->close();
}
