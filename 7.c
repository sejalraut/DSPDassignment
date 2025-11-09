#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int adjList[SIZE+1][4];
int adjSize[SIZE+1];

void build() {
    for (int i = 1; i <= SIZE; i++) {
        adjSize[i] = 0;
    }
    for (int i = 1; i <= SIZE; i++) {
        int j = (i-1)/3;  // row
        int k = (i-1)%3;  // column
        if (j > 0)       adjList[i][ adjSize[i]++ ] = i-3;
        if (j < 2)       adjList[i][ adjSize[i]++ ] = i+3;
        if (k > 0)       adjList[i][ adjSize[i]++ ] = i-1;
        if (k < 2)       adjList[i][ adjSize[i]++ ] = i+1;
    }
    for (int i = 1; i <= SIZE; i++) {
        for (int a = 0; a < adjSize[i]; a++) {
            for (int b = a+1; b < adjSize[i]; b++) {
                if (adjList[i][b] < adjList[i][a]) {
                    int t = adjList[i][a];
                    adjList[i][a] = adjList[i][b];
                    adjList[i][b] = t;
                }
            }
        }
    }
}

void bfs(int start) {
    bool seen[SIZE+1] = { false };
    int queue[SIZE+1];
    int front = 0, back = 0;
    seen[start] = true;
    queue[back++] = start;
    printf("BFS: ");
    while (front < back) {
        int cur = queue[front++];
        printf("%d ", cur);
        for (int i = 0; i < adjSize[cur]; i++) {
            int nb = adjList[cur][i];
            if (!seen[nb]) {
                seen[nb] = true;
                queue[back++] = nb;
            }
        }
    }
    printf("\n");
}

void dfs(int start) {
    bool seen[SIZE+1] = { false };
    int stackArr[SIZE+1];
    int top = 0;
    stackArr[top++] = start;
    printf("DFS: ");
    while (top > 0) {
        int cur = stackArr[--top];
        if (seen[cur]) continue;
        seen[cur] = true;
        printf("%d ", cur);
        for (int i = adjSize[cur] - 1; i >= 0; i--) {
            int nb = adjList[cur][i];
            if (!seen[nb]) {
                stackArr[top++] = nb;
            }
        }
    }
    printf("\n");
}

int main() {
    build();
    bfs(1);
    dfs(1);
    return 0;
}
