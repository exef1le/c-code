#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    
    bool *laws = (bool*) malloc(n * sizeof(bool));  // Allocate memory for the laws array
    for (int i = 0; i < n; i++) {
        laws[i] = true;  // Initialize all laws as active
    }
    
    int activeLaws = n;  // Counter for active laws
    for (int i = 0; i < n; i++) {
        char action[10];
        scanf("%s", action);
        
        if (action[0] == 'c') {  // If the action is 'cancel'
            int cancelIndex;
            scanf("%d", &cancelIndex);
            
            if (laws[cancelIndex - 1]) {  // If the law is active
                laws[cancelIndex - 1] = false;  // Mark the law as inactive
                activeLaws--;  // Decrease the count of active laws
            }
        }
    }
    
    printf("%d\n", activeLaws);  // Print the count of active laws
    
    for (int i = 0; i < n; i++) {
        if (laws[i]) {
            printf("%d ", i + 1);  // Print the indices of active laws
        }
    }
    
    free(laws);  // Free the dynamically allocated memory
    
    return 0;
}

                                  // Check the code on an online compiler !!!