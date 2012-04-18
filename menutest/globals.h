#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtGui/QApplication>
#include <QFileInfo>
#include <QString>
#include <vector>
#include <string>
#include <fstream>
#include <libical/ical.h>
#include <ctime>
#include <iostream>

using namespace std;

#include "log.h"

extern std::vector<std::string> all_categories;
extern icalcomponent* calendar;

#endif // GLOBALS_H
