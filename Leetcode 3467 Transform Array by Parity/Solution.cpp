class Solution 
{
public:
    vector<int> transformArray(vector<int>& nums) 
{
        vector<int>ans;
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]%2==0)
          {
            ans.push_back(0);
          }
          if(nums[i]%2!=0)
          {
            ans.push_back(1);
          }
        }
        std::sort(ans.begin(),ans.end());
        return ans;
    }
};
