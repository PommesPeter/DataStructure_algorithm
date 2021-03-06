#include <cstdio>
#include <cstdlib>
#include <cstring>

/*此处是顺序线性表数据结构定义*/
typedef int DataType;
struct seqList {//有3个数据成员
    int MAXNUM;//用于记录顺序线性表中能存放的最大元素个数的 整型 MAXNUM
    int curNum;//用于存放顺序线性表中数据元素的个数  整型  curNum
    DataType *element;//用于存放顺序线性表数据元素的连续空间的起始地址
};

typedef struct seqList *PseqList;

/*创建空的顺序线性表，能存放的最大元素个数为 m*/
PseqList createNullList_seq(int m) { //若m=0，则返回NULL
    PseqList plist = (struct seqList *) malloc(sizeof(struct seqList));
    if (plist == NULL) return NULL; //分配空间失败
    plist->MAXNUM = m;
    plist->curNum = 0;
    plist->element = (DataType *) malloc(sizeof(DataType) * m);
    if (plist->element == NULL) {
        free(plist);
        return NULL;
    }
    return plist;
}


/*在线性表表尾插入数据元素,返回值0表示插入失败，返回值1表示在表尾插入成功*/
int insertP_tail(PseqList plist, int x) {
    if (plist->curNum == plist->MAXNUM) //若表满，则无法插入
    {
        printf("list if full !");
        return 0;
    }
    plist->element[plist->curNum] = x;
    plist->curNum++;
    return 1;

}

/*回收线性表占用的空间*/
int destroyList_seq(PseqList plist) {
    //返回值为销毁的线性表中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (plist == NULL) return 0;
    int m = plist->curNum;
    free(plist->element);
    free(plist);
    return m;

}

void printList_seq(PseqList plist) {//逐个输出线性表的元素，相邻的两个数据元素之间以一个空格为分隔符隔开
    for (int i = 0; i < plist->curNum; i++)
        printf("%d ", plist->element[i]);
}

//第一关:求顺序线性表中连续子表（最少有一个元素）的最大和并输出
//前缀和
int seqMaxSum(PseqList plist) {
    int max = 0;
    int max_sum = 0;
    for (int i = 0; i < plist->curNum; i++) {
        int cur_sum = 0;
        for (int j = i; j < plist->curNum; j++) {
            cur_sum += plist->element[j];
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
            }
        }
    }
    return max_sum;
}

//第二关：寻找线性表中没有出现的最小的正整数
int findMinNumber(PseqList plist) {
    //若线性表为空，则返回0
    //定义一个数据结构要有他的操作类型、数据对象(抽象数据类型)
    for (int i = 0; i < plist->curNum; i++) {
        while (plist->element[i] > 0 && plist->element[i] <= plist->curNum &&
               plist->element[plist->element[i] - 1] != plist->element[i]) {
            int t = plist->element[plist->element[i] - 1];
            plist->element[plist->element[i] - 1] = plist->element[i], plist->element[i] = t;
        }
        for (int i = 0; i < plist->curNum; i++) {
            if (plist->element[i] != i + 1) {
                return i + 1;
            }
        }
    }
    return plist->curNum + 1;
}
//wjy第二关：寻找线性表中没有出现的最小的正整数
int findMinNumber_(PseqList plist) {
    if (plist == NULL || plist->MAXNUM == 0 || plist->curNum == 0) return 0;
    // 开一个数组，是0~curNum
    // 意思是长度为5的数组，最小缺少的正整数就是1~5，如果都出现了，那就是6
    int *mark = (int *)malloc(sizeof(int) * (plist->curNum + 1));
    memset(mark, 0, sizeof(int) * (plist->curNum + 1));
    for (int i = 0; i < plist->curNum; ++i) {
        // 非法数字，肯定不是，防止数组越界不处理
        if (plist->element[i] <= 0 || plist->element[i] > plist->curNum) {
            continue;
        }
        mark[plist->element[i]] = 1;
    }
    for (int i = 1; i <= plist->curNum; ++i) {
        if (mark[i] == 0) return i;
    }
    return plist->curNum + 1;
}

//第三关：找出给定目标值target在有序线性表中出现的起始位置和结束位置
void findPos(PseqList plist, int target, int *pos) {
//起始位置放在pos[0], 结束位置放在pos[1]
    pos[0] = -1;
    pos[1] = -1;
    //特殊情况
    if (plist->element[0] == plist->element[plist->curNum - 1]) {
        pos[0] = 0;
        pos[1] = plist->curNum - 1;
    }
    int low = 0, high = plist->curNum - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (plist->element[mid] > target) {
            high = mid - 1;
        } else if (plist->element[mid] < target) {
            low = mid + 1;
        } else {
            int flag = 0;
            while (low < mid && flag == 0) {
                if (target != plist->element[low] && target != plist->element[low + 1] && target != plist->element[low - 1]) {
                    if (plist->element[(low + mid) / 2] < target) {
                        low = (high + mid) / 2 + 1;
                    }
                } else {
                    flag = 1;
                }
            }
            pos[0] = low;
            flag = 0;
            while (high > mid && flag == 0) {
                if (target != plist->element[high]) {
                    // high--;
                    if (plist->element[(high + mid) / 2] > target) high = (high + mid) / 2 - 1;
                } else {
                    flag = 1;
                }
            }
            pos[1] = high;
            break;
        }
    }
}


int main()
{
    int num , data ;
    scanf("%d",&num);
    PseqList plist = createNullList_seq(num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&data);
        insertP_tail( plist ,data);
    }
    printf("%d",findMinNumber(plist));
}