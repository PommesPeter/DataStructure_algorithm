#include <stdio.h>
#include <stdlib.h>

struct node {//链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    int data;
    struct node *next;
};
typedef struct node *pnode;

struct node *mycreateList() {//函数功能：创建一个只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void myinsertHead(struct node *head, int insData) {
    /*函数功能：实现在head为表头的链表中使用头插法，插入数据元素insData*/
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = insData;
    p->next = head->next;
    head->next = p;
}

void myinsertTail(struct node *head, int insData) {
    /*在head为表头的单链表表尾插入数据元素insData*/
    struct node *p, *q;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = insData;
    p->next = NULL;
    q = head;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
}

void myprintList(struct node *L) {
    /*输出head为表头的链表中的数据元素，每输出一个数据空一格*/
    struct node *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void genNumber(struct node *A, int num) {//本函数用于接收输入的大数的各个位，返回大数链表表头，可使用上面已实现的链表插入函数
/*------begin---------*/
    int data = 0;
    for (int i = 0; i < num; i++) {
        scanf("%d", &data);
        myinsertHead(A, data);
    }

/*------end---------*/
}

//10 1 2 3 4 5 6 7 8 9 9 2 6 5
struct node *addNumber(struct node *A, struct node *B) {
    //此处实现函数求两数相加，并返回和值链表的表头；
    /*------begin---------*/
    int carry = 0;
    int sum = 0, temp = 0;
    pnode C = mycreateList();
    pnode p = A->next;
    pnode q = B->next;
    while (p != NULL || q != NULL) {
        if (p == NULL) {
            sum = q->data + carry;
            temp = sum % 10;
            carry = sum / 10;
            q = q->next;
        } else if (q == NULL) {
            sum = p->data + carry;
            temp = sum % 10;
            carry = sum / 10;
            p = p->next;
        } else {
            sum = p->data + q->data + carry;
            temp = sum % 10;
            carry = sum / 10;
            p = p->next;
            q = q->next;
        }
        myinsertHead(C, temp);
    }

    return C;

    /*------end---------*/
}
