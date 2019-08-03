/**************************************
 * 解题思路
 * 如果一个数n为素数，而且在d进制下反转后的数
 * 在十进制下依旧是素数，输出YES或者NO
 *  0 < n < 105    1 < d <= 10
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
bool isprime(int n)//判定是否为素数
{
    if( n <= 1) return false; //1不为素数
    int sqr = int(sqrt(n*1.0));//求平方数
    for(int i = 2; i <= sqr; i++){
        if(n%i == 0)
        return false;
    }
    return true;
}
int rever_prime(int n,int d)//d进制反转数
{
    int len = 0, temp = 0,arr[100]={0};
    while(n > 0)
    {
        arr[len++] = n%d;
        n = n / d;
    }
    for(int i = 0; i < len; i++)
    {
        n = n*d + arr[i];
    }
    return n;
}

int main()
{
    int n,d;
    n = 0;
    while(scanf("%d",&n)!=EOF)//不进行输入时自动结束while循环
    {
        if(n < 0) break;
        scanf("%d",&d);//转换进制
        if(isprime(n) == false){
            printf("No\n");
            continue;
        }
        n = rever_prime(n,d);
        printf("%s",isprime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}