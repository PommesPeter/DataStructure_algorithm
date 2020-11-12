# 二叉树

## 特殊二叉树

### 满二叉树
深度为k，有$2^{k+1}-1$个结点的二叉树
树中只有叶子结点和度为2的分支结点
所有叶子结点均在同一层

### 完全二叉树
倒数的两层可以有不满的节点，其他都得满

### 扩充二叉树
把二叉树中所有的叶都扩充成满二叉树

## 路径长度

### 外部路径长度

在扩充二叉树中，外部结点是扩充出来的，路径跟层数一致

### 内部路径长度


## 二叉树的性质

- 性质1：在二叉树的$i$层上至多有$2^i$个结点
- 性质2：高度为$k$的二叉树中最多有$2^{k+1}-1$个结点
- 性质3： 对于任何一棵二叉树，如果叶结点个数为$n_0$，度为$2$的结点个数为$n_2$，则有：$n_0 = n_2+ 1$，N=分支数+1 N=n1+n2*2+1 N为结点个数
- 性质4：具有n个结点的完全二叉树的深度k为\[log2n\]\(下取整\) 最多节点数2^{k+1}-1,最少2^k-1+1 (最下面一层只有一个结点)
- 性质5：对具有n个结点的完全二叉树，若按照从上（根结点）到下（叶结点）且每一层从左到右的顺序对二叉树中的所有结点从0进行编号，则对编号为i的结点有：
若i=0，则它是根结点；若i＞0，且其父结点的编号为[(i-1)/2]
若2i＋1≤n－1，则编号为i的结点的左孩子结点的编号为2i＋1；否则，编号为i的结点没有左孩子结点
若2i+2≤n－1，则编号为i的结点的右孩子结点的下标为2i+2；否则，编号为i的结点没有右孩子结点
- 性质6： 满二叉树的叶结点的数目比分支结点数目多1。
- 性质7：扩充二叉树中，外部结点的数目比内部结点的数目多1。
- 性质8：对任意扩充二叉树，外部路径长度E和内部路径长度I之间满足：E = I + 2n，其中n是内部结点个数
(需要懂证明)

## code

创建二叉树先扩充二叉树
先序访问左子树，遇到标志就结束，切换到右子树
1. 访问根
2. 遍历根的左子树
3. 遍历根的右子树

先根遍历 先遍历根
中根遍历 先遍历左子树，再遍历根，再遍历右子树
后根遍历 先遍历左子树，再遍历右子树，再遍历根

```c++
#include <iostream>
using namespace std;

typedef char DataType;

//二叉树数据结构 
struct node
{
	DataType info ; //存放结点数据 
	struct node *lchild , *rchild ; //指向左右孩子的指针 
};

typedef struct node *BiTree ;

/*创建二叉树
  函数名：createBiTree
  参数：无
  返回值：二叉树根结点指针
  */
BiTree createBiTree(void)
{
	//请在此处填写代码， 完成二叉树和创建，返回值是二叉树的根结点指针
    /********** Begin **********/
    DataType c;
    BinTree T;
    cin >> c;
    if (c == '#') {
        T = NULL;
    } else {
        T = new struct BinTreeNode;
        T->info = c;
        T->llink = createBinTree();
        T->rlink = createBinTree();
    }
    return T;
        
    /********** End *********/
}

void visit(BiTree T) //输出结点T的数据
{
	cout<<T->info ;
}

void inOrder(BiTree root)
{
	if(root == NULL) return ;
	inOrder(root->lchild);
	visit(root);
	inOrder(root->rchild);
}

int main(void)
{
	BiTree root = createBiTree();
	inOrder(root);
}

```