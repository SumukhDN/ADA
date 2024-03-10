// Dijkstra's Algorithm in C.

#include <stdio.h>
#include <string.h>
#include <math.h>

#define IN 99
#define N 6

int dijkstra(int cost[][N], int source, int target);

int main() {
    int cost[N][N], i, j, w, co;
    int source, target, x, y;

    printf("\n The Shortest Path Algorithm (DIJKSTRA'S ALGORITHM in C)\n");

    // Initialize the cost matrix
    for (i = 1; i < N; i++)
        for (j = 1; j < N; j++)
            cost[i][j] = IN;

    // Input weights for paths between nodes
    for (x = 1; x < N; x++) {
        for (y = x + 1; y < N; y++) {
            printf("Enter the weight of the path between nodes %d and %d: ", x, y);
            scanf("%d", &w);
            cost[x][y] = cost[y][x] = w;
        }
        printf("\n");
    }

    // Input source and target nodes
    printf("Enter the source: ");
    scanf("%d", &source);
    printf("Enter the target: ");
    scanf("%d", &target);

    // Find the shortest path
    co = dijkstra(cost, source, target);

    printf("\nThe Shortest Path: %d\n", co);

    return 0;
}

int dijkstra(int cost[][N], int source, int target) {
    int dist[N], prev[N], selected[N] = {0};
    int i, m, min, start, d, j;
    char path[N];

    // Initialize distance and previous arrays
    for (i = 1; i < N; i++) {
        dist[i] = IN;
        prev[i] = -1;
    }

    start = source;
    selected[start] = 1;
    dist[start] = 0;

    // Dijkstra's algorithm
    while (selected[target] == 0) {
        min = IN;
        m = 0;
        for (i = 1; i < N; i++) {
            d = dist[start] + cost[start][i];
            if (d < dist[i] && selected[i] == 0) {
                dist[i] = d;
                prev[i] = start;
            }
            if (min > dist[i] && selected[i] == 0) {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }

    // Backtrack to find the path
    start = target;
    j = 0;
    while (start != -1) {
        path[j++] = start + 65; // Convert to character ('A' for node 1, 'B' for node 2, etc.)
        start = prev[start];
    }
    path[j] = '\0'; // Null-terminate the string
    strrev(path); // Reverse the path

    printf("Shortest Path: %s\n", path);

    return dist[target];
}
