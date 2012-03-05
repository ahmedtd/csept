
#ifndef CALENGAGEMENT
#define CALENGAGEMENT

#include <set>
using std::set;

#include "boost/date_time/posix_time/posix_time.hpp"
using boost::posix_time::time_period;

#include "calitem.hpp"

class calengagement
{
public:
    virtual set<time_period> extent() const;
    virtual 
};

    
#endif
