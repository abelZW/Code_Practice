/**************************************
 * 解题思路
 * 输入数字都是两位，直接转换为对应的13进制数
 * 根据字符串数组对应到进制
 * 字符串数组相加
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
    string color = "0123456789ABC",result = "#";
    for(int i = 0; i < 3; i++){
        int num;
        scanf("%d", &num);
        result = result + color[num/13] + color[num%13];
    }
    cout << result;
    return 0;
}