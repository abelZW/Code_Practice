/**************************************
 * 解题思路
 * 
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

int FriendNum(int num){
    int sum = 0;
    while(num != 0){
        sum = sum + (num % 10);
        num = num / 10;
    }
    return sum;
}
int main()
{
    int flag[90] = {0};
    int j = 0,n,num,cnt = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&num);
        flag[FriendNum(num)] = flag[FriendNum(num)] + 1;
        if(flag[FriendNum(num)] == 1)
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    while(flag[j] == 0)
        j++;
    printf("%d",j);
    for(int i = j+1; i < 90; i++)
    {
        if(flag[i] != 0)
            printf(" %d",i);
    }
    return 0;
}