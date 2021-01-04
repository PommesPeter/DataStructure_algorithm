#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*�˴���˳�����Ա����ݽṹ����*/
typedef int DataType;
struct seqList
{//��3�����ݳ�Ա
  int MAXNUM;//���ڼ�¼˳�����Ա����ܴ�ŵ����Ԫ�ظ����� ���� MAXNUM   
  int curNum;//���ڴ��˳�����Ա�������Ԫ�صĸ���  ����  curNum
  DataType *element;//���ڴ��˳�����Ա�����Ԫ�ص������ռ����ʼ��ַ  
};

typedef struct seqList *PseqList;
//��һ��
PseqList createNullList_seq(int m)
{//�˴���д���룬����һ���յ�˳�����Ա��ܴ�ŵ����Ԫ�ظ���Ϊ m
 //��m=0���򷵻�NULL 
    PseqList L = (PseqList)malloc(sizeof( struct seqList));
    L->curNum = 0;
    L->MAXNUM = m;
    L->element = (DataType*)malloc(sizeof( struct seqList));
    return L;
}

//�ڶ���
int isFullList_seq(PseqList L)
{
  //�ж�˳�����Ա��Ƿ�������������������ֵΪ1�����򷵻�ֵΪ0
 return L->curNum == L->MAXNUM;
 

}


int insertP_seq(PseqList L , int p ,int x)
{// �����Ա�L���±�Ϊp��λ�ò�������Ԫ��x�����±�p�Ƿ������Ա������޷��������ݣ�����0������ɹ�����ֵΪ1
   //������Ա����ˣ� ������"list is full"����ʾ
  //�������λ�÷Ƿ����������ʾ"position is illegel" 
  if(p<0 || p>L->curNum) return 0;
  for(int i=L->curNum;i>p;i--)
    L->element[i] = L->element[i-1];
  L->element[p] = x ;
  L->curNum++;
  return 1;  
    
}

int insertPre_seq(PseqList L , int p ,int x)
{
 // �����Ա�L���±�Ϊp��λ�õ�ǰ���������Ԫ��x�����±�p�Ƿ������Ա������޷��������ݣ�����0������ɹ�����ֵΪ1
//��ʾ��ֱ�ӵ���insertP����ʵ�ּ���    
    return insertP_seq(L,p-1,x);
    
}

int insertPost_seq(PseqList L , int p ,int x)
{
 // �����Ա�L���±�Ϊp��λ�õĺ����������Ԫ��x�����±�p�Ƿ������Ա������޷��������ݣ�����0������ɹ�����ֵΪ1
//��ʾ��ֱ�ӵ���insertP����ʵ�ּ���    
     return insertP_seq(L,p+1,x);
    
}

void printList_seq(PseqList L)
{//���������Ա��Ԫ�� ,�˴�Ϊ�����16���Ƶ�A-F ��д��������� 
/*��������µ�������� 

 for(int i=0;i<=L->curNum-1;i++)
     	  printf("%d",L->element[i]+48);
	 */
 
   for(int i=L->curNum-1;i>=0;i--)
     if(L->element[i]<10)
       printf("%c",L->element[i]+48);
     else
	    printf("%c",L->element[i]+55);
	    
}

void convert(int data,int k)//��dataת��Ϊk���Ʋ���� 
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




