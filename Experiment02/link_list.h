#ifndef _LAB1_H_
#define  _LAB1_H_

#include <stdlib.h>
#include <stdio.h>

//5 0 2 1 3 5 -2 7 0 0 12 1 2 7 13 15 0 0
//存放多项式某项的结点结构 
struct node {
    int exp;  // 表示指数
    int coef; //表示系数
    struct node *next;  //指向下一个结点的指针
};

typedef struct node *PNODE;

/*
  函数功能：生成多项式
  函数名：createPoly
  函数参数：无
  返回值：指向多项式的头指针 
*/
PNODE createPoly() {
    //在此处填写代码，能实现创建一个多项式并返回多项式头指针的函数
    //注意：头指针不存放多项式的项。
    /**********  Begin **********/
    PNODE head = (PNODE) malloc(sizeof(struct node));
    PNODE temp = head;
    head->exp = 0;
    head->coef = 0;
    head->next = NULL;

    while (1) {
        PNODE p = (PNODE) malloc(sizeof(struct node));
        p->next = NULL;
        scanf("%d", &p->coef);
        scanf("%d", &p->exp);
        if (p->coef == 0) {
            break;
        }
        temp->next = p;
        temp = p;
    }

    return head;
    /**********  End  **********/
}

/*
   函数功能：进行多项式相加
   函数名：addPoly
   函数参数：polyAddLeft ：加法左边多项式头指针, polyAddRight：加法右边多项式头指针 
   返回值：指向结果多项式的头指针 
*/
PNODE addPoly(PNODE polyAddLeft, PNODE polyAddRight) {
    //在此处填写代码，能实现创两个多项式相加并返回结果多项式头指针的函数
    /**********  Begin **********/
    PNODE polyAddResult = createPoly();
    PNODE p1 = polyAddLeft;
    PNODE p2 = polyAddRight;
    PNODE p3 = polyAddResult;
    PNODE s;
    while (p1 != NULL && p2 != NULL){
        if (p1->exp > p2->exp){
            s = (PNODE)malloc(sizeof(struct node));
            s->exp = p1->exp;
            s->coef = p1->coef;
            p3->next = s;
            p3 = s;
            p1 = p1->next;
        }
    }
    return polyAddResult;
    /**********  End **********/
}

/*
   函数功能：输出多项式 
   函数名：printPoly
   函数参数：待输出多项式的头指针poly 
   返回值：无 
*/
void printPoly(PNODE poly) {
    //在此处填写代码，能实现按格式输出多项式的功能，输出格式样例见说明
    /**********  Begin **********/
    for (PNODE p = poly->next; p != NULL; p = p->next) {
        if (p == poly->next || p->coef < 0) {
            printf("%d^%d", p->coef, p->exp);
            continue;
        } else if (p->coef > 0) {
            printf("+%dx^%d", p->coef, p->exp);
        }
    }
    /**********  End **********/
}

void destroyPoly(PNODE poly) {
//释放存储多项式的链表空间

}

#endif