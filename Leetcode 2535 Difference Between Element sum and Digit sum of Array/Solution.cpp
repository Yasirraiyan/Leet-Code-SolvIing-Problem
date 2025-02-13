#include<vector>
#include<iostream>
#include<cmath>
class Solution {
public:
int digitsum(int n)
{
    int sum1=0;
    while(n>0)
    {
        sum1+=n%10;
        n=n/10;
    }
    return sum1;
}
    int differenceOfSum(vector<int>& nums) 
    {
        int sum2=0;
        int sum3=0;
        int result;
        for(int i=0;i<nums.size();i++)
        {
            sum2+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
          sum3+=digitsum(nums[i]);
        }
        result=abs(sum2-sum3);
        return result;
    }
};
