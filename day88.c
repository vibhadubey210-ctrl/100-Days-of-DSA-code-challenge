/*Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/
#include <stdio.h>

// --------- Bubble Sort (for sorting) ----------
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// --------- Iterative Binary Search ----------
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // not found
}

int main() {
    int n;

    // input size
    scanf("%d", &n);

    int arr[n];

    // input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    bubbleSort(arr, n);

    // Step 2: Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // (Optional) Search example
    /*
    int key;
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, n, key);

    if (index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not Found\n");
    */

    return 0;
}