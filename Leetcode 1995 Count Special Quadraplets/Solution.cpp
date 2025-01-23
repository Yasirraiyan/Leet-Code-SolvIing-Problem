#include<vector>
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count=0;
        for(int a=0;a<nums.size();a++)
        {
            for(int b=a+1;b<nums.size();b++)
            {
                for(int c=b+1;c<nums.size();c++)
                {
                    for(int d=c+1;d<nums.size();d++)
                    {
                        if((a<b)&&(b<c)&&(c<d)&&(d<nums.size()))
                        {
                             if(nums[a]+nums[b]+nums[c]==nums[d])
                             {
                                count++;
                             }
                        }
                    }
                }
            }
        }
        return count;
    }
};
