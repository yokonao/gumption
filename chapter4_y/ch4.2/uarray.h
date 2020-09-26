#ifndef UARRAY_HPP
#define UARRAY_HPP

class UArray
{
private:
    int beta;
    int alpha;
    int w = 1;
    int n = 0;
    int *b;

public:
    int operator[](int i);
    int size();
    void pushBack(int e);
    void popBack();
    void reallocate(int wp);
    UArray();
    UArray(int al, int be);
};
#endif