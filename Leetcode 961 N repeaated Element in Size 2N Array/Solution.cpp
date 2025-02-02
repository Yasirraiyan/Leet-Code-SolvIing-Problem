#include<vector>
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int count=0;
        vector<int>ans;//(2*nums.size())
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(i!=j)
                {
                if(nums[i]==nums[j])
                {
                  ans.push_back(nums[i]);
                  count++;
                  break;
                }
                }
            }
        }
        if(!ans.empty())
        {
            return ans[0];
        }
        return -1;
    }
};
