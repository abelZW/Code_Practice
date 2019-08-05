/**************************************
 * 解题思路
 * 两个数组，第一个数组记录输入的数值，第二个数组记录每个数值出现的次数
 * 即第一个数组值为第二个数组的下标
 * 在第二个数组中查找第一次出现1的数组值
 ************************************/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string.h>
using namespace std;
int a[100001],m[100000] = {0};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n; i++)
    {
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        if(m[a[i]] == 1){
            printf("%d",a[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}