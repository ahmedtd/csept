#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "alarm.h"
#include "event.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setupAlarmTab();

public slots:
    void testSlot();
    void change2calendar_Slot();
    void change2todolist_Slot();
    void change2memopad_Slot();
    void change2eventlist_Slot();
    void change2alarmlist_Slot();

    void changeddate_Slot();

    void alarmList_changed_slot();
    void alarmList_repeatingYes_slot();
    void alarmList_repeatingNo_slot();
    void alarmList_newFrequency_slot(QString);
    void alarmList_addalarm_slot();
    void alarmList_deletealarm_slot();
    void alarmList_editalarm_slot();

private:
    Ui::MainWindow *ui;
    std::vector<Alarm> alarm_list;
    std::vector<Event> event_list;

};

#endif // MAINWINDOW_H
