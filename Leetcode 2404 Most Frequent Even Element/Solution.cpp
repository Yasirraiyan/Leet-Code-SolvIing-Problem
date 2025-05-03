#include<iostream>
//#include<unorderd_map>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        vector<int>reserve;
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]%2==0)
          {
            reserve.push_back(nums[i]);
          }
        }
        unordered_map<int,int>freq;
        for(int j=0;j<reserve.size();j++)
       {
        freq[reserve[j]]++;
       }
       if(reserve.empty())
       {
        ans=-1;
       }
       int max_count=0;
       for(int k=0;k<reserve.size();k++)
       {
          max_count=max(max_count,freq[reserve[k]]);
         // ans=max_count;
       }
       for(int m=0;m<reserve.size();m++)
       {
        if(freq[reserve[m]]==max_count)
        {
          if(ans==-1||reserve[m]<ans)
          {
            ans=reserve[m];
          }
        }
       }
       return ans;
    }
};
