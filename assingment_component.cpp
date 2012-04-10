#include <stdlib.h>
#include<iostream>
#include <istream>
#include <string>
#include <vector>
#include <time.h> /* for time() */

#include "ical.h"

using namespace std;


vector <icalcomponent*> assignmentList;

//creates new assignment, which is a VTODO, then adds it to a calendar
// must have a title
//Still need to: make uid unique, add the seq property
void makeNewAssignment( icalcomponent* calendar, string title){
	icalcomponent* event;				
	icaltimetype currentTime = icaltime_from_timet( time(0), 0);
	event = icalcomponent_new(ICAL_VTODO_COMPONENT);

	//adding dtstamp - must have for VTODO
    icalcomponent_add_property(event, icalproperty_new_dtstamp(currentTime));

	//adding uid - must have for VTODO
    icalcomponent_add_property(event, icalproperty_new_uid("guid-1.host1.com")); 

	// class is defined as public
	// completed property, will define if needed later, tells time of completion
	
	//adding created, time todo first created
	icalcomponent_add_property(event, icalproperty_new_created(currentTime));

    // adding a discription, is empty to start with
	icalcomponent_add_property(event, icalproperty_new_description(" "));

	//dtstart, way using todo will not need
	//geo, tells location, will not need

	// adding last-mod
	icalcomponent_add_property(event, icalproperty_new_lastmodified(currentTime));

	//adding location of assignment, default no location
	icalcomponent_add_property(event, icalproperty_new_location(" "));

	//organizer, do not need for todo

	//adding percent completed, starts at 0, int from 0 to 100
	icalcomponent_add_property(event, icalproperty_new_percentcomplete(0));

	//adding priority, 0 for undefined priority
	icalcomponent_add_property(event, icalproperty_new_priority(0));

	//recurid, do not need for todo
	//seq, no not need for todo           

	//status of assignment, set to incomplete
	icalcomponent_add_property(event,icalproperty_new_status(ICAL_STATUS_NEEDSACTION));

	//adding a summary, which will be the title of assinment
	char *charTitle = (char*)title.c_str();
	icalcomponent_add_property(event, icalproperty_new_summary(charTitle));

	//url, not to todo right now
	//rrule, do not need for todo
    
	//adding a due-date, 
    icalcomponent_add_property(event,icalproperty_new_due(icaltime_from_timet( time(0),0)));

	//attach, are not supporting
	//attendee, do not need for todo

	//adding category, needs to correspond to event categories
	icalcomponent_add_property(event, icalproperty_new_categories("Default"));

	//comment, do not need already have description
	//contact, do not need for todo
	//exdate, do not need for todo
	//rstatus, may need to add in later
	//related to, do not think using
	//resources, do not need for todo

	//rdate, do not need for todo
	//x-prop
	//inana-prop


	//putting pointer into cector list
	assignmentList.push_back(event);
}


//takes in assignment
// still need to fix status, and date due, and category needs more work
void updateAssignment(icalcomponent* eventUpdating){
	bool continueUpdating = true;
	int prop;
	icalproperty *p;

	while(continueUpdating ==true){

		cout<<"1. Description"<<endl;
		cout<<"2. Location"<<endl;
		cout<<"3. Percent completed"<<endl;
		cout<<"4. Priority"<<endl; //switch case
		cout<<"5. Status"<<endl;
		cout<<"6. Title (summary)"<<endl;
		cout<<"7. Due-date"<<endl;
		cout<<"8. Category"<<endl;	//switch case
		
		cout<<"What property would you like to update (enter a number): "<<endl;

		cin>>prop;

		switch (prop){

			case 1: //description
				{
					string description;
					cout<<"Enter description: "<<endl;
					cin>> description;
					char *charDescription = (char*)description.c_str();
					p= icalcomponent_get_first_property(eventUpdating,ICAL_DESCRIPTION_PROPERTY);
					icalproperty_set_description(p, charDescription);
					break;
				}
		case 2: //location
			{
					string location;
					cout<<"Enter location: "<<endl;
					cin>> location;
					char *charLocation = (char*)location.c_str();
					p= icalcomponent_get_first_property(eventUpdating,ICAL_LOCATION_PROPERTY);
					icalproperty_set_location(p,charLocation);
					break;
				}
		case 3: // percent completed 
			{
					int completed;
					cout<<"Enter new description: "<<endl;
					cin>> completed;
					p= icalcomponent_get_first_property(eventUpdating,ICAL_PERCENTCOMPLETE_PROPERTY);
					icalproperty_set_percentcomplete(p,completed);
					break;
				}
		case 4: // priority
			{
					int priority;
					cout<<"Enter new description: "<<endl;
					cin>> priority;
					p= icalcomponent_get_first_property(eventUpdating,ICAL_PRIORITY_PROPERTY);
					icalproperty_set_priority(p, priority);
					break;
				}

		case 5: //status, not working ///////////////////////////////////////////////////
				{
					string status;
					cout<<"Enter new status"<<endl;
					cin>> status;
					//p= icalcomponent_get_first_property(eventUpdating,ICAL_STATUS_PROPERTY);
					//icalproperty_set_status(p,
					break;
				}
		case 6: // title (summary)
			{
					string title;
					cout<<"Enter title: "<<endl;
					cin>> title;
					char *chartitle = (char*)title.c_str();
					p= icalcomponent_get_first_property(eventUpdating,ICAL_SUMMARY_PROPERTY);
					icalproperty_set_summary(p, chartitle);
					break;
				}

		case 7: // due-date, not working /////////////////////////////////////
		{
				icaltimetype duedateTime=;
				//cout<<"Enter due-date: "<<endl;
				//cin>> duedateTime;


				//icaltimetype currentTime = icaltime_from_timet( time(0), 0);
				//char *chartitle = (char*)title.c_str();
				p= icalcomponent_get_first_property(eventUpdating,ICAL_DUE_PROPERTY);
				icalproperty_set_due(p,duedateTime);
				break;
			}
		case 8: //category
			{
				string category;
				cout<<"Enter category: "<<endl;
				cin>> category;
				char *charCategory = (char*)category.c_str();
				p= icalcomponent_get_first_property(eventUpdating,ICAL_CATEGORIES_PROPERTY);
				icalproperty_set_categories(p, charCategory);
				break;
			}
	
		}

	char answer;
	cout<<"Do you want to continue to modify assignment? (Y/N)"<<endl;
	cin>>answer;
	if(answer != 'Y')
		continueUpdating = false;


	}
	
	// adding last-mod
	p= icalcomponent_get_first_property(eventUpdating,ICAL_LASTMODIFIED_PROPERTY);
	icalcomponent_add_property(eventUpdating, icalproperty_new_lastmodified(icaltime_from_timet( time(0), 0)));

}

int main ()
{

//making a calendar for assignment to be added to//
/* following code from freeassociatin libical example */

  /* variable definitions */
    icalcomponent* calendar;
    struct icaltimetype atime = icaltime_from_timet( time(0),0);
    struct icalperiodtype rtime;
    icalproperty* property;
	
	/* Define a time type that will use as data later. */
    rtime.start = icaltime_from_timet( time(0),0);
    rtime.end = icaltime_from_timet( time(0),0);
	rtime.end.hour++;

	 /* Create calendar and add properties */

    calendar = icalcomponent_new(ICAL_VCALENDAR_COMPONENT);
    
    /* Nearly every libical function call has the same general
       form. The first part of the name defines the 'class' for the
       function, and the first argument will be a pointer to a struct
       of that class. So, icalcomponent_ functions will all take
       icalcomponent* as their first argument. */

    /* The next call creates a new proeprty and immediately adds it to the 
       'calendar' component. */ 

    icalcomponent_add_property(
	calendar,
	icalproperty_new_version("2.0")
	);

  
    icalcomponent_add_property(
	calendar,
	icalproperty_new_prodid("-//RDU Software//NONSGML HandCal//EN")
	);
    
    /////////////////////////////////////////////////////////////////////

    //make a new assignment
	string assignmnetTitle = "Test";
	//makeNewAssignment(assinmentToUpdate, assignmnetTitle);





  return 0;
}