 //Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

#include <stdio.h>
int main() {
    int n, pos;
    int arr[100];
    // Step 1: Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Step 3: Input position to delete (1-based)
    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);
    // Step 4: Check for valid position
    if(pos < 1 || pos > n) {
        printf("Invalid position!");
        return 0;
    }
    // Step 5: Shift elements to the left
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Step 6: Print updated array
    printf("Array after deletion:\n");
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
