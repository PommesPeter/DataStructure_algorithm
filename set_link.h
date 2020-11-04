#ifndef _LINKSET_H_
#define _LINKSET_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

struct node {
    DataType element;
    struct node *next;
};
typedef struct node *SET;

void insert(DataType datax, SET set);

/*
  函数名： InitSet
  函数功能：根据参数num，初始化集合
  函数参数：集合元素的个数 
  返回值：集合头指针 
*/
//5 91 51 2 32 7 4 21 51 2 16
//并集：21 16 91 51 2 32 7
//交集：51 2
//差集：91 32 7
SET InitSet(int num) {
    SET p;
    p = (struct node *) malloc(sizeof(struct node));
    p->next = NULL;
    p->element = num;
    int temp;
    for (int i = 0; i < num; i++) {
        scanf("%d", &temp);
        insert(temp, p); //调用insert函数，将输入数据插入集合
    }
    return p;
}


/*
  函数名： find
  函数功能：在集合中查找值为datax的成员 
  函数参数：datax:待查找的值 ； set：集合的头结点 
  返回值：找到值为datax的成员返回1，否则返回0 
*/
int find(DataType datax, SET set) {
    //请在此处填写代码，在set集合中查找值为datax的成员，若找到返回1，否则返回0
    /**********  Begin  **********/
    for (SET p = set->next;; p = p->next) {
        if (p->element == datax) {
            return 1;
        } else if (p->next == NULL) {
            return 0;
        }
    }
    /**********   End   **********/
}

/*
  函数名： insert
  函数功能：在集合set中插入值为datax的成员 ，插入位置在表头 
  函数参数：datax:待插入的值 ； set：集合的头结点 
  返回值：无 
  时间复杂度：O（1）
*/
void insert(DataType datax, SET set) {
    //请在此处填写代码，将datax插入集合set， 注意因集合元素是无序的，只需将新成员插入表头
    /**********  Begin  **********/
    SET temp = (SET) malloc(sizeof(struct node));
    temp->element = datax;
    temp->next = set->next;
    set->next = temp;
    /**********   End   **********/
}

/*
  函数名： copySet
  函数功能：将集合setA复制生成集合setB 
  函数参数：setA 、setB的头结点 
  返回值：无 
*/
void copySet(SET setA, SET setB) {
    /**********  Begin  **********/
    setB->element = setA->element;
    setB->next = NULL;
    for (SET pa = setA->next; pa != NULL; pa = pa->next ) {
        insert(pa->element, setB);
    }
    /**********   End   **********/
}

/*
  函数名： printSet
  函数功能：输出集合的元素，以空格作为元素之间分界符 
  函数参数：set的头结点 
  返回值：无 
*/
void printSet(SET set) {
    //请在此处填写代码，实现输出集合元素的功能，元素之间以空格为分界符
    /**********  Begin  **********/
    for (SET p = set->next; p != NULL; p = p->next) {
        printf("%d ", p->element);
    }
    /**********  End  **********/
}

/*
  函数名： setUnion
  函数功能：求两个集合setA 和 setB的并集 
  函数参数：setA和setB的头结点 
  返回值：并集集合的头结点 
*/
SET setUnion(SET setA, SET setB) {
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET res = (SET)malloc(sizeof(struct node));
    copySet(setA, res);

    for (SET p = setB->next; p != NULL; p = p->next) {
        if (find(p->element, res) - 1) {
            insert(p->element, res);
            res->element++;
        }
    }
    return res;
    /**********  End  **********/
}

/*
  函数名： setIntersect
  函数功能：求两个集合setA 和 setB的交集 
  函数参数：setA和setB的头结点 
  返回值：交集集合的头结点 
*/
SET setIntersect(SET setA, SET setB) {
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET res = (SET)malloc(sizeof(struct node));
    res->next = NULL;
    res->element = 0;
    for (SET p = setA->next; p != NULL; p = p->next) {
        if (find(p->element, setB)) {
            res->element++;
            insert(p->element, res);
        }
    }
    return res;

    /**********  End  **********/
}

/*
  函数名： setExcept
  函数功能：求两个集合setA 和 setB的差 
  函数参数：setA和setB的头结点 
  返回值：结果集合的头结点 
*/
SET setExcept(SET setA, SET setB) {
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET res = (SET)malloc(sizeof(struct node));
    res->next = NULL;
    res->element = 0;
    for (SET p = setA->next; p != NULL; p = p->next) {
        if (find(p->element, setB) - 1) {
            insert(p->element, res);
            res->element++;
        }
    }
    return res;

    /**********  End  **********/
}

void destroySet(SET set) {
//释放存储集合的链表空间，表头为set
    SET p = set->next;
    while (p != NULL) {
        p = p->next;
        free(set->next);
        set->next = p;;
    }
    free(p);
}

#endif