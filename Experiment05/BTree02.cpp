#include <cstdlib>
#include <iostream>

using namespace std;
typedef char DataType;
//二叉树结点定义
//此处进行二叉树结构定义
/*-------begin------*/
struct node {
    DataType data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node BiTree;
typedef struct node *pTree;

/*-----end---------*/

void print(DataType d) {
    cout << d << " ";
}

//初始化二叉树的结点序列
int i = 0;
char treeData[] = "ABC##D##E#F#G##";

/*
函数名：createBiTree
函数功能：读取treeData 数组中的字符序列进行二叉树创建二叉树，并返回二叉树的根结点指针
参数：无
返回值：二叉树的根结点指针
*/

pTree createBiTree() {
    //在此处填入代码
    /*----------begin-------------*/
    pTree T;
    DataType c;
    c = treeData[i];
    i++;
    if (c == '#') {
        T = nullptr;
    } else {
        T = new BiTree;
        T->data = c;
        T->lchild = createBiTree();
        T->rchild = createBiTree();
    }
    return T;
    /*----------end-------------*/
}

void Sibling(pTree T) {
    //在此处填入代码,输出结点T的所有兄弟姐妹
    /*----------begin-------------*/
    if (T == nullptr) {
        return;
    }
    print(T->data);
    Sibling(T->lchild);
    Sibling(T->rchild);

    /*----------end-------------*/
}

/*
函数名：preOrder
函数功能：先根遍历二叉树 ，并找到值为ch的结点指针
参数：根结点指针 BiTree *T  ,需查找的结点值 ch
返回值：无
*/
void preOrder(pTree T, DataType c) {
    //在此处填入代码,利用先序遍历，找到结点值ch后调用函数sibling输出该结点的所有兄弟姐妹，以空格分界
    /*----------begin-------------*/
    if (T == nullptr) {
        return;
    }
    if (T->data == c) {
        Sibling(T);
    }
    preOrder(T->lchild, c);
    preOrder(T->rchild, c);
    /*----------end-------------*/
}


void preOrder(pTree T) {
    //在此处填入代码,利用先序遍历，找到结点值ch后调用函数sibling输出该结点的所有兄弟姐妹，以空格分界
    /*----------begin-------------*/
    if (T == nullptr) {
        return;
    }
    print(T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
    /*----------end-------------*/
}

int main() {
    pTree T;
    T = createBiTree(); //创建二叉树
//    preOrder(T);
    char ch;
    cin >> ch; //输入某人的代号
    preOrder(T, ch); //调用函数输出ch的所有兄弟姐妹

    return 0;
}  