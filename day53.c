/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue for building tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Structure for queue (node + HD)
struct Pair {
    struct Node* node;
    int hd;
};

// Vertical traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // Queue
    struct Pair queue[2000];
    int front = 0, rear = 0;

    // Map (array of arrays)
    int map[2000][2000];
    int size[2000] = {0};

    int minHD = 1000, maxHD = 1000;

    // Start with root at HD = 1000 (to avoid negative index)
    queue[rear++] = (struct Pair){root, 1000};

    while (front < rear) {
        struct Pair temp = queue[front++];

        struct Node* node = temp.node;
        int hd = temp.hd;

        map[hd][size[hd]++] = node->data;

        if (node->left) {
            queue[rear++] = (struct Pair){node->left, hd - 1};
        }
        if (node->right) {
            queue[rear++] = (struct Pair){node->right, hd + 1};
        }

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
    }

    // Print result from left to right
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}