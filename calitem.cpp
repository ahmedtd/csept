
#include <algorithm>
using std::min;
#include <stdexcept>
using std::invalid_argument;
#include <sstream>
using std::stringstream;

#include "config.hpp"

#include "calitem.hpp"


calitem::calitem(const string &name,
                 const set<time_period> &coverage,
                 const set<calitem*> &children,
                 const set<calitem*> &parents)
:
    mName(name),
    mCoverage(coverage),
    mChildren(children),
    mParents(parents)
{
    #ifdef CSEPT_PPI_TESTS
    // Precondition checks
    
    // Check if mCoverage is non-self-intersecting
    set<time_period>::const_iterator it_a = mCoverage.begin();
    for(; it_a != mCoverage.end(); it_a++)
    {
        set<time_period>::const_iterator it_b = mCoverage.begin();
        for(; it_b != mCoverage.end(); it_b++)
        {
            if(it_a != it_b && it_a->intersects(*it_b))
            {
                stringstream msg;
                msg << "calitem::constructor: argument coverage contains"
                    " intersecting time periods. ";
                msg << *it_a << " " << *it_b;

                throw invalid_argument(msg.str());
            }
        }
    }

    // Check for invalid pointers in mChildren
    set<calitem*>::const_iterator it_children = mChildren.begin();
    for(; it_children != mChildren.end(); it_children++)
    {
        if(dynamic_cast<calitem*>(*it_children) == NULL)
        {
            stringstream msg;
            msg << "calitem::constructor: argument children contains null"
                " pointer";
            
            throw invalid_argument(msg.str());
        }
    }

    // Check for invalid pointers in mParents
    set<calitem*>::const_iterator it_parents = mParents.begin();
    for(; it_parents != mParents.end(); it_parents++)
    {
        if(dynamic_cast<calitem*>(*it_parents) == NULL)
        {
            stringstream msg;
            msg << "calitem::constructor: argument parents contains null"
                " pointer";
            
            throw invalid_argument(msg.str());
        }
    }

    #endif
    // End precondition checks 

}

string calitem::name() const
{
    return mName;
}

void calitem::addchild(calitem &child, bool link_back)
{
    mChildren.insert(&child);
    
    if(link_back)
    {
        child.addparent(*this, false);
    }
}

void calitem::addparent(calitem &parent, bool link_back)
{
    mParents.insert(&parent);
    
    if(link_back)
    {
        parent.addchild(*this, false);
    }
}

set<time_period> calitem::coverage() const
{
    return mCoverage;
}

set<time_period> calitem::intersect(const calitem &other) const
{
    set<time_period> condensedperiods;

    // Intersect the time period sets.  Because we know the sets are
    // non-self-intersecting, we can intersect every element in the first set
    // with every element in the second set and push all the valid intersections
    // into the result set.
    set<time_period>::const_iterator period_it = other.mCoverage.begin();
    for(; period_it != other.mCoverage.end(); period_it++)
    {
        set<time_period>::const_iterator this_it = mCoverage.begin();
        for(; this_it != mCoverage.end(); this_it++)
        {
            if(this_it->intersects(*period_it))
                condensedperiods.insert(this_it->intersection(*period_it));
        }
    }

    return condensedperiods;
}

set<time_period> calitem::unify(const calitem &other) const
{
    set<time_period>::const_iterator it_a = mCoverage.begin();
    set<time_period>::const_iterator it_b = other.mCoverage.begin();

    set<time_period> union_set;

    while(it_a != mCoverage.end() && it_b != other.mCoverage.end())
    {
        if(it_a->intersects(*it_b))
        {
            union_set.insert(it_a->merge(*it_b));
            it_a++;
            it_b++;
        }
        else
        {
            union_set.insert(min(*it_a, *it_b));
            if(min(*it_a, *it_b) == *it_a)
                it_a++;
            else
                it_b++;
        }
    }

    return union_set;
}
