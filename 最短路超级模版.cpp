#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#define INF 999999999
using namespace std;

const int MAXN = 105;  //最大节点数
int START,END;
int graph[MAXN][MAXN];

void initialize();
void add(int u, int v, int w);//u-起点;v-终点;w-权
void floyd(int x);//x-节点个数
void SPFA(int s,int x);//s-起点节点;x-节点个数
void dijkstra(int s,int x);//s-起点节点;x-节点个数

int main()
{
    //注意编号从0开始还是1开始，相应模版要做微调
    //目前编号默认从1起
    int i,j,n,m,u,v,w;
    while(cin>>n>>m)
    {
        START = 1;   //起点
        END = n;     //终点
        if(m==0 && n==0)
            break;
        initialize();
        for(i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            add(u,v,w);
        }
        floyd(n);
        //dijkstra(START,n);
        //SPFA(START,n);
    }
	return 0;
}

void initialize() //初始化
{
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<MAXN;j++)
        {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
}

void add(int u, int v, int w) //向矩阵中加入边
{
    //记得有向图要处理下
    if(w<graph[u][v] || w<graph[v][u])
    {
        graph[u][v] = w;
        graph[v][u] = w;
    }
}

void floyd(int x) //注意编号范围
{
    int i,j,k;
    for(k=1;k<=x;++k)
    {
        for(i=1;i<=x;++i)
        {
            for(j=1;j<=x;++j)
            {
                if(graph[i][k]+graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k]+graph[k][j];
            }
        }
    }
    cout<<graph[START][END]<<endl;
}

void SPFA(int s, int x) //注意编号范围
{
    queue<int> q;
    while(q.empty() == false)
    {
        q.pop();
    }
    int dis[MAXN];
    int vis[MAXN];
    int i,temp;
    for(i=0;i<=x;i++)
        dis[i] = INF;
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(q.empty() == false)
    {
        temp = q.front();
        q.pop();
        vis[temp] = 0;
        for(i=1;i<=x;i++)
        {
            if(graph[temp][i]>0 && dis[i]>dis[temp]+graph[temp][i])
            {
                dis[i] = dis[temp]+graph[temp][i];
                if(vis[i] == 0)
                {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
    cout<<dis[END]<<endl;
}

void dijkstra(int s,int x) //注意编号范围
{
    int i,j,minn,u=0;
    int v[MAXN];
    int dis[MAXN];
    memset(v,0,sizeof(v));
    memset(dis,0,sizeof(dis));
    for(i=1;i<=x;i++)
    {
        dis[i] = graph[s][i];
    }
    v[s] = 1;
    for(i=1;i<=x;i++)
    {
        minn = INF;
        for(j=1;j<=x;j++)
        {
            if(v[j]==0 && dis[j]<minn)
            {
                minn = dis[j];
                u = j;
            }
        }
        v[u] = 1;
        for(j=1;j<=x;j++)
        {
            if(v[j]==0 && dis[j]>dis[u]+graph[u][j])
                dis[j] = dis[u]+graph[u][j];
        }
    }
    cout<<dis[END]<<endl;
}