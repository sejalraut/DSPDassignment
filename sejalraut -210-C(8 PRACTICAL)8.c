#include <stdio.h>
#define MAX 100
#define INF 99999

int cost[MAX][MAX];
int used[MAX];
int dist[MAX];
int parent[MAX];

int findMin(int n) {
    int best = INF;
    int bestNode = -1;
    for (int i = 1; i <= n; i++) {
        if (!used[i] && dist[i] < best) {
            best = dist[i];
            bestNode = i;
        }
    }
    return bestNode;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;
    }

    int start;
    scanf("%d", &start);

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        used[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (int k = 1; k <= n; k++) {
        int u = findMin(n);
        if (u == -1) break;
        used[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (cost[u][v] < INF && !used[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("%d: -1\n", i);
        else printf("%d: %d\n", i, dist[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (i != start && parent[i] != -1) {
            printf("%d <- %d\n", i, parent[i]);
        }
    }

    return 0;
}
