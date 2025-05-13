class Solution 
{
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
{
    unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        vector<int>ans;
        for(auto it:freq)
        {
          if(it.second>1)
          {
            ans.push_back(it.first);
          }
        }
        return ans;
    }
};
