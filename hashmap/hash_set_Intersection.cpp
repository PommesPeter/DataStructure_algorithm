#define MAXNUM 100 //假设每个集合中的元素都不超过100

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

typedef struct Set {
    int number;  //记录集合中的实际元素个数
    int *element;  //使用数组保存集合中各元素
} Set;

Set* Intersection(Set* SA, Set* SB) //假设SA对应的集合中元素个数多于SB表示的集合
{
    Set * result = (Set *) malloc(sizeof(Set));  //用于存放交集操作的结果
    result->element = (int *)malloc((SA->number > SB->number) ? SA->number : SB->number * sizeof(int));  //分配存放结果的存储空间
    int pos = 0;
    //建立散列地址空间
    int p = PrimeNumber(SA->number); // PrimeNumber ( int n )能得到不大于n的最大素数
    int *hash = (int*) malloc(p * sizeof(int));
    memset(hash, -1, p);
    for (int i = 0; i < SA->number; i++) {
        hash[(int)(SA->element[i] % p)] = SA->element[i];
    }
    for (int i = 0; i < SB->number; i++) {
        if (hash[(int)(SB->element[i] % p)] == SB->element[i]) {
            result->element[pos++] = SB->element[i];
        }
    }
    return result;
}