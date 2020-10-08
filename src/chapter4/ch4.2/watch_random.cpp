#include <iostream>
#include "gen_random.h"
#include "operation.h"
#include "universal_hash.h"
#include <uarray.h>

int main()
{
    int m = 257;
    UArray<int> res;
    for (int i = 0; i < m; i++)
    {
        res.pushBack(0);
    }
    for (int rep = 0; rep < m * m * 5; rep++)
    {
        res[gen_mt(m)]++;
    }
    for (int i = 0; i < m; i++)
    {
        std::cout << res[i] << std::endl;
    }
}
