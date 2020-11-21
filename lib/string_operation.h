#include <cstddef>
#include <utility>

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
            std::swap(s[i], s[n - i - 1]);
        }
    }
}