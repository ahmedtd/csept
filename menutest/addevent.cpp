#include "globals.h"
#include "addevent.h"
#include <string>
#include "ui_addevent.h"

AddEvent::AddEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEvent)
{
    //Update the category combo box to be current
    for (unsigned int i = 0; i < all_categories.size(); i++)
    {
        ui->CategoryBox->addItem(QString::fromStdString(all_categories[i]));
    }

    ui->setupUi(this);
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
        ui->CategoryBox->addItem(QString::fromStdString(all_categories[all_categories.size() - 1]));
    }
}

void AddEvent::on_addAlarmButton_clicked()
{
    //FIXME open dialog with label "when will the alarm trigger" and time/date edit and url path to audio file
    //FIXME on ok clicked:
    //FIXME     prepare alarm for component
    //FIXME     set alarm_here = true
    //FIXME on cancel clicked:
    //FIXME     close dialog
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
        //FIXME error message "Bad Category"
        return;
    }else
    {
        category = all_categories[ui->CategoryBox->currentIndex()];
    }


    struct icaltimetype dtstart = icaltime_from_timet(ui->StartTimeEdit->dateTime().toTime_t(), 0);
    struct icaltimetype dtend = icaltime_from_timet(ui->EndTimeEdit->dateTime().toTime_t(), 0);

    if (!(ui->StartTimeEdit->dateTime().toTime_t() >= ui->EndTimeEdit->dateTime().toTime_t()))
    {
        //FIXME display error message "Invalid date range"
        return;
    }

    //FIXME pull rrule

    //FIXME pull exdates

    //FIXME pull alarm

    std::string location = ui->LocationEdit->text().toStdString();

    std::string organizer = ui->OrganizerEdit->text().toStdString();

    //FIXME pull attendees
    //FIXME split on ';' into std::vector<string> attendees
    //FIXME will have to add extra attendees after the fact to the event

    //FIXME pull status

    std::string url = ui->UrlEdit->text().toStdString();

    std::string attach = ui->AttachEdit->text().toStdString();

    //FIXME pull class

    //FIXME pull freebusy

    //Set uid
    stringstream ss;
    std::string uid;
    ss << time(0) << " " << summary;
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

         //FIXME attendee

        icalproperty_new_url(url.c_str()),
        icalproperty_vanew_attach(
            icalattach_new_from_url (attach.c_str()),
            0
            ),

        //FIXME status, freebusy

        //"Hidden" properties
        icalproperty_new_dtstamp(atime),    //Current time
        icalproperty_new_created(atime),    //Current time
        icalproperty_new_lastmodified(atime), //Auto-updates
        icalproperty_vanew_sequence(0),  //Increments with each edit
        icalproperty_new_status(ICAL_STATUS_CONFIRMED),
        icalproperty_new_uid(uid.c_str()), //Used as part of the related-to field

        //FIXME icalproperty_vanew_recurid(),
        //FIXME icalproperty_vanew_related(), //FIXME used to associate events with to-dos
        //FIXME icalproperty_new_rrule(values[23].c_str()),
        /*FIXME icalproperty_vanew_exdate(  //FIXME exceptions to recurrences
          values[12].c_str(), //FIXME struct icaltimetype v
          icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
          0
          ),*/
        //icalproperty_new_transp(ICAL_TRANSP_NONE), //FIXME values[28]... This is a six-way selector between ICAL_TRANSP_X, ICAL_TRANSP_OPAQUE, ICAL_TRANSP_OPAQUENOCONFLICT, ICAL_TRANSP_TRANSPARENT,  ICAL_TRANSP_TRANSPARENTNOCONFLICT, ICAL_TRANSP_NONE... Relates to free/busy conflicts
          /*icalproperty_vanew_attendee(
            values[1].c_str(),
            icalparameter_new_role(ICAL_ROLE_OPTPARTICIPANT),
            icalparameter_new_cutype(ICAL_CUTYPE_GROUP),
          0
          ),*/
                    //icalproperty_new_class(ICAL_CLASS_PUBLIC),  //FIXME either "PUBLIC" / "PRIVATE" / "CONFIDENTIAL" available. anything else when read is viewed as private
                    0
                    );

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
