#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

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
    int lchild, rchlid;
};

struct tree {
    int max_num;
    int cur_num;
    struct node* element;
};

typedef struct node node;
typedef struct tree HTree;
typedef HTree *pHTree;

pHTree create_huffmantree(pHTree T, DataType* w, priority_queue<DataType, vector<DataType>, greater<DataType> > q, DataType n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        T->element[i].parent = 0;
        T->element[i].lchild = 0;
        T->element[i].rchlid = 0;
    }
    for (int i = 0; i < n; i++) {
        T->element[i].weight = w[i];
    }
    for (int i = n; i < 2 * n - 1; i++) {

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

void printf_tree(pHTree T, int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "parent:" << T->element[i].parent << " lchild:" << T->element[i].lchild << " rchild:" << T->element[i].rchlid << " weight:"
             << T->element[i].weight << endl;
    }
}

int main() {

    int n, w_temp;
    cin >> n;
    auto weight_array = new DataType[n];
    auto huffman_tree = new HTree;
    huffman_tree->max_num = 2 * n -1;
    huffman_tree->cur_num = 0;
    priority_queue<DataType, vector<DataType>, greater<DataType> > q;
    for (int i = 0; i < n; i++) {
        cin >> w_temp;
        q.push(w_temp);
    }
    huffman_tree = create_huffmantree(huffman_tree, q, n);
    printf_tree(huffman_tree, n);
    return 0;
}