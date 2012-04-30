
// Unit test implementation file for calitem.

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

#include "../calitem.hpp"

BOOST_AUTO_TEST_CASE(calitem_test_constructor)
{
    string name("item a");

    date day(2012, Jul, 2);
    ptime start_time(day, hours(5));
    ptime end_time(day, hours(10));
    time_period duration(start_time, end_time);
    set<time_period> coverage;
    coverage.insert(duration);

    calitem item(name, coverage);

    BOOST_CHECK(item.name() == name);

    BOOST_CHECK(item.coverage() == coverage);
}
