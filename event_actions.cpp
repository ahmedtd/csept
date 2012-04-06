#include <cstring>

//FIXME CHECK FOR ICAL ERRORS

void add_class(icalcomponent* calendar, vector<string>& classes)
{
  cout << "What is the name of the class?" << endl;
  string class_name;
  cin >> class_name;
  classes.push_back(class_name);
  
  
  //List each property field one at a time
  string all_props[] = {"ATTACH", "ATTENDEE", "CATEGORIES", "CLASS", "COMMENT", "CONTACT", "CREATED", "DESCRIPTION", "DTEND", "DTSTAMP", "DTSTART", "DURATION", "EXDATE", "EXRULE", "GEO", "LAST-MOD", "LOCATION", "ORGANIZER", "PRIORITY", "RDATE", "RECURID", "RELATED", "RESOURCES", "RRULE", "RSTATUS", "SEQ", "STATUS", "SUMMARY", "TRANSP", "UID", "URL"};
  
  //FIXME Start/end dates rely on default start/end of semester if user okays default
  
  vector<string> values;
  
  for (int i = 0; i < 31; i++)
  {
    cout << all_props[i] << ": ";
    std::flush(cout);
    
    string value = "";
    getline(cin, value);
    
    if (cin.fail())
    {
      throw cin_fail_ex;
    }

    //FIXME Take user input and validate 
    values.push_back(value);
    cout << endl;
  }
   
  struct icaltimetype atime = icaltime_from_timet(time(0), 0);
  
  //Add the values to the event
  icalcomponent* class_event = icalcomponent_vanew(
		ICAL_VEVENT_COMPONENT,
		icalproperty_new_dtstamp(atime),
    icalproperty_new_contact(values[5].c_str()),
    icalproperty_new_comment(values[4].c_str()),
    icalproperty_vanew_attach(
      NULL, //FIXME icalattach *icalattach_new_from_url (const char *url);
      values[0].c_str(),  //FIXME?
      0
      ),
    //FIXME icalproperty_new_duration(values[11].c_str()), //needs right type
    //FIXME icalproperty_new_exdate(values[13].c_str()),  //needs struct icaltimetype v
    //FIXME icalproperty_new_geo(values[14].c_str()), //needs right type- two floats with 6 decimal places (-90 to 90; -180 to 180)
    //FIXME icalproperty_new_lastmodified(values[15].c_str()),  //FIXME auto-make with timestamp
    icalproperty_new_priority(atoi(values[18].c_str())),
    //FIXME icalproperty_vanew_recurid(),
    //FIXME icalproperty_vanew_related(), //FIXME used to associate events with to-dos
    //FIXME icalproperty_vanew_resources(),
    //FIXME icalproperty_vanew_sequence(),  //FIXME starts at 0; increments with each edit
    //FIXME icalproperty_new_rrule(values[23].c_str()),
    //FIXME icalproperty_new_status(values[26].c_str()),
    //FIXME icalproperty_new_rstatus()  may not exist...
    /*FIXME icalproperty_vanew_rdate(
      values[15].c_str(),
      icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
      0
      ),*/
    /*FIXME icalproperty_vanew_exdate(  //FIXME exceptions to recurrences
      values[12].c_str(), //FIXME struct icaltimetype v
      icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
      0
      ),*/
    icalproperty_new_transp(ICAL_TRANSP_NONE), //FIXME values[28]... This is a six-way selector between ICAL_TRANSP_X, ICAL_TRANSP_OPAQUE, ICAL_TRANSP_OPAQUENOCONFLICT, ICAL_TRANSP_TRANSPARENT,  ICAL_TRANSP_TRANSPARENTNOCONFLICT, ICAL_TRANSP_NONE... Relates to free/busy conflicts
		icalproperty_new_uid(values[29].c_str()), //FIXME UNIQUE! used as part of the related-to field
    icalproperty_new_url(values[30].c_str()),
		icalproperty_vanew_organizer(
		    values[17].c_str(),
		    icalparameter_new_role(ICAL_ROLE_CHAIR),
		    0
		    ),
		icalproperty_vanew_attendee(
      values[1].c_str(),
      icalparameter_new_role(ICAL_ROLE_REQPARTICIPANT),  //FIXME overwrites user settings. Either ICAL_ROLE_REQPARTICIPANT, ICAL_ROLE_OPTPARTICIPANT, ICAL_ROLE_NONPARTICIPANT
      icalparameter_new_cutype(ICAL_CUTYPE_GROUP),  //FIXME overwrites user settings. Type of calendar user specified by property?
      0
      ),
		icalproperty_new_description(values[7].c_str()),

		icalproperty_new_categories(values[2].c_str()), //FIXME selects from list of categoires, with option to add new one
		icalproperty_new_class(ICAL_CLASS_PUBLIC),  //FIXME either "PUBLIC" / "PRIVATE" / "CONFIDENTIAL" available. anything else when read is viewed as private
		icalproperty_new_created(atime),  //FIXME overwrites user settings
		icalproperty_new_summary(values[27].c_str()),
		icalproperty_vanew_dtstart(
      atime,                  //FIXME overwrites user settings
      icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
      0
      ),
		icalproperty_vanew_dtend(
      atime,                //FIXME overwrites user settings
      icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
      0
      ),
		icalproperty_new_location(values[16].c_str()),
		0
		);  
  
  //FIXME Handle alarm threads (to be implemented later)
 
  //Add the class component to calendar
  icalcomponent_add_component(calendar, class_event);
  
  append_action_to_closed_log("Add Class", true);
}

void add_event(icalcomponent* calendar)
{
  string class_name;

  //Ask if the event is for a class
  bool is_class_event = yes_no_prompt("Is this event for a class? (y/n)");
  
  //FIXME Following not implemented in this sprint
  if (is_class_event)
  {
    //FIXME If event for class, make sure the semester is not over
    //FIXME If the semester is over, notify the user
    
    //If event for class, prompt for class id
    cout << "What is the name of this class?" << endl;
    cin >> class_name;
  }
    
    
  //List each property field one at a time
  cout << "Enter information for each of the following properties." << endl;
  string all_props[] = {"ATTACH", "ATTENDEE", "CATEGORIES", "CLASS", "COMMENT", "CONTACT", "CREATED", "DESCRIPTION", "DTEND", "DTSTAMP", "DTSTART", "DURATION", "EXDATE", "EXRULE", "GEO", "LAST-MOD", "LOCATION", "ORGANIZER", "PRIORITY", "RDATE", "RECURID", "RELATED", "RESOURCES", "RRULE", "RSTATUS", "SEQ", "STATUS", "SUMMARY", "TRANSP", "UID", "URL"};
  
  vector<string> values;
  
  for (int i = 0; i < 31; i++)
  {
    cout << all_props[i] << ": ";
    flush(cout);
    
    string value = "";
    getline(cin, value); //FIXME Check for failbit
    
    //FIXME Take user input and validate 
    values.push_back(value);
    cout << endl;
  }
  
  //If event for class, add property X-CLASS
  string value = "";
  if (is_class_event)
  {
    cout << "X-CLASS: ";
    flush(cout);
      
    getline(cin, value); //FIXME Check for failbit
    //FIXME Take user input and validate
    values.push_back(value);
      
    cout << endl;
  }
  
  struct icaltimetype atime = icaltime_from_timet(time(0), 0);
  
  //Add the values to the event
  icalcomponent* event = icalcomponent_vanew(
		ICAL_VEVENT_COMPONENT,
		icalproperty_new_dtstamp(atime),
    icalproperty_new_contact(values[5].c_str()),
    icalproperty_new_comment(values[4].c_str()),
    icalproperty_vanew_attach(
      NULL, //FIXME is this the file encoding?
      values[0].c_str(),
      0
      ),
    //FIXME icalproperty_new_duration(values[11].c_str()),
    //FIXME icalproperty_new_exdate(values[13].c_str()),
    //FIXME icalproperty_new_geo(values[14].c_str()),
    //FIXME icalproperty_new_lastmod(values[15].c_str()),
    icalproperty_new_priority(atoi(values[18].c_str())),
    //FIXME icalproperty_vanew_recurid(),
    //FIXME icalproperty_vanew_related(),
    //FIXME icalproperty_vanew_resources(),
    //FIXME icalproperty_vanew_sequence(),
    //FIXME icalproperty_new_rrule(values[23].c_str()),
    //FIXME icalproperty_new_status(values[26].c_str()),
    //FIXME icalproperty_new_rstatus()  may not exist...
    /*FIXME icalproperty_vanew_rdate(
      values[15].c_str(),
      icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
      0
      ),*/
    /*FIXME icalproperty_vanew_exdate(
      values[12].c_str(),
      icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
      0
      ),*/
    //FIXME icalproperty_new_transp(values[28].c_str()),
		icalproperty_new_uid(values[29].c_str()),
    icalproperty_new_url(values[30].c_str()),
		icalproperty_vanew_organizer(
		    values[17].c_str(),
		    icalparameter_new_role(ICAL_ROLE_CHAIR),  //FIXME overwrites user settings
		    0
		    ),
		icalproperty_vanew_attendee(
      values[1].c_str(),
      icalparameter_new_role(ICAL_ROLE_REQPARTICIPANT),  //FIXME overwrites user settings
      //FIXME icalparameter_new_rsvp(1),  //FIXME overwrites user settings
      icalparameter_new_cutype(ICAL_CUTYPE_GROUP),  //FIXME overwrites user settings
      0
      ),
		icalproperty_new_description(values[7].c_str()),

		icalproperty_new_categories(values[2].c_str()),
		icalproperty_new_class(ICAL_CLASS_PUBLIC),  //FIXME overwrites user settings
		icalproperty_new_created(atime),  //FIXME overwrites user settings
		icalproperty_new_summary(values[27].c_str()),
		icalproperty_vanew_dtstart(
      atime,                  //FIXME overwrites user settings
      icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
      0
      ),
		icalproperty_vanew_dtend(
      atime,                //FIXME overwrites user settings
      icalparameter_new_tzid("US-Central"), //FIXME should get timezone from user
      0
      ),
		icalproperty_new_location(values[16].c_str()),
		0
		);  
  
  if (is_class_event)
  {
    icalproperty* p;
    icalproperty_set_x(p, value.c_str());
    icalcomponent_add_property(event, p);
  }
  
  //Add component event to calendar
  icalcomponent_add_component(calendar,event);
  
  //FIXME Handle alarm threads (to be implemented later)
  
  append_action_to_closed_log("Add Event", true);
}

//Order swapped from 7cterm.cpp due to dependencies
icalcomponent* find_event(icalcomponent* calendar)
{
  int num_matches = 0;
  
  //Display possible fields and prompt for which ones(!) to use
  //FIXME Doesn't display possible properties for readability
  cout << "Enter all properties you want to use in all caps, delimited by semicolons" << endl;
  
  string properties;
  cin >> properties;
  
  char* c_properties = new char[properties.size()+1];
  strcpy(c_properties, properties.c_str());
  
  char* sel_props_c = strtok(c_properties, ";");
  vector<string> sel_props;
  vector<int> sel_props_pos;
  while (sel_props_c != NULL)
  {
    sel_props.push_back(sel_props_c);
    sel_props_pos.push_back(0);
    sel_props_c = strtok(c_properties, ";");
  }
  
  string all_props[] = {"ATTACH", "ATTENDEE", "CATEGORIES", "CLASS", "COMMENT", "CONTACT", "CREATED", "DESCRIPTION", "DTEND", "DTSTAMP", "DTSTART", "DURATION", "EXDATE", "EXRULE", "GEO", "LAST-MOD", "LOCATION", "ORGANIZER", "PRIORITY", "RDATE", "RECURID", "RELATED", "RESOURCES", "RRULE", "RSTATUS", "SEQ", "STATUS", "SUMMARY", "TRANSP", "UID", "URL"};
  
  for (int i = 0; i < sel_props.size() && i < 31; i++)
  {
    for (int j = 0; j < 31; j++)
    {
      if (sel_props[i] == all_props[j])
      {
        sel_props_pos[i] = j;
        break;
      }
    }
    
    if (sel_props[i] == "X-CLASS")
    {
      sel_props_pos[i] = 32; //beyond the end of all_props
    }
  }
  
  vector<string> values;
  cout << "Enter values for: " << endl;
  for (int i = 0; i < sel_props.size(); i++)
  {
    cout << sel_props[i] << ": ";
    flush(cout);
    string value;
    cin >> value; //FIXME error check for type
    values.push_back(value);
  }
  
  //Iterate through class events and non-class events to match properties
  icalcomponent *c;
  vector<icalcomponent*> matching_events;
  
  for (c = icalcomponent_get_first_component(calendar,ICAL_VEVENT_COMPONENT); c != 0; 	c = icalcomponent_get_next_component(calendar,ICAL_VEVENT_COMPONENT))
  {
    bool is_match = true;
    //Check each of the properties
    for (int i = 0; i < sel_props.size(); i++)
    {
      if (sel_props_pos[i] == 32)
      {
        icalproperty* p =  icalcomponent_get_first_property(c, ICAL_X_PROPERTY);
        char* class_name;
        strcpy(class_name, icalproperty_get_x(p));
        for (int j = 0; class_name != 0 && j < values[i].size(); j++)
        {
          if (class_name[j] != values[i][j])
          {
            is_match = false;
            break;
          }
        }
      }else
      {
        //FIXME Iterate through all properties
        icalproperty* p = icalcomponent_get_first_property(c,ICAL_ANY_PROPERTY);
        char* prop_value;
        strcpy(prop_value, icalproperty_get_comment(p));
        
        for (int j = 0; prop_value != 0 && j < values[i].size(); j++)
        {
          if (prop_value[j] != values[i][j])
          {
            is_match = false;
            break;
          }
        }
      }
    }
    
    if (is_match)
    {
      matching_events.push_back(c);
      num_matches++;
    }
  }
  
  if (num_matches == 0)
  {
    cout << "No matches found" << endl;
    return NULL;
  }
  
  cout << "Which event do you want?" << endl;
  int user_choice;
  
  while (true)
  {
    cin >> user_choice;
  
    if ((user_choice >= 1) && (user_choice <= num_matches))
    {
      break;
    }
    
    cout << "Invalid selection (Not between 1 and "<< num_matches <<" inclusive)" << endl;
  }
  
  //Return the user_choice-th event from the results
  return matching_events[user_choice];

}

void delete_event(icalcomponent* calendar)
{
  icalcomponent* event = find_event(calendar);
   
  if (!yes_no_prompt("Are you sure you want to delete this event? (y/n"))
  {
    return;
  }
  
  //Find the event in the components
  icalcomponent* c = icalcomponent_get_first_component(calendar, ICAL_VEVENT_COMPONENT);
  
  bool found_event = false;
  
  while((c=icalcomponent_get_current_component(c)) != 0 )
  { 
    if(icalcomponent_isa(c) == ICAL_VEVENT_COMPONENT)
    {
      if (c == event)
      {
        icalcomponent_remove_component(calendar, c);
        found_event = true;
      }
    }else
    { 
      icalcomponent_get_next_component(calendar, ICAL_VEVENT_COMPONENT); 
    }
  }
  
  if (!found_event)
  {
    append_action_to_closed_log("Delete event", false);
    return;
  }
  
  append_action_to_closed_log("Delete event", true);
}

void edit_event(icalcomponent* calendar)
{
  icalcomponent* event = find_event(calendar);
  
  if (event == NULL)
  {
    append_action_to_closed_log("Edit event", false);
  }
  
  //Once event found by property, display all fields and prompt for which to edit
  cout << "Which fields would you like to edit?" << endl;
  
  string properties;
  cin >>properties;
  
  char* c_properties = new char[properties.size()+1];
  strcpy(c_properties, properties.c_str());
  
  char * sel_props_c = strtok(c_properties, ";");
  vector<string> sel_props;
  vector<int> sel_props_pos;
  while (sel_props_c != NULL)
  {
    sel_props.push_back(sel_props_c);
    sel_props_pos.push_back(0);
    sel_props_c = strtok(c_properties, ";");
  }
  
  string all_props[] = {"ATTACH", "ATTENDEE", "CATEGORIES", "CLASS", "COMMENT", "CONTACT", "CREATED", "DESCRIPTION", "DTEND", "DTSTAMP", "DTSTART", "DURATION", "EXDATE", "EXRULE", "GEO", "LAST-MOD", "LOCATION", "ORGANIZER", "PRIORITY", "RDATE", "RECURID", "RELATED", "RESOURCES", "RRULE", "RSTATUS", "SEQ", "STATUS", "SUMMARY", "TRANSP", "UID", "URL"};
  
  for (int i = 0; i < sel_props.size(); i++)
  {
    for (int j = 0; j < 31; j++)
    {
      if (sel_props[i] == all_props[j])
      {
        sel_props_pos[i] = j;
        break;
      }
    }
    
    if (sel_props[i] == "X-CLASS")
    {
      sel_props_pos[i] = 32; //beyond the end of all_props
    }
  }
  
  //Update fields
  vector<string> values;
  cout << "Enter values for: " << endl;
  for (int i = 0; i < sel_props.size(); i++)
  {
    cout << sel_props[i] << ": ";
    flush(cout);
    string value;
    cin >> value; //FIXME error check for type
    values.push_back(value);
  }
  
  //Check that we are in the right property
  icalcomponent *c;
  
  for (c = icalcomponent_get_first_component(event,ICAL_VEVENT_COMPONENT); c != 0; 	c = icalcomponent_get_next_component(event,ICAL_VEVENT_COMPONENT))
  {
    bool is_match = true;
    //Check each of the properties
    for (int i = 0; i < sel_props.size(); i++)
    {
      if (sel_props_pos[i] == 32)
      {
        icalproperty* p = icalcomponent_get_first_property(event, ICAL_X_PROPERTY);
        icalproperty_set_x(ical_x_class_prop, values[i].c_str());
      }else
      {
        icalproperty* p;
        
        for( 	p = icalcomponent_get_first_property(event,ICAL_ANY_PROPERTY); 	p != 0; 	p = icalcomponent_get_next_property(event,ICAL_ANY_PROPERTY))
        {
          //FIXME no support for multi-parameter properties yet
          //FIXME also no value checking, which matters
          //FIXME use void icalproperty_set_value(icalproperty* prop, icalvalue* value);
        }
      }
    }
  }
  
  append_action_to_closed_log("Edit event", true);
}

void view_event(icalcomponent* calendar)
{
  //Ask user if they want null fields in addition to filled ones
  bool show_null_fields_too = yes_no_prompt("Do you want to view empty fields? (y/n)");
    
  icalcomponent* event = find_event(calendar);
  
  if (event == NULL)
  {
    append_action_to_closed_log("View event", false);
  }
  
  //Once user selects desired one, displays all needed fields  
  icalproperty* p;
  for(p = icalcomponent_get_first_property(event,ICAL_ANY_PROPERTY); p != 0; p = icalcomponent_get_next_property(event,ICAL_ANY_PROPERTY))
  {
    if ((icalproperty_get_comment(p) != NULL) || (show_null_fields_too))
    {
      cout << icalproperty_get_x_name(p) << ": ";
      cout << icalproperty_get_comment(p) << endl;
    }
  }
  
  append_action_to_closed_log("View event", true);
}

void delete_class(icalcomponent* calendar)
{
  //FIXME Not implemented in this sprint
  //FIXME Are we planning to remove ALL events associated with the class?
}
