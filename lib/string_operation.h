#include <iostream>
#include <cstddef>
#include <utility>
#include <stack.h>

template <typename T>
void swap(T &t1, T &t2)
{
    T temp = std::move(t1);
    t1 = std::move(t2);
    t2 = std::move(temp);
}

std::size_t strlen(const char *s)
{
    auto i = s;
    while (*i != '\0')
    {
        ++i;
    }
    return i - s;
}

bool charcmp(char *a, char *b)
{
    auto sizea = strlen(a);
    auto sizeb = strlen(b);
    if (sizea != sizeb)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < int(sizea); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
}

void inplace_reverse(char *s)
{
    if (s)
    {
        std::size_t n = strlen(s);
        for (int i = 0; i < int(n) / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
}

int f_atoi(char *str)
{
    int n = 0;
    int sgn = -1;
    while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' || *str == '\t' || *str == '\v')
    {
        str++;
    }
    if (*str == '-')
    {
        sgn = 1;
    }
    if (*str == '-' or *str == '+')
    {
        str++;
    }
    while (*str != '\0' and *str >= '0' and *str <= '9')
    {
        //-2147483648を処理するときにnを正として扱うとn=2147483648,となりoverflowする
        n *= 10;
        n -= *str - '0';
        str++;
    }

    return sgn * n;
}
char *f_itoa(int value, char *str, int radix)
{
    int idx = 0;
    Stack<char> t;
    while (value != 0)
    {
        if (value < 0)
        {
            str[idx] = '-';
            idx++;
            value *= -1;
        }
        else
        {
            t.pushBack(value % radix + '0');
            value /= radix;
        }
    }
    while (not t.isEmpty())
    {
        str[idx] = t.last();
        t.popBack();
        idx++;
    }
    str[idx] = '\0';
    return str;
}