#include "set_link.h"

int main(void)
{
    int count;
    scanf("%d",&count);
    SET setA = InitSet(count);
    scanf("%d",&count);
    SET setB = InitSet(count);
    printf("并集：");
    printSet(setUnion(setA,setB));
    printf("\n交集：");
    printSet(setIntersect(setA,setB));
    printf("\n差集：");
    printSet(setExcept(setA,setB));
    destroySet(setA);
    destroySet(setB);
}