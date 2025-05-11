#include<iostream>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution 
{
public:

    int mostFrequent(vector<int>& nums, int key)
     {
        vector<int>reserve1;
        for(int i=0;i<nums.size()-1;i++)
        {
          if(nums[i]==key)
          {
            reserve1.push_back(nums[i+1]);
          }
        }
        unordered_map<int,int>freq;
        for(int j=0;j<reserve1.size();j++)
        {
          freq[reserve1[j]]++;
        }
        vector<int>reserve2;
        int ans;
        for(auto it:freq)
        {
          reserve2.push_back(it.second);
        }
      //  int maxx=std::max(reserve2);
      int maxx = *std::max_element(reserve2.begin(), reserve2.end());
        for(auto it:freq)
        {
          if(it.second==maxx)
          {
            ans=it.first;  
                    }
        }
        return ans;
    }
};
