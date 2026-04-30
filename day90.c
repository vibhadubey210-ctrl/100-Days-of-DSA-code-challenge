/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/
#include <stdio.h>

// check if allocation possible with maxPages = mid
int canAllocate(int arr[], int n, int m, int mid) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return 0; // safety check

        if (pages + arr[i] <= mid) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > low) low = arr[i]; // max element
        high += arr[i];                 // total sum
    }

    int ans = high;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller value
        } else {
            low = mid + 1;   // increase value
        }
    }

    printf("%d\n", ans);
    return 0;
}