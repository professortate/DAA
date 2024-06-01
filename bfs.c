#include <stdio.h>
#include <time.h>

void bfs(int a[10][10], int n, int source) {
    int s[10], q[10], f = 0, r = -1, t, v;

    // Initialize all nodes as unvisited
    for (v = 0; v < n; v++) {
        s[v] = 0;
    }

    // Enqueue the source node and mark as visited
    q[++r] = source;
    s[source] = 1;
    printf("The BFS traversal is:\n%d ", source);

    while (f <= r) {
        // Dequeue a vertex from the queue
        t = q[f++];

        // Process all adjacent vertices of the dequeued vertex
        for (v = 0; v < n; v++) {
            if (a[t][v] == 1 && s[v] == 0) {
                q[++r] = v;
                printf("%d ", v); // Print each visited node
                s[v] = 1;
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j, s;
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix representation:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source city: ");
    scanf("%d", &s);

    starttime = clock(); 
    bfs(a, n, s);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
