#include <QtGui/QApplication>
#include <QFileInfo>
#include <QString>
#include <QMessageBox>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>
#include <libical/ical.h>
#include <ctime>
#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include <phonon/backendcapabilities.h>
#include <sstream>
#include <iostream>
#include <QTimer>
#include <QFileDialog>

using namespace std;

#include "log.h"

std::vector<QTimer *> alarms;
icalcomponent* calendar = 0;
vector<icalcomponent*> events;
