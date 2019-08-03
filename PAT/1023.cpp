/**************************************
 * 解题思路
 * 
 * 
 * 
 * 问题：printf中无法输出字符串
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
int book[10] = {0};
/*********************
int main()
{
    char num[22];//数字20位，末尾\0，可能进位
    scanf("%s", num);
    int flag = 0,len = 0;
    for(int i = 0; num[i] != '\0'; i++)
        len++;
    // cout << len;
    for(int i = len - 1; i >= 0; i--){
        int temp = num[i] - '0';
        book[temp]++;
        temp = temp*2 + flag;
        flag = 0;
        if(temp >= 10){
            flag = 1;
        }
    }
    int flag1 = 0;
    for(int i = 0; i < 10; i++){
        if(book[i] != 0)
            flag1 = 1;
    }
    printf("%s", (flag == 1 || flag == 1) ? "No\n":"Yes\n");
    if(flag == 1) printf("1");//进位输出
    printf("%s", num);
    return 0;
}
**********************/

bool judge(string &s){
    reverse(s.begin(),s.end());
    int len = s.length(),carry = 0;
    for(int i = 0; i < len; i++){
        s[i] = s[i] + s[i] + carry - '0';   //ASCLL码进行运算，若jin
        carry = 0;                          //carry进位标识符   
        if(s[i] > '9'){
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s+='1';//string中加法运算
    reverse(s.begin(),s.end());
    for(int i = 0; i < s.length(); i++){
        book[s[i]-'0']--;
    }
    for(int i = 0; i < s.length(); i++){
        if(book[i] != 0)
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        book[s[i]-'0']++;
    }
    if(judge(s))
        cout << "Yes" << endl << s;
    else
        cout << "No" << endl << s;
    return 0;
}