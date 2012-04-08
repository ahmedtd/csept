
#ifndef CALITEM
#define CALITEM

#include <set>
using std::set;
#include <string>
using std::string;

#include <boost/date_time/posix_time/posix_time.hpp>
using boost::posix_time::time_period;

#include "config.hpp"

/// Base class for calendar items
class calitem
{
public:
    
    /// Specification constructor.
    ///
    /// \param name
    /// The name of the calendar item
    ///
    /// \param coverage
    /// The time coverage of the calendar item.
    ///
    /// \pre
    /// The time_periods contained within the coverage argument should be
    /// non-intersecting.  This means that for all pairs A,B of time_periods in
    /// coverage, A.intersects(B) == false.
    ///
    /// \param children
    /// A set of pointers to calendar items that are children of this calendar
    /// item.  Has a default argument of an empty set.
    ///
    /// \pre
    /// The argument children should not contain any pointers that are not
    /// valid pointers to calitem objects.  For all A in children,
    /// dynamic_cast<calitem*>(A) != nullptr.
    ///
    /// \param parents
    /// A set of pointers to calendar items that are parents of this calendar
    /// item.  Has a default argument of an empty set.
    /// 
    /// \pre
    /// The argument parents should not contain any pointers that are not valid
    /// pointers to calitem objects.  For all A in parents,
    /// dynamic_cast<calitem*>(A) != nullptr.
    calitem(const string &name,
            const set<time_period> &coverage,
            const set<calitem*> &children = (set<calitem*>()),
            const set<calitem*> &parents = (set<calitem*>()));
	
    /// Get the name of this calendar item.
    virtual string name() const;
    
    /// Add a child to this calendar item.
    ///
    /// \param child
    /// The child to add.
    ///
    /// \param link_back
    /// Should the child be modified to link back to the parent?
    virtual void addchild(calitem &child, bool link_back=true);

    /// Add a parent to this calendar item.
    ///
    /// \param parent
    /// The parent to add.
    ///
    /// \param link_back
    /// Should the parent be modified to link back to the child?
    virtual void addparent(calitem &parent, bool link_back=true);
    
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
    virtual set<time_period> unify(const calitem &other) const;

    /// Get the time period coverage of this item.
    ///
    /// \return
    /// A non-self-intersecting set of the time periods covered by this item.
    virtual set<time_period> coverage() const;
    
private:
    set<calitem*> mChildren;
    set<calitem*> mParents;
    
    string         mName;

    set<time_period> mCoverage;
};
    
#endif
