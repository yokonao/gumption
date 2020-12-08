#include "uarray.h"
#include <cassert>
using namespace std;

UArray::UArray(int al, int be){
    alpha = al;
    beta = be;
    b = new int[0];
}
int UArray::operator[](int i){
    assert(i >= 0 and i < n);
    return b[i]; 
}
int UArray::size(){return n;}
void UArray::pushBack(int e){
    if(n == w){
        reallocate(beta * n);
    }
    b[n] = e;
    n++;
}
void UArray::popBack(){
    assert(n>0);
    n--;
    if(alpha * n <= w and n > 0){
        reallocate(beta * n);
    }

}
void UArray::reallocate(int wp){
    w = wp;
    int *bp = new int[w];
    for(int i=0;i<n;i++){bp[i] = b[i];}
    delete b;
    b = bp;
}