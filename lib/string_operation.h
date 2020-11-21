#include <cstddef>
#include <utility>

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