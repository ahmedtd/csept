#include "globals.h"
#include "addevent.h"
#include "mainwindow.h"

//TODO on program exit, stop all running threads

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //TODO existence of backup.ics means there was an error or that two sessions are running
    QFileInfo backupInfo("/backup.ics");
    bool backupExists = backupInfo.exists();

    if (backupExists)
    {
        QMessageBox errorMessBox;
        errorMessBox.setText("");
        errorMessBox.exec();
    }

    QFileInfo file7cInfo("/7c.ics");
    bool file7cExists = file7cInfo.exists();

    if (file7cExists)
    {
        //TODO import default ics file
        //TODO on calendar load, look for all alarms. start threads counting down to when they fire if they finish in the future
    }else
    {
        //TODO create if they don't exist
    }

    //If we don't have a saved calendar, make a new one
    if (calendar == NULL)
    {
      struct icaltimetype atime;
      struct icalperiodtype rtime;
      atime = icaltime_from_timet( time(0),0);

      rtime.start = icaltime_from_timet( time(0),0);
      rtime.end = icaltime_from_timet( time(0),0);
      rtime.end.hour++;

      calendar = icalcomponent_new(ICAL_VCALENDAR_COMPONENT);
    }

    MainWindow w;
    w.show();

    for (unsigned int i = 0; i < alarms.size(); i++)
    {
        alarms[i]->stop();
    }

    return a.exec();
}
