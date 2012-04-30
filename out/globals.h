#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtGui/QApplication>
#include <QMessageBox>
#include <QFileInfo>
#include <time.h>
#include <QString>
#include <vector>
#include <string>
#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include <phonon/backendcapabilities.h>
#include <fstream>
#include <libical/ical.h>
#include <ctime>
#include <sstream>
#include <iostream>
#include <QTimer>
#include <QFileDialog>

using namespace std;

#include "log.h"

extern std::vector<QTimer *> alarms;
extern icalcomponent* calendar;
extern vector<icalcomponent*> events;

#endif // GLOBALS_H
