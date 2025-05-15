#include<vector>
class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
       
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        int n=nums.size();
        int ans;
        for(auto it:freq)
        {
          if(it.second==n/2)
          {
            ans=it.first;
          }
        }
       return ans;

    }
};
