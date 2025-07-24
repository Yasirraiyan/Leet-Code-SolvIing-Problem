class Solution 
{
public:
    int arraySign(vector<int>& nums) 
{
        int count2=0;
        int ans;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<0)
                {
                    count2++;
                }
                if(nums[i]==0)
                    return 0;
            }
        if(count2%2==0)
        {
            ans=1;
        }
        if(count2%2!=0)
        {
            ans=-1;
        }
    
    return ans;
    }
};
