#include <iostream>
#include <vector>

using namespace std;


class Solution 
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>&grid) 
    {
       unordered_map<int,int>freq;
       vector<int>ans;
       int sum1=0;
       for(int i=0;i<grid.size();i++)
       {
        for(int j=0;j<grid.size();j++)
        {
          freq[grid[i][j]]++;
          sum1+=grid[i][j];
        }
       }
       int actualsum=0;
       for(int m=0;m<=grid.size()*grid.size();m++)
       {
        actualsum+=m;
       }
     
       for(auto it:freq)
       {
        if(it.second>1)
        {
          ans.push_back(it.first);
        }
       }
       int sum2=0;
       for(int k=0;k<ans.size();k++)
       {
        sum2+=ans[k];
       }
         int miss=actualsum-sum1+sum2;
         ans.push_back(miss);
        return ans;
    }
};
