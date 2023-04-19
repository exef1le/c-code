#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int main() {
    int n, i;
    int stack[MAX_N], top = -1;
    int order = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int wagon;
        scanf("%d", &wagon);

        // Put the wagon into the siding
        stack[++top] = wagon;

        // Check if wagons can be moved from the siding to track 2
        while (top >= 0 && stack[top] == order) {
            top--;
            order++;
        }
    }

    if (order == n + 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}