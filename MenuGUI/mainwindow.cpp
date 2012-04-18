#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    //ui->alarmListview

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testSlot()
{

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
