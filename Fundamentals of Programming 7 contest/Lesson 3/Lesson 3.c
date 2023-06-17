#include <stdio.h>

#define MAX_SIZE 100

void dfs(int graph[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE], int n, int v) {
    visited[v] = 1; // Mark the vertex as visited

    // Iterate through all vertices and recursively call dfs for unvisited adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, n, i);
        }
    }
}

int countConnectedVertices(int graph[MAX_SIZE][MAX_SIZE], int n, int s) {
    int visited[MAX_SIZE] = {0}; // Array to track visited vertices
    dfs(graph, visited, n, s - 1); // Call dfs for the given vertex

    int count = 0;
    // Count the number of visited vertices
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    int graph[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int result = countConnectedVertices(graph, n, s);
    printf("%d\n", result);

    getchar(); // Wait for user input

    return 0;
}
                                               // Check the code on an online compiler !!!