#include<cmath>
#include<vector>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      bool contain;
       for(int i=0;i<nums.size();i++) 
       {
        for(int j=i+1;j<nums.size();j++)
        {
            if (abs(i - j) > k) {
                    break; // Early exit from the loop if the condition is not met
                }
            if(abs(i-j)<=k)
            {
                if(nums[i]==nums[j])
                {
                return true;
                }
               
            }
        }
       }
       
       return false;
       
    }
};
