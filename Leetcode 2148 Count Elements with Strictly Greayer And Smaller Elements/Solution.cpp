class Solution 
{
public:
int findmin(vector<int>&nums)
{
    int min=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<min)
        {
            min=nums[i];
        }
    }
    return min;
}
int findmax(vector<int>&nums)
{
    int max=nums[0];
    for(int j=1;j<nums.size();j++)
    {
        if(nums[j]>max)
        {
            max=nums[j];
        }
    }
    return max;
}
    int countElements(vector<int>& nums) 
    {
        int count=0;
        for(int k=0;k<nums.size();k++)
        {
            if((nums[k]!=findmin(nums))&&(nums[k]!=findmax(nums)))
            {
                count++;
            }
        }
        return count;

    }
};
