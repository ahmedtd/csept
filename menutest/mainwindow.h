#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addevent.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_AddEventButton_clicked();

    void on_EditTaskButton_clicked();

    void on_EditEventButton_clicked();

    void on_AddTaskButton_clicked();

    void on_actionAbout_triggered();

    void on_actionImport_Calendar_triggered();

    void on_actionExport_Calendar_triggered();

    void on_actionExport_Range_triggered();

    void on_actionPreferences_triggered();

    void on_actionAlarms_triggered();

    void on_actionCategories_triggered();

private:
    Ui::MainWindow *ui;
    AddEvent* winEvent;
};

#endif // MAINWINDOW_H
