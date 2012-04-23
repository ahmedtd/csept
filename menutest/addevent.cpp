#include "globals.h"
#include "addcategory.h"
#include "addevent.h"
#include "addalarm.h"
#include <string>
#include "ui_addevent.h"

AddEvent::AddEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEvent)
{
    winCategory = new AddCategory(this);
    winAlarm = new AddAlarm(this);

    ui->setupUi(this);

    //Update the category combo box to be current
    ui->CategoryBox->addItem("");

    //Read from categories.txt line by line
    std::vector<std::string> all_categories;

    std::ifstream cats;
    cats.open("categories.txt");
    std::string temp;

    while(getline(cats, temp))
    {
        all_categories.push_back(temp);
    }

    cats.close();

    for (unsigned int i = 0; i < all_categories.size(); i++)
    {
        ui->CategoryBox->addItem(QString::fromStdString(all_categories[i]));
    }

    num_cats = all_categories.size();

    ui->CategoryBox->addItem("Add New Category...");

    this->update();
    this->repaint();
}

AddEvent::~AddEvent()
{
    delete ui;
}

void AddEvent::on_CategoryBox_activated(int index)
{
    //When Add Category is selected, update the current box and the file
    if (index == (ui->CategoryBox->count() - 1) )
    {
        winCategory->show();

        //Read from categories.txt line by line
        std::ifstream cats2;
        std::string temp;
        cats2.open("categories.txt");
        std::vector<std::string> all_categories;

        while(getline(cats2, temp))
        {
            all_categories.push_back( temp );
        }

        cats2.close();

        if ((unsigned)num_cats < all_categories.size())
        {
            //FIXME item is added to cats.txt, but the list doesn't update until the new cat dialog reappears
            ui->CategoryBox->insertItem(ui->CategoryBox->count() - 1, QString::fromStdString(all_categories[all_categories.size() - 1]));
            ui->CategoryBox->setCurrentIndex(ui->CategoryBox->count() - 2);
            this->update();
            this->repaint();
        }

        this->update();
        this->repaint();
    }
}

void AddEvent::on_addAlarmButton_clicked()
{
    winAlarm->show();
    has_alarm = true;
}

void AddEvent::on_buttonBox_accepted()
{
    struct icaltimetype atime;
    atime = icaltime_from_timet( time(0), 0 );

    std::string summary = ui->SummaryEdit->text().toStdString();
    std::string description = ui->DescriptionEdit->text().toStdString();

    std::string category;
    if (ui->CategoryBox->currentIndex() == (ui->CategoryBox->count() - 1) )
    {
        //Error, so don't add event
        QMessageBox errorMessBox;
        errorMessBox.setText("Bad Category");
        errorMessBox.exec();
        return;
    }else
    {
        category = ui->CategoryBox->currentText().toStdString();
    }

    struct icaltimetype dtstart = icaltime_from_timet(ui->StartTimeEdit->dateTime().toTime_t(), 0);
    struct icaltimetype dtend = icaltime_from_timet(ui->EndTimeEdit->dateTime().toTime_t(), 0);

    if (!(ui->StartTimeEdit->dateTime().toTime_t() >= ui->EndTimeEdit->dateTime().toTime_t()))
    {
        //Error, so don't add event
        QMessageBox errorMessBox;
        errorMessBox.setText("Invalid date range");
        errorMessBox.exec();
        return; //FIXME this closes the window too. bools still close it
    }

    //FIXME pull rrule
    //FIXME FREQ = ??? = DAILY, WEEKLY, HOURLY, YEARLY, MINUTELY
    //FIXME BYDAY = ??? = SU, MO, TU, WE, TH, FR, SA
    //FIXME BYMONTH = ??? = ints???
    //FIXME BYHOUR = ints???
    //FIXME BYMINUTE = ints???
    //FIXME COUNT = int???
    //FIXME INTERVAL = int???
    //FIXME UNTIL = ???
    //FIXME WKST = one of SU, MO, TU, WE, TH, FR, SA
    //FIXME BYMONTHDAY = ints???
    //FIXME BYSETPOS  = int???
    //FIXME icalrecurrencetype

    //FIXME pull exdates

    //Alarm pulled later
    //FIXME alarm has a param actionvalue = "AUDIO"?


    std::string location = ui->LocationEdit->text().toStdString();

    std::string organizer = ui->OrganizerEdit->text().toStdString();

    //Pull all attendees to be dealt with later
    char all_attendees[] = "";
    std::string check = ui->AttendEdit->text().toStdString();
    if (check.size() > 0)
    {
        strcpy(all_attendees, check.c_str());
    }

    vector<string> attendees;
    const char* p;
    for (p = strtok(all_attendees, ";"); p; p = strtok(NULL, ";"))
    {
        attendees.push_back(p);
    }

    if (attendees.size() == 0)
    {
        attendees.push_back("");
    }

    std::string url = ui->UrlEdit->text().toStdString();

    std::string attach = ui->AttachEdit->text().toStdString();

    //Pull class
    icalproperty_class class_type;
    if (ui->PublicBox->isChecked())
    {
        //This is a public event
        class_type = ICAL_CLASS_PUBLIC;
    }else
    {
        class_type = ICAL_CLASS_PRIVATE;
    }

    //Pull freebusy
    icalproperty_transp freebusy;
    if (ui->BusyTimeBox->isChecked())
    {
        //This is busy time
        freebusy = ICAL_TRANSP_OPAQUE;
    }else
    {
        freebusy = ICAL_TRANSP_TRANSPARENT;
    }

    //Set uid
    std::stringstream ss;
    std::string uid;
    ss << time(0) << "." << summary;
    ss >> uid;

    //Add the values to the event
    icalcomponent* new_event = icalcomponent_vanew(
        ICAL_VEVENT_COMPONENT,

        //User-defined properties
        icalproperty_new_summary(summary.c_str()),
        icalproperty_new_description(description.c_str()),
        icalproperty_new_categories(category.c_str()),
        icalproperty_vanew_dtstart(
            dtstart,
            icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
            0
            ),
        icalproperty_vanew_dtend(
            dtend,
            icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
            0
            ),
    //FIXME rrule, exdate, alarm

        icalproperty_new_location(location.c_str()),
        icalproperty_vanew_organizer(
            organizer.c_str(),
            icalparameter_new_role(ICAL_ROLE_CHAIR),
            0
            ),

        //The first attendee
        icalproperty_vanew_attendee(
            attendees[0].c_str(),
            icalparameter_new_role(ICAL_ROLE_OPTPARTICIPANT),
            icalparameter_new_cutype(ICAL_CUTYPE_GROUP),
            0
            ),
        icalproperty_new_url(url.c_str()),
        icalproperty_vanew_attach(
            icalattach_new_from_url (attach.c_str()),
            0
            ),
        icalproperty_new_class(class_type),
        icalproperty_new_transp(freebusy),

        //"Hidden" properties
        icalproperty_new_dtstamp(atime),    //Current time
        icalproperty_new_created(atime),    //Current time
        icalproperty_new_lastmodified(atime), //Auto-updates
        icalproperty_new_sequence(0),  //Increments with each edit
        icalproperty_new_status(ICAL_STATUS_CONFIRMED),
        icalproperty_new_uid(uid.c_str()), //Used as part of the related-to field
        icalproperty_new_recurrenceid(dtstart), //matches original value of dtstart

        //FIXME icalproperty_new_rrule(values[23].c_str()),
        //FIXME icalproperty_vanew_exdate(  struct icaltimetype v, icalparameter_new_tzid("US-Central"),           0),
         0
         );

    //FIXME Add extra attendees after the fact to the event

    //Pull alarm to be added now
    if (has_alarm)
    {
        struct icaltimetype alarmTime = icaltime_from_timet(winAlarm->getDateTime().toTime_t(), 0);
        std::string fileName = winAlarm->getFileName();
//FIXME add alarm to new_event
        //FIXME start alarm thread
    }

    //Add the event to the calendar
    icalcomponent_add_component(calendar, new_event);

    //Update the log
    append_action_to_closed_log("Add Event \"" + summary + "\"", true);

    this->close();
}

void AddEvent::on_buttonBox_rejected()
{
    this->close();
}
