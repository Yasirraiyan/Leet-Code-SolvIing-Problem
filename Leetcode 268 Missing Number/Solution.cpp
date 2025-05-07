class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
       int arraysum=0;
       for(int i=0;i<nums.size();i++)
       {
        arraysum+=nums[i];
       }
       int n=nums.size();
       int actualsum=0;
       for(int j=1;j<=n;j++)
       {
        actualsum+=j;
       }
       int miss;
       miss=actualsum-arraysum;
       return miss;
    }
};
