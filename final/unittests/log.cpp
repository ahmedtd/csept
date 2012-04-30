//Unit test for logs

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

#include "..globals.h"
#include "../log.h"

BOOST_AUTO_TEST_CASE(calitem_test_constructor)
{
  fstream log;
  std::string s = "Test data";
  std::string s2 = "More test data\n";
  bool result = false;
  
  BOOST_CHECK(open_log_file(log));  //pass
  BOOST_CHECK(append_action_to_log(log, s, result));  //pass
  BOOST_CHECK(append_raw_to_log(log, s2));  //pass
  BOOST_CHECK(close_log_file(log)); //pass
  
  BOOST_CHECK(append_raw_to_log(log, s2)); //fail
  BOOST_CHECK(append_action_to_log(log, s, result));  //fail
  BOOST_CHECK(close_log_file(log)); //pass
  BOOST_CHECK(open_log_file(log));  //pass
  BOOST_CHECK(open_log_file(log));  //fail
}
