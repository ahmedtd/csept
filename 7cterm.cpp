#include <ctime>
#include <libical/ical.h>
#include <cstdlib>

#include "ical_x_defs.hpp"  //Contains libical macros, property types
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
  //FIXME Later versions will try to load from the default file here
  
  //If we don't have a saved calendar, make a new one
  if (calendar == NULL)
  {
    struct icaltimetype atime = icaltime_from_timet( time(0),0);
    struct icalperiodtype rtime;
    
    rtime.start = icaltime_from_timet( time(0),0);
    rtime.end = icaltime_from_timet( time(0),0);
    rtime.end.hour++;
  }
  
  //FIXME Find all non-school days by prompt?
  //FIXME Ask for start/end of semester
  
  //FIXME does ical have a unique id for each component?
  
  //Actually manupulating the calendar
  while (true)
  {
    //Prompt for user action
    cout << "What would you like to do?\n" <<
      "1. Add a class\n" <<
      "2. Add an event\n" <<
      "3. Delete an event\n" <<
      "4. Edit an event\n" <<
      "5. Find an event\n" <<
      "6. View an event\n" << 
      "7. Exit the program\n" << endl;
    cout << "Enter the integer corresponding to your choice" << endl;
    
    string user_choice = "";
    cin >> user_choice;
    
    bool user_choice_flag = true;
    
    //Check the string is all digits
    for (int i = 0; i < user_choice.size(); i++)
    {
      if (!isdigit(user_choice[i]))
      {
        cout << "Invalid selection (Not all digits)" << endl;
        user_choice_flag = false;
        break;
      }
    }
    
    if (!user_choice_flag)
    {
      continue;
    }
    
    //Given the choice, perform the desired action
    switch (atoi(user_choice.c_str()))
    {
    
      case 1:
      {
        //FIXME
        break;
      }
      
      case 2:
      {
        //FIXME
        break;
      }
      
      case 3:
      {
        //FIXME
        break;
      }
      
      case 4:
      {
        //FIXME
        break;
      }
      
      case 5:
      {
        //FIXME
        break;
      }
      
      case 6:
      {
        //FIXME
        break;
      }
      
      //EXIT
      case 7:
      {
        //Prompt for okay
        cout << "Your calendar data will not be saved. Continue? (y/n)" << endl;
        
        cin >> user_choice;
        
        if ((user_choice == "y") || (user_choice != "Y"))
        {
          return 0;
        }
        
        break;
      }
      
      default:
      {
        cout << "Invalid selection (Not between 1 and 7 inclusive)" << endl;
        break;
      }
    }
    
    //FIXME list of actions
      //1 Add class
        //List each property field one at a time
        //Take user input and validate (null means null)
        //Follow the really ugly component adding method for each property
          //Start/end dates rely on default start/end of semester if user okays default
        //Add component class to calendar
      //2 Add event
        //Ask if the event is for a class
          //If event for class, make sure the semester is not over
            //If it is, notify the user
          //If event for class, prompt for class id
        //List each property field one at a time
        //Take user input and validate (null means null)
        //Follow the really ugly component adding method for each property
        //If event for class, add component event to class
          //Else, add component event to calendar
        //FIXME Handle alarm threads
      //3 Delete event
        //If event is class, all subentries will be deleted. Prompt for confirmation
        //Iterate to each event that matches the criteria
        //Display short view of event, prompt for confirmation before deletion
      //4 Edit event
        //Relies on Find Event
        //Once event found by property, display all fields and prompt for which to edit
        //Update fied and return to main selector
      //5 Find event
        //Display possible fields and prompt for which ones(!) to use
        //Iterate through class events and non-class events to match properties
        //Return all matches
      //6 View event
        //Ask user if they want null fields in addition to filled ones
        //Relies on Find Event
        //Displays short view of all found events
        //Once user selects desired one, displays all needed fields (needed depends on the first user prompt after View Event selected)
  }
  
  return 0;
}
