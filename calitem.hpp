
#ifndef CALITEM
#define CALITEM

#include <set>
using std::set;

#include <boost/date_time/posix_time/posix_time.hpp>
using boost::posix_time::time_period;

#include <boost/test/unit_test.hpp>

/// Base class for calendar items
class calitem
{
public:	
    virtual string name() const;
    virtual void addchild(const calitem *child, bool link_back=true);
    virtual void addparent(const calitem *parent, bool link_back=false);
    
    /// Get the time period overlap of this item with another item
    ///
    /// \return
    /// A non-self-intersecting set describing the intersection of the time
    /// periods covered by this and other.
    virtual set<time_period> intersect(const calitem &other) const;
    
    /// Get the time period union of this item with another item.
    ///
    /// \return
    /// A non-self-intersecting set describing the union of the time periods
    /// covered by this and other.
    virtual set<time_period> union(const calitem &other) const;

    /// Get the time period coverage of this item.
    ///
    /// \return
    /// A non-self-intersecting set of the time periods covered by this item.
    virtual set<time_period> extent() const;
    
private:
    list<calitem*> mChildren;
    list<calitem*> mParents;
    
    string         mName;

    set<time_period> mCoverage;
};
    
#endif
