#include <stdio.h>
#include <stdlib.h>

/*数据结构定义*/
typedef int DataType;
typedef struct {
    DataType *data; //用于存放待排序关键字的起始地址
    int NUM; //待排序关键字的个数
} SortObject;

typedef struct node //用于表插入排序的数据结构
{
    DataType info;
    struct node *next;
} linkObject;

//输出顺序表
void print(SortObject *p)
{
    for(int i=0;i<p->NUM;i++)
        printf("%d ",p->data[i]);
    printf("\n");
}

//输出链表
void printLink(linkObject *Head)
{
    linkObject *p = Head->next ;
    while(p)
    {
        printf("%d ",p->info);
        p = p->next;
    }
    printf("\n");
}

/*第一关
此处请填写代码实现递增序进行直接插入排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况*/
void insertSort(SortObject *Rec) {
    /*----begin------*/
    for (int i = 1; i < Rec->NUM; i++) {
        if (Rec->data[i] < Rec->data[i - 1]) {
            int pos = i - 1;
            int temp = Rec->data[i];
            while (pos > -1 && temp < Rec->data[pos]) {
                Rec->data[pos + 1] = Rec->data[pos];
                pos--;
            }
            Rec->data[pos + 1] = temp;
        }
        print(Rec);
    }
    /*-----end------*/
}

/*第二关
此处请填写代码实现递增序进行二分插入排序,

  实质是在已经有序的表中采用二分法查找插入位置
  要求每趟排序后 调用print函数，输出关键字的排列情况*/
void binInsertSort(SortObject *Rec) {
    int low, high, mid;
    int temp, j;
//    printf("the result of binInsertSort:\n");
    /*----begin------*/
    for (int i = 1; i < Rec->NUM; i++) {
        low = 0;
        high = i - 1;
        temp = Rec->data[i];
        while (low <= high) {
            mid = (low + high) / 2;
            if (temp < Rec->data[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--) {
            Rec->data[j + 1] = Rec->data[j];
        }
        if (low != i) {
            Rec->data[low] = temp;
        }
        print(Rec);
    }
    /*-----end------*/
}

/* 第四关
此处请填写代码实现递增序进行shell排序,

  要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void shellSort(SortObject *Rec, int d)
{
    while (d > 0) {
        for (int i = d; i < Rec->NUM; i++) {
            if (Rec->data[i] < Rec->data[i - d]) {
                int pos = i - d;
                int temp = Rec->data[i];
                while (pos > -1 && temp < Rec->data[pos]) {
                    Rec->data[pos + d] = Rec->data[pos];
                    pos -= d;
                }
                Rec->data[pos + d] = temp;
            }
        }
        d /= 2;
        print(Rec);
    }

}

/*第三关
此处请填写代码实现递增序进行表插入排序,
  返回值是关键字比较次数
  Head是表头结点，不存放数据，info是待插入数据
  要求每趟排序后 调用printLink函数，输出关键字的排列情况
  */
void listSort(linkObject *plist ) {
    /*----begin------*/
    linkObject* ptemp = plist, *phead, *q, *r, *t;
    phead = (linkObject*)malloc(sizeof(linkObject));
    phead->next = NULL;
    while (ptemp != NULL) {
        if (phead->next == NULL) {
            phead->next = ptemp;
            q = ptemp->next;
            ptemp->next = NULL;
            ptemp = q;
        } else {
            q = phead->next;
            r = phead;
            while (q != NULL && ptemp->info < q->info) {
                r = q;
                q = q->next;
            }
            t = ptemp->next;
            ptemp->next = r->next;
            r->next = ptemp;
            ptemp = t;
        }
        printLink(phead);
    }
    t = phead;
    phead = phead->next;
    free(t);

    /*-----end------*/
}

//8 49 38 65 97 76 113 27 49
//8 38 49 65 97 76 113 27 49
//6 23 13 45 7 123 89
//8 49 38 65 97 13 76 27 49
