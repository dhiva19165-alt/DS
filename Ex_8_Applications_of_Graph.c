#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 10
#define INFINITY 999
// Function prototypes
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src);
int main() {
    int graph[MAX_VERTICES][MAX_VERTICES], n, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Input the adjacency matrix
    printf("Enter the cost adjacency matrix (enter %d for no direct path):\n", INFINITY);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INFINITY;
 // Assigning infinity where there is no direct edge
            }
        }
    }
    printf("Enter the source vertex (starting from 0): ");
    scanf("%d", &src);
    dijkstra(graph, n, src);
    return 0;
}
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src) {
    int dist[MAX_VERTICES], visited[MAX_VERTICES], i, j, u, min;
    for (i = 0; i < n; i++) {
        dist[i] = graph[src][i];
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;
    for (i = 1; i < n; i++) {
        min = INFINITY;
        u = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] != INFINITY && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    printf("\nShortest distances from source %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == INFINITY)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}
