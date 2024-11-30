#include<iostream>
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
const int MAX_NODES=550;
const int INF=INT_MAX;
typedef pair<int,int> pii;
int adjMatrix[MAX_NODES][MAX_NODES];
pii edges[5500];
int numNodes;

//初始化
void init(int n){
    numNodes=n;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            adjMatrix[i][j] = (i == j) ? 0 : INF; 
        }
    }
}


int dijkstra(int n, int s, int t) {
    vector<int> dist(n + 1, INF); 
    vector<bool> visited(n + 1, false); 
    dist[s] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) break;
        visited[u] = true;

        for (int v = 1; v <= n; v++) { 
            if (!visited[v] && adjMatrix[u][v] != 0 && adjMatrix[u][v] != INF) {
                if (dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }
    }

    return dist[t] == INF ? -1 : dist[t];
}


int main() {
    int m,q;
    cin>>numNodes>>m>>q;
    init(numNodes);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjMatrix[u][v]=w;
        adjMatrix[v][u]=w;
        edges[i]={u,v};
    }
    // printf("****\n");
    // printf("%d\n",dijkstra(numNodes,1,4));
    // printf("****\n");
    while(q--){
        int s,t,k;
        cin>>s>>t>>k;
        int minDis=dijkstra(numNodes,s,t);
        if(minDis==-1){
            printf("No1\n");
        }else{
            pii a=edges[k];
            int x=a.first,y=a.second;
            int d1=dijkstra(numNodes,s,x),d2=dijkstra(numNodes,y,t);
            int d3=dijkstra(numNodes,s,y),d4=dijkstra(numNodes,x,t);
            int xx=d1+d2+adjMatrix[x][y];
            int yy=d3+d4+adjMatrix[x][y];
            if(xx==minDis||yy==minDis){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    
    return 0;
}