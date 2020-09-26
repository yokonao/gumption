#include "chaining_hash.h"
#include <regex>
#include <stdexcept>
#include <cmath>
#include <iostream>

std::string key(std::string e)
{
    return e;
}

std::string element(std::string key)
{
    return key;
}

long long hashPrime(std::string key)
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

    long long N = 0;
    for (int i = 0; i < key.length(); i++)
    {
        long long tmp = (key[key.length() - i - 1] - 'a' + 1) * std::pow(26, i);
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
    t = new SLinkedList[1];
}

void ChainingHash::insert(std::string e, std::string value)
{
    if (n == m)
    {
        reallocate(beta * n);
    }
    std::string k = key(e);
    int h = hash(k, m);
    t[h].pushBack(e, value);
    n++;
}

void ChainingHash::remove(std::string key)
{
    int h = hash(key, m);
    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {
        if (tmp->next->e == element(key))
        {
            t[h].removeAfter(tmp);
            n--;
        }
        if (tmp->next->isDummy)
        {
            break;
        }
        else
        {
            tmp = tmp->next;
        }
    }

    if (m >= alpha * n && n > 0)
    {
        reallocate(beta * n);
    }
}

std::string ChainingHash::find(std::string key)
{
    int h = hash(key, m);
    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {
        if (tmp->next->e == element(key))
        {
            return tmp->next->e;
        }
        tmp = tmp->next;
    }
    return "";
}

std::string ChainingHash::operator[](std::string key)
{
    int h = hash(key, m);
    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {
        if (tmp->next->e == element(key))
        {
            return tmp->next->value;
        }
        tmp = tmp->next;
    }
    return "";
}

void ChainingHash::reallocate(int mp)
{
    SLinkedList *tp = new SLinkedList[mp];
    for (int i = 0; i < m; i++)
    {
        SItem *tmp = t[i].head()->next;
        while (!tmp->isDummy)
        {
            int h = hash(key(tmp->e), mp);
            tp[h].pushBack(tmp->e, tmp->value);
            tmp = tmp->next;
        }
    }

    m = mp;
    delete[] t;
    t = tp;
}
