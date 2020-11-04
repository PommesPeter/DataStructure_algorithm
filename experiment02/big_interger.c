#include "big_interger.h"
//10 1 2 3 4 5 6 7 8 9 9 2 6 5
int main() {
    struct node *A, *B, *C;
    int i, j;
    A = mycreateList();
    B = mycreateList();
    scanf("%d", &i);
    genNumber(A, i);
    scanf("%d", &j);
    genNumber(B, j);
    C = addNumber(A, B);
    myprintList(C);
    return 0;
}
