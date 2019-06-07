#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    char tag[4] = {"WTL"};
    double sum = 1.0;
    int max_index[3] = {0};
    for(int i = 0; i < 3; i++)
    {
        double max_value = 0.0;
        // max_index[i] = 0;
        for(int j = 0; j < 3; j++)
        {
            double score;
            cin >> score;
            if(max_value <= score)
            {
                max_value = score;
                max_index[i] = j;
            }
        }
        // cout << max_value << endl;
        sum = sum * max_value;
    }
    for(int i = 0; i < 3;i++)
    {
        cout << tag[max_index[i]] << " ";
    }
    sum = (sum*0.65 - 1) * 2;
    printf("%0.2f",sum);
    return 0; 
}