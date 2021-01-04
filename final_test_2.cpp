#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

typedef int DataType;
struct hashdata //hash表结构
{
    int num;//hash表长度
    DataType *element;
};

typedef struct hashdata *phash;

phash InitHashTable(int n) {
    //请在此处填入代码， 初始化哈希表 注意初始化时，未装填数据哈希表填入-1
    /**********  Begin  *********/
    auto ht = new struct hashdata;
    ht->element = new DataType[n];
    for (int i = 0; i < n; i++) {
        ht->element[i] = -1;
    }
    ht->num = n;
    return ht;
    /**********  End  *********/
}

int hashFun(int data) //hash函数
{
    return data % 11;
}

void InsertHash(phash H, int data) {
    //请在此处填入代码，调用hashFun计算哈希地址，将数据data装填到哈希表中对应地址 处，处理冲突的方法是线性探查法
    /**********  Begin  *********/
    int hash_key = hashFun(data);
    for (int k = hash_key; k < H->num;) {
        if (H->element[k] != -1) {
            k++;
        } else if (H->element[k] == -1){
            H->element[k] = data;
            break;
        }
    }

    /**********  End  *********/
}

void Print(phash H) //输出哈希表
{
    for (int i = 0; i < H->num; i++) {
        cout << H->element[i] << " ";
    }
}

int main() {
    phash H = InitHashTable(11); //初始化哈希表
    int d;
    for (int i = 0; i < 7; i++) //输入7个元素，装填到哈希表中
    {
        cin >> d;
        InsertHash(H, d);
    }
    Print(H); //输出哈希表
}
