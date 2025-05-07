#include <vector>
#include <unordered_map>

class Solution 
{
public:
    int singleNumber(std::vector<int>& nums) 
{
     unordered_map<int,int>freq;
     for(int i=0;i<nums.size();i++)
     {
      freq[nums[i]]++;
     }
     int ans;
     for(auto it:freq)
     {
      if(it.second==1)
      {
        ans=it.first;
        break;
      }
     }
    return ans;
   }
};
