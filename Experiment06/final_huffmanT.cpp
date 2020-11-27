#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int weight;
    int parent;
    int lchild, rchild;
};

struct hTree {
    struct node* element;
};

typedef struct node node;
typedef struct hTree* phTree;

phTree init_huffmanTree(int n) {
    size_t m = 2 * n - 1;
    auto T = new struct hTree;
    T->element = new node[m];
    for (int i = 0; i < m; i++) {
        T->element[i].weight = -1;
        T->element[i].parent = -1;
        T->element[i].lchild = -1;
        T->element[i].rchild = -1;
    }

    return T;
}

int main() {

    int n;
    cin >> n;
    phTree T = init_huffmanTree(n);


    return 0;
}