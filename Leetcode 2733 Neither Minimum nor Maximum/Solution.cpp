class Solution 
{
public:
    int findNonMinOrMax(vector<int>& nums) 
{
        int min=nums[0];
        int max=nums[0];
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<min)
            {
                min=nums[i];
            }
            if(nums[i]>max)
            {
                max=nums[i];
            }
            
            
        }
       for(int j=0;j<nums.size();j++)
       {
        if(nums[j]!=min&&nums[j]!=max)
       {
            ans=nums[j];
       }
       }
        return ans;
        
    }
};
