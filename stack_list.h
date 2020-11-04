#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 自己定义需要的栈结构，及栈基本操作函数，假设操作数都是整数
struct stack {
    int max_num;
    int top;
    char *element;
};
typedef struct stack *Stack;

/*在此定义并完成第一关函数，参考main要求*/
int result(int n, int m, int a, int x) {
    int f[1001] = {0};
    int t;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    t = (m - (f[n - 3] + 1) * a) / (f[n - 2] - 1);
    return (f[x - 2] + 1) * a + (f[x - 1] - 1) * t;
}

/*
   第二关
   函数名：inToPost，本函数名和参数不能更改
   函数功能：将中缀表达式转换为后缀表达式输出
   函数参数：中缀表达式，放在字符数组中
   返回值：返回放有后缀表达式的栈
*/
//123*3/2+3*45 123 3 2 / * 3 45 * +
Stack create_stack(int m) {
    Stack head = (Stack) malloc(sizeof(struct stack));
    if (head == NULL || m <= 0) {
        return NULL;
    }
    head->max_num = m + 1;
    head->top = 0;
    head->element = (char *) malloc(sizeof(char));
    return head;
}

int is_emptyStack(Stack s) {
    if (s->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

void push_back(Stack s, char x) {
    s->element[s->top] = x;
    s->top++;
}

char pop_back(Stack s) {
    s->top--;
    return s->element[s->top];
}

char top(Stack s) {
    return s->element[s->top - 1];
}

int priority(char c) {
    if (c == '+') {
        return 0;
    } else if (c == '-') {
        return 1;
    } else if (c == '*') {
        return 2;
    } else if (c == '/') {
        return 3;
    } else {
        return -1;
    }
}

int *discriminate_charnum(char *expression) {
    int count = 0;
    char temp[10];
    int t_num[10] = {0};
    int num = 0;
    int m = 0;
    for (int i = 0; i <= strlen(expression); i++) {
        if (expression[i] > '0' && expression[i] <= '9') {
            temp[count] = expression[i];
            count++;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' ||
                   expression[i] == '\0') {
            for (int j = 0; j < count; j++) {
                if (j == count - 1) {
                    num += (temp[j] - '0');
                    break;
                }
                num += (temp[j] - '0');
                num *= 10;
            }
            printf("%d ", num);
            t_num[m++] = num;
            num = 0;
            count = 0;
        }
    }
    return t_num;
}

//123*3/2+3*45
Stack inToPost(char *expression) {
    //在此处填写代码，完成中缀表达式转换为后缀表达式并输出
    /**********  Begin  **********/
    Stack num = create_stack(strlen(expression));
    Stack operators = create_stack(strlen(expression));
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            push_back(num, expression[i]);
            if (expression[i + 1] == '+' || expression[i + 1] == '-' || expression[i + 1] == '*' ||
                expression[i + 1] == '/') {
                push_back(num, '#');
            }
        } else if (expression[i] == '(') {
            push_back(operators, expression[i]);
        } else if (is_emptyStack(operators) == 1) {
            push_back(operators, expression[i]);
        } else if (is_emptyStack(operators) == 0 && priority(top(operators)) > priority(expression[i])) {
            while (operators->top != 0) {
                push_back(num, pop_back(operators));
                push_back(num, '#');
            }
            push_back(operators, expression[i]);
        } else if (is_emptyStack(operators) == 0 && priority(top(operators)) <= priority(expression[i])) {
            push_back(operators, expression[i]);
        } else if (expression[i] == ')') {
            while (top(operators) != '(') {
                push_back(num, pop_back(operators));
            }
            if (top(operators) == '(') {
                char *c = (char *) pop_back(operators);
                free(c);
            }
        }
    }
    push_back(num, '#');
    while (!is_emptyStack(operators)) {
        push_back(num, pop_back(operators));
        push_back(num, '#');
    }
    return num;
    /**********  End  **********/
}

//print函数用于输出后缀表达式，参数是 inToPost的返回值
void print(Stack s) {
    for (int i = 0; i < s->top; i++) {
        if (s->element[i] == '#') {
            s->element[i] = ' ';
        }
        printf("%c", s->element[i]);
    }
}
/*
   第三关
   函数名：calExp，本函数名和参数不能更改
   函数功能：调用inToPost函数求解后缀表达式，并求解后缀表达式的值返回
   函数参数：
   返回值：无
*/
int calExp(char *expression) {
    //在此处填写代码，完成表达式求值并输出
    /**********  Begin  **********/
    int temp, m = 0, num = 0;
    Stack s = inToPost(expression);
    s->top = 0;
    int *t_num = (int *) malloc(sizeof(int) * strlen(s->element));
    // replace '#' to ' '
    for (int i = 0; s->element[i] != '\0'; i++) {
        if (s->element[i] == '#') {
            s->element[i] = ' ';
        }
    }
    //Convert char_num to int_num
    for (int i = 0; i < strlen(s->element); i++) {
        if (s->element[i] != ' ') {
            if (s->element[i + 1] == ' ') {
                num += (s->element[i] - '0');
                t_num[m++] = num;
                num = 0;
                continue;
            }
            num += (s->element[i] - '0');
            num *= 10;
        }
    }
    num = 0;
    m = 0;
    // calculate the result
    for (int i = 0; i < strlen(s->element); i++) {
        if (s->element[i] >= '0' && s->element[i] <= '9') {
            if (s->element[i + 1] == ' ') {
                num += (s->element[i] - '0');
                t_num[m++] = num;
                num = 0;
                continue;
            }
            num += (s->element[i] - '0');
            num *= 10;
        } else if (s->element[i] == '+' || s->element[i] == '-' || s->element[i] == '*' || s->element[i] == '/') {
            int cal_temp;
            switch (s->element[i]) {
                case '+':
                    temp = t_num[--m];
                    cal_temp = t_num[--m] + temp;
                    t_num[m++] = cal_temp;
                    break;
                case '-':
                    temp = t_num[--m];
                    cal_temp = t_num[--m] - temp;
                    t_num[m++] = cal_temp;
                    break;
                case '*':
                    temp = t_num[--m];
                    cal_temp = t_num[--m] * temp;
                    t_num[m++] = cal_temp;
                    break;
                case '/':
                    temp = t_num[--m];
                    cal_temp = t_num[--m] / temp;
                    t_num[m++] = cal_temp;
                    break;
            }
        }
    }
//    printf("%d", cal_s->element[0]);
    return t_num[0];
    /**********  End  **********/
}
