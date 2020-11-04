#include <iostream>
#include <vector>

using namespace std;

typedef char DataType;

//二叉树数据结构
struct node {
    DataType info; //存放结点数据
    struct node *lchild, *rchild; //指向左右孩子的指针
};
int count = 0;
typedef struct node *BiTree;

/*创建二叉树
  函数名：createBiTree
  参数：无
  返回值：二叉树根结点指针
  */
BiTree createBiTree(void) {
    char ch;
    BiTree root;
    cin >> ch;
    if (ch == '#') root = nullptr;
    else {
        root = new struct node;
        root->info = ch;
        root->lchild = createBiTree();
        root->rchild = createBiTree();
    }
    return root;
}

//AB##C##
int countFullNode(BiTree root) {
    //请在此处填写代码，计算二叉树中满结点的个数
    /********** Begin **********/
    if (root == nullptr) {
        return 0;
    } else if (root->lchild == nullptr && root->rchild == nullptr) {
        return 0;
    } else if (root->lchild == nullptr && root->rchild != nullptr) {
        count = countFullNode(root->rchild);
    } else if (root->lchild != nullptr && root->rchild == nullptr) {
        count = countFullNode(root->lchild);
    } else {
        count = 1 + countFullNode(root->lchild) + countFullNode(root->rchild);
    }
    return count;
    /*********** End-**********/
}

int main() {
    BiTree root = createBiTree();
    cout << countFullNode(root);
}
