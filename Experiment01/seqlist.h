#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*此处是顺序线性表数据结构定义*/
typedef int DataType;
struct seqList
{//有3个数据成员
  int MAXNUM;//用于记录顺序线性表中能存放的最大元素个数的 整型 MAXNUM   
  int curNum;//用于存放顺序线性表中数据元素的个数  整型  curNum
  DataType *element;//用于存放顺序线性表数据元素的连续空间的起始地址  
};

typedef struct seqList *PseqList;
//第一关
PseqList createNullList_seq(int m)
{//此处填写代码，创建一个空的顺序线性表，能存放的最大元素个数为 m
 //若m=0，则返回NULL 
    PseqList L = (PseqList)malloc(sizeof( struct seqList));
    L->curNum = 0;
    L->MAXNUM = m;
    L->element = (DataType*)malloc(sizeof( struct seqList));
    return L;
}

//第二关
int isFullList_seq(PseqList L)
{
  //判断顺序线性表是否已满，若已满，返回值为1，否则返回值为0
 return L->curNum == L->MAXNUM;
 

}


int insertP_seq(PseqList L , int p ,int x)
{// 在线性表L中下标为p的位置插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
   //如果线性表满了， 还需输"list is full"的提示
  //如果插入位置非法，需输出提示"position is illegel" 
  if(p<0 || p>L->curNum) return 0;
  for(int i=L->curNum;i>p;i--)
    L->element[i] = L->element[i-1];
  L->element[p] = x ;
  L->curNum++;
  return 1;  
    
}

int insertPre_seq(PseqList L , int p ,int x)
{
 // 在线性表L中下标为p的位置的前面插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
//提示：直接调用insertP函数实现即可    
    return insertP_seq(L,p-1,x);
    
}

int insertPost_seq(PseqList L , int p ,int x)
{
 // 在线性表L中下标为p的位置的后面插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
//提示：直接调用insertP函数实现即可    
     return insertP_seq(L,p+1,x);
    
}

void printList_seq(PseqList L)
{//逐个输出线性表的元素 ,此处为了输出16进制的A-F 改写了输出函数 
/*正常情况下的输出函数 

 for(int i=0;i<=L->curNum-1;i++)
     	  printf("%d",L->element[i]+48);
	 */
 
   for(int i=L->curNum-1;i>=0;i--)
     if(L->element[i]<10)
       printf("%c",L->element[i]+48);
     else
	    printf("%c",L->element[i]+55);
	    
}

void convert(int data,int k)//将data转换为k进制并输出 
{
	int m = log2(data) ;
	PseqList L = createNullList_seq(m) ;
	int pos = 0;
	while(data)
	{
		insertP_seq(L,pos,data%k);
		data = data / k;
		pos++;
	}
  	printList_seq(L);
}




