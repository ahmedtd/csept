#ifndef ADDALARM_H
#define ADDALARM_H

#include <QDialog>
#include <QDateTime>
#include <QButtonGroup>
#include <globals.h>

namespace Ui {
    class AddAlarm;
}

class AddAlarm : public QDialog
{
    Q_OBJECT

public:
    explicit AddAlarm(QWidget *parent = 0);
    ~AddAlarm();

    QDateTime getDateTime();

    bool isDefaultAudio();

    string getFileName();

private slots:
    void on_browseButton_clicked();

    void on_alarmBox_accepted();

    void on_alarmBox_rejected();

private:
    Ui::AddAlarm *ui;
    QDateTime alarmTime;
    bool defaultAudio;
    std::string fileName;
};

#endif // ADDALARM_H
