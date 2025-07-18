class Solution
{
public:
    int arrangeCoins(int n) 
    {
        int ans;
        long long sum=0;
        for(int i=1;i<=n;i++)
            {
                sum+=i;
                if(sum>n)
                {
                    ans=i-1;
                    break;
                }
            }
        return ans;
    }
};
