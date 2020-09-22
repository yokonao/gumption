#include "chaining_hash.h"
#include <regex>
#include <stdexcept>
#include <cmath>

std::string key(std::string e)
{
    return e;
}

std::string element(std::string key)
{
    return key;
}

unsigned long long hashPrime(std::string key)
{

    std::smatch smatch;
    if (!std::regex_search(key, smatch, std::regex("^[a-z]+$")))
    {
        throw std::invalid_argument("ハッシュの引数は半角英数字のみが許容されます");
    }
    if (key.length() == 0)
    {
        throw std::invalid_argument("ハッシュの引数には空文字でない文字列を指定してください");
    }
    if (key.length() >= 7)
    {
        throw std::length_error("文字列が長すぎます。1~6文字の文字列を指定してください");
    }
    
    unsigned long long N = 0;
    for (int i = 0; i < key.length(); i++)
    {
        unsigned long long tmp = (key[key.length() - i - 1] - 'a' + 1) * std::pow(26, i);
        N += tmp;
    }
    return N;
}

int hash(std::string key, int mod)
{
    return hashPrime(key) % mod;
}

ChainingHash::ChainingHash()
{
    t = new SLinkedList[0];
}

void ChainingHash::insert(std::string e, std::string value)
{
    if (n == m)
    {
        reallocate(beta * n);
    }
    std::string k = key(e);
}

void ChainingHash::reallocate(int mp)
{
    m = mp;
    SLinkedList *tp = new SLinkedList[mp];
    for (int i = 0; i < n; i++)
    {
        tp[i] = t[i];
    }
    delete t;
    t = tp;
}
