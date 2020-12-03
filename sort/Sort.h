#pragma once
//Sort.h
#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>

void bubble_sort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge_sort(int *arr, int len) {
    int pivot = arr[0];
    int low = 0, high = len - 1;
    while (1) {
        while (arr[high] >= pivot) {
            high--;
        }
        if (high <= low) {
            arr[low] = pivot;
            bubble_sort(arr, low);
            bubble_sort(arr + low + 1, len - low - 1);
            break;
        }
        arr[low] = arr[high];

        while (arr[low] <= pivot) {
            low++;
        }
        if (low >= high) {
            arr[high] = pivot;
            bubble_sort(arr, high);
            bubble_sort(arr + high + 1, len - high - 1);
            break;
        }
        arr[low] = arr[high];
    }
}

//void quick_sort_r1(int *arr, int len) {
//    _quickSort(arr, 0, len - 1);
//    return;
//}
//
//void quick_sort_r2(int *arr, int len) {
//
//}
//
//void quick_sort_r3(int *arr, int len) {
//    _quickSort3(arr, 0, len - 1);
//    return;
//}

void selection_sort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        //Ѱ����Сֵ�ı��min
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        //����
        if (min != i) {
            int temp;
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void insertion_sort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int temp = arr[i], j;
        for (j = i; j > 0 && temp < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

void shell_sort(int *arr, int len) {
    int temp, j;
    for (int k = len / 2; k >= 1; k /= 2) {
        for (int i = k; i < len; i++) {
            temp = arr[i];
            for (int j = k; j >= k; j -= k) {
                if (temp < arr[j - k]) {
                    arr[j] = arr[j - k];
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

//void heap_sort(int *arr, int len) {
//    for (int i = (len - 2) / 2; i >= 0; i--) {
//        shiftDown(arr, len, i);
//    }
//    for (int i = len - 1; i > 0; i--) {
//        swap(&arr[0], &arr[i]);
//        shiftDown(arr, i, 0);
//    }
//    return;
//}

void printf_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rand_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//void shiftUp(int arr[], int n, int k) {
//    while ((k - 1) / 2 >= 0 && arr[k] > arr[(k - 1) / 2]) {
//        swap(arr[k], &arr[(k - 1) / 2]);
//        k = (k - 1) / 2;
//    }
//    return;
//}
//
//void shiftDown(int arr[], int n, int k) {
//    int j = 0;
//    while (2 * k + 1 < n) {
//        j = 2 * k + 1;
//        if (j + 1 < n && arr[j] < arr[j + 1]) {
//            j++;
//        }
//        if (arr[k] < arr[j]) {
//            swap(&arr[k], &arr[j]);
//            k = j;
//        } else {
//            break;
//        }
//    }
//    return;
//}
//arr[l+1....i) <=arr[l], arr(j...r] >=arr[l]

int partition(int arr[], int l, int r) {
    int i = l + 1, j = l;

    while (i <= r) {
        if (arr[i] > arr[l]) {
            i++;
        } else {
            swap(&arr[j + 1], &arr[i]);
            i++;
            j++;
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

int partition2(int arr[], int l, int r) {
    int i, j;

    i = l + 1;
    j = r;

    while (i <= j) {
        while (i <= j && arr[j] > arr[l])
            /*注意arr[j] >arr[l] 不是arr[j] >= arr[l]*/
        {
            j--;
        }
        while (i <= j && arr[i] < arr[l]) {
            i++;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    swap(&arr[j], &arr[l]);
    return j;
}

void _quickSort(int arr[], int l, int r) {
    int key;
    if (l >= r) {
        return;
    }
    key = partition(arr, l, r);
    _quickSort(arr, l, key - 1);
    _quickSort(arr, key + 1, r);
}

void _quickSort3(int arr[], int l, int r) {
    int i, lt, gt;

    if (l >= r) {
        return;
    }
    i = l + 1;
    lt = l;
    gt = r;

    while (i <= gt) {
        if (arr[i] < arr[l]) {
            swap(&arr[lt + 1], &arr[i]);
            lt++;
            i++;
        } else if (arr[i] > arr[l]) {
            swap(&arr[i], &arr[gt]);
            gt--;
        } else {
            i++;
        }
    }
    swap(&arr[l], &arr[gt]);
    _quickSort3(arr, l, lt);
    _quickSort3(arr, gt + 1, r);
    return;
}

#endif