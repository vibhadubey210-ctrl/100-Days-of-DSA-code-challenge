//Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>
int main() {
    int n, k;
    int arr[100];
    int comparisons = 0;
    int found = 0;
    // Step 1: Input array size
    printf("Enter array size: ");
    scanf("%d", &n);
    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Step 3: Input key to search
    printf("Enter key to search: ");
    scanf("%d", &k);
    // Step 4: Linear Search
    for(int i = 0; i < n; i++) {
        comparisons++;          // count comparison
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    // Step 5: If not found
    if(found == 0) {
        printf("Not Found\n");
    }
    // Step 6: Print comparisons
    printf("Comparisons = %d", comparisons);
    return 0;
}
