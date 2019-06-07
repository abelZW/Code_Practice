#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//数据过大，不可以直接做为整形数据输入，100位数据
/*int main()
{
    int sum = 0;
    long long int num;
    cin >> num;
    long long int temp = num;
    while(temp > 0)
    {
        sum = sum + temp%10;
        temp = temp/10;
    }
    cout << sum << endl;
    string s = to_string(sum);
    int a[s.length()];
    temp = sum;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        a[i] = temp%10;
        temp = temp / 10;

        cout << temp << endl;
    }
    string digit[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << digit[a[0]];
    for(int i = 1; i < s.length(); i++)
    {
        // cout << " " << digit[s[i] - '0'];
        cout << " " << digit[a[i]];
    }
    return 0;
}*/
int main()
{
    string s;
    cin >> s;
    string digit[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int sum;
    for(int i = 0;i < s.length(); i++)
    {
        sum = sum + s[i] - '0';
    }
    string Sum = to_string(sum);
    cout << digit[Sum[0] - '0'];
    for(int i = 1; i < Sum.length(); i++)
    {
        cout << " " << digit[Sum[i] - '0'];
    }
}