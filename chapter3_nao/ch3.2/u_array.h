// サイズ制限のない配列
class UArray
{
    const int beta = 2;
    const int alpha = 4;
    int w = 1;
    int n = 0;
    int *b;

public:
    UArray();

    int operator[](int i);

    int size();

    void pushBack(int n);

    void popBack();

    void reallocate(int wp);
};
