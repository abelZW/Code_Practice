/*****************************
分析：
１、结构体表示学生的ＩＤ、四门成绩、四门排名、最好的排名所对应学科的下标
２、排名并列使用１、１、３、４、５，不为１、１、２、３、４　　　测试无法通过
３、平均分四舍五入，所以需要按照＋０．５后取整，保证四舍五入
４、存储的时候直接默认ACMＥ的顺序存储数据可简化程序逻辑
５、用exist数组保存当前ｉｄ是否存在，这个ｉｄ对应结构体的下标为多少。用ｉ＋１可以保证为零的都是不存在的可以直接输出Ｎ/A，
　　其余不为０的保存的值是对应结构体index+1的值
 *****************************/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node{
    int id,best;
    int score[4],rank[4];
}stu[2001];//总的学生数最大为2000
int exist[1000000],flag = -1;
bool cmp(node a,node b) {return a.score[flag] > b.score[flag];}
int main()
{
    int n,m,id;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0 + 0.5;
    }
    for(flag = 0; flag <= 3; flag++){
        sort(stu,stu+n,cmp);
        stu[0].rank[flag] = 1;
        for(int i = 1;i<n;i++){
            stu[i].rank[flag] = i+1;
            if(stu[i].score[flag] == stu[i-1].score[flag])
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
    }
    for(int i = 0;i < n; i++){
        exist[stu[i].id] = i + 1;
        stu[i].best = 0;
        int minn = stu[i].rank[0];
        for(int j = 1; j <= 3; j++){
            if(stu[i].rank[j] < minn){
                minn = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }
    char c[5] = {'A','C','M','E'};
    for(int i = 0; i < m; i++){
        scanf("%d",&id);
        int temp = exist[id];
        if(temp){
            int best = stu[temp-1].best;
            printf("%d %c\n",stu[temp-1].rank[best],c[best]);
        }else{
            printf("N/A\n");
        }
    }
    
    return 0;
}