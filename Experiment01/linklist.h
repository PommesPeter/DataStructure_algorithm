#include <stdio.h>
#include <stdlib.h>
//第一关代码

struct node
{//此处填写代码，定义链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    
    int data ;
    struct node *link;
};

/*此处添加一个代码，用于新建一个结点，返回值为结点指针*/
struct node *createNode(int data)
{
   struct node *p ;
   p = (struct node *)malloc(sizeof(struct node));
   if(p ==NULL) return NULL;
   p->data = data;
   p->link = NULL;
   return p;
 } 


struct node *mycreateList()
{//此处填写代码，创建一个只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
  
   struct node *head = createNode(0);
   return head;
}


//第二关代码

void myinsertHead(struct node * head, int insData )
{
	/*在此处完成任务，实现在head为表头d 链表的头插数据元素insData的功能*/
	//begin
   
	 struct node *p = createNode(insData);
	 p->link = head->link;
	 head->link = p ;
	 
	//end 
}

void myinsertTail(struct node *  head , int insData )
{
	/*在此处完成任务，在head为表头的单链表表尾插入数据元素insData*/
	//begin
   struct node *p = createNode(insData),*q = head;
   while(q->link!=NULL)
     q = q->link;
     
   q->link = p ;
	
	//end 	
}

void myprintList(struct node *L)
{
     /*在此处完成任务，输出head为表头链表中的数据，每输出一个数据换一行*/
	//begin
	struct node *p = L->link;
	while(p!=NULL)
	  {
	  	printf("%d\n",p->data);
	  	p = p->link;
	   } 
	
	//end 
    
}

//第三关代码
 void reverseList_link( struct node *L)
 {
    //请在此处填入代码，实现链表逆置功能 
 	//begin
 	struct node*p = L->link,*q;
 	L->link = NULL;
 	while(p!=NULL)
 	{
 		q = p->link ;
 		p->link = L->link;
 		L->link = p;
 		p = q ;
	 }
 	 
	//end 
 }


//第四关代码
int locateAndChange( struct node *L, int data)
 {
    //请在此处填入代码，在头结点为L的链表中查找 与data值相等的第一个结点，若能找到该结点，则将该结点的值与前驱结点的值交换
    //若未找到与data值相等的结点，则返回值为-1，若找到的结点无前驱结点，则返回值为0，否则返回值为前驱结点的值
 	//begin
 	if (L==NULL || L->link==NULL)  return -1 ;
 	struct node*p = L;
 	while(p!=NULL && p->link->data!=data)
       	 p = p->link;
    if(p==NULL) return -1;
	int t = p->data ;
	p->data = p->link->data;
	p->link->data = t;   	 
	//end 
 }

//第五关代码
int destroyList(struct node *L)
{
  //请在此处填写代码，实现将链表L的结点空间回收
 //返回值为回收结点的个数，含头结点在内   
 if (L==NULL) return 0;
 struct node *p = L->link ;
 int count = 0;
 while(L!=NULL)
  {
  	  free(L);
  	  count++;
  	  L = p ;
  	  p = p->link;
  }
  return count;

}



