#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
// 8 19 21 2 3 6 7 10 32
using namespace std;
//哈夫曼树定义
typedef struct {
    int weight;
    int parent, lchild, rchild;
    string code;
} node, *HuffmanTree;

typedef struct {
    int start;
    int code[100];
}code, *HuffmanCode;

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
HuffmanTree create_huffmantree(HuffmanTree T, int n) {
    //初始化
    int m = 2 * n - 1, s1, s2;        //m为所有结点的个数
    T = new node[m + 1];                //0号不用从1开始，多申请一行，前1~n存放叶子结点
    for (int i = 1; i <= m; ++i) {  //遍历每一个结点并赋值为0
        T[i].parent = 0;
        T[i].lchild = 0;
        T[i].rchild = 0;
    }
    //创建树
    //把叶子结点权值放入表中
    for (int i = 1; i <= n; ++i) {
//        cout << "请输入第" << i << "个叶子：" << endl;
        cin >> T[i].weight;
    }
    //从非叶子结点开始创建
    for (int i = n + 1; i <= m; ++i) {
        Select(T, i - 1, s1, s2);        //选择两个最小的结点
        //先用数组的一半存所有节点，然后从第n+1个开始创建
        //优先队列更快？ todo: convert to priority queue
        T[s1].parent = i;  //找到权值最小的两个节点的下标，把叶子结点的双亲域赋上
        T[s2].parent = i;
        T[i].lchild = s1;  //将上面生成的父节点的孩子域赋值为双亲
        T[i].rchild = s2;
        T[i].weight = T[s1].weight + T[s2].weight;   //计算权值
    }
//    printf("\nHT的终态\n");
    println(T, m);
    return T;
}

string *encoding_huffman_code(HuffmanTree T, int n) {
    size_t m = 2 * n - 1;
    auto T_code = new code[n];
    code temp;
    for (int i = 1; i <= m; i++) {
        temp.start = n - 1;
        DataType c = i;
        DataType p = T[i].parent;
        while (p != 0) {
            if (T[p].lchild == c) {
                temp.code[temp.start] = 0;
            } else {
                temp.code[temp.start] = 1;
            }
            temp.start--; //求低一位
            c = p;  // 保存父节点
            p = T[c].parent;
        }

        for (int j = temp.start + 1; j < n; j++) {
            T_code[i].code[j] = temp.code[j];
        }
        T_code[i].start = temp.start;
    }
    for (int i = 0; i < n; i++) {
        cout << i << " 's Huffman code is: ";
//        cout << T_code[i].code.substr(T_code[i].start + 1, T_code[i].code.size());
        for (int j = T_code[i].start + 1; j < n; j++) {
            printf ("%d", T_code[i].code[j]);
        }
        cout << " start: " << T_code[i].start << endl;
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
    HT = create_huffmantree(HT, n);
    encoding_huffman_code(HT, n);
    return 0;
}
