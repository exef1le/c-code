#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

char stack[MAX_N]; // stack to store opening symbols
int top = -1; // index of the top element in the stack

// function to push an element onto the stack
void push(char c) {
    stack[++top] = c;
}

// function to pop an element from the stack
char pop() {
    return stack[top--];
}

// function to check if the stack is empty
int is_empty() {
    return top == -1;
}

// function to check if two symbols are matching
int is_matching(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

int main() {
    int n, i;
    char str[MAX_N];

    scanf("%d", &n); // read the length of the string
    scanf("%s", str); // read the string

    for (i = 0; i < n; i++) {
        char c = str[i];

        // if the current symbol is an opening symbol, push it onto the stack
        if (c == '(' || c == '[' || c == '{') {
            push(c);
        }
        // if the current symbol is a closing symbol
        else if (c == ')' || c == ']' || c == '}') {
            // if the stack is empty or the top element of the stack does not match with the current symbol, then the string is not balanced
            if (is_empty() || !is_matching(pop(), c)) {
                printf("No\n");
                return 0;
            }
        }
    }

    // if the stack is empty after processing all symbols, then the string is balanced
    if (is_empty()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}