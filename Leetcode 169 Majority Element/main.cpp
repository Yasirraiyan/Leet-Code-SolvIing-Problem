class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    count++;
                }
            }
            if(count>nums.size()/2)
        {
            return nums[i];
        }
        
        
        count=0;
    }
    return -1;
    }
};
