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

std::vector<std::string> all_categories;
icalcomponent* calendar = NULL;
