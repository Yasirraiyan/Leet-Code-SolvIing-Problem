#include<vector>
class Solution {
public:
  vector<int> separatedigit(int n)
  {
    vector<int>reserve;
    if (n == 0)
     {
            reserve.push_back(0);
        }
    while(n>0)
    {
        int rem=n%10;
        reserve.push_back(rem);
        n=n/10;

    }
  //  n=n/10;
   std::reverse(reserve.begin(), reserve.end());
    return reserve;
  }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        //vector<int>result;
        
        for(int i=0;i<nums.size();i++)
        {
            //result=separatedigit(i);
            vector<int>result=separatedigit(nums[i]);
          //ans.push_back(result);
          ans.insert(ans.end(), result.begin(), result.end());
        }
        return ans;

    }
};
