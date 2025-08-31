class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
          if(nums.empty()) return 0;
        int i=0;
        int j=1;
        while(/*i<j&&i<nums.size()&&*/j<nums.size())
        {
            if(nums[i]==nums[j])
            {
                j++;
            }
            else
            {
                 i++;
                  nums[i]=nums[j];
           
          
            }
        }
        int ans=i+1;
        return ans;
    }
};
