class Solution
 {
public:
int findmax(vector<int>& arr)
 {
    if(arr.empty()) return -1;
    int max_val = arr[0]; 
    for(int i = 1; i < arr.size(); i++) 
    {
        if(arr[i] > max_val) 
        {
            max_val = arr[i];
        }
    }
    return max_val;
}
bool Test(vector<int>&nums)
{
    int max=findmax(nums);
    bool test=true;
    for(int j=0;j<nums.size();j++)
    {
        if(nums[j]!=max&&2*nums[j]>max)
        {
            test=false;
            break;
        }
    }
    return test;
}
    int dominantIndex(vector<int>& nums) 
    {
        int dominent;
         int ans;
         int max=findmax(nums);
        if(Test(nums))
        {
            for(int k=0;k<nums.size();k++)
            {
                    if(nums[k]==max&&2*nums[k]>max)
                    {
                       dominent=max;
                       break;
                    }
            }
        }
        else
        {
            return -1;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==dominent)
            {
                ans=j;
                break;
            }
        }
        return ans;
    }
};
