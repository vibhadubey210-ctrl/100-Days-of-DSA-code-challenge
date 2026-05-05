/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/
#include <stdio.h>

// Function to check if painters can finish within maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0; // safety check

        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];
        }
    }

    return painters <= k;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;

    // initialize search range
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];   // max element
        high += boards[i];     // total sum
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter board lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int result = minTime(boards, n, k);

    printf("Minimum time required: %d\n", result);

    return 0;
}