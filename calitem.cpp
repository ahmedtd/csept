
#include "calitem.hpp"

string calitem::name() const
{
    return mName;
}

void calitem::addchild(const calitem *child, bool link_back)
{
    mChildren.push_back(child);
    child->addparent(this, false);
}

void calitem::addparent(const calitem *parent, bool link_back)
{
    mParents.push_back(parent);
    parent->addchild(this, false);
}

set<time_period> calitem::coverage() const
{
    return mCoverage;
}

set<time_period> calitem::intersect(const calitem &other) const
{
    set<time_period> otherperiods = other.coverage();
    set<time_period> condensedperiods;

    // Unify the time period sets
    set<time_period>::const_iterator period_it = allperiods.begin();
    for(; period_it != otherperiods.end(); period_it++)
    {
        set<time_period>::const_iterator this_it = mCoverage.begin();
        for(; this_it != allperiods.end(); this_it++)
    }

    // Condense the coverage set
    period_it = allperiods.begin();
    
}
