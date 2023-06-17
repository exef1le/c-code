#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    printf("%d\n", 2);  // Print the number of lines used for dividing the kingdom
    printf("y %d\n", y[1]);  // Print the first line: parallel to the y-axis, passing through the second point
    printf("x %d\n", x[2]);  // Print the second line: parallel to the x-axis, passing through the third point

    return 0;
}

                                     // Check the code on an online compiler !!!