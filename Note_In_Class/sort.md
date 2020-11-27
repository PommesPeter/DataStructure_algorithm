# Sort

```c++
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
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
        swap(a[i], a[min]);
    }
}

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n - 1; i++) { // 趟数
        // 已排序子序列长度为i
        int tmp = a[i];
        for(int j = i - 1; j >= 0; j--) { 
            if (a[j] > tmp) {
                a[j + 1] = a[j];    //后移
            } else {
                break;
            }
            a[j + 1] = tmp;
        }
    }
}

void shell_sort(int a[], int n) {
    int d = n / 2;
    for (int inc = d; inc > 0; inc /= 2) {
        for (int i = 1;i < n- 1; i++) {
            int tmp = a[i + inc];
            for (int j = i - 1; j >= 0; j--) {
                if (a[j + inc] > tmp) {
                    a[j + inc] = a[j + inc];
                } else {
                    break;
                }
                a[j + inc + 1] = tmp
            }
        }
    }
}

```

- 衡量排序算法的好坏的因素
    * 算法时间复杂度(最坏时间或平均时间)
    * 算法空间复杂度(临时辅助变量)
    * 算法本身的复杂度
    * 稳定性: 排序算法不改变, 相同排序码记录的原有相对次序（看相等数的位置没有交换）
    * 适应性：在原始待排序序列比较接近有序，算法更快完成工作

- 插入排序基本方法
- 直接插入排序
    每步将待排序的序列，按排序码大小，插入到前面已经排好的位置
- 二分插入排序
    查找插入位置，用二分查找法在已排好序的序列中找R_{i+1}的插入位置
    如果没有找到，就是中间的位置
- 表插入排序(不推荐)
    用单链表代替顺序表，在直接插入排序的基础上减少记录移动的次数
- Shell排序
    又叫增量排序法，排序慢是因为移动太慢，要经过很多步才能到达最终的位置，把每个序列看成长度为d的子序列
    1. 确定增量，加大移动步伐，增量取序列长度的1/2
    2. 
    
逐步按步骤写出来，理清楚步骤就可以了
想为什么学它