#include <stdio.h>
#include <stdlib.h>

/*数据结构定义*/
typedef int DataType;
typedef struct
{
    DataType *data; //用于存放待排序关键字的起始地址
    int NUM; //待排序关键字的个数
} SortObject;

typedef struct node //用于表插入排序的数据结构
{
    DataType  info;
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
void insertSort( SortObject *Rec )
{

    /*----begin------*/


    /*-----end------*/

}

/*第二关
此处请填写代码实现递增序进行二分插入排序,

  实质是在已经有序的表中采用二分法查找插入位置
  要求每趟排序后 调用print函数，输出关键字的排列情况*/
void binInsertSort(  SortObject *Rec )
{
    printf("the result of binInsertSort:\n");
    /*----begin------*/


    /*-----end------*/

}

/* 第四关
此处请填写代码实现递增序进行shell排序,

  要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void shellSort( SortObject *Rec,int d )
{


}

/*第三关
此处请填写代码实现递增序进行表插入排序,
  返回值是关键字比较次数
  Head是表头结点，不存放数据，info是待插入数据
  要求每趟排序后 调用printLink函数，输出关键字的排列情况
  */
void listSort(linkObject *plist )
{

    /*----begin------*/


    /*-----end------*/

}
