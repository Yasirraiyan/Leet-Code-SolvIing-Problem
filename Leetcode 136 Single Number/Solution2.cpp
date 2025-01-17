class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count=0;
        int i;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
               if(nums[i]==nums[j])
               {
                count++;
               }
            }
             
        }
        if (count==1)
        {
            return nums[i];
        }
        return nums[i];
    }
};
