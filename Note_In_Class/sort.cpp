#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#define N 10
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void selection_sort_max(int a[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        int max = n - 1;
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] > a[max]) {
                max = j;
            }
        }
        swap(&a[i], &a[max]);
    }
}

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n - 1; i++) { // 趟数
        // 已排序子序列长度为i
        int tmp = a[i];
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > tmp) {
                a[j + 1] = a[j]; //后移
            }
            else {
                break;
            }
        }
        a[j + 1] = tmp;
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        if (i % n == 0 && i != 0)
            printf("\n");
    }
}

int main()
{
    int a[N];
    int n = N;
    srand(time(NULL)); //用于生成随机数种子
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100; //随机数给关键码
    cout << "排序前: " << endl;
    print(a, n); //输出排序前的关键码
    long t1 = GetTickCount();
    // bubble_sort(a, n);
    // selection_sort_max(a, n);

    long t2 = GetTickCount();
    cout << endl << "排序后: " << endl;
    print(a, n);
    cout << endl << "花费时间: " << t2 - t1;
    return 0;
}
