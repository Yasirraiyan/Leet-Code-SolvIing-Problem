class Solution 
{
public:
  int findDistinctvalue(vector<int>& nums)
  {
    unordered_map<int,int>freq;
    for(int i=0;i<nums.size();i++)
    {
      freq[nums[i]]++;
    }
    vector<int>v;
    for(auto it:freq)
    {
      v.push_back(it.first);
    }
    int ans=freq.size();
    return ans;
  }
    int sumCounts(vector<int>& nums) 
    {
      int n=nums.size();
      int ans=0;
      for(int i=0;i<nums.size();i++)
      {
        for(int j=i;j<nums.size();j++)
        {
             vector<int> sub; 
          for(int k=i;k<=j;k++)
          {
            sub.push_back(nums[k]);
          }
            int distinct=findDistinctvalue(sub);
             ans+=distinct*distinct;
        }
      }
      return ans;
    }
};
