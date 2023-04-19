#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Function prototypes
int expression(char **str);
int term(char **str);
int factor(char **str);

int main() {
    char str[MAX_LENGTH];
    fgets(str, MAX_LENGTH, stdin); // Read input expression

    char *ptr = str;
    int result = expression(&ptr); // Evaluate expression

    // Check for invalid characters at the end of the input
    if (*ptr != '\n' && *ptr != '\0') {
        printf("WRONG\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}

// Evaluate an expression
int expression(char **str) {
    int result = term(str);

    while (true) {
        while (isspace(**str)) (*str)++;
        if (**str == '+') {
            (*str)++;
            result += term(str);
        } else if (**str == '-') {
            (*str)++;
            result -= term(str);
        } else {
            break;
        }
    }

    return result;
}

// Evaluate a term
int term(char **str) {
    int result = factor(str);

    while (true) {
        while (isspace(**str)) (*str)++;
        if (**str == '*') {
            (*str)++;
            result *= factor(str);
        } else {
            break;
        }
    }

    return result;
}

// Evaluate a factor
int factor(char **str) {
    int result = 0;

    while (isspace(**str)) (*str)++;
    if (**str == '(') {
        (*str)++;
        result = expression(str);
        if (**str == ')') {
            (*str)++;
        } else {
            printf("WRONG\n");
            exit(0);
        }
    } else if (isdigit(**str)) {
        while (isdigit(**str)) {
            result = 10 * result + (**str - '0');
            (*str)++;
        }
    } else {
        printf("WRONG\n");
        exit(0);
    }

    return result;
}
ы