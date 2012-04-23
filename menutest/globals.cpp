#include <QtGui/QApplication>
#include <QFileInfo>
#include <QString>
#include <QMessageBox>
#include <vector>
#include <string>
#include <fstream>
#include <libical/ical.h>
#include <ctime>
#include <sstream>
#include <iostream>

using namespace std;

#include "log.h"

icalcomponent* calendar = NULL;
