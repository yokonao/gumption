#include <iostream>
#include "gen_random.h"
#include "operation.h"
#include "universal_hash.h"
#include <uarray.h>
UArray<int> watch_cite()
{
    int m = 257;
    int w = floorlog(m);

    UArray<int> res;
    for (int i = 0; i < m; i++)
    {
        res.pushBack(0);
    }
    for (int rep = 0; rep < m * m; rep++)
    {
        std::string cString = "";
        for (int i = 0; i < 10; i++)
        {
            char c = 'a' + gen_mt(26); //aからzの文字を一つ作成
            cString = cString + c;
        }
        res[hash(key(cString, w), m)]++;
    }
    return res;
}
double get_mean()
{
    int rep = 10;
    int idx = 111;
    double mean = 0.0;
    UArray<int> res;
    for (int i = 0; i < rep; i++)
    {
        std::cout << "start:" << i << std::endl;
        res = watch_cite();
        mean += res[idx];
    }
    mean /= rep;
    return mean;
}
void print_hash()
{
    UArray<int> res;
    res = watch_cite();
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << std::endl;
    }
}
int main()
{
    print_hash();
}
