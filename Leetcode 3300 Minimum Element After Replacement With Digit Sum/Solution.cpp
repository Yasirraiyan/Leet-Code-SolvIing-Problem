class Solution
{
public:
int digitsum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n=n/10;
    }
  
    return sum;
}
    int minElement(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(digitsum(nums[i]));
        }
        int min=ans[0];
        for(int j=0;j<ans.size();j++)
        {
            if(ans[j]<min)
            {
                min=ans[j];
            }

        }
        return min;
        
    }
};
