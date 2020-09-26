#include <iostream>
#include <cmath>
#include "operation.h"

int floorlog(int m)
{
    if (m < 1)
    {
        throw std::invalid_argument("1以上の値を指定してください");
    }
    return int(floor(log2(double(m))));
}