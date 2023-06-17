#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node in the tree
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to calculate the height of the tree
int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Function to check if the tree is balanced
int isBalanced(Node* root) {
    if (root == NULL) {
        return 1;
    } else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    Node* root = NULL;
    int num;
    
    // Input numbers until zero is entered and insert them into the tree
    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        root = insertNode(root, num);
    }
    
    // Check if the tree is balanced
    if (isBalanced(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}

                                //  Check the code on an online compiler !!!