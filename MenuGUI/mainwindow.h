#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



public slots:
    void testSlot();
    void change2calendar_Slot();
    void change2todolist_Slot();
    void change2memopad_Slot();
    void change2eventlist_Slot();
    void change2alarmlist_Slot();

    void changeddate_Slot();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
