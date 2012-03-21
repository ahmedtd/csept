
#ifndef CALENGAGEMENT
#define CALENGAGEMENT

#include <set>
using std::set;

#include "boost/date_time/posix_time/posix_time.hpp"
using boost::posix_time::time_period;

#include "calitem.hpp"

class calengagement : public calitem
{
public:
	/// Get the set of time periods that this even occupies
    virtual set<time_period> extent() const;
	
	/// Get a map of attendees to capacities
    virtual map<string,string> attendees() const;
	
	/// Set the map of attendees to capacities
	virtual void attendees(const map<string,string> &attendees);
	
	/// Get the location of the engagement
	virtual string location() const;
	
	/// Set the location of the engagement
	virtual void location(const string &location);
	
private:
    set<string> mAttendees;
};
    
#endif
