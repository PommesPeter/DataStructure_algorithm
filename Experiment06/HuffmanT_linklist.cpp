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
    int *parent;
    int *lchild, *rchild;
};

typedef struct node HTree;
typedef HTree *pHTree;

void find_min(pHTree T, priority_queue<DataType, vector<DataType>, greater<DataType>> q, int *s_1, int *s_2, DataType n) {
    for (int i = 0; i < n; i++) {
        if (T->weight == q.top()) {
            *s_1 = i;
            break;
        }
    }
    q.pop();
    for (int i = 0; i < n; i++) {
        if (T->weight == q.top()) {
            *s_2 = i;
            break;
        }
    }
    q.pop();
}

pHTree init_huffman_node() {
    auto p = new HTree;

    p->weight = 0;
    p->lchild = 0;
    p->rchild = 0;
    return p;
}

pHTree create_huffmantree(pHTree T, DataType *w, priority_queue<DataType, vector<DataType>, greater<DataType> > q,
                          DataType n) {

    return T;
}

string *decode_huffmantree(pHTree T, int n) {
    auto result = new string[n];
    std::size_t m = n - 1;
    for (int i = 0; i < n - 1; i++) {

    }
}

void print(pHTree T, int n) {

}

int main() {

    int n;
    cin >> n;
    auto weight_array = new DataType[n];
    auto huffman_tree = init_huffman_head();
    priority_queue<DataType, vector<DataType>, greater<DataType> > q;
    for (int i = 0; i < n; i++) {
        cin >> weight_array[i];
        q.push(weight_array[i]);
    }
    huffman_tree = create_huffmantree(huffman_tree, weight_array, q, n);
    print(huffman_tree, n);
    return 0;
}