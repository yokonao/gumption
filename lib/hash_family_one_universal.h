#ifndef HASH_FAMILY_ONE_UNIVERSAL_HPP
#define HASH_FAMILY_ONE_UNIVERSAL_HPP

#include <string>
#include <bit_string.h>
#include <gen_mt.h>
#include <stdexcept>
#include <cmath>
#include <iostream>

class IHashFamily
{
protected:
    int m;

public: 
    virtual ~IHashFamily() {}

    virtual int hash(std::string s) = 0;
};

class HashFamily_OneUniversal : IHashFamily
{
    int w;

    int floorLog(int m)
    {
        if (m < 1)
        {
            throw std::invalid_argument("1以上の値を指定してください");
        }
        return int(floor(log2(double(m))));
    }

public:
    HashFamily_OneUniversal(int m)
    {
        this->m = m;
        this->w = floorLog(m);
    }

    int hash(std::string s)
    {
        BitString x = BitString(s);
        int k = (w - 1 + x.size()) / w;
        long long N = 0;

        for (int i = 0; i < k; i++)
        {
            int x_i = 0;
            for (int j = 0; j < w; j++)
            {
                int idx = i * w + j;
                if (idx >= x.size())
                {
                    break;
                }
                x_i += x[idx] * pow(2, j);
            }
            int a_i = gen_mt(m);
            N += x_i * a_i;
        }

        return N % m;
    }
};

#endif
