#ifndef EDITEVENT_H
#define EDITEVENT_H

#include <QDialog>
#include "addalarm.h"
#include "addcategory.h"
#include "recurrence.h"
#include "ui_editevent.h"
#include <QComboBox>

namespace Ui {
    class EditEvent;
}

class EditEvent : public QDialog
{
    Q_OBJECT

public:
    explicit EditEvent(QWidget *parent = 0);
    ~EditEvent();
    int index;

private slots:

    void on_CategoryBox_activated(int index);

    void on_addAlarmButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_recurButton_clicked();

    void on_exceptButton_clicked();

private:
    Ui::EditEvent *ui;
    AddCategory *winCategory;
    AddAlarm *winAlarm;
    Recurrence *winRecurrence;
    int num_cats;
    bool has_alarm;
};

#endif // EDITEVENT_H
