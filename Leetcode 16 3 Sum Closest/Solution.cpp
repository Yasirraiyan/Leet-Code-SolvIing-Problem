class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
{
      sort(nums.begin(),nums.end());
      int closeSum=nums[0]+nums[1]+nums[2];
      for(int i=0;i<nums.size();i++)
      {
        int low=i+1;
        int high=nums.size()-1;
        while(low<high)
        {
            if(abs(nums[i]+nums[low]+nums[high]-target)<abs(closeSum-target))
            {
                closeSum=nums[i]+nums[low]+nums[high];
            }
            if(nums[i]+nums[low]+nums[high]<target)
            {
                low++;
            }
          else   if(nums[i]+nums[low]+nums[high]>target)
            {
               high--;
            }
            else
                 return nums[i]+nums[low]+nums[high];
        }
      }
      return closeSum;
    }
};
