#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct node
{
    char data;
    struct node *next;
};
typedef struct node *Node;
// 自己定义需要的栈结构，及栈基本操作函数，假设操作数都是整数
struct stack
{
    Node symbol_top;
};
typedef struct stack *Stack;
int result(int n, int m, int a, int x)
{
    int i, j = 1, last, up_2, up_1, up, down, temp;
    if (x == n - 1)
        return m;
    else if (x == 1 || x == 2)
        return a;
    else
    {
        while (1)
        {
            last = a;
            up_2 = a;
            up_1 = j;
            for (i = 2; i < n - 1; i++)
            {
                up = up_2 + up_1;
                down = up_1;
                last = last + up - down;
                up_2 = up_1;
                up_1 = up;
                if (i + 1 == x)
                    temp = last;
            }
            if (last == m)
                break;
            j++;
        }
    }
    return temp;
}

Node createNode(char a)
{
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = a;
    return newNode;
}

int priority(char symbol)
{
    if (symbol == '+' || symbol == '-')
        return 1;
    else if (symbol == '*')
        return 2;
    else if (symbol == '/')
        return 3;
    else
        return -1;
}
void push_node(Stack L, char a)
{
    // 入栈
    Node newNode = createNode(a);
    newNode->next = L->symbol_top;
    L->symbol_top = newNode;
}
void pop_stack(Stack L, Stack result)
{
    // 弹出所有的栈内元素
    Node q;
    while (L->symbol_top != NULL)
    {
        if (L->symbol_top->data == '(')
        {
            q = L->symbol_top;
            L->symbol_top = L->symbol_top->next;
            free(q);
            break;
        }
        else
        {
            push_node(result, L->symbol_top->data);
            q = L->symbol_top;
            L->symbol_top = L->symbol_top->next;
            free(q);
        }
    }
}

char pop_node(Stack L)
{
    char temp = L->symbol_top->data;
    Node p = L->symbol_top;
    L->symbol_top = p->next;
    free(p);
    return temp;
}

Stack change(Stack result)
{
    char temp;
    Stack new_result = (Stack)malloc(sizeof(struct stack));
    while (result->symbol_top != NULL)
    {
        temp = pop_node(result);
        push_node(new_result, temp);
    }
    return new_result;
}

/*
   第二关
   函数名：inToPost，本函数名和参数不能更改
   函数功能：将中缀表达式转换为后缀表达式输出
   函数参数：中缀表达式，放在字符数组中
   返回值：返回放有后缀表达式的栈
*/
Stack inToPost(char *expression)
{
    //在此处填写代码，完成中缀表达式转换为后缀表达式并输出
    /**********  Begin  **********/
    int i;
    Stack symbol = (struct stack *)malloc(sizeof(struct stack));
    symbol->symbol_top = NULL;
    Stack result = (struct stack *)malloc(sizeof(struct stack));
    result->symbol_top = NULL;
    for (i = 0; expression[i] != '\0'; i++)
    {
        if ('0' <= expression[i] && expression[i] <= '9')
        {
            while ('0' <= expression[i] && expression[i] <= '9')
            {
                push_node(result, expression[i]);
                i++;
            }
            push_node(result, '#');
            i--;
            printf(" ");
            if (expression[i + 1] == '\0')
                pop_stack(symbol, result);
            continue;
        }
        else
        {
            if ('(' == expression[i])
                push_node(symbol, expression[i]);
            else if (')' == expression[i])
                pop_stack(symbol, result);
            else if (symbol->symbol_top == NULL || priority(expression[i]) > priority(symbol->symbol_top->data))
                push_node(symbol, expression[i]);
            else
            {
                pop_stack(symbol, result);
                push_node(symbol, expression[i]);
            }
        }
        if (expression[i + 1] == '\0')
            pop_stack(symbol, result);
    }
    return result;
    /**********  End  **********/
}
//print函数用于输出后缀表达式，参数是 inToPost的返回值

void print(Stack s)
{
    int a = 0;
}

void caculation(int num[], int *count, char a)
{
    int result;
    switch (a)
    {
        case '+':
            result = num[*count - 1] + num[*count];
            break;
        case '-':
            result = num[*count - 1] - num[*count];
            break;
        case '*':
            result = num[*count - 1] * num[*count];
            break;
        case '/':
            result = num[*count - 1] / num[*count];
            break;
    }
    *count = *count - 1;
    num[*count] = result;
}
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
    Stack result = inToPost(express);
    char str[100], temp;
    int i = 0;
    Node q;
    while (result->symbol_top != NULL)
    {
        str[i] = result->symbol_top->data;
        i++;
        q = result->symbol_top;
        result->symbol_top = q->next;
        free(q);
    }
    str[i] = '\0';
    for (i = 0; i < strlen(str) / 2; i++)
    {
        temp = str[i];
        str[i] = str[strlen(str) - 1 - i];
        str[strlen(str) - 1 - i] = temp;
    }
    int num[10];
    int count = -1;
    int data = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
            data = data*10 + str[i] - '0';
        else if (str[i] == '#')
        {
            count++;
            num[count] = data;
            data = 0;
        }
        else
        {
            caculation(num, &count, str[i]);
        }
    }
    return num[0];
    /**********  End  **********/
}