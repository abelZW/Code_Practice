#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cctype>
#include<cmath>
using namespace std;
 
 /******************************************************
//可能最后会爆掉
//数字转换
int digit_translate(char c)
{
    if(int(c) >= int('0')&&int(c)<=int('9'))
    {
        return (int(c) - int('0'));
    }
    else
    {
        return int(c) - int('a') + 10;
    }
    
}

//r基底的数
long long r_digit(string s,int r)
{
    long long sum = 0;
    for(int i = 0; i < s.size();i++)
    {
        sum = sum *r;
        sum = sum + digit_translate(s[i]);
        if(sum < 0)//溢出,设置结果为-1
            return -1;
    }
    return sum;
}

//查找基底
long long FindRadix(long long start,long long end, long long n1,string n2)
{
    //二分查找
    long long mid = (start + end) / 2;//确定进制
    long long temp = r_digit(n2,mid);//计算数值
    long long result = -1;
    if(start <= end)//查找条件
    {
        if(temp == -1 || temp > n1)//溢出减小基底
        {
            result = FindRadix(start,mid - 1, n1, n2);
        }
        else if(temp < n1){
            result = FindRadix(mid+1,end,n1,n2);
        }
        else {
            result = mid;
        }
    }
    return result;
}

int main()
{
    string N1,N2;
    string temp;
    int tag,r;

    cin >> N1 >> N2 >> tag >>r;
    if(tag == 2)
    {
        //swap(N1,N2);
        temp = N2;
		N2 = N1;
		N1 = temp;
    }
    long long n1 = 0, n2 = 0;
    n1 = r_digit(N1,r);//将n1转换为十进制数

    long long Radix = 0;
    long long MinRadix = 2;//最小二进制
    long long MaxRadix = n1 + 1;//上界
    for(int i  = 0; i < N2.size();i++){
        if(digit_translate(N2[i])  >= MinRadix)
            MinRadix = digit_translate(N2[i]) + 1;
    }

    Radix = FindRadix(MinRadix,MaxRadix,n1,N2);
    if(Radix != -1){
        cout << Radix << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}
*******************************************************/

long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }   
    return 0;
}