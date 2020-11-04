#include <stdio.h>
#include <stdlib.h>

struct node { //链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    int data;
    struct node *next;
};

//第一关代码
struct node *createRlist() { //函数功能：创建一个有一个空循环链表，返回值为头指针
    struct node *head = (struct node *) malloc(sizeof(struct node));
    if (head == NULL) {
        return NULL;
    }
    head->data = 0;
    head->next = head;
    return head;
}

void insertOrder(struct node *list, int insData) {
    //在单向递增有序的循环链表（表头指针list）中插入数据元素insData，使之依然有序 。
    struct node *p = createRlist();
    p->data = insData;

    if (list->data > insData) {
        p->next = list;
        list->next = p;
    }

    struct node *pre = list;
    struct node *cur = list->next;

    while (cur != list && cur->data < insData) {
        pre = cur;
        cur = cur->next;
    }

    //插入
    p->next = cur;
    pre->next = p;
}

int deleteData(struct node *list, int delData) {
    //在单向递增有序循环链表（表头指针list）中删除所有值为delData的结点,返回值为删除结点的个数
    int count = 0;
    for (struct node *p = list->next; p != list;) {
        if (p->next->data == delData) {
            p->next = p->next->next;
            count++;
        }
        else
        {
            p = p->next;
        }
    }
    return count;
}

void printRlist(struct node *list) {
    //从链表第一个结点开始输出单向循环链表中各数据元素的值，每输出一个数据元素空一格
    for (struct node *p = list->next; p != list; p = p->next) {
        printf("%d ", p->data);
    }
}

int destroyRlist(struct node *list) {
    //从第一个结点开始释放循环链表各结点占用的空间,返回值为最后一个结点的值
    int temp_num = 0;
    for (struct node *p = list->next; p != list; p = p->next) {
        if (p->next == list)
        {
            temp_num = p->data;
            break;
        }
    }
    return temp_num;
}