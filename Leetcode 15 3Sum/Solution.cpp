class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<int>v;
        vector<vector<int>>vv;
        sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size();i++)
     {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
        int low=i+1;
        int high=nums.size()-1;
        while(low<high)
        {
            if(nums[i]+nums[low]+nums[high]==0)
            {
             vv.push_back({nums[i], nums[low], nums[high]}); 
                  while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
            }
         else   if(nums[i]+nums[low]+nums[high]<0)
            {
                low++;
            }
           else   if(nums[i]+nums[low]+nums[high]>0)
            {
               high--;
            }
        }
     }
     return vv;
    }
};
