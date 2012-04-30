#ifndef RECURRENCE_H
#define RECURRENCE_H

#include <QDialog>

namespace Ui {
    class Recurrence;
}

class Recurrence : public QDialog
{
    Q_OBJECT

public:
    explicit Recurrence(QWidget *parent = 0);
    ~Recurrence();
    std::string get_rrule();

private slots:
    void on_recurExitBox_accepted();

private:
    Ui::Recurrence *ui;
    std::string rrule;
};

#endif // RECURRENCE_H
