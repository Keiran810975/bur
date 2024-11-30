#include<stdio.h>
#include<string.h>
#define MaxSize 100
#define INF 1000000
int graph[MaxSize][MaxSize];
int numEdge[100][100];
int vetrix[100];
int prim(int n)                 //初始选取顶点0
{
    int lowcost[100],sum = 0;      //数组lowcost用来存储V-T中的顶点到T的最短距离，lowcost[i] = 0表示顶点i在树T中
    int count = 1;        //vetrix[i]表示i到T中顶点vetrix[i]的距离最小，用于打印路径
    lowcost[0] = 0;
    for(int i = 0;i < n;i++)
    {
        lowcost[i] = graph[0][i];
        vetrix[i] = 0;
    }
    while(count <n)
    {
        int min = INF;
        int min_index;
        for(int i = 1;i < n;i++)
        {
            if(lowcost[i] != 0 && lowcost[i] < min) //找到权最小的边<vetrix[i],i>，其中vetrix[i]在T中，i在V-T中
            {
    	        min = lowcost[i];       //min记录最小的权值
    	        min_index = i;          //min_index记录最小边对应的顶点,即要加入T中的顶点
            }
        }
        sum += min;
        lowcost[min_index] = 0;
        count++;
        printf("%d ", numEdge[vetrix[min_index]][min_index]);
        //printf("%d->%d\n", vetrix[min_index],min_index);
        printf("%d->%d\n", vetrix[min_index],min_index);
        for(int i = 1;i < n;i++)
        {
	    if(lowcost[i] != 0 && lowcost[i] > graph[min_index][i])       //由于新加入T的顶点min_index,更新V-T中的顶点到T的最短距离，及对应的顶点
	        lowcost[i] = graph[min_index][i];
	        vetrix[i] = min_index;      
        }
    }
    return sum;
}
void initg(){//初始化邻接矩阵
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            graph[i][j]=INF;
        }
    }
}
int main(){
    initg();
    int n, e, v1, v2;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++){
        int x,y,w,a;
        scanf("%d%d%d%d",&a,&x,&y,&w);
        numEdge[x][y]=a;
        numEdge[y][x]=a;
        graph[x][y]=w;
        graph[y][x]=w;
    }
    printf("\n%d\n",prim(n));
    return 0;
}
