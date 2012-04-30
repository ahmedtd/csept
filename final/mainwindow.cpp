#include <QTextEdit>
#include <QWidget>
#include <Qt>
#include <QFileDialog>
#include "addevent.h"
#include "editevent.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace Qt;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    winEvent = new AddEvent(this);
    winEditEvent = new EditEvent(this);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_AddEventButton_clicked()
{
    winEvent->show();
    ui->TabWidget->setCurrentIndex(0);
    ui->TabWidget->setCurrentIndex(1);
}

void MainWindow::on_EditTaskButton_clicked()
{
    //Check that there is a selected item
    if (ui->EventList->selectedItems().count() == 1)
    {
        winEditEvent->index = ui->EventList->currentRow();
        winEditEvent->show();
    }
}

void MainWindow::on_EditEventButton_clicked()
{
    //FIXME basically take addevent and make it load the current values

    //FIXME won't fire unless an event is highlighted
}

void MainWindow::on_AddTaskButton_clicked()
{
    //TODO
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox aboutMessBox;
    aboutMessBox.setText("<h1>About 7C</h1>Developed by:<br/> <ul><li>Taahir Ahmed</li> <li>Rachel Flores-Meath</li> <li>Andrew Funderburgh</li> <li>Maggie O\'Brien</li> <li>Patrick Smith</li> </ul>");
    aboutMessBox.exec();
}

void MainWindow::on_actionImport_Calendar_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import File"), "", tr("iCal Files (*.ics)"));

    //TODO Do file stuff
}

void MainWindow::on_actionExport_Calendar_triggered()
{
    //TODO export full calendar thru dialog
}

void MainWindow::on_actionExport_Range_triggered()
{
    //TODO portion of calendar thru dialog
}

void MainWindow::on_actionPreferences_triggered()
{
    //TODO open preferences window
    //TODO Window has timezone setting
}

void MainWindow::on_actionAlarms_triggered()
{
    //TODO open alarms window
    //TODO Window has list of alarms that are running and option to destroy them
    //TODO if alarm destroyed, delete valarm from associated ical_component and kill the alarm thread
    //TODO close button to exit

    //The option to edit the alarm is provided through the Edit menus
}

//TODO no need for this yet
void MainWindow::on_actionCategories_triggered()
{
    //TODO load new dialog containing list of strings representing current categories
    //TODO allow for deletion/addition of categories
        //TODO if deleting, check if any components belong to it
            //TODO if so, prompt for okay
            //TODO then delete the corresponding components, stop alarms associated with those, and delete category from the file
        //TODO if adding, update the file
}

void MainWindow::on_TabWidget_currentChanged(int index)
{
    switch (index)
    {
        //Update the Main tab
        case 0:
        {
            //Update EventList
            ui->EventList->clear();

           //Iterate through all events
           icalcomponent *event;
           icalproperty *p;

           for(event = icalcomponent_get_first_component(calendar,ICAL_VEVENT_COMPONENT);
                event != 0;
                event = icalcomponent_get_next_component(calendar,ICAL_VEVENT_COMPONENT))
           {
               //Load at most three recurrences of events into the list
               int recur_count = 0;

               p = icalcomponent_get_first_property(event, ICAL_DTSTART_PROPERTY);
               icaltimetype dtstart = icalproperty_get_dtstart(p);

               p = icalcomponent_get_first_property(event, ICAL_RRULE_PROPERTY);

               if (p != 0)
               {
                   icalrecurrencetype rrule = icalproperty_get_rrule(p);
                   icalrecur_iterator* ritr;
                   ritr = icalrecur_iterator_new(rrule,dtstart);
                   struct icaltimetype next;
                   next = icalrecur_iterator_next(ritr);
                   while (!icaltime_is_null_time(next) && (recur_count < 3))
                   {
                      next = icalrecur_iterator_next(ritr);
                      recur_count++;

                      //Make sure the event is not cancelled nor in the past
                      time_t event_time = icaltime_as_timet(next);
                      time_t current_time =time(0);

                      if (event_time < current_time)
                      {
                        break;
                      }

                      for(p = icalcomponent_get_first_property(event,ICAL_STATUS_PROPERTY);
                          p != 0;
                          p = icalcomponent_get_next_property(event,ICAL_STATUS_PROPERTY)
                          )
                      {
                          if (icalproperty_get_status(p) == ICAL_STATUS_CANCELLED)
                          {
                            break;
                          }
                      }

                    //Update ViewEventList
                    ui->ViewEventList->clear();

                    //Make string with event summary and the time
                    p = icalcomponent_get_first_property(event,ICAL_SUMMARY_PROPERTY);
                    string full_text = "";
                    if (p != 0)
                    {
                        full_text = icalproperty_get_summary(p);
                    }

                    full_text += "\n";
                    full_text += ctime(&event_time);

                    ui->ViewEventList->addItem(QString::fromStdString(full_text));

                    //TODO sort by start time by finding the last instance of "\n"

                    this->update();
                    this->repaint();
                }
               }else
               {
                   //Make sure the event is not cancelled nor in the past
                   time_t event_time = icaltime_as_timet(dtstart);
                   time_t current_time = time(0);

                   if (event_time < current_time)
                   {
                     break;
                   }

                   for(p = icalcomponent_get_first_property(event,ICAL_STATUS_PROPERTY);
                       p != 0;
                       p = icalcomponent_get_next_property(event,ICAL_STATUS_PROPERTY)
                       )
                   {
                       if (icalproperty_get_status(p) == ICAL_STATUS_CANCELLED)
                       {
                         break;
                       }
                   }
             }

             //Make string with event summary and the time
             p = icalcomponent_get_first_property(event,ICAL_SUMMARY_PROPERTY);
             string full_text = "";
             if (p != 0)
             {
                 full_text = icalproperty_get_summary(p);
             }

             time_t event_time = icaltime_as_timet(dtstart);
             full_text += "\n";
             full_text += ctime(&event_time);

             ui->ViewEventList->addItem(QString::fromStdString(full_text));

             this->update();
             this->repaint();
            }

           //TODO load each task with detail on the due date and percent complete
            //TODO sort by due date
           break;
        }
        //Update the Event tab
        case 1:
        {
            //Load brief description of each event that is not in past or CANCELLED
            //Iterate through all events
            icalcomponent *event;
            icalproperty *p;

            ui->EventList->clear();
            events.clear();

            for(event = icalcomponent_get_first_component(calendar,ICAL_VEVENT_COMPONENT);
                 event != 0;
                 event = icalcomponent_get_next_component(calendar,ICAL_VEVENT_COMPONENT))
            {
                p = icalcomponent_get_first_property(event, ICAL_DTSTART_PROPERTY);
                icaltimetype dtstart = icalproperty_get_dtstart(p);

                //Make sure the event is not cancelled nor in the past
                time_t event_time = icaltime_as_timet(dtstart);
                time_t current_time = time(0);

                //TODO Some issue with time conversions results in negative times
                if (event_time < current_time)
                {
                    for(p = icalcomponent_get_first_property(event,ICAL_STATUS_PROPERTY);
                        p != 0;
                        p = icalcomponent_get_next_property(event,ICAL_STATUS_PROPERTY)
                        )
                    {
                        if (icalproperty_get_status(p) == ICAL_STATUS_CANCELLED)
                        {
                          break;
                        }
                    }
                }

              //Update EventList
              //Use event summary, start time, end time
              //If category is "CLASS:*", prepend * to the summary
              //TODO on select, display description, recurrence rule, organizer, location
              string full_text = "";
              p = icalcomponent_get_first_property(event,ICAL_CATEGORIES_PROPERTY);
              if (p != 0)
              {
                  string cat = icalproperty_get_categories(p);
                  if (cat.substr(0,7) == "CLASS: ")
                  {
                    full_text = cat.substr(7);
                  }
              }

              p = icalcomponent_get_first_property(event,ICAL_SUMMARY_PROPERTY);
              if (p != 0)
              {
                  full_text += icalproperty_get_summary(p);
              }

              p = icalcomponent_get_first_property(event,ICAL_DTSTART_PROPERTY);
              if (p != 0)
              {
                  full_text += "\n";
                  time_t end = icaltime_as_timet(icalproperty_get_dtstart(p));
                  full_text += ctime(&end);
              }

              full_text += "\n";
              p = icalcomponent_get_first_property(event,ICAL_DTEND_PROPERTY);
              if (p != 0)
              {
                  time_t end = icaltime_as_timet(icalproperty_get_dtend(p));
                  full_text += ctime(&end);
              }

              events.push_back(event);
              ui->EventList->addItem(QString::fromStdString(full_text));
          }

          this->update();
          this->repaint();
          break;
        }
        //Update the To-do tab
        case 2:
        {
           //TODO load brief description of each task that is not completed or cancelled
           break;
        }
    }
}
