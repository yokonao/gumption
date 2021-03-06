#ifndef CHAINING_HASH_HPP
#define CHAINING_HASH_HPP

#include <s_linked_list.h>
#include <hash_family.h>
#include <stdexcept>

template <class Key, class Value>
class ChainingHash
{
private:
    const int beta = 2;
    const int alpha = 4;
    int m = 257;
    int w = 8;
    int n = 0;
    SLinkedList<Key, Value> *t;
    HashFamily<Key> *hashFamily;

    int hash(Key key)
    {
        return hashFamily->hash(key);
    }

    void reallocate(int mp)
    {
        int k = findK(mp);
        mp = findPrime(k);
        int wp = int(floor(log2(double(mp))));
        // Hash関数を再計算
        delete hashFamily;
        hashFamily = new HashFamily<Key>(mp);

        SLinkedList<Key, Value> *tp = new SLinkedList<Key,Value>[mp];
        for (int i = 0; i < m; i++)
        {
            SItem<Key,Value> *tmp = t[i].head()->next;
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

    int findK(int m)
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

    int findPrime(int k)
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

public:
    ChainingHash()
    {
        t = new SLinkedList<Key, Value>[m];
        hashFamily = new HashFamily<std::string>(m);
    }

    ~ChainingHash()
    {
        delete[] t;
        delete hashFamily;
    }

    void insert(Key key, Value value)
    {
        if (n == m)
        {
            reallocate(beta * n);
        }
        int h = hash(key);
        t[h].pushBack(key, value);
        n++;
    }

    void remove(Key key)
    {
        int h = hash(key);
        SItem<Key, Value> *tmp = t[h].head();
        while (!tmp->next->isDummy)
        {
            if (tmp->next->e == key) //右辺はeそのものでは？
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
    }

    Key find(Key key)
    {
        int h = hash(key);
        SItem<Key, Value> *tmp = t[h].head();
        while (!tmp->next->isDummy)
        {

            if (tmp->next->e == key)
            {
                return tmp->next->e;
            }
            tmp = tmp->next;
        }
        throw std::runtime_error("指定されたキーは存在しません");
    }

    Value operator[](Key key)
    {
        int h = hash(key);
        SItem<Key, Value> *tmp = t[h].head();
        while (!tmp->next->isDummy)
        {
            if (tmp->next->e == key)
            {
                return tmp->next->value;
            }
            tmp = tmp->next;
        }
        throw std::runtime_error("指定されたキーは存在しません");
    }
};

#endif
