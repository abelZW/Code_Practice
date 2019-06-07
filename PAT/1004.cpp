#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> T[100];//树最多100个节点,类似一个动态的二维数组
int floor[100] = {0};//树最多100层
int maxdepth = -1;
void dfs(int index,int depth)
{
    if(T[index].size() == 0){
        floor[depth]++;
        maxdepth = max(maxdepth,depth);
        cout << maxdepth << endl;
        return ;
    }
    for(int i = 0; i < T[index].size(); i++)
    {
        dfs(T[index][i],depth + 1);
    }
}
int main()
{
    int n,m;//节点个数，非叶子节点个数
    cin >> n >> m;
    int num,node,node_c;//孩子数，节点值，子节点值
    for(int i = 0; i < m; i++)
    {
        cin >> node >> num;
        for(int j = 0; j < num; j++)
        {
            cin >>node_c;
            T[node].push_back(node_c);//节点的子节点
        }
    }
    dfs(1,0);
    cout << floor[0];
    for(int i = 1; i <= maxdepth; i++)
    {
        cout << " " << floor[i];
    }
    return 0;
}