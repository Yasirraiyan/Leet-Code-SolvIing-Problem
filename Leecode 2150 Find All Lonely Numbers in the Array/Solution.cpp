class Solution
 {
public: 
bool CheckLonely(vector<int>&nums,int x,unordered_set<int>& set1, unordered_map<int,int>& freq)
{
  bool islonely=false;
   if(freq[x]==1)
    {
      if((set1.find(x+1)==set1.end())&&(set1.find(x-1)==set1.end()))
      {
        islonely=true;
      }
      else
      {
        islonely=false;  
      }
    }
    else
    {
      islonely=false;
    }
  return islonely;
}
    vector<int> findLonely(vector<int>& nums) 
    {
       unordered_map<int,int> freq;
  unordered_set<int> set1;
for(int i=0;i<nums.size();i++)
{
  freq[nums[i]]++;
  set1.insert(nums[i]);
}
      vector<int>ans;
      for(int k=0;k<nums.size();k++)
      {
        if(CheckLonely(nums,nums[k],set1,freq))
        {
          ans.push_back(nums[k]);
        }
      }
      return ans;
    }
};
