#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
//哈夫曼树定义
typedef struct {
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef int DataType;

//选择两个双亲域为0且权值最小的结点，并返回在HT中的序号s1，s2
void Select(HuffmanTree &HT, int n, int &s1, int &s2) {
    //寻找第一个双亲域为0且权值最小的结点
    int min;
    for (int i = 1; i <= n; i++)    //找到第一个双亲域为0的，下标暂存到min
    {
        if (HT[i].parent == 0) {
            min = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (HT[i].parent == 0) {
            if (HT[i].weight < HT[min].weight) {
                min = i;
            }
        }
    }
    s1 = min;

    //寻找第二个双亲域为0且权值最小的结点
    for (int i = 1; i <= n; i++)    //找到第一个双亲域为0的，下标暂存到min
    {
        if (HT[i].parent == 0 && i != s1) {
            min = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (HT[i].parent == 0 && i != s1) {
            if (HT[i].weight < HT[min].weight) {
                min = i;
            }
        }
    }
    s2 = min;
}

//输出
void println(HuffmanTree &HT, int m) {
    cout << "==============================" << endl;
    for (int i = 1; i <= m; i++) {
        printf("%d,   ", i);
        printf("%d   ", HT[i].weight);
        printf("%d   ", HT[i].parent);
        printf("%d  ", HT[i].lchild);
        printf("%d   \n", HT[i].rchild);
        cout << "==============================" << endl;
    }
}

//创建哈夫曼树
void create_huffmantree(HuffmanTree HT, int n) {
    //初始化
    int m = 2 * n - 1, s1, s2;        //m为所有结点的个数
    HT = new HTNode[m + 1];                //0号不用从1开始，多申请一行，前1~n存放叶子结点
    for (int i = 1; i <= m; ++i)            //遍历每一个结点并赋值为0
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    //创建树
    //把叶子结点权值放入表中
    for (int i = 1; i <= n; ++i) {
//        cout << "请输入第" << i << "个叶子：" << endl;
        cin >> HT[i].weight;
    }
    //从非叶子结点开始创建
    for (int i = n + 1; i <= m; ++i) {
        Select(HT, i - 1, s1, s2);        //选择两个最小的结点
        //先用数组的一半存所有节点，然后从第n+1个开始创建
        //优先队列更快？ todo: convert to priority queue
        HT[s1].parent = i;  //找到权值最小的两个节点的下标，把叶子结点的双亲域赋上
        HT[s2].parent = i;
        HT[i].lchild = s1;  //将上面生成的父节点的孩子域赋值为双亲
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;   //计算权值
    }
//    printf("\nHT的终态\n");
    println(HT, m);
}

string *encoding_huffman_code(HuffmanTree T, int n) {
    size_t m = 2 * n - 1;
    for (int i = 1; i <= m; i++) {
        
    }
}

int main() {
    HuffmanTree HT;
    DataType n; //n为叶子节点的个数
//    cout << "请输入叶子节点的个数：" << endl;
    cin >> n;
    if (n <= 1) {
        cout << "输入节点个数错误，程序结束" << endl;
        return 0;
    }
    create_huffmantree(HT, n);
    return 0;
}
