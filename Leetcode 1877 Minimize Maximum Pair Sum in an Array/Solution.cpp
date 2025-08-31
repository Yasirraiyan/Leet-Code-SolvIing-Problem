class Solution 
{
public:
int findmax(vector<int>& nums)
{
    int max=nums[0];
    for(int k=1;k<nums.size();k++)
    {
        if(nums[k]>max)
        {
            max=nums[k];
        }
    }
    return max;
}
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
       int i=0;
       int j=nums.size()-1;
       vector<int>v;
       while(i<j)
       {
        int sum=nums[i]+nums[j];
        v.push_back(sum);
        i++;
        j--;
       }
    int ans=findmax(v);
    return ans;
    }
};
