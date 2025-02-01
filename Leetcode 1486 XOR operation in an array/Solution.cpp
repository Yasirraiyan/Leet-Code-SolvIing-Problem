#include<vector>
class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>nums;
        int sum=0;
        for(int i=0;i<n;i=i+1)
        {
          nums.push_back(start+2*i);
        }
        for(int j=0;j<nums.size();j++)
        {
           sum^=nums[j];
        }
        return sum;
    }
};
