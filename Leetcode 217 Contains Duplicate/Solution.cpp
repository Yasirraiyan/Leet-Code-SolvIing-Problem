#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        bool contain=false;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        vector<int>reserve;
        for(auto it:freq)
        {
           reserve.push_back(it.second);
        }
        for(int j=0;j<reserve.size();j++)
        {
          
              if(reserve[j]>=2)
              {
                contain=true;
                break;
              }
            
          }
        
        return contain;
    }
};
