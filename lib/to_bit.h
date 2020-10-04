#ifndef TO_BIT_HPP
#define TO_BIT_HPP

#include <uarray.h>
#include <string>
#include <bitset>
#include <stdexcept>

UArray<int> toBit(std::string s)
{
    // 'p' -> 01110000ならばx=[0,0,0,0,1,1,1,0]で有ることに注意
    UArray<int> x;
    for (int idx = 0; idx < s.size(); idx++)
    {
        char curs = s[s.size() - 1 - idx];
        std::bitset<8> b = std::bitset<8>(curs);
        for (int i = 0; i < 8; i++)
        {
            x.pushBack(int(b[i]));
        }
    }
    return x;
}

std::string toString(UArray<int> a)
{
    if (a.size() % 8 != 0)
    {
        throw std::invalid_argument("配列の長さは8の倍数にしてください");
    }
    std::string s = "";
    for (int idx = 0; idx < a.size() / 8; idx++)
    {
        std::string curs = "";
        char c = 0;
        int res = 0;
        for (int i = 0; i < 8; i++)
        {
            res = 2 * res + a[idx * 8 + 7 - i];
        }
        c = res;
        s = c + s;
    }
    return s;
}

#endif
