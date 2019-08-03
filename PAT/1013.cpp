/**************************************
 * 解题思路
 * 一个图，某个点抹掉之后所构成的子图个数，然后：子图个数-1=恢复道路条数
 * DFS
 * 遇到问题：使用scanf所消耗时间比cin要短，才可以过最后一个实例
 * ***********************************/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int v[1010][1010];//图
bool visit[1010];//标记每个点
int n;//n*n为城市构建图
void dfs(int node){
    visit[node] = true;
    for(int i = 1;i <=n; i++){
        if(visit[i]==false && v[node][i] == 1)
        dfs(i);
    }
}
int main()
{
    int m,k,a,b;
    cin >> n >> m >> k;//城市数量，道路数量，需要被检查的城市数量
    for(int i = 0; i < m; i++){
        // cin >> a >> b;
        scanf("%d%d",&a,&b);
        v[a][b] = v[b][a] = 1;//输入城市的图结构
    }
    for(int i = 0; i < k; i++){
        fill(visit,visit+1010,false);
        // cin >> a;
        scanf("%d",&a);
        int num = 0;//子图数量
        visit[a] = true;//检查的城市标记
        for(int j = 1; j <= n; j++){
            if(visit[j]==false){
                dfs(j);
                num++;
            }
        }
        cout << num-1 << endl;
    }
    return 0;
}