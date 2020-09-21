#include <iostream>
using namespace std;
class UArray{
    private:
        int beta;
        int alpha;
        int w = 1;
        int n = 0;
        int *b;
    public:
        int operator [](int i);
        int size();
        void pushBack(int e);
        void popBack();
        void reallocate(int wp);
        UArray(int al, int be);
};