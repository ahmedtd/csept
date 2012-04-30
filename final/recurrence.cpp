#include "recurrence.h"
#include "ui_recurrence.h"
#include "globals.h"

Recurrence::Recurrence(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recurrence)
{
    rrule = "";
    ui->setupUi(this);
}

Recurrence::~Recurrence()
{
    delete ui;
}

void Recurrence::on_recurExitBox_accepted()
{
    //parse all the fields to a string
    rrule = "FREQ=";
    switch (ui->freqSelect->currentIndex())
    {
        case 0: rrule += "YEARLY;"; break;
        case 1: rrule += "MONTHLY;"; break;
        case 2: rrule += "WEEKLY;"; break;
        case 3: rrule += "DAILY;"; break;
        case 4: rrule += "HOURLY;"; break;
        case 5: rrule += "MINUTELY;"; break;
    }

    rrule += "COUNT=" + ui->countEdit->text().toStdString() + ";";
    rrule += "INTERVAL=" + ui->intervalEdit->text().toStdString() + ";";

    rrule += "BYDAY=";

    QItemSelectionModel * selections = ui->daysSelect->selectionModel();
    QModelIndexList indices = selections->selectedIndexes();

    for(int i = 0 ; i < indices.size() ; i++)
    {
        int j = indices[i].row(); //this will give the list of selected indexes
        switch (j)
        {
            case 0: rrule += "MO"; break;
            case 1: rrule += "TU"; break;
            case 2: rrule += "WE"; break;
            case 3: rrule += "TH"; break;
            case 4: rrule += "FR"; break;
            case 5: rrule += "SA"; break;
            case 6: rrule += "SU"; break;
        }

        if (i != indices.size() - 1)
        {
            rrule += ",";
        }else
        {
            rrule += ";";
        }
    }

}

std::string Recurrence::get_rrule()
{
    return rrule;
}
