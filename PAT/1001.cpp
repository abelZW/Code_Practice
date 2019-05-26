#include<iostream>
#include<string>
#include<vector>
#include<map>
//to_string()转换整形数据为字符串
using namespace std;
int main()
{
    int num1,num2;
    cin >> num1 >>num2;
    string s = to_string(num1+num2);
    int size = s.length();
    for(int i = 0;i < size;i++)
    {
        cout << s[i];
        if(s[i]=='-') 
        //continue;
        {
            cout << s[++i];
        }
        if((i+1)%3 == size%3 && (i+1) < size)//余数相同时输出“,”
            cout <<",";
    }
    return 0;
}