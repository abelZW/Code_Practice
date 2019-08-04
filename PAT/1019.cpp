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

int main()
{
    int num,base;
    cin >> num >> base;
    int arr[40],index = 0;
    while(num != 0){
        arr[index++] = num % base;
        num = num / base;
    }
    int flag = 0;
    for(int i = 0; i < index / 2; i++)
    {
        if(arr[i] != arr[index - i - 1]){
            printf("No\n");
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("Yes\n");
    printf("%d",arr[--index]);
    for(int i = index -1; i >= 0; i--){
        printf(" %d",arr[i]);
    }
    
    return 0;
}