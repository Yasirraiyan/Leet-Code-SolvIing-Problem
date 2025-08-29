class Solution {
public:
 int findmin(vector<int>& nums)
 {
    int min=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<min)
        {
            min=nums[i];
        }
    }
    return min;
 }
 bool FindNeg(vector<int>&nums)
 {
    for(int k=0;k<nums.size();k++)
    {
        if(nums[k]<0)
        {
            return true;
        }
    }
    return false;
 }
 int FindSum(vector<int>&nums)
 {
    int sum=0;
      for(int k=0;k<nums.size();k++)
    {
        sum+=nums[k];
    }
  return sum;
 }
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        
            for(int j=0;j<nums.size()&&k>0;j++)
            {
                //if(FindNeg(nums))
                //{
                if(nums[j]<0&&k>0)
                {
                    nums[j]=-nums[j];
                    k--;
                }
               
            
            
             if(k==0) break;
            }
            sort(nums.begin(),nums.end());
            if(k%2==1)
            {
                nums[0]=-nums[0];
            }
            int ans=FindSum(nums);
            return ans;
        
    }
};
