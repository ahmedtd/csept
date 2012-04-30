#include "globals.h"
#include "addcategory.h"
#include "editevent.h"
#include "addalarm.h"
#include "recurrence.h"
#include <string>
#include "ui_editevent.h"

EditEvent::EditEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEvent)
{
    winCategory = new AddCategory(this);
    winAlarm = new AddAlarm(this);
    winRecurrence = new Recurrence(this);

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

EditEvent::~EditEvent()
{
    delete ui;
}

void EditEvent::on_CategoryBox_activated(int index)
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
            //TODO item is added to cats.txt, but the list doesn't update until the new cat dialog reappears
            ui->CategoryBox->insertItem(ui->CategoryBox->count() - 1, QString::fromStdString(all_categories[all_categories.size() - 1]));
            ui->CategoryBox->setCurrentIndex(ui->CategoryBox->count() - 2);
            this->update();
            this->repaint();
        }

        this->update();
        this->repaint();
    }
}

void EditEvent::on_addAlarmButton_clicked()
{
    winAlarm->show();
    has_alarm = true;
}

//FIXME turn all these adds into sets
void EditEvent::on_buttonBox_accepted()
{
    struct icaltimetype atime;
    atime = icaltime_from_timet( time(0), 0 );

    //Find the event to edit
    if (index < 0)
    {
        return; //don't bother with bad indices
    }

    icalcomponent* event = events[index];
    icalproperty* p;

    std::string summary = ui->SummaryEdit->text().toStdString();
    if (ui->SummaryEdit->isModified())
    {
        //FIXME find the property. if it exists, just set. if it doesn't, add
        //FIXME set the summary
    }

    std::string description = ui->DescriptionEdit->text().toStdString();

    std::string category;
    if (ui->CategoryBox->currentIndex() == (ui->CategoryBox->count() - 1) )
    {
        //Error, so don't add event
        QMessageBox errorMessBox;
        errorMessBox.setText("Bad Category");
        errorMessBox.exec();

        //Update the log
        append_action_to_closed_log("Edit Event \"" + summary + "\"", false);

        return;
    }else
    {
        category = ui->CategoryBox->currentText().toStdString();
    }

    struct icaltimetype dtstart = icaltime_from_timet(ui->StartTimeEdit->dateTime().toTime_t(), 0);
    struct icaltimetype dtend = icaltime_from_timet(ui->EndTimeEdit->dateTime().toTime_t(), 0);

    //Check for valid time frame
    if (ui->StartTimeEdit->dateTime().toTime_t() > ui->EndTimeEdit->dateTime().toTime_t())
    {
        //Error, so don't add event
        QMessageBox errorMessBox;
        errorMessBox.setText("Invalid date range");
        errorMessBox.exec();

        //Update the log
        append_action_to_closed_log("Add Event \"" + summary + "\"", false);

        return; //TODO this closes the window too. bools still close it
    }

    //pull rrule
    std::string rrule = winRecurrence->get_rrule();

    //TODO pull exdates from exdate ui
    //TODO exdates are currently unimplemented
    std::vector<struct icaltimetype> exdates;

    //Alarm pulled later

    std::string location = ui->LocationEdit->text().toStdString();

    std::string organizer = ui->OrganizerEdit->text().toStdString();

    //Pull all attendees as single string
    std::string attendees = ui->AttendEdit->text().toStdString();

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
            icalparameter_new_tzid("US-Central"), //TODO should get timezone from user
            0
            ),
        icalproperty_vanew_dtend(
            dtend,
            icalparameter_new_tzid("US-Central"), //TODO should get timezone from user
            0
            ),
        icalproperty_new_location(location.c_str()),
        icalproperty_vanew_organizer(
            organizer.c_str(),
            icalparameter_new_role(ICAL_ROLE_CHAIR),
            0
            ),

        //attendee
        icalproperty_vanew_attendee(
            attendees.c_str(),
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
         0
         );

    if (rrule != "")
    {
        icalcomponent_add_property(new_event,
        icalproperty_new_rrule(icalrecurrencetype_from_string(rrule.c_str())));
    }


    //Pull alarm to be added now
    if (has_alarm)
    {
        struct icaltimetype alarmTime = icaltime_from_timet(winAlarm->getDateTime().toTime_t(), 0);
        std::string file_name = winAlarm->getFileName();

        //add alarm to new_event
        icalcomponent* alarm = icalcomponent_new(ICAL_VALARM_COMPONENT);
        icalcomponent_add_property(
                alarm,
                icalproperty_new_attach(icalattach_new_from_url(file_name.c_str()))
                );

        icalcomponent_add_property(
                alarm,
                icalproperty_new_action(ICAL_ACTION_AUDIO)
                );

        icalcomponent_add_property(
                alarm,
                icalproperty_new_trigger(icaltriggertype_from_int(static_cast<int>(winAlarm->getDateTime().toTime_t())))
                );

        icalcomponent_add_component(new_event,alarm);

        if (rrule != "")
        {
            //Start alarm thread for each recurrence
            icalrecur_iterator* ritr;
            ritr = icalrecur_iterator_new(icalrecurrencetype_from_string(rrule.c_str()),dtstart);
            struct icaltimetype next;
            next = icalrecur_iterator_next(ritr);
            while (!icaltime_is_null_time(next))
            {
               next = icalrecur_iterator_next(ritr);
               QTimer* timer = new QTimer(this);
               timer->setSingleShot(true);

               //TODO Setting custom audio is currently unimplemented
               connect(timer, SIGNAL(timeout()), this, SLOT(play_audio()));

               //FIXME time is not correct yet
               int recur_time = static_cast<int> (icaltime_as_timet(next));
               int current_time = static_cast<int> (time(0));

               //Don't add alarms that expire in the past
               if (recur_time - current_time - (recur_time - static_cast<int>(icaltime_as_timet(alarmTime))) < 0)
               {
                   break;
               }
               timer->start(recur_time - current_time - (recur_time - static_cast<int>(icaltime_as_timet(alarmTime)))); //this is the time until trigger
               alarms.push_back(timer);
            }
        }
        else
        {
            QTimer* timer = new QTimer(this);
            timer->setSingleShot(true);

            //TODO Setting custom audio is currently unimplemented
            connect(timer, SIGNAL(timeout()), this, SLOT(play_audio()));

            time_t dtstart_t = icaltime_as_timet(dtstart);

            int recur_time = static_cast<int> (dtstart_t);
            int current_time = static_cast<int> (time(0));

            //Don't add alarms that expire in the past
            if (recur_time - current_time - (recur_time - static_cast<int>(icaltime_as_timet(alarmTime))) >= 0)
            {
                timer->start(recur_time - current_time - (recur_time - static_cast<int>(icaltime_as_timet(alarmTime)))); //this is the time until trigger
                alarms.push_back(timer);
            }
        }
    }

    //add exdates
    icalproperty* property;
    for (unsigned int i = 0; i < exdates.size(); i++)
    {
        property = icalproperty_new_exdate(exdates[i]);

        icalproperty_add_parameter(
            property,
            icalparameter_new_tzid("US-Central")
            );

        icalcomponent_add_property(new_event, property);
    }

    //Update the log
    append_action_to_closed_log("Edit Event \"" + summary + "\"", true);

    this->close();
}

void EditEvent::on_buttonBox_rejected()
{
    this->close();
}

void EditEvent::on_recurButton_clicked()
{
    winRecurrence->show();
}

void EditEvent::on_exceptButton_clicked()
{

}
