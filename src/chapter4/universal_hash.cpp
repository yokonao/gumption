
#include <iostream>
#include <string>
#include <cmath>
#include <expectation.h>
#include <gen_mt.h>
#include "universal_hash.h"

int UniversalHash::findK(int m)
{
    if (m < 8)
    {
        throw std::invalid_argument("引数は8以上である必要があります");
    }
    int k = 2;
    while ((k + 1) * (k + 1) * (k + 1) <= m)
    {
        k++;
    }
    return k;
}

int UniversalHash::findPrime(int k)
{
    if (k < 2)
    {
        throw std::invalid_argument("引数は2以上である必要があります");
    }
    int kt = k * k * k;
    int kpt = (k + 1) * (k + 1) * (k + 1);
    int length = kpt - kt;
    UArray<bool> furui;
    for (int i = 0; i < length; i++)
    {
        furui.pushBack(true); //素数はtrue
    }
    for (int i = 2; i <= sqrt(kpt); i++)
    {
        int keisu = ((kt + i - 1) / i);
        int j = i * keisu - kt;
        while (j < length)
        {
            furui[j] = false;
            j += i;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (furui[i])
        {
            return kt + i;
        }
    }
    return findPrime(k + 1);
}

UniversalHash::UniversalHash()
{
    t = new SLinkedList[m];
    hashFamily = new HashFamily<std::string>(m);
}

int UniversalHash::hash(std::string s)
{
    return hashFamily->hash(s);
}

void UniversalHash::insert(std::string s, std::string value)
{
    if (n == m)
    {
        reallocate(beta * n);
    }
    int h = hash(s);
    t[h].pushBack(s, value);
    n++;
}

void UniversalHash::remove(std::string s)
{
    int h = hash(s);
    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {
        if (tmp->next->e == s) //右辺はeそのものでは？
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
    int h = hash(s);

    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {

        if (tmp->next->e == s)
        {
            return tmp->next->e;
        }
        tmp = tmp->next;
    }
    return "";
}

std::string UniversalHash::operator[](std::string s)
{
    int h = hash(s);
    SItem *tmp = t[h].head();
    while (!tmp->next->isDummy)
    {
        if (tmp->next->e == s)
        {
            return tmp->next->value;
        }
        tmp = tmp->next;
    }
    return "";
}

void UniversalHash::reallocate(int mp)
{
    int k = findK(mp);
    mp = findPrime(k);
    int wp = int(floor(log2(double(mp))));
    // Hash関数を再計算
    delete hashFamily;
    hashFamily = new HashFamily<std::string>(mp);

    SLinkedList *tp = new SLinkedList[mp];
    for (int i = 0; i < m; i++)
    {
        SItem *tmp = t[i].head()->next;
        while (!tmp->isDummy)
        {
            int h = hash(tmp->e);
            tp[h].pushBack(tmp->e, tmp->value);
            tmp = tmp->next;
        }
    }

    m = mp;
    w = wp;
    delete[] t;
    t = tp;
}
