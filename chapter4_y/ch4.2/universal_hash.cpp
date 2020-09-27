
#include <iostream>
#include <string>
#include <bitset>
#include <regex>
#include <stdexcept>
#include <cmath>
#include <expectation.h>

#include "s_item.h"
#include "s_linked_list.h"
#include "s_free_list.h"
#include <uarray.h>
#include "universal_hash.h"
#include "operation.h"
#include "gen_random.h"
#include "rand_list.h"

UArray<UArray<int>> key(std::string e, int w)
{
    std::smatch smatch;
    if (!std::regex_search(e, smatch, std::regex("^[a-z]+$")))
    {
        throw std::invalid_argument("ハッシュの引数は半角英数字のみが許容されます");
    }
    if (e.length() == 0)
    {
        throw std::invalid_argument("ハッシュの引数には空文字でない文字列を指定してください");
    }

    UArray<UArray<int>> res; //教科書とは逆(x_k,...,x_1)
    UArray<int> x = tobit(e);
    int numsplit = (w - 1 + x.size()) / w; //分割数
    for (int i = 0; i < numsplit; i++)
    {
        UArray<int> cur;
        for (int j = 0; j < w; j++)
        {
            if (i * w + j >= x.size())
            {
                break;
            }
            cur.pushBack(x[i * w + j]);
        }
        res.pushBack(cur);
    }
    return res;
}

std::string element(UArray<UArray<int>> k, int w)
{
    UArray<int> flatten;
    for (int i = 0; i < k.size(); i++)
    {
        UArray<int> cur = k[i];
        for (int idx = 0; idx < cur.size(); idx++)
        {
            flatten.pushBack(cur[idx]);
        }
    }

    std::string res = tostr(flatten);
    return res;
}

long long hashRand(UArray<UArray<int>> k, int m)
{

    long long N = 0;
    int count = 1;
    for (int i = 0; i < k.size(); i++)
    {
        UArray<int> cur = k[i];
        for (int j = 0; j < cur.size(); j++)
        {
            if (count > RandList::size())
            {

                RandList::pushBack(m * m); //できれば大きい値にしておきたい reallocで再計算のほうが良い？
            }
            N += cur[j] * RandList::at(count - 1);
            count++;
        }
    }
    return N;
}

int hash(UArray<UArray<int>> k, int mod)
{
    return hashRand(k, mod) % mod;
}
UniversalHash::UniversalHash()
{
    t = new SLinkedList[m];
}

void UniversalHash::insert(std::string s, std::string value)
{
    if (n == m)
    {
        reallocate(beta * n);
    }
    UArray<UArray<int>> k = key(s, w);
    int h = hash(k, m);
    t[h].pushBack(s, value);
    n++;
}

void UniversalHash::remove(std::string s)
{
    UArray<UArray<int>> k = key(s, w);
    int h = hash(k, m);
    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {
        if (tmp->next->e == element(k, w)) //右辺はeそのものでは？
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

    //if (m >= alpha * n && n > 0)
    //{
    //reallocate(beta * n);
    //}
}

std::string UniversalHash::find(std::string s)
{

    UArray<UArray<int>> k = key(s, w);

    int h = hash(k, m);

    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {

        if (tmp->next->e == element(k, w))
        {
            return tmp->next->e;
        }
        tmp = tmp->next;
    }
    return "";
}

std::string UniversalHash::operator[](std::string s)
{
    UArray<UArray<int>> k = key(s, w);
    int h = hash(k, m);
    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {
        if (tmp->next->e == element(k, w))
        {
            return tmp->next->value;
        }
        tmp = tmp->next;
    }
    return "";
}

void UniversalHash::reallocate(int mp)
{
    int k = findk(mp);
    mp = findPrime(k);
    SLinkedList *tp = new SLinkedList[mp];
    for (int i = 0; i < m; i++)
    {
        SItem *tmp = t[i].head()->next;
        while (!tmp->isDummy)
        {
            int h = hash(key(tmp->e, w), mp);
            tp[h].pushBack(tmp->e, tmp->value);
            tmp = tmp->next;
        }
    }

    m = mp;
    w = floorlog(m);
    delete[] t;
    t = tp;
}