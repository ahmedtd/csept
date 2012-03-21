
#ifndef CALITEM
#define CALITEM

#include <set>
using std::set;

#include "boost/date_time/posix_time/posix_time.hpp"
using boost::posix_time::time_period;

/// Base class for calendar items
class calitem
{
public:
	
    virtual string name() const;
    virtual void addchild(const weak_ptr<calitem> &childptr);
    virtual set<time_period> overlap(calitem &other) const;
};
    
#endif
