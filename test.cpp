#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// 自己定义需要的栈结构，及栈基本操作函数，假设操作数都是整数
struct stack
{
    int top;
    int max;
    char *element;
};
typedef struct stack *Stack;

/*在此定义并完成第一关函数，参考main要求*/



/*
   第二关
   函数名：inToPost，本函数名和参数不能更改
   函数功能：将中缀表达式转换为后缀表达式输出
   函数参数：中缀表达式，放在字符数组中
   返回值：返回放有后缀表达式的栈
*/
//在此处填写代码，完成中缀表达式转换为后缀表达式并输出
/**********  Begin  **********/
int Priority(char ch) // 优先级
{
    int level = 0;
    switch(ch)
    {
        case '+':
            level = 0;
            break;
        case '-':
            level=1;
            break;
        case '*':
            level = 2;
            break;
        case '/':
            level = 3;
            break;
    }
    return level;
}
void push(Stack pastack,char x )
{
    pastack->element[pastack->top+1] = x ;
    pastack->top++;
    return ;
}
void pop(Stack pastack)
{
    pastack->top--;
    return ;
}
//中缀转后缀
//输入123*3/2+3*45
//输出123 3 2 / * 3 45 * +
//123 3 * 2 / 3 45 * +
Stack inToPost(char *expression)
{
    int i,j;
    char a[50];
    int max=sizeof(expression);
    Stack pastack;
    pastack=(Stack)malloc(sizeof(struct stack));
    pastack->element=(char*)malloc(sizeof(char)*2);
    pastack->top=-1;

    i=0;
    j=0;
    while(i<=max)
    {
        if(expression[i]>='0'&& expression[i]<='9')
        {
            while(expression[i]>='0'&& expression[i]<='9')
            {
                a[j]=expression[i];
                j++;
                i++;
            }
            a[j]=' ';
            j++;
        }
        else
        {
            if(pastack->top==-1||Priority(expression[i])>=Priority(pastack->element[pastack->top]))
            {
                push(pastack,expression[i]);
                i++;
            }
            else
            {
                while(Priority(expression[i])<Priority(pastack->top)||pastack->top==-1)
                {

                    if(pastack->top==-1)
                        break;
                    else
                    {
                        a[j]=pastack->element[pastack->top];
                        j++;
                        a[j]=' ';
                        i++;
                        pop(pastack);
                    }
                }
                push(pastack,expression[i]);
            }
        }
    }
    while(pastack->top!=-1)//将栈中剩余元素赋给a[]
    {
        a[i]=pastack->element[pastack->top];
        pastack->top=pastack->top-1;
        a[i+1]=' ';
        i=i+2;
    }

    while(pastack->top!=-1)//将栈清空
    {
        pop(pastack);
    }
    max=sizeof(a);
    for(i=max-1;i>=0;i--)//   a[]倒序进栈
    {
        pastack->top=pastack->top+1;
        pastack->element[pastack->top]=a[i];
    }
    return pastack;







    /*int temp,n=0;
    while(expression[i]!='\0')
    {
        temp=0;
        while(expression[i]>='0'&& expression[i]<='9')
        {
            temp=temp*10;
            temp=temp+expression[i]-48;
            i++;
        }
        a[n]=temp+48;
        n++;
        continue;
    }

   /**********  End  **********/
}

//print函数用于输出后缀表达式，参数是 inToPost的返回值

void print(Stack s)
{
    Stack p;
    p=s;
    while(p->top!=-1)
    {
        printf("%c",p->element[p->top]);
        p->top=p->top-1;
    }

}

//输入12+3*5-2+1
/*
   第三关
   函数名：calExp，本函数名和参数不能更改
   函数功能：调用inToPost函数求解后缀表达式，并求解后缀表达式的值返回
   函数参数：
   返回值：无
*/
int calExp(char *express)
{
    //在此处填写代码，完成表达式求值并输出
    /**********  Begin  **********/
    int i=0,x=0,x1,x2;
    Stack p;
    p=inToPost(express);

    while(express)
    {
        if(express[i]>='0'&& express[i]<='9')
        {
            while(express[i]>='0'&& express[i]<='9')
            {
                x=x*10+express[i]-'0';
                i++;
            }
            push(p,x);
        }
        else
        {
            x1=p->element[p->top];
            pop(p);
            x2=p->element[p->top];
            pop(p);
            switch(express[i])
            {
                case '+':x=x1+x2;break;
                case '-':x=x1-x2;break;
                case '*':x=x1*x2;break;
                case '/':x=x1/x2;break;
            }
            push(p,x);
            i++;
        }
    }
    return p->element[p->top];


    /**********  End  **********/
}
int main(void)
{
    char express[80];
    gets(express);

    // printf("%s",express);
    Stack s = inToPost(express);
    print(s);

}
