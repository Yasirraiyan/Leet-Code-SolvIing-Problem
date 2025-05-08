#include<vector>
class Solution 
{
public:
int findmax(vector<int>&nums)
{
  int maxval=nums[0];
  for(int j=1;j<nums.size();j++)
  {
    if(nums[j]>maxval)
    {
      maxval=nums[j];
      
    }
  }
  return maxval;
}
int mymax(int a,int b)
{
  int max=a;
  if(a<b)
  {
  max=b;
  }
  return max;
}
    int findLucky(std::vector<int>& arr) {
        unordered_map<int,int>freq;

        for(int i=0;i<arr.size();i++)
       {
        freq[arr[i]]++;
       }
       vector<int>reserve;
       for(auto it:freq)
       {
        if(it.first==it.second)
        {
          reserve.push_back(it.first);
        }
       }
       int lucky=-1;
       if (reserve.empty()) return lucky;
      
        int maxx=findmax(reserve);
        int ans=mymax(lucky,maxx);
        lucky=ans;
        return lucky;
       
            }
};
