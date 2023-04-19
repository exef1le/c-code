#include <stdio.h>
#define MAX_N 10

int h[MAX_N];

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]); // Read the elements of the array
    }
    int max_area = 0; // Initialize the maximum area to 0
    int stack[MAX_N]; // Create a stack to keep track of the indices of the elements in the array
    int top = -1; // Initialize the top of the stack to -1
    for (int i = 0; i < n; i++) {
        while (top >= 0 && h[i] <= h[stack[top]]) {
            int height = h[stack[top]]; // Get the height of the current element
            top--; // Pop the element from the stack
            int width = i; // Calculate the width of the rectangle
            if (top >= 0) {
                width = i - stack[top] - 1;
            }
            int area = height * width; // Calculate the area of the rectangle
            if (area > max_area) { // Update the maximum area if necessary
                max_area = area;
            }
        }
        stack[++top] = i; // Push the current index onto the stack
    }
    while (top >= 0) { // Process any remaining elements on the stack
        int height = h[stack[top]]; // Get the height of the current element
        top--; // Pop the element from the stack
        int width = n; // Calculate the width of the rectangle
        if (top >= 0) {
            width = n - stack[top] - 1;
        }
        int area = height * width; // Calculate the area of the rectangle
        if (area > max_area) { // Update the maximum area if necessary
            max_area = area;
        }
    }
    printf("%d\n", max_area); // Print out the maximum area
    return 0;
}