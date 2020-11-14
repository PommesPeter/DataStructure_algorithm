#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iomanip>

using namespace std;
// 8 19 21 2 3 6 7 10 32
// 7 9 6 2 3 7 10 8
//9 00
//10 01
//2 1000
//3 1001
//6 101
//7 110
//8 111
typedef int DataType;
struct node {
    int weight;
    int parent;
    int lchild, rchild;
};

struct tree {
    int max_num;
    int cur_num;
    struct node* element;
};

typedef struct node node;
typedef struct tree HTree;
typedef HTree *pHTree;

priority_queue<DataType, vector<DataType>, greater<DataType>> find_min(pHTree T, priority_queue<DataType, vector<DataType>, greater<DataType>> q, int* s_1, int* s_2, DataType n) {
    for (int i = 0;i < n; i++) {
        if (T->element[i].weight == q.top()) {
            *s_1 = i;
            break;
        }
    }
    q.pop();
    for (int i = 0; i < n; i++) {
        if (T->element[i].weight == q.top()) {
            *s_2 = i;
            break;
        }
    }
    q.pop();
    return q;
}

pHTree create_huffmantree(pHTree T, DataType* w, priority_queue<DataType, vector<DataType>, greater<DataType> > q, DataType n) {
    T->element = new node[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++) {
        T->element[i].parent = 0;
        T->element[i].lchild = 0;
        T->element[i].rchild = 0;
    }
    for (int i = 0; i < n; i++) {
        T->element[i].weight = w[i];
    }
    for (int i = n; i < 2 * n - 1; i++) {
        int i_1, i_2;
        q = find_min(T, q, &i_1, &i_2, n);
        T->element[i_1].parent = i;
        T->element[i_2].parent = i;
        T->element[i].lchild = i_1;
        T->element[i].rchild = i_2;
        T->element[i].weight = T->element[i_1].weight + T->element[i_2].weight;
        q.push(T->element[i].weight);
    }
    return T;
}

string* decode_huffmantree(pHTree T, int n) {
    auto result = new string[n];
    std::size_t m = n - 1;
    for (int i = 0;i < n - 1; i++) {
        if (T->element[i].weight == T->element[i + 1].lchild && T->element[i].parent != 0) {

        } else if (T->element[i].parent != 0){

        } else {
            continue;

        }
    }
}

void print(pHTree T,int n)
{
    cout << "index weight parent lChild rChild" << endl;
    cout << left;    // 左对齐输出
    for (int i = 0; i < n; ++i)
    {
        cout << i << " ";
        cout << T->element[i].weight << " ";
        cout << T->element[i].parent << " ";
        cout << T->element[i].lchild << " ";
        cout << T->element[i].rchild << endl;
    }
}

int main() {

    int n;
    cin >> n;
    auto weight_array = new DataType[n];
    auto huffman_tree = new HTree;
    huffman_tree->max_num = 2 * n -1;
    huffman_tree->cur_num = 0;
    priority_queue<DataType, vector<DataType>, greater<DataType> > q;
    for (int i = 0; i < n; i++) {
        cin >> weight_array[i];
        q.push(weight_array[i]);
    }
    huffman_tree = create_huffmantree(huffman_tree, weight_array, q, n);
    print(huffman_tree, n);
    return 0;
}