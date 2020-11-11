#include <cstdio>
#include <cstring>
using namespace std;

typedef struct {
    int weight;         // 结点权值?
    int parent, lc, rc; // 双亲结点和左 右子节点
} HTNode, *HuffmanTree;

void Select(HuffmanTree &HT, int n, int &s1, int &s2)
{
    int minum;      // 定义一个临时变量保存最小值?
    for(int i=1; i<=n; i++)     // 以下是找到第一个最小值
    {
        if(HT[i].parent == 0)
        {
            minum = i;
            break;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(HT[i].parent == 0)
            if(HT[i].weight < HT[minum].weight)
                minum = i;
    }
    s1 = minum;
    // 以下是找到第二个最小值，且与第一个不同
    for(int i=1; i<=n; i++)
    {
        if(HT[i].parent == 0 && i != s1)
        {
            minum = i;
            break;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(HT[i].parent == 0 && i != s1)
            if(HT[i].weight < HT[minum].weight)
                minum = i;
    }
    s2 = minum;
}

void CreatHuff(HuffmanTree &HT, int *w, int n)
{
    int m, s1, s2;
    m = n * 2 - 1;  // 总结点的个数
    HT = new HTNode[m + 1]; // 分配空间
    for(int i=1; i<=n; i++) // 1 - n 存放叶子结点，初始化
    {
        HT[i].weight = w[i];
        HT[i].parent = 0;
        HT[i].lc = 0;
        HT[i].rc = 0;
    }
    for(int i=n+1; i<=m; i++)   // 非叶子结点的初始化
    {
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lc = 0;
        HT[i].rc = 0;
    }

    printf("\nthe HuffmanTree is: \n");

    for(int i = n+1; i<=m; i++)     // 创建非叶子节点，建哈夫曼树
    {   // 在HT[1]~HT[i-1]的范围内选择两个parent为0且weight最小的两个结点，其序号分别赋值给 s1 s2
        Select(HT, i-1, s1, s2);
        HT[s1].parent = i;  // 删除这两个结点
        HT[s2].parent = i;
        HT[i].lc = s1;      // 生成新的树，左右子节点是 s1和s2
        HT[i].rc = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;   // 新树的权�?
        printf("%d (%d, %d)\n", HT[i].weight, HT[s1].weight, HT[s2].weight);
    }
    printf("\n");
}

int main2()
{
    HuffmanTree HT;

    int *w, n, wei;
    printf("input the number of node\n");
    scanf("%d", &n);
    w = new int[n+1];
    printf("\ninput the %dth node of value\n", n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &wei);
        w[i] = wei;
    }
    CreatHuff(HT, w, n);



    return 0;
}