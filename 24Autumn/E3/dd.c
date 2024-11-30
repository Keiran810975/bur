#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100005

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAXN];  
int color[MAXN];      
bool visited[MAXN];  
int operations = 0;   
int n;              

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}
bool dfs(int node) {
    visited[node] = true;
    bool has_black_child = (color[node] == 1);  
    Node* current = adjList[node];
    while (current != NULL) {
        int child = current->vertex;
        if (!visited[child]) {
            if (dfs(child)) {
                has_black_child = true;
            }
        }
        current = current->next;
    }
    if (color[node] == 0 && has_black_child) {
        operations++;
        has_black_child = true; 
    }

    return has_black_child;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    dfs(1);
    printf("%d\n", operations);
    for (int i = 1; i <= n; i++) {
        Node* current = adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
