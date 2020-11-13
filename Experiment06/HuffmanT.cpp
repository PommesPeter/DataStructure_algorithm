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
    int weight_value;
    int parent;
    int lchild, rchlid;
};

struct tree {
    int max_num;
    int cur_num;
    struct node* element;
};

typedef struct node node;
typedef tree HTree;
typedef HTree *pHTree;

pHTree init_huffman(pHTree T, DataType *w, DataType n) {
    T->element = new node[2 * n];
    for (int i = 0; i < n; i++) {
        T->element[i].weight_value = w[i];
        T->element[i].parent = 0;
        T->element[i].lchild = 0;
        T->element[i].rchlid = 0;
    }
    return T;
}

pHTree create_huffmantree(pHTree T, DataType *w, priority_queue<DataType, vector<DataType>, greater<DataType> > q,
                          DataType n) {
    int weight_sum;
    T = init_huffman(T, w, n);
    for (int i = 0; i < n - 1; i++) {
        DataType temp = q.top();
        T->element[i].lchild = temp;
        q.pop();
        weight_sum = temp + q.top();
        T->element[i].rchlid = q.top();
        q.pop();
        q.push(weight_sum);
        T->element[i].weight_value = weight_sum;
        if (i == 0) {
            continue;
        } else {
            T->element[i - 1].parent = T->element[i].weight_value;
        }
        if (i + 1 == n - 1) {
            T->element[i].parent = 0;
        }
    }
    return T;
}

string* decode_huffmantree(pHTree T, int n) {
    auto result = new string[n];
    std::size_t m = n - 1;
    for (int i = 0;i < n - 1; i++) {
        if (T->element[i].weight_value == T->element[i + 1].lchild && T->element[i].parent != 0) {

        } else if (T->element[i].parent != 0){

        } else {
            continue;

        }
    }
}

void printf_tree(pHTree T, int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "parent:" << T->element[i].parent << " lchild:" << T->element[i].lchild << " rchild:" << T->element[i].rchlid << " weight:"
             << T->element[i].weight_value << endl;
    }
}

int main() {

    int n;
    cin >> n;
    auto weight_array = new DataType[n];
    auto huffman_tree = new HTree;
    priority_queue<DataType, vector<DataType>, greater<DataType> > q;
    for (int i = 0; i < n; i++) {
        cin >> weight_array[i];
        q.push(weight_array[i]);
    }
    huffman_tree = create_huffmantree(huffman_tree, weight_array, q, n);
    printf_tree(huffman_tree, n);
    return 0;
}
