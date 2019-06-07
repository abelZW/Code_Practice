#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int max = 0,min = 99999999;
    int maxID,minID;
    int n;//总人数
    cin >> n;
    string ID[n];//人员ID
    int Time[n][6];
    // int h1,h2,m1,m2,s1,s2;
    int SecondIN[n];
    int SecondOUT[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ID[i];
        scanf("%d:%d:%d %d:%d:%d",&Time[i][0],&Time[i][1],&Time[i][2],&Time[i][3],&Time[i][4],&Time[i][5]);
        SecondIN[i] = Time[i][0]*3600 + Time[i][1]*60 + Time[i][2];
        SecondOUT[i] = Time[i][3]*3600 + Time[i][4]*60 + Time[i][5];
        if(SecondOUT[i] > max)
        {
            max = SecondOUT[i];
            maxID = i;
        }
        if(SecondIN[i] < min)
        {
            min = SecondIN[i];
            minID = i;
        }
    }
    cout << ID[minID] <<" " << ID[maxID];
    return 0;
}