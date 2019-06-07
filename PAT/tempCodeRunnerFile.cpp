#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,c1,c2;//城市数目，道路数目，出发地，目的地
    cin>>n>>m>>c1>>c2;
    int e[n][n],weight[n],dis[n],num[n],w[n];//图，节点权重，距离，道路数目，救援队数目
    for(int i = 0;i < n; i++)
    {
        cin>>weight[i];
    }
    bool visit[n] = {0};//标记是否为已计算过 
    int flow = 99999999;
    //开始填充为无穷大
    fill(e[0],e[0]+n*n,flow);
    fill(dis,dis+n,flow);
    int a,b,c;//输入边的权重
    for(int i=0; i < m; i++)
    {
        cin>> a >> b >> c;
        e[a][b]=e[b][a]=c;
    }
    dis[c1] = 0;//开始城市距离为0
    w[c1] = weight[c1];//开始救援队伍
    num[c1] = 1;//开始的路径数目

    for(int i=0; i < n; i++)
    {
        int u = -1;
        int min = flow;
        for(int j = 0; j<n; j++)
        {
            if(visit[j]==false && dis[j] < min)//节点没做计算，节点距离更小
            {
                u = j;
                min = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(visit[v]==false && e[u][v]!=flow)
            {
                if(dis[u] + e[u][v] < dis[v])
                {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }else if(dis[u] + e[u][v] == dis[v])
                {
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v])
                    {
                        w[v] = w[u] + weight[v];
                    }
                }
            }
        }
    }
    cout << num[c1] << " " <<w[c2];
    return 0;
}