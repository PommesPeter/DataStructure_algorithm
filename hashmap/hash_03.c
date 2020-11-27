#include "hash.h"
//7 8 30 11 18 9 14
//7 14 -1 8 -1 11 30 18 9 -1
int main( )
{
    struct hashTable *h = initHashTable_linear();
    int key;
    for(int i=0;i<7;i++)
    {
        scanf("%d",&key);
        insertKey(h, key);
    }
    printHashTable(h);
}
 