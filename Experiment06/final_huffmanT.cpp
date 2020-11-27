#include <iostream>
#include <cstdlib>
#include <string>
//5 1 5 3 6 2
using namespace std;

struct node {
    int weight;
    int parent;
    int lchild, rchild;
    string code;
};

struct hTree {
    struct node* element;
};

typedef struct node node;
typedef struct hTree hTree;
typedef struct hTree* phTree;

phTree init_huffmanTree(int n) {
    size_t m = 2 * n - 1;
    auto T = new hTree;
    T->element = new node[m];
    for (int i = 0; i < m; i++) {
        T->element[i].weight = -1;
        T->element[i].parent = -1;
        T->element[i].lchild = -1;
        T->element[i].rchild = -1;
    }

    return T;
}

void find_min(phTree T, int n, int min_pos[]) {
    //寻找第一个双亲域为0且权值最小的结点
    int min;
    for (int i = 0; i < n; i++)    //找到第一个双亲域为0的，下标暂存到min
    {
        if (T->element[i].parent == -1) {
            min = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (T->element[i].parent == -1) {
            if (T->element[i].weight < T->element[min].weight) {
                min = i;
            }
        }
    }
    min_pos[0] = min;

    //寻找第二个双亲域为0且权值最小的结点
    for (int i = 0; i < n; i++)    //找到第一个双亲域为0的，下标暂存到min
    {
        if (T->element[i].parent == -1 && i != min_pos[0]) {
            min = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (T->element[i].parent == -1 && i != min_pos[0]) {
            if (T->element[i].weight < T->element[min].weight) {
                min = i;
            }
        }
    }
    min_pos[1] = min;
}


phTree create_huffmanTree(phTree T, int n, int m) {

    int min_pos[2] = {0, 0};
    for (int i = n ;i < m; i++) {
        find_min(T, i, min_pos);
//        cout << "min_pos[1]:" << min_pos[1] << endl;
//        cout << "min_pos 0, 1" << min_pos[0] << min_pos[1] << endl;
        T->element[i].weight = T->element[min_pos[0]].weight + T->element[min_pos[1]].weight;
        T->element[i].lchild = min_pos[0];
        T->element[i].rchild = min_pos[1];
        T->element[min_pos[0]].parent = i;
        T->element[min_pos[1]].parent = i;
    }
    return T;
}

void cout_huffmanTree(phTree T, int m) {
    cout << "TreeIndex\tweight\tparent\tlchild\trchild" << endl;
    for (int i = 0;i < m; i++) {
        cout << i << "\t" << T->element[i].weight << "\t" << T->element[i].parent << "\t" << T->element[i].lchild << "\t" << T->element[i].rchild << endl;
    }
}

int main() {

    int n;
    cin >> n;
    int m = 2 * n - 1;
    phTree T = init_huffmanTree(n);
    for (int i = 0; i < n; i++) {
        cin >> T->element[i].weight;
    }
    T = create_huffmanTree(T, n, m);
    cout_huffmanTree(T, m);


    return 0;
}