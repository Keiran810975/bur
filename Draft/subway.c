#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVEX 1000
#define INF 32767
 
typedef struct station
{
    char station_name[32];
    int istransfer; //if the station is a transfer station
} Vex;
 
typedef struct edge
{
    int weight;
    int line; //line of the edge
} Edge;
 
Vex v[MAXVEX];            //vertex of station
int vnum = 0;             //number of station
Edge mat[MAXVEX][MAXVEX]; //adjacency matrix
 
int add_vex(Vex p)
{ //return index(xia'biao) of p in v[];
    if (!p.istransfer)
    { //if p is not a transfer station
        v[vnum++] = p;
        return vnum - 1; //add p into v and return index
    }
    else
    {
        for (int i = 0; i < vnum; i++)
        { //if p is already in v[], don't add and return its index
            if (!strcmp(p.station_name, v[i].station_name))
                return i;
        }
        v[vnum++] = p; //if p is not in v[],add p into v
        return vnum - 1;
    }
}
 
void create_graph()
{ //to make the map of Beijing Subway
    FILE *src = fopen("bgstations.txt", "r");
    int v1, v2; //v1 is the index of last station,v2 is the index of present station
    int line_cnt;
    Vex tmp_vex;
    fscanf(src, "%d", &line_cnt);
    for (int i = 0; i < line_cnt; i++)
    {
        int lineID, staion_cnt;
        fscanf(src, "%d%d", &lineID, &staion_cnt);
        v1 = v2 = -1;
        for (int j = 0; j < staion_cnt; j++)
        {
            fscanf(src, "%s%d", tmp_vex.station_name, &tmp_vex.istransfer);
            v2 = add_vex(tmp_vex);
            if (v1 != -1)
            {
                mat[v1][v2].weight = mat[v2][v1].weight = 1;
                mat[v1][v2].line = mat[v2][v1].line = lineID;
            }
            v1 = v2;
        }
    }
    fclose(src);
}
 
int visited_dfs[MAXVEX] = {0};
void DFS(int i)
{
    printf("%s\n", v[i].station_name);
    visited_dfs[i] = 1;
    for (int j = 0; j < vnum; j++)
    {
        if (mat[i][j].weight > 0 && visited_dfs[j] == 0)
        {
            DFS(j);
        }
    }
}
 
int sweight[MAXVEX]; //to record the shortest len between i and v0
int spath[MAXVEX];   //to record the shortest path
void Dijkstra(int v0)
{
    int minweight, minv;
    int wfound[MAXVEX] = {0}; //to sign if the shortest path from i to v0 is found
    for (int i = 0; i < vnum; i++)
    {
        sweight[i] = mat[v0][i].weight;
        spath[i] = v0;
        wfound[i] = 0;
    }
    sweight[v0] = 0;
    wfound[v0] = 1;
    for (int i = 0; i < vnum - 1; i++)
    {
        minweight = INF;
        for (int j = 0; j < vnum; j++)
        {
            if (!wfound[j] && sweight[j] < minweight)
            {
                minv = j;
                minweight = sweight[minv];
            }
        }
        wfound[minv] = 1;
        for (int j = 0; j < vnum; j++)
        {
            if (!wfound[j] && (minweight + mat[minv][j].weight) < sweight[j])
            {
                sweight[j] = minweight + mat[minv][j].weight;
                spath[j] = minv;
            }
        }
    }
}
int final_path[MAXVEX] = {0};
int path_cnt = 0;
void reverse()
{
    int temple[MAXVEX] = {0};
    for (int i = 0; i < path_cnt; i++)
    {
        temple[path_cnt - 1 - i] = final_path[i];
    }
    for (int i = 0; i < path_cnt; i++)
    {
        final_path[i] = temple[i];
    }
}
 
void put_path()
{
    int now, last, way_now, len;
    last = 0, now = 1;
    way_now = mat[final_path[last]][final_path[now]].line;
    len = 0;
    printf("%s", v[final_path[0]].station_name);
    for (; now < path_cnt; now++)
    {
        if (way_now != mat[final_path[last]][final_path[now]].line)
        {
            printf("-%d(%d)-%s", way_now, len, v[final_path[last]].station_name);
            way_now = mat[final_path[last]][final_path[now]].line;
            len = 0;
        }
        len++;
        last = now;
    }
    printf("-%d(%d)-%s", way_now, len, v[final_path[last]].station_name);
}
 
int main()
{
    for (int i = 0; i < MAXVEX; i++)
    {
        for (int j = 0; j < MAXVEX; j++)
        {
            mat[i][j].weight = INF;
            mat[i][j].line = 0;
        }
    }
    create_graph();
    char begin[32], end[32];
    scanf("%s%s", begin, end);
    int index_b, index_e;
    for (int i = 0; i < vnum; i++)
    {
        if (!strcmp(begin, v[i].station_name))
        {
            index_b = i;
        }
        if (!strcmp(end, v[i].station_name))
        {
            index_e = i;
        }
    }
    
    Dijkstra(index_b);
    int tmp = index_e;
    while (tmp != index_b)
    {
        final_path[path_cnt++] = tmp;
        tmp = spath[tmp];
    }
    final_path[path_cnt++] = tmp;
    reverse();
    put_path();
}