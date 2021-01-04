#include <stdio.h>
#include <stdlib.h>

/*�˴�����ջ���ݽṹ����*/
typedef int DataType;
struct node 
{
  DataType  info;
  struct node  *link;
};

typedef struct node *PNode;

struct LinkStack {
   PNode  top;
};
typedef struct LinkStack *PLinkStack;

//��һ��
PLinkStack createNullStack_link( )
{//�˴���д���룬����һ���յ���ջ 
 PLinkStack head = (struct LinkStack*)malloc(sizeof(struct LinkStack));

 head->top = NULL;
 return head;
     
}

//�ڶ���
int isNullStack_link(PLinkStack L)
{
  //�ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ�����ֵΪ1�����򷵻�ֵΪ0,��ջ�����ڣ��򷵻�-1
  if(L==NULL) return -1;
  if(L->top== NULL) return 1;
  else return 0;
}




//������
int push_link(PLinkStack L ,DataType x)
{//��ջ�в�������Ԫ��x�������벻�ɹ�������0������ɹ�����ֵΪ1
    PNode p = (struct node*)malloc(sizeof(struct node));
    p->info  = x ;
    p->link = L->top;
    L->top = p;
    return 1;
}
 


//���Ĺ�
DataType pop_link(PLinkStack L)
{//��ջ������ɾ��Ԫ�أ���ջΪ�գ��򷵻�-1
    if(isNullStack_link(L)) return -1;
    struct node *p = L->top ;
    DataType x = p->info ;
    L->top = p->link;
    free(p);
    return x ;
}

//�����
DataType top_link(PLinkStack L)
{// ȡջ��Ԫ�ط��أ���ջΪ�գ��򷵻�-1
    if(L->top == NULL) return -1;
    return L->top->info ;
}


//����ջ���ͷ�ջ��ռ�洢�ռ�
int destroystack_link(PLinkStack L)
{
    //����ֵΪ���ٵ�ջ����������Ԫ�صĸ������������ٵ����Ա����ڣ��򷵻�0
    int cnt =0 ;
    if(L==NULL) return 0;
    struct node *p = L->top ,*q ;
    free(L);
    while(p!=NULL)
    {
       q = p->link;
       cnt++;
       free(p);
       p = q ;
    }
    return cnt ;
}

//������

int  balance_symbol(char *s)
{//�ڴ˴���д������ɷ�������жϣ�����ԣ�����ֵΪ1�����򷵻�ֵΪ0
   PLinkStack L = createNullStack_link();
   int i = 0 ,t ;
   while(*(s+i)!='\0')
   {
     if(*(s+i)=='(' )push_link(L,40);
     else if( *(s+i)=='[')push_link(L,91);
     else if( *(s+i)=='{')push_link(L,123);
     else   if( *(s+i)==')' ||  *(s+i)==']' ||  *(s+i)=='}')
     {
       t = pop_link(L);
       
       if(*(s+i)==')' && t!=40 )  return 0;
       else if( *(s+i)==']' && t!=91) return 0;
       else if( *(s+i)=='}' && t!=123)return 0;
       }
     
      i++;  
   }
   
   if(isNullStack_link(L)) return 1;
   else return 0;
}















