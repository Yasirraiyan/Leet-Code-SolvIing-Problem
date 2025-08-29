class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int j=0;j<nums.size();j++)
        {
            if(j%2==0)
            {
                sum+=nums[j];
            }
        }
        return sum;
    }
};
