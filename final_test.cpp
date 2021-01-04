#include <iostream>

using namespace std;

//11 42 12 5 77 16 91 24
void Show(int *A, int N) {
    //函数用于输出A数组的N个元素，以空格作为分界符
    int k;
    for (k = 0; k < N; k++)
        cout << A[k] << " ";
    cout << endl;
}
//11 42 12 5 77 16 91 24
//5 11 6 38 19 12 66 4
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort_1(int *A, int N) {
    //请在此处填写另一种冒泡排序的算法，使得结果能如说明所示
    /********** Begin *********/
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
        Show(A, N);
    }
}
    /********** End *********/


int main() {
    int a[8];
    int i;
    for (i = 0; i < 8; i++)
        cin >> a[i];
    BubbleSort_1(a, 8);
}
