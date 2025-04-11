#include<vector>
#include<iostream>
#include<cctype>
class Solution 
{
public:
  int getmax(vector<int>arr)
  {
    int max=arr[0];
    for(int i=1;i<arr.size();i++)
    {
      if(arr[i]>max)
      {
        max=arr[i];
      }
    }
    return max;
  }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool>ans;
        for(int j=0;j<candies.size();j++)
        {
          if(candies[j]+extraCandies>=getmax(candies))
          {
            ans.push_back(true);
          }
          else
          {
            ans.push_back(false);
          }
        }
        return ans;
    }
};
