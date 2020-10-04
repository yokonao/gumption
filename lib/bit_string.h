#ifndef BIT_STRING_HPP
#define BIT_STRING_HPP

#include <string>
#include <bitset>
#include <cassert>
#include <algorithm>

const int byte_size = 8;

struct BitChar
{
private:
    std::bitset<8> m_BitSet;

public:
    BitChar()
    {
        m_BitSet = 'a';
    }

    BitChar(char c)
    {
        m_BitSet = std::bitset<8>(c);
    }

    int operator[](int i)
    {
        assert(i >= 0 && i < byte_size);
        return m_BitSet[i];
    }

    char toChar()
    {
        return (int)m_BitSet.to_ulong();
    }
};

struct BitString
{
private:
    BitChar *bit_list;
    int *bits;
    int n;
    int l;

public:
    BitString(std::string s)
    {
        l = s.length();
        n = l * byte_size;
        bit_list = new BitChar[l];
        bits = new int[n];

        std::reverse(s.begin(), s.end());
        for (int i = 0; i < l; i++)
        {
            bit_list[i] = BitChar(s[i]);
            for (int j = 0; j < byte_size; j++)
            {
                bits[i * byte_size + j] = bit_list[i][j];
            }
        }
    }

    ~BitString()
    {
        delete[] bit_list;
        delete[] bits;
    }

    std::string toString()
    {
        std::string s = "";
        for (int i = 0; i < l; i++)
        {
            s += bit_list[i].toChar();
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    int operator[](int i)
    {
        assert(i >= 0 and i < n);
        return bits[i];
    }
};

#endif
