class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
          for(int j=i+1;j<nums.size();j++)
          {
            if(i!=j)
            {
              if(nums[i]==nums[j])
              {
                ans.push_back(nums[i]);
              }
            }
          }
        }
        return ans;
    }
};
