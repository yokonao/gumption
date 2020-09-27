#include <iostream>
#include <cmath>
#include <string>
#include <bitset>
#include "operation.h"
#include <uarray.h>

int floorlog(int m)
{
    if (m < 1)
    {
        throw std::invalid_argument("1以上の値を指定してください");
    }
    return int(floor(log2(double(m))));
}
UArray<int> tobit(std::string s)
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
std::string tostr(UArray<int> a)
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
    // sはビットの文字列表現になっているはず
    return s;
}
long long Umul(UArray<int> a, UArray<int> b)
{
    if (a.size() != b.size())
    {
        throw std::invalid_argument("配列の長さが違います");
    }
    if (a.size() == 0 or b.size() == 0)
    {
        throw std::invalid_argument("配列の長さは0以上にしてください");
    }

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        res += a[i] * b[i];
    }
    return res;
}
int findk(int m)
{
    if (m < 8)
    {
        throw std::invalid_argument("引数は8以上である必要があります");
    }
    int k = 2;
    while ((k + 1) * (k + 1) * (k + 1) <= m)
    {
        k++;
    }
    return k;
}

int findPrime(int k)
{
    if (k < 2)
    {
        throw std::invalid_argument("引数は2以上である必要があります");
    }
    int kt = k * k * k;
    int kpt = (k + 1) * (k + 1) * (k + 1);
    int length = kpt - kt;
    UArray<bool> furui;
    for (int i = 0; i < length; i++)
    {
        furui.pushBack(true); //素数はtrue
    }
    for (int i = 2; i <= sqrt(kpt); i++)
    {
        int keisu = ((kt + i - 1) / i);
        int j = i * keisu - kt;
        while (j < length)
        {
            furui[j] = false;
            j += i;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (furui[i])
        {
            return kt + i;
        }
    }
    return findPrime(k + 1);
}