class Solution 
{
public:
 int findmax(vector<int>&nums)
 {
  if (nums.empty()) return 0;
  int max=nums[0];
  for(int j=1;j<nums.size();j++)
  {
    if(nums[j]>max)
    {
      max=nums[j];
    }
  }
  return max;
 }
 int findmin(vector<int>&nums)
 {
  if (nums.empty()) return 0;
  int min=nums[0];
  for(int j=1;j<nums.size();j++)
  {
    if(nums[j]<min)
    {
      min=nums[j];
    }
  }
  return min;
 }
    int maxDifference(string s)
     {
        unordered_map<char,int>freq;
        for(int i=0;i<s.size();i++)
        {
          freq[s[i]]++;
        }
        vector<int>reserve1;
        vector<int>reserve2;
        for(auto it:freq)
        {
          if(it.second%2==0)
          {
            reserve1.push_back(it.second);
          }
           if(it.second%2!=0)
          {
            reserve2.push_back(it.second);
          }
        } 
         // Check if vectors are empty before finding max/min
    if (reserve1.empty() || reserve2.empty()) {
        return 0; // No valid pair found
    }
        int a=findmin(reserve1);
        int b=findmax(reserve2);
        int ans=b-a;
        return ans;

    }
};
