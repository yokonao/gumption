#include <iostream>
#include <cmath>
#include <string>
#include <bitset>
#include "operation.h"
#include "uarray.h"

int floorlog(int m)
{
    if (m < 1)
    {
        throw std::invalid_argument("1以上の値を指定してください");
    }
    return int(floor(log2(double(m))));
}
UArray tobit(char s)
{
    // 'p' -> 01110000ならばx=[0,0,0,0,1,1,1,0]で有ることに注意
    UArray x;
    std::bitset<8> b = std::bitset<8>(s);
    for (int i = 0; i < 8; i++)
    {
        x.pushBack(int(b[i]));
    }
    return x;
}
char tostr(UArray a);
