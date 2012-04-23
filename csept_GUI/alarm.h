#ifndef ALARM_H
#define ALARM_H

#include <QString>
#include <QTime>

class Alarm{

public:
    bool enabled;
	QString name;
	bool repeating;
        QTime time;
		int frequency;
		QString custom_days;
	
        QTime time_and_date;
	
	QString audio_file_path;
	int audio_volume;

    Alarm();

private:
    ;

};




#endif // ALARM_H
