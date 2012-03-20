#include <libical/ical.h>

#include "exception.hpp"
#include "log.cpp"


/*
//Now, create the same component as in the previous routine, but use
the constructor style.

icalcomponent* create_new_component_with_va_args()
{
    icalcomponent* calendar;
    struct icaltimetype atime = icaltime_from_timet( time(0),0);
    struct icalperiodtype rtime;
    
    rtime.start = icaltime_from_timet( time(0),0);
    rtime.end = icaltime_from_timet( time(0),0);
    rtime.end.hour++;

    //Some of these routines are the same as those in the previous
    //   routine, but we've also added several 'vanew' routines. These
    //   'vanew' routines take a list of properties, parameters or
    //   values and add each of them to the parent property or
    //   component.

    calendar = 
	icalcomponent_vanew(
	    ICAL_VCALENDAR_COMPONENT,
	    icalproperty_new_version("2.0"),
	    icalproperty_new_prodid("-//RDU Software//NONSGML HandCal//EN"),
	    icalcomponent_vanew(
		ICAL_VEVENT_COMPONENT,
		icalproperty_new_dtstamp(atime),
		icalproperty_new_uid("guid-1.host1.com"),
		icalproperty_vanew_organizer(
		    "mailto:mrbig@host.com",
		    icalparameter_new_role(ICAL_ROLE_CHAIR),
		    0
		    ),
		icalproperty_vanew_attendee(
		    "mailto:employee-A@host.com",
		    icalparameter_new_role(ICAL_ROLE_REQPARTICIPANT),
		    icalparameter_new_rsvp(1),
		    icalparameter_new_cutype(ICAL_CUTYPE_GROUP),
		    0
		    ),
		icalproperty_new_description("Project XYZ Review Meeting"),

		icalproperty_new_categories("MEETING"),
		icalproperty_new_class(ICAL_CLASS_PUBLIC),
		icalproperty_new_created(atime),
		icalproperty_new_summary("XYZ Project Review"),
		icalproperty_vanew_dtstart(
		    atime,
		    icalparameter_new_tzid("US-Eastern"),
		    0
		    ),
		icalproperty_vanew_dtend(
		    atime,
		    icalparameter_new_tzid("US-Eastern"),
		    0
		    ),
		icalproperty_new_location("1CP Conference Room 4350"),
		0
		),
	    0
	    );

   
    // Note that properties with no parameters can use the regular
    //   'new' constructor, while those with parameters use the 'vanew'
    //   constructor. And, be sure that the last argument in the 'vanew'
    //   call is a zero. Without, your program will probably crash.

    return calendar;
}


void find_sub_components(icalcomponent* comp)
{
    icalcomponent *c;
    
    // The second parameter to icalcomponent_get_first_component
       indicates the type of component to search for. This will
       iterate through all sub-components
    for(c = icalcomponent_get_first_component(comp,ICAL_ANY_COMPONENT);
	c != 0;
	c = icalcomponent_get_next_component(comp,ICAL_ANY_COMPONENT)){

	do_something(c);
    }

    // This will iterate only though VEVENT sub-components

    for(c = icalcomponent_get_first_component(comp,ICAL_VEVENT_COMPONENT);
	c != 0;
	c = icalcomponent_get_next_component(comp,ICAL_VEVENT_COMPONENT)){

	do_something(c);
    }

}

// Ical components only have one internal iterator, so removing the
//   object that the iterator points to can cause problems. Here is the
//   right way to remove components

void remove_vevent_sub_components(icalcomponent* comp){
    
    icalcomponent *c, *next;

    for( c = icalcomponent_get_first_component(comp,ICAL_VEVENT_COMPONENT);
	 c != 0;
	 c = next)
    {
	next  = icalcomponent_get_next_component(comp,ICAL_VEVENT_COMPONENT);

	icalcomponent_remove_component(comp,c);

	do_something(c);
    }

}


*/



int main()
{
  icalcomponent* calendar = NULL;
  //Later versions will try to load from the default file here
  
  //If we don't have a saved calendar, make a new one
  if (calendar == NULL)
  {
    struct icaltimetype atime = icaltime_from_timet( time(0),0);
    struct icalperiodtype rtime;
    
    rtime.start = icaltime_from_timet( time(0),0);
    rtime.end = icaltime_from_timet( time(0),0);
    rtime.end.hour++;
  }
  /*
  *  
  */ 

  return 0;
}
