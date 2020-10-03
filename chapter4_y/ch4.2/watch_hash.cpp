#include <iostream>
#include "gen_random.h"
#include "operation.h"
#include "universal_hash.h"
#include <uarray.h>

int main()
{
    int m = 257;
    int w = floorlog(m);
    UArray<int> res;
    for (int i = 0; i < m; i++)
    {
        res.pushBack(0);
    }
    char c;
    std::string cs;
    for (int rep = 0; rep < m * m; rep++)
    {
        std::string ts = "";
        for (int i = 0; i < 10; i++)
        {
            c = 'a';
            cs = "";
            c = c + gen_mt(26);
            cs = cs + c;
        }
        res[hash(key(cs, w), m)]++;
    }
    for (int i = 0; i < m; i++)
    {
        std::cout << res[i] << std::endl;
    }
}
