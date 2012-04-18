#include <QTextEdit>
#include <QWidget>
#include <Qt>
#include <QFileDialog>
#include "addevent.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace Qt;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    winEvent= new AddEvent(this);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_AddEventButton_clicked()
{
    winEvent->show();
}

void MainWindow::on_EditTaskButton_clicked()
{
    //FIXME
}

void MainWindow::on_EditEventButton_clicked()
{
    //FIXME basically take addevent and make it load the current values
    //FIXME won't fire unless an event is highlighted
}

void MainWindow::on_AddTaskButton_clicked()
{
    //FIXME
}

void MainWindow::on_actionAbout_triggered()
{
    //FIXME
    /*QTextEdit *help = new QTextEdit(this);
    help->setWindowFlag(Qt::Window);
    help->setReadOnly(true);
    help->append("<h1>About 7C</h1>Developed by:<br/> <ul><li>Taahir Ahmed</li> <li>Rachel Flores-Meath</li> <li>Andrew Funderburgh</li> <li>Maggie O\'Brien</li> <li>Patrick Smith</li> </ul>");
    help->show();*/
}

void MainWindow::on_actionImport_Calendar_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import File"), "", tr("iCal Files (*.ics)"));

    //FIXME Do file stuff
}

void MainWindow::on_actionExport_Calendar_triggered()
{
    //FIXME export full calendar thru dialog
}

void MainWindow::on_actionExport_Range_triggered()
{
    //FIXME portion of calendar thru dialog
}

void MainWindow::on_actionPreferences_triggered()
{
    //FIXME open preferences window
    //FIXME Window has timezone setting
}

void MainWindow::on_actionAlarms_triggered()
{
    //FIXME open alarms window
    //FIXME Window has list of alarms that are running and option to destroy them
    //FIXME if alarm destroyed, delete valarm from associated ical_component and kill the alarm thread
    //FIXME close button to exit

    //The option to edit the alarm is provided through the Edit menus
}

void MainWindow::on_actionCategories_triggered()
{
    //FIXME load new dialog containing list of strings representing current categories
    //FIXME allow for deletion/addition of categories
        //FIXME if deleting, check if any components belong to it
            //FIXME if so, prompt for okay
            //FIXME then delete the corresponding components, stop alarms associated with those, and delete category from the file
        //FIXME if adding, update all category boxes, the current list, and the file
}
