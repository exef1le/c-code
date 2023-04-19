#include <stdio.h>
#define MAX_SIZE 10001

// Define a stack data structure
typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

// Function to push an element onto the stack
void push(Stack *s, double x) {
    s->data[++s->top] = x;
}

// Function to pop an element from the stack
double pop(Stack *s) {
    return s->data[s->top--];
}

// Function to get the top element of the stack
double top(Stack *s) {
    return s->data[s->top];
}

// Function to check if the stack is empty
int empty(Stack *s) {
    return s->top == 0;
}

int main() {
    int n, k, i, j;
    double x, y;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        Stack conveyor, storage;
        conveyor.top = storage.top = 0;
        scanf("%d", &k);
        for (j = 0; j < k; j++) {
            scanf("%lf", &x);
            push(&conveyor, x);
        }
        y = 1.0;
        // While the conveyor or storage is not empty
        while (!empty(&conveyor) || !empty(&storage)) {
            // If the top of the storage is equal to y
            if (!empty(&storage) && top(&storage) == y) {
                pop(&storage);
                y += 1.0;
            // If the top of the conveyor is equal to y
            } else if (!empty(&conveyor) && top(&conveyor) == y) {
                pop(&conveyor);
                y += 1.0;
            // If the conveyor is not empty
            } else if (!empty(&conveyor)) {
                push(&storage, pop(&conveyor));
            } else {
                break;
            }
        }
        // If all containers have been processed
        if (y == k) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}