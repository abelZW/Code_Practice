#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
    //项系数最大为1001，所以应该定义1001内存数组
    int const max = 1001;
    float c[max] = {0};
    int m,n,t;
    float num;//项系数
    cin >> m;
    for (int i=0; i < m; i++){
        cin >> t >> num;
        c[t] += num;
    }
    cin >> n;
    for (int i=0; i < n; i++){
        cin >> t >> num;
        c[t] += num;
    }

    int cnt = 0;//记录最后的项数
    for (int i=0; i < max; i++){
        if(c[i] != 0.0)
        cnt++;
    }
    cout << cnt;
    for (int i=max-1; i >= 0; i--){
        if(c[i] != 0.0)
        {
            printf(" %d %0.1f",i,c[i]);
            //cout <<" "<< i << " " << c[i];
        } 
    }
    return 0;
}