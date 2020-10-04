#ifndef BIT_STRING_HPP
#define BIT_STRING_HPP

#include <string>
#include <bitset>
#include <stdexcept>
#include <cassert>

struct BitString
{
private:
    int *bits;
    int n;

public:
    BitString(std::string s)
    {
        int l = s.length();
        const int unit = 8;
        n = l * unit;
        bits = new int[n];
        for (int i = 0; i < l; i++)
        {
            std::bitset<8> b = std::bitset<8>(s[l - 1 - i]);
            for (int j = 0; j < unit; j++)
            {
                bits[i * unit + j] = b[j];
            }
        }
    }

    ~BitString()
    {
        delete[] bits;
    }

    std::string toString()
    {
        std::string s = "";
        for (int idx = 0; idx < n / 8; idx++)
        {
            std::string curs = "";
            char c = 0;
            int res = 0;
            for (int i = 0; i < 8; i++)
            {
                res = 2 * res + bits[idx * 8 + 7 - i];
            }
            c = res;
            s = c + s;
        }
        return s;
    }

    int operator[](int i)
    {
        assert(i >= 0 and i < n);
        return bits[i];
    }
};

#endif
