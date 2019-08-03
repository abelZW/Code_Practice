/**************************************
 * 解题思路
 * 大数运算采用字符串存储进行运算
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
string s;
void add(string &t){
    int len = s.length(),carry = 0;
    for(int i = 0; i < len; i++){
        s[i] = s[i] + t[i] + carry - '0';   //ASCLL码进行运算，若jin
        carry = 0;                          //carry进位标识符   
        if(s[i] > '9'){
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s+='1';//string中加法运算
    reverse(s.begin(),s.end());
}

int main()
{
    int cnt,i;
    cin >> s >> cnt;
    for(i = 0; i <= cnt; i++){
        string t = s;
        reverse(t.begin(),t.end());
        if(s == t || i == cnt) break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}