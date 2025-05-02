class Solution 
{
public:

    vector<int> runningSum(vector<int>& nums) 
    {
         int n=nums.size()-1;
       vector<int>prefix(n+1,0);
        prefix[0]=nums[0];
       //int n=nums.size();
       for(int i=1;i<=n;i++)
       {
        prefix[i]=nums[i]+prefix[i-1];
       }
       return prefix;
    }
};
Apply prefix sum approach not seeing any solution or help or hints frim another.
