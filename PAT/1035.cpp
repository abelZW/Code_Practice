/**************************************
 * 解题思路
 * switch中修改字符串，定义结构体
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
struct PW{
    string name,s;
    int flag = 0;
}PW;
int main()
{
    int n,cnt = 0;//输入个数，修改个数
    scanf("%d",&n);
    struct PW num[n];
    for(int i = 0; i < n; i++){
        cin >> num[i].name >> num[i].s;
        int len = num[i].s.length();
        for(int j = 0; j < len; j++){
            switch(num[i].s[j]){
                case '1' : num[i].s[j] = '@'; num[i].flag = 1; break;
                case '0' : num[i].s[j] = '%'; num[i].flag = 1; break;
                case 'l' : num[i].s[j] = 'L'; num[i].flag = 1; break;
                case 'O' : num[i].s[j] = 'o'; num[i].flag = 1; break;
            }
        }
        if(num[i].flag ==  1)
            cnt++;
    }
    if(cnt != 0){
        printf("%d\n",cnt);
        for(int i = 0; i < n; i++)
            if(num[i].flag == 1)
                cout << num[i].name << " " << num[i].s << endl;
    }else if(n == 1) {
        printf("There is 1 account and no account is modified");
    } else {
        printf("There are %d accounts and no account is modified", n);
    }

    return 0;
}

//法二
// int main() {
//     int n;
//     scanf("%d", &n);
//     vector<string> v;
//     for(int i = 0; i < n; i++) {
//         string name, s;
//         cin >> name >> s;
//         int len = s.length(), flag = 0;
//         for(int j = 0; j < len; j++) {
//             switch(s[j]) {
//                 case '1' : s[j] = '@'; flag = 1; break;
//                 case '0' : s[j] = '%'; flag = 1; break;
//                 case 'l' : s[j] = 'L'; flag = 1; break;
//                 case 'O' : s[j] = 'o'; flag = 1; break;
//             }
//         }
//         if(flag) {
//             string temp = name + " " + s;
//             v.push_back(temp);
//         }
//     }
//     int cnt = v.size();
//     if(cnt != 0) {
//         printf("%d\n", cnt);
//         for(int i = 0; i < cnt; i++)
//             cout << v[i] << endl;
//     } else if(n == 1) {
//         printf("There is 1 account and no account is modified");
//     } else {
//         printf("There are %d accounts and no account is modified", n);
//     }
//     return 0;
// }