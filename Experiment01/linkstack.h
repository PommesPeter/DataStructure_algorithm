#include <stdio.h>
#include <stdlib.h>

/*此处是链栈数据结构定义*/
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

//第一关
PLinkStack createNullStack_link( )
{//此处填写代码，创建一个空的链栈 
 PLinkStack head = (struct LinkStack*)malloc(sizeof(struct LinkStack));

 head->top = NULL;
 return head;
     
}

//第二关
int isNullStack_link(PLinkStack L)
{
  //判断栈是否为空，若为空，返回值为1，否则返回值为0,若栈不存在，则返回-1
  if(L==NULL) return -1;
  if(L->top== NULL) return 1;
  else return 0;
}




//第三关
int push_link(PLinkStack L ,DataType x)
{//在栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    PNode p = (struct node*)malloc(sizeof(struct node));
    p->info  = x ;
    p->link = L->top;
    L->top = p;
    return 1;
}
 


//第四关
DataType pop_link(PLinkStack L)
{//弹栈并返回删除元素，若栈为空，则返回-1
    if(isNullStack_link(L)) return -1;
    struct node *p = L->top ;
    DataType x = p->info ;
    L->top = p->link;
    free(p);
    return x ;
}

//第五关
DataType top_link(PLinkStack L)
{// 取栈顶元素返回，若栈为空，则返回-1
    if(L->top == NULL) return -1;
    return L->top->info ;
}


//销毁栈，释放栈所占存储空间
int destroystack_link(PLinkStack L)
{
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
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

//第六关

int  balance_symbol(char *s)
{//在此处填写代码完成符号配对判断，若配对，返回值为1，否则返回值为0
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















