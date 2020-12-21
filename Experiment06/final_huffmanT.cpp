#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

struct node {
    int weight;
    int parent;
    int lchild, rchild;
};

struct huffman_code {
    int start;
    int weight;
    char code[10];
};

struct hTree {
    struct node* element;
};

typedef struct node node;
typedef struct hTree hTree;
typedef struct hTree* phTree;
typedef struct huffman_code huffman_code;
typedef huffman_code* pHuffmancode;

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

void cout_huffman_code(phTree T, int root, huffman_code* T_code, int n) {
    if (T->element[root].lchild != -1 && T->element[root].rchild != -1) {
        cout_huffman_code(T, T->element[root].lchild, T_code, n);
        cout_huffman_code(T, T->element[root].rchild, T_code, n);
    } else {
        cout << T->element[root].weight << " ";
        for (int j = T_code[root].start + 1; j < n; j++) {
            cout << T_code[root].code[j];
        }
        cout << endl;
    }
}


void encoding_huffmanTree(phTree T, int n, int m) {
    //遍历要编码的元素
    auto T_code = new huffman_code[m];
    huffman_code temp;
    if (n == 1) {
        cout << T->element[0].weight << " 0" << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        //遍历整棵树为其编码
        memset(T_code[i].code, '\0', sizeof(T_code[i].code));
        temp.start = n - 1;
        size_t node_index = i;
        size_t node_parent = T->element[i].parent;
        T_code[i].weight = T->element[i].weight;
        while (node_parent != -1) {
            //记录当前节点
            if (T->element[node_parent].lchild == node_index) {
                temp.code[temp.start] = '0';
            } else {
                temp.code[temp.start] = '1';
            }
            temp.start--;
            node_index = node_parent;
            node_parent = T->element[node_index].parent;
        }
        int temp_start = 0;
        for (int j = temp.start + 1; j <= n; j++) {
            temp_start = j;
            T_code[i].code[j] = temp.code[j];
        }
        T_code[i].code[temp_start] = '\0';
        T_code[i].start = temp.start;
    }
    cout_huffman_code(T, m - 1, T_code, n);
//    for (int i = 0; i < n; i++) {
//        cout << T_code[i].weight << " ";
//        for (int j = T_code[i].start + 1; j < n; j++) {
//            cout << T_code[i].code[j];
//        }
//        cout << endl;
//    }
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
    cout << "index\tweight\tparent\tlchild\trchild" << endl;
    for (int i = 0;i < m; i++) {
        cout << i << "\t" << T->element[i].weight << "\t" << T->element[i].parent << "\t" << T->element[i].lchild << "\t" << T->element[i].rchild << endl;
    }
}

//5 1 5 3 6 2
//5 2 7 4 5 19
int main() {
    int n;
    cin >> n;
    if (n < 1) {
        cout << "TypeError: wrong data type" << endl;
        return 0;
    }
    int m = 2 * n - 1;
    phTree T = init_huffmanTree(n);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp < 0) {
            cout << "TypeError: weight is a minus number..." << endl;
            return 0;
        }
        if (temp >= 'A' && temp <= 'z') {
            cout << "TypeError: weight is a character..." << endl;
            return 0;
        }
        T->element[i].weight = temp;
    }
    T = create_huffmanTree(T, n, m);
//    cout_huffmanTree(T, m);
    encoding_huffmanTree(T, n, m);
    free(T->element);
    free(T);
    return 0;
}