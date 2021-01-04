#include <stdio.h>
#include <stdlib.h>
//��һ�ش���

struct node
{//�˴���д���룬�������������ͣ�����һ������������ݵ� data ��Ա����һ��ָ����һ������next��Ա
    
    int data ;
    struct node *link;
};

/*�˴����һ�����룬�����½�һ����㣬����ֵΪ���ָ��*/
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
{//�˴���д���룬����һ��ֻ��һ��ͷ���Ŀ�����ͷ�ڵ��������ֵΪ0��������ͷ���ĵ�ַ����
  
   struct node *head = createNode(0);
   return head;
}


//�ڶ��ش���

void myinsertHead(struct node * head, int insData )
{
	/*�ڴ˴��������ʵ����headΪ��ͷd �����ͷ������Ԫ��insData�Ĺ���*/
	//begin
   
	 struct node *p = createNode(insData);
	 p->link = head->link;
	 head->link = p ;
	 
	//end 
}

void myinsertTail(struct node *  head , int insData )
{
	/*�ڴ˴����������headΪ��ͷ�ĵ������β��������Ԫ��insData*/
	//begin
   struct node *p = createNode(insData),*q = head;
   while(q->link!=NULL)
     q = q->link;
     
   q->link = p ;
	
	//end 	
}

void myprintList(struct node *L)
{
     /*�ڴ˴�����������headΪ��ͷ�����е����ݣ�ÿ���һ�����ݻ�һ��*/
	//begin
	struct node *p = L->link;
	while(p!=NULL)
	  {
	  	printf("%d\n",p->data);
	  	p = p->link;
	   } 
	
	//end 
    
}

//�����ش���
 void reverseList_link( struct node *L)
 {
    //���ڴ˴�������룬ʵ���������ù��� 
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


//���Ĺش���
int locateAndChange( struct node *L, int data)
 {
    //���ڴ˴�������룬��ͷ���ΪL�������в��� ��dataֵ��ȵĵ�һ����㣬�����ҵ��ý�㣬�򽫸ý���ֵ��ǰ������ֵ����
    //��δ�ҵ���dataֵ��ȵĽ�㣬�򷵻�ֵΪ-1�����ҵ��Ľ����ǰ����㣬�򷵻�ֵΪ0�����򷵻�ֵΪǰ������ֵ
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

//����ش���
int destroyList(struct node *L)
{
  //���ڴ˴���д���룬ʵ�ֽ�����L�Ľ��ռ����
 //����ֵΪ���ս��ĸ�������ͷ�������   
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



