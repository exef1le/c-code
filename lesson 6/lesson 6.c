#include <stdio.h>
#include <stdbool.h>

// Function to evaluate a boolean expression
bool evaluateExpression(char *expr, int len) {
    bool stack[len];
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '0') {
            stack[++top] = false;
        } else if (expr[i] == '1') {
            stack[++top] = true;
        } else if (expr[i] == '!') {
            bool val = !stack[top--];
            stack[++top] = val;
        } else if (expr[i] == '&') {
            bool val1 = stack[top--];
            bool val2 = stack[top--];
            stack[++top] = val1 && val2;
        } else if (expr[i] == '|') {
            bool val1 = stack[top--];
            bool val2 = stack[top--];
            stack[++top] = val1 || val2;
        } else if (expr[i] == '^') {
            bool val1 = stack[top--];
            bool val2 = stack[top--];
            stack[++top] = val1 ^ val2;
        }
    }
    return stack[top];
}

int main() {
    char expr[101];
    fgets(expr, 101, stdin); // Read the input expression
    int len = 0;
    while (expr[len] != '\n') { // Calculate the length of the expression
        len++;
    }
    bool result = evaluateExpression(expr, len); // Evaluate the expression
    printf("%d\n", result); // Print the result
    return 0;
}