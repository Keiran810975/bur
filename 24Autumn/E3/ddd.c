#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct Node {
    int id;
    struct Node* next;
} Node;
Node* adj[MAXN];
int color[MAXN];
int visited[MAXN];
int operations = 0;
void addEdge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = v;
    node->next = adj[u];
    adj[u] = node;
}
int dfs(int u) {
    visited[u] = 1;
    int isWhiteSubtree = 1; 

    for (Node* node = adj[u]; node != NULL; node = node->next) {
        int v = node->id;
        if (!visited[v]) {
            int isWhiteChild = dfs(v);
            if (isWhiteChild == 0) {
                isWhiteSubtree = 0;
            }
        }
    }
    if (color[u] == 1) {
        isWhiteSubtree = 0;  
    }
    if (isWhiteSubtree && color[u] == 0) {
        operations++;
        isWhiteSubtree = 0; 
    }

    return isWhiteSubtree;
}
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        adj[i] = NULL;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(1); 

    printf("%d\n", operations);
    for (int i = 1; i <= n; i++) {
        Node* node = adj[i];
        while (node) {
            Node* tmp = node;
            node = node->next;
            free(tmp);
        }
    }

    return 0;
}
