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

//struct tree {
//    int max_num;
//    int cur_num;
//    struct node* element;
//};

typedef struct node HTree;
typedef HTree *pHTree;

pHTree init_huffman(pHTree T, DataType *w, DataType n) {
    for (int i = 0; i < n; i++) {
        T[i].weight_value = w[i];
        T[i].parent = 0;
        T[i].lchild = 0;
        T[i].rchlid = 0;
    }
    return T;
}


pHTree create_huffmantree(pHTree T, DataType *w, priority_queue<DataType, vector<DataType>, greater<DataType> > q,
                          DataType n) {
    int weight_sum;
    T = init_huffman(T, w, n);
    for (int i = 0; i < n - 1; i++) {
        DataType temp = q.top();
        T[i].lchild = temp;
        q.pop();
        weight_sum = temp + q.top();
        T[i].rchlid = q.top();
        q.pop();
        q.push(weight_sum);
        T[i].weight_value = weight_sum;
        if (i == 0) {
            continue;
        } else {
            T[i - 1].parent = T[i].weight_value;
        }
        if (i + 1 == n - 1) {
            T[i].parent = 0;
        }
    }
    return T;
}

string* decode_huffmantree(pHTree T, int n) {
    auto result = new string[n];
    std::size_t m = n - 1;
    for (int i = 0;i < n - 1; i++) {
        if (T[i].weight_value == T[i + 1].lchild && T[i].parent != 0) {

        } else if (T[i].parent != 0){

        } else {
            continue;

        }
    }
}

void printf_tree(pHTree T, int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "parent:" << T[i].parent << " lchild:" << T[i].lchild << " rchild:" << T[i].rchlid << " weight:"
             << T[i].weight_value << endl;
    }
}

int main() {

    int n;
    cin >> n;
    auto weight_array = new DataType[n];
    auto huffman_tree = new HTree[2 * n];
    priority_queue<DataType, vector<DataType>, greater<DataType> > q;
    for (int i = 0; i < n; i++) {
        cin >> weight_array[i];
        q.push(weight_array[i]);
    }
    huffman_tree = create_huffmantree(huffman_tree, weight_array, q, n);
    printf_tree(huffman_tree, n);
    return 0;
}
