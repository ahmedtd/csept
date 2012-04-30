
#ifndef CALTODO
#define CALTODO

#include "boost/date_time/posix_time/posix_time.hpp"
using boost::posix_time::ptime;

/// Represents to do item placed inside the calendar.  
class caltodo : public calitem
{
public:

	/// Get the due date for this to do item
    virtual ptime duedate() const;
	
	/// Set the due date for this to do item
    virtual void duedate(const ptime &duedate);
	
	/// Get the text for this to do item
	virtual string text() const;
	
	
};
    
#endif
