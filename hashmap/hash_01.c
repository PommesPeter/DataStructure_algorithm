#include "hash.h"
//10
//-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//10
//0 0 0 0 0 0 0 0 0 0
int main( )
{
    struct hashTable *h = initHashTable_linear();
    printf("%d\n",h->maxNum);
    for(int i=0;i<h->maxNum;i++) { printf("%d ", h->element[i]); }
    printf("\n");
    struct hashTable_link *h1 = initHashTable_link();
    printf("%d\n",h1->maxNum);
    for(int i=0;i<h1->maxNum;i++) { printf("%d ", h1->element[i].data); }
}
