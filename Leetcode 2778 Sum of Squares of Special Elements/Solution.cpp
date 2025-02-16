class Solution 
{
public:
    int sumOfSquares(vector<int>& nums) 
{
        int sum=0;
        for(int i=1;i<=nums.size();i++)
        {
            if(nums.size()%i==0)
            {
                sum+=nums[i-1]*nums[i-1];
            }
        }
        return sum;
    }
};
