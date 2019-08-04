/**************************************
 * 解题思路
 * 环形路径，计算每个点到初始点距离，
 * 两点距离在环上两条路径，确保 left  < right
 * 
 * vector中() 和[]
 * 
 * 
 * 
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

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> dis(n+1);//arr长度为n+1
    int sum = 0,left,right,cnt;
    for(int i = 1; i <= n; i++){
        int temp;
        scanf("%d",&temp);
        sum = sum + temp;
        dis[i] = sum;
        // dis.push_back(sum);
    } 
    scanf("%d",&cnt);
    int result[cnt];
    for(int i = 0; i < cnt; i++){
        scanf("%d %d",&left,&right);
        if(left > right)
            swap(left,right);
        int temp = dis[right - 1] - dis[left - 1];
        // printf("%d\n",min(temp,sum-temp));
        result[i] = min(temp,sum-temp);
    }  
    for(int i = 0; i < cnt; i++){
        printf("%d\n",result[i]);
    }
    return 0;
}