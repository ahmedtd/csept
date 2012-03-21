#include <ctime>
#include <vector>
#include <libical/ical.h>
#include <cstdlib>

#include "ical_x_defs.hpp"  //Contains libical macros, property types
#include "text_utilities.cpp" //Contains general text utilities
#include "exception.hpp"
#include "log.cpp"
#include "event_actions.cpp"

int main()
{
  vector<string> classes; //the first line of the ics7 file contains the elements of this
  
  icalproperty_set_x_name(ical_x_class_prop, "X-CLASS");

  icalcomponent* calendar = NULL;
  struct icaltimetype atime;
  struct icalperiodtype rtime;

  //FIXME Later versions will try to load from the default file here
  
  //If we don't have a saved calendar, make a new one
  if (calendar == NULL)
  {
    atime = icaltime_from_timet( time(0),0);

    rtime.start = icaltime_from_timet( time(0),0);
    rtime.end = icaltime_from_timet( time(0),0);
    rtime.end.hour++;
    
    calendar = icalcomponent_new(ICAL_VCALENDAR_COMPONENT);
  }
  
  //FIXME Find all non-school days by prompt?
  
  //FIXME Ask for start/end of semester
  
  //Actually manipulating the calendar
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
      "7. Delete a class\n" <<
      "8. Exit the program\n" << endl;
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
      //ADD CLASS
      case 1:
      {
        add_class(calendar, classes);
        break;
      }
      
      //ADD EVENT (for a class or in general)
      case 2:
      {
        add_event(calendar);
        break;
      }
      
      //DELETE SINGLE EVENT
      //FIXME Not implemented in this sprint
      case 3:
      {
        cout << "This feature is not implemented in this sprint." << endl;
        break;
        
        
      
        delete_event(calendar);
        break;
      }
      
      //EDIT EVENT (class or general)
      case 4:
      {
        edit_event(calendar);
        break;
      }
      
      //FIND EVENT
      case 5:
      {
        icalcomponent* event = find_event(calendar);
        if (event == NULL)
        {
          append_action_to_closed_log("Find event", false);
        }else
        {
          append_action_to_closed_log("Find event", true);
        }
        break;
      }
      
      //VIEW EVENT
      case 6:
      {
        view_event(calendar);
        break;
      }
      
      //DELETE CLASS
      //FIXME Not implemented in this sprint
      case 7:
      {
        //FIXME Ask for class name
        //FIXME Scan through first level of components for class
        //FIXME Print all matches and get the one to delete
        //FIXME Warn that all events for that class will be deleted
        //FIXME Delete class after user okay
        
        cout << "This feature is not implemented in this sprint." << endl;
        break;
      }
      
      //EXIT
      case 8:
      {
        //Prompt for okay
        if (yes_no_prompt("Your calendar data will not be saved. Continue? (y/n)"))
        {
          return 0;
        }
        
        break;
      }
      
      default:
      {
        cout << "Invalid selection (Not between 1 and 8 inclusive)" << endl;
        break;
      }
    }
  }
  
  return 0;
}
