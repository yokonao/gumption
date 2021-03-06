#ifndef GEN_MT_HPP
#define GEN_MT_HPP

#include <random>
#include <stdexcept>

inline int gen_mt(int m)
{
    if (m <= 0)
    {
        throw std::invalid_argument("1以上の値を指定してください");
    }
    //[0,1]の一様分布を作成
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<int> dist(0, m - 1);
    return dist(mt);
}

#endif
