class Solution 
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
      int n=nums.size();
      vector<int>ans(n,0);
      int count=0;
      for(int i=0;i<nums.size();i++)
      {
        count=0;
        for(int j=0;j<nums.size();j++)
        {
               if(nums[j]<nums[i])
               {
                count++;
               }
        }
        ans[i]=count;
      }
    return ans;
    }
};
