#include <stdio.h>
#include <stdlib.h>

/*哈希结构*/
struct hashTable
{
    int *element;//存放键值的连续空间起始地址
    int maxNum;// 哈希表长度
    int curNum;//当前哈希表已有数据元素
};

struct node
{
    int data ;
    struct node *next;
};

struct hashTable_link
{
    struct node *element;
    int maxNum;// 哈希表长度
};


/*第一关*/
//初始化一个哈希表，能满足线性探测再散列处理冲突法使用，初始化哈希表元素均为-1，表示该位置为空，可插入
struct hashTable* initHashTable_linear()
{
    struct hashTable* h = (struct hashTable*)malloc(sizeof(struct hashTable));
    if (h == NULL) {
        return NULL;
    }
    h->maxNum = 10;
    h->curNum = 0;
    h->element = (int*)malloc(h->maxNum * sizeof(int));
    for (int i = 0; i < h->maxNum; i++) {
        h->element[i] = -1;
    }
    return h;
}

//初始化一个哈希表，能满足据拉链法处理冲突法使用。初始化哈希表元素为0，用于计算该条链中数个数，在插入时增加
struct hashTable_link * initHashTable_link()
{
    struct hashTable_link* hash_link = (struct hashTable_link*)malloc(sizeof(struct hashTable_link));
    if (hash_link == NULL) {
        return NULL;
    }
    hash_link->maxNum = 10;
    hash_link->element = (struct node*)malloc(hash_link->maxNum * sizeof(struct node));
    for (int i = 0; i < hash_link->maxNum; i++) {
        hash_link->element[i].data = 0;
    }
    return hash_link;
}

/*第二关*/
//输出线性探测再散列法构建的哈希表,从下标为0的元素开始输出，每输出一个数据空一格
void printHashTable(struct hashTable *h)
{
    for (int i = 0; i < h->maxNum; i++) {
        printf("%d ", h->element[i]);
    }
}

/*第三关*/
//哈希函数，h(key) = (key*3) %  7
int hashFun(int key)
{
    return (key * 3) % 7;
}

//函数功能：计算key的哈希地址，若发生冲突，则使用线性探测再散列的方法查找合适的插入位置下标，并返回该下标
int findPos(struct hashTable *h , int key)
{
    int hash_key = hashFun(key);
    if (h->element[hash_key] == -1) {
        return hash_key;
    } else if (h->element[hash_key] != -1){
        while (1) {
            if (h->element[++hash_key] == -1) {
                return hash_key;
            }
        }
    }
    return -1;
}

//插入键值函数,若哈希表空间已满，则返回-1，否则返回插入位置下标
int insertKey(struct hashTable *h , int key)
{
    int insert_key = findPos(h, key);
    if (insert_key == -1) {
        return -1;
    } else {
        h->element[insert_key] = key;
        return insert_key;
    }
}