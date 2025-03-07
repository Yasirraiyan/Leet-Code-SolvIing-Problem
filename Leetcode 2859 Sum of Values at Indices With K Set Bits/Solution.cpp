#include<vector>
class Solution 
{
public:
 int findsetbit(int n)
 {
  int count=0;
  while(n>0)
  {
    int rem=n%2;
    if(rem==1)
    {
      count++;
    }
    n=n/2;
   
  }
  
  return count;
 }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) 
    {
        vector<int>reserve;
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
          if(findsetbit(i)==k)
          {
            reserve.push_back(nums[i]);
          }
        }
        for(int j=0;j<reserve.size();j++)
        {
          result+=reserve[j];
        }
        return result;
    }
};
