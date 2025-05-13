class Solution 
{
public:
bool isvowel(char c)
{
  
  bool isvowel=false;
 if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
 {
  isvowel=true;
 }
  return isvowel;
}
bool isconsonent(char s)
{
  
  if(!isvowel(s))
  {
    return true;
  }
  return false;
}
int findmax(vector<int>&nums)
{
  if (nums.empty()) return 0;
  int max=nums[0];
  for(int k=1;k<nums.size();k++)
  {
    if(nums[k]>max)
    {
      max=nums[k];
    }
    //return max;
  }
  return max;
}
    int maxFreqSum(string s) 
    {
        unordered_map<char,int>freq;
        for(int j=0;j<s.size();j++)
        {
          freq[s[j]]++;
        }
        vector<int>reserve1;
        for(auto it:freq)
        {
          if(isvowel(it.first))
          {
            reserve1.push_back(it.second);
          }
        }
        vector<int>reserve2;
        for(auto it:freq)
        {
          if(isconsonent(it.first))
          {
            reserve2.push_back(it.second);
          }
        }
        int max1;
        int max2;
        max1=findmax(reserve1);
        max2=findmax(reserve2);
        int ans;
        ans=max1+max2;
        return ans;
    }
};
