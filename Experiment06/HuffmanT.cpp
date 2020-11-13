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
    string code;
    int parent;
    struct node* lchild, *rchlid;
};

typedef struct node node;
typedef node *pHTree;

pHTree init_huffman(pHTree T, DataType n) {
    for (int i = 0; i < 2 * n; i++) {
        T->element[i].weight_value = 0;
        T->element[i].parent = 0;
        T->element[i].lchild = 0;
        T->element[i].rchlid = 0;
    }
    return T;
}

pHTree create_huffmantree(pHTree T, priority_queue<DataType, vector<DataType>, greater<DataType> > q,
                          DataType n) {
    int weight_sum;
    T = init_huffman(T, n);
    for (int i = 0; i < n - 1; i++) {

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


int main() {

    int n;
    cin >> n;
    auto huffman_tree = new node;
    priority_queue<DataType, vector<DataType>, greater<DataType> > q;
    huffman_tree->max_num = 2 * n - 1;
    huffman_tree->cur_num = 0;
    for (int i = 0; i < n; i++) {
        int w_temp;
        cin >> w_temp;
        q.push(w_temp);
    }
    huffman_tree = create_huffmantree(huffman_tree, q, n);
    printf_tree(huffman_tree, n);
    return 0;
}
