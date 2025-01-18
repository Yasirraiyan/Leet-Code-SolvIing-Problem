#include<vector>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int tempCount = 0;
        
        
        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<=nums.size();j++)
            {
                if(i==j+1)
                {
                    if(i < nums.size() && j < nums.size()&& nums[i] == 1 && nums[j] == 1)
                    {
                   count++;
                    }
               
                }
            }
        }
        
        return count;
    }
};
