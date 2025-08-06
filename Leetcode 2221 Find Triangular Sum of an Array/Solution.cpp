class Solution 
{
public:
vector<int> trianguler(vector<int>& nums) 
 {
  vector<int>v(nums.size()-1,0);
        for(int i=0;i<nums.size()-1;i++)
        {
          v[i]=(nums[i]+nums[i+1])%10;
        }
        return v;
 }
    int triangularSum(vector<int>& nums) 
    {
      if(nums.size()==1) return nums[0];
       while(nums.size()>1)
       {
            nums=trianguler(nums);
       }
       int ans=nums[0];
       return ans;
    }
};
