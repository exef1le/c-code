#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 501

typedef struct {
    int node;
    int time;
    int weight;
} Road;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Road graph[MAX_NODES][MAX_NODES];
    int weightLimit[MAX_NODES];
    int dist[MAX_NODES];
    bool visited[MAX_NODES];

    // Initialize arrays
    for (int i = 1; i <= n; i++) {
        weightLimit[i] = INT_MAX;
        dist[i] = INT_MAX;
        visited[i] = false;
        for (int j = 1; j <= n; j++) {
            graph[i][j].node = 0;
            graph[i][j].time = 0;
            graph[i][j].weight = 0;
        }
    }

    // Read road information and populate the graph
    for (int i = 0; i < m; i++) {
        int u, v, time, weight;
        scanf("%d %d %d %d", &u, &v, &time, &weight);

        graph[u][v].node = v;
        graph[u][v].time = time;
        graph[u][v].weight = weight;

        graph[v][u].node = u;
        graph[v][u].time = time;
        graph[v][u].weight = weight;

        weightLimit[u] = weightLimit[u] > weight ? weight : weightLimit[u];
        weightLimit[v] = weightLimit[v] > weight ? weight : weightLimit[v];
    }

    dist[1] = 0;

    // Dijkstra's algorithm to find the shortest path
    for (int i = 1; i <= n; i++) {
        int minDist = INT_MAX;
        int u = -1;

        // Find the unvisited node with the minimum distance
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        // Update the distances of the neighboring nodes
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v].node != 0) {
                int newTime = dist[u] + graph[u][v].time;
                int newWeight = weightLimit[v];

                // Check if the new path satisfies the conditions
                if (newTime <= 1440 && newWeight >= 3000 && newTime < dist[v]) {
                    dist[v] = newTime;
                }
            }
        }
    }

    // Count the number of reachable nodes (except the starting node)
    int maxCups = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] != INT_MAX)
            maxCups++;
    }

    printf("%d\n", maxCups);

    return 0;
}
                                    //Check the code on an online compiler !!!