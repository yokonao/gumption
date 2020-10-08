#include "rand_list.h"
UArray<int> RandList::m_randlist;
int RandList::at(int i) { return m_randlist[i]; };
int RandList::size() { return m_randlist.size(); };
void RandList::pushBack(int m) { m_randlist.pushBack(gen_mt(m)); };
void RandList::recalc(int m)
{
    m_randlist.clear();
    for (int i = 0; i < m; i++)
    {
        m_randlist.pushBack(gen_mt(m));
    }
}