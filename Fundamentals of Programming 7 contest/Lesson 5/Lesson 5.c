#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to calculate the height of the tree
int treeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

int main() {
    Node* root = NULL;
    int num;

    printf("Enter a sequence of integers (0 to end input):\n");

    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        root = insertNode(root, num);
    }

    int height = treeHeight(root);
    printf("Height of the tree: %d\n", height);

    return 0;
}

                               // Check the code on an online compiler !!!