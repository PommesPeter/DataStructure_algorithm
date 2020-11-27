#include "hash.h"
//-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main( )
{
    struct hashTable *h = initHashTable_linear();
    //printf("%d\n",h->maxNum);
    printHashTable(h);

}