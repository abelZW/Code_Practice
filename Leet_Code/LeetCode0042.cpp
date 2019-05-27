/*
接雨水
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int sum=0;//储水量
        int left=0,left_max=0,right=len-1,right_max=len-1;
        for(int i=0;i<len;i++)
        {
            if(height[left] <= height[i])
            {
                for(int j = left; j < i; j++){
                    sum = sum + height[left] - height[j];
                }
                left_max = i;
                left = i;
            }
        }
        printf("第一次%d\n",height[left]);
        for(int i = len - 1; i >= left_max; i--)//右侧开始计算终止条件是到达左侧计算的最大值
        {
            if(height[right] <= height[i])//右侧同样可能遇到两个数组值相同
            {
                for(int j = right; j > i; j--){
                    sum = sum + height[right] - height[j];
                }
                right_max = i;
                right = i;
            }
        }
        printf("第二次%d\n",height[right]);
        return sum;
    }
};
int main()
{
    Solution solution;
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {4,2,0,3,2,5};
    cout << solution.trap(height) << endl;
    return 0;
}