//常量空间复杂度
//交换两个变量的值
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

//线性空间复杂度
//创建一个与输入数组等长的数组
#include <stdio.h>
#include <stdlib.h>

int* create_array(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    return arr;
}

int main() {
    int n = 5;
    int *arr = create_array(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
//对数空间复杂度 O(log n)
//例子：二分搜索的递归实现
#include <stdio.h>

int binary_search(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binary_search(arr, mid + 1, high, target);
    } else {
        return binary_search(arr, low, mid - 1, target);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int result = binary_search(arr, 0, n - 1, target);
    printf("Index of %d is %d\n", target, result);
    return 0;
}
//平方空间复杂度
//动态创建一个n*n的二维数组
#include <stdio.h>
#include <stdlib.h>

int** create_matrix(int n) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return matrix;
}

int main() {
    int n = 3;
    int **matrix = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * n + j;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
