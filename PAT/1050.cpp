/**************************************
 * 解题思路
 * 1、sizeof():返回所占总空间的字节数
    （1）、对于整型字符型数组
    （2）、对于整型或字符型指针
 * 2、strlen():返回字符数组或字符串所占的字节数
    （1）、针对字符数组
    （2）、针对字符指针
 * 256个字符直接标记在s2中是否存在，之后在s1中匹配
 * 
 * 问题：字符串长度总体在100000
 * ***********************************/
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

int main(){
    char s1[100000],s2[100000];
    cin.getline(s1,100000);//getline(cin,s1);
    cin.getline(s2,100000);
    int lens1 = strlen(s1),lens2 = strlen(s2);
    bool flag[256] = {false};
    for(int i = 0; i < lens2; i++){
        flag[s2[i]] = true;
    }
    for(int i = 0; i < lens1; i++){
        if(flag[s1[i]] == false)
            printf("%c",s1[i]);
    }
    return 0;
}
