#ifndef ADDEVENT_H
#define ADDEVENT_H

#include <QDialog>
#include "addalarm.h"
#include "addcategory.h"
#include <QComboBox>

namespace Ui {
class AddEvent;
}

class AddEvent : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddEvent(QWidget *parent = 0);
    ~AddEvent();
    
private slots:

    void on_CategoryBox_activated(int index);

    void on_addAlarmButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddEvent *ui;
    AddCategory *winCategory;
    AddAlarm *winAlarm;
    int num_cats;
    bool has_alarm;
};

#endif // ADDEVENT_H
