class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff=-1;
        int diff;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if((0<=i)&&(i<j)&&(j<nums.size()))
                {
                if(nums[i]<nums[j])
                {
                   diff=abs(nums[j]-nums[i]);
                    max_diff=std::max(diff,max_diff);
                }
                }

            }
        }
        
       
        return max_diff;

    }
};
