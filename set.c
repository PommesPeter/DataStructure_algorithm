#include "set_link.h"

int main(void)
{
    int count;
    scanf("%d",&count);
    SET setA = InitSet(count);
    scanf("%d",&count);
    SET setB = InitSet(count);
    printf("������");
    printSet(setUnion(setA,setB));
    printf("\n������");
    printSet(setIntersect(setA,setB));
    printf("\n���");
    printSet(setExcept(setA,setB));
    destroySet(setA);
    destroySet(setB);
}