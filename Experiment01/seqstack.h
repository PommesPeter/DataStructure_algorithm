#include <stdio.h>

/*�˴���˳��ջ���ݽṹ����*/
typedef int DataType;
struct seqStack
{//��3�����ݳ�Ա
  int MAXNUM;//���ڼ�¼˳��ջ���ܴ�ŵ����Ԫ�ظ����� ���� MAXNUM   
  int top;//���ڴ��˳��ջ��ջ��λ�ã���ʼ��Ϊ0��-1 ����  ����  curNum
  DataType *element;//���ڴ��˳��ջ����Ԫ�ص������ռ����ʼ��ַ  
};

typedef struct seqStack *PseqStack;
//��һ��
PseqStack createNullStack_seq(int m)
{//�˴���д���룬����һ���յ�˳��ջ���ܴ�ŵ����Ԫ�ظ���Ϊ m,ջ��top����Ϊ0
 //��m=0���򷵻�NULL 
 PseqStack s = (PseqStack)malloc(sizeof(struct seqStack ));
 s->MAXNUM = m;
 s->top = 0;
 s->element = (DataType *)malloc(sizeof(DataType));
 return s ;
    
}

//�ڶ���
int isNullStack_seq(PseqStack L)
{
  //�ж�˳��ջ�Ƿ�Ϊ�գ���Ϊ�գ�����ֵΪ1�����򷵻�ֵΪ0,��ջ�����ڣ��򷵻�-1
  if(L==NULL) return NULL;
  if(L->top==0) return 1;
  else return 0;
}


//������ 
int isFullStack_seq(PseqStack L)
{
  //�ж�˳��ջ�Ƿ�������������������ֵΪ1�����򷵻�ֵΪ0
    if(L->top==L->MAXNUM) return 1;
    else return 0;
}


//���Ĺ�
int push_seq(PseqStack L ,DataType x)
{//��˳��ջ�в�������Ԫ��x�������벻�ɹ�������0������ɹ�����ֵΪ1
    if(isFullStack_seq(L) == 1)
      return 0;
	L->element[L->top] = x ;
    L->top++;
    return 1;
    
}
 


//�����
DataType pop_seq(PseqStack L)
{//��ջ������ɾ��Ԫ�أ���ջΪ�գ��򷵻�-1
  if(isNullStack_seq(L) == 1)
      return -1;
  L->top--;
  return L->element[L->top];    
    
}

//������
DataType top_seq(PseqStack L)
{// ȡջ��Ԫ�ط��أ���ջΪ�գ��򷵻�-1
     if(isNullStack_seq(L) == 1)
      return -1;
     return L->element[L->top-1];    
}

//����˳��ջ���ͷ�ջ��ռ�洢�ռ�
int destroystack_seq(PseqStack L)
{
    //����ֵΪ���ٵ�ջ����������Ԫ�صĸ������������ٵ����Ա����ڣ��򷵻�0
    if(L==NULL) return 0;
    int num = L->top;
    free(L->element);
    free(L);
    return num;
}


//���߹�
//ʹ����ʵ�ֵ�ջ������ʵ������ת��

void print(PseqStack L)
{
//�������ջL�е�����Ԫ�ز������������ݼ䲻��Ҫ�κμ������
  int t ;
  while(isNullStack_seq(L)==0)
  {
  	t = pop_seq(L);
  	if(t<10)
  	    printf("%c",t+48);
     else
	    printf("%c",t+55);
  }

}

void convert(int data , int k)
{
//����ջʵ�ֽ�dataת��Ϊk���ƣ�k������2��8��16. �ڱ�������ʵ��ת��������print�������ת����Ľ��
//ʮ������ʱ��� A ,B ,C, D,E,F ʹ�ô�д��ĸ
PseqStack s = createNullStack_seq(100) ; // �˴��ɵ���log�����������λ������֤������ջ�㹻�ռ��Ҳ��˷ѣ��Լ�д 
 while(data��=0)
 {
 	 push_seq(s,data%k);
	 data = data / k ; 
 } 
 print(s);
}










