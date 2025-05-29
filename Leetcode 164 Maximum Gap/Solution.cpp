class Solution 
{
public:
int findmax(vector<int>&nums)
{
  int max=nums[0];
  for(int k=1;k<nums.size();k++)
  {
    if(nums[k]>max)
    {
      max=nums[k];
    }
  }
  return max;
}
    int maximumGap(vector<int>& nums) 
    {
      int ans=0;
      vector<int>reserve;
        if(nums.size()<2)
        {
         return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
        
                   reserve.push_back(nums[i]-nums[i-1]);
              
          }
          
         
        
        ans=findmax(reserve);
        return ans;
    }
};
