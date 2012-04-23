#include "alarm.h"

Alarm::Alarm()
{
    enabled = true;
    name = "";
    repeating = true;
    time = QTime();
        frequency = -1;
        custom_days = "";

        time_and_date= QTime();

        audio_file_path = "";
    audio_volume = -1;
}
