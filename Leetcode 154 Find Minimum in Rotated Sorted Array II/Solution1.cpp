class Solution 
{
public:
    int findMin(vector<int>& nums) 
{
      int min=nums[0];
        for(int j=1;j<nums.size();j++)
        {
            if(nums[j]<min)
            {
                min=nums[j];
            }
        }
        return min;
}
};
