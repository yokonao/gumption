#ifndef RAND_LIST_HPP
#define RAND_LIST_HPP

#include <uarray.h>
#include <gen_mt.h>
#include <cassert>

class RandList
{
private:
    static UArray<int> m_randlist;

public:
    static int at(int i);
    static int size();

    static void pushBack(int m);
    static void recalc(int m);
};

#endif
