// 用最小栈方式构建哈弗曼树

// 定义一个哈夫曼树的节点
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct MinHeapNode {
    // One of the input characters
    char data;
    // Frequency of the character
    unsigned freq;
    // 哈夫曼的编码值, #号表示无编码
    string code_huff = "#";
    // Left and right child
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// 定义一个哈弗曼树的存储节点
struct Node {
    char data;
    string code_huff = "#";
} node[256];

// For comparison of
// two heap nodes (needed in min heap)
struct compare {
    bool operator()(MinHeapNode *l, MinHeapNode *r) {
        return (l->freq > r->freq);
    }
};

// 递归的方式打印哈夫曼编码从树的根部
void printCodes(struct MinHeapNode *root, string str) {
    int cou = 0;
    if (!root)
        return;
    if (root->data != '$') {
        cout << root->data << ": " << str << "\n";
        root->code_huff = str;
        node[cou].data = root->data;
        node[cou].code_huff = root->code_huff;
        cou++;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// 创建一个哈夫曼树
// data 为字符数组, freq 为对应频数, size 为字符数组元素的个数
struct MinHeapNode *HuffmanCodes(char data[], unsigned int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    // 创建一个根据频数值的最小堆并插入字符数组中所有的字符
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    // 将需要排序的内容压入堆中
    for (int i = 0; i < size; ++i) {
        if (freq[i] != 0)
            minHeap.push(new MinHeapNode(data[i], freq[i]));
    }
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // 从最小堆中取出两个最小频数的项目
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        // 创建树中的和节点, 并连接左右两个子节点, 后再将其压入堆中
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    // 输出哈夫曼编码通过已创建的哈弗曼树
    printCodes(minHeap.top(), "");
    // 返回哈夫曼树的根
    return minHeap.top();
}