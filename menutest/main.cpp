#include "globals.h"
#include "addevent.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //FIXME check for backup.ics and 7c.ics being the same size with this
    //FIXME also use .exists() and size().toString()
    //QFileInfo fileInfo(strFileName); // strFileName is a QString conaining the path/name of the file
    //QString str = fileInfo.lastModified().toString();

    //FIXME load categories.txt into all_categories
    //FIXME import default ics file
    //FIXME create if they don't exist

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

    return a.exec();
}
