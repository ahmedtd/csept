//Unit test for adding an event

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE calitem

#include <boost/test/unit_test.hpp>
using namespace boost::unit_test;

#include <boost/date_time/gregorian/gregorian.hpp>
using boost::gregorian::date;
using boost::gregorian::Jul;

#include <boost/date_time/posix_time/posix_time.hpp>
using boost::posix_time::time_period;
using boost::posix_time::ptime;
using boost::posix_time::hours;

#include <libical/ical.h>
#include "..globals.h"
#include "../addevent.h"

BOOST_AUTO_TEST_CASE(calitem_test_constructor)
{
  //Make new addevent
  AddEvent *addEvent;
  //FIXME set the ui values
  AddEvent::ui->CategoryBox->addItem("Test");

  icalcomponent* calendar;

  addEvent->on_buttonBox_accepted();

  BOOST_CHECK(icalcomponent_count_properties(event, ICAL_RRULE_PROPERTY) == 0);
  BOOST_CHECK(icalcomponent_count_components(event, ICAL_ANY_COMPONENT) == 0);
  BOOST_CHECK(icalcomponent_count_components(calendar, ICAL_ANY_COMPONENT) == 1);

  BOOST_CHECK(item.coverage() == coverage);
}
