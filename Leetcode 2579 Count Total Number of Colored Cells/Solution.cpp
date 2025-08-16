class Solution 
{
public:
    long long coloredCells(int n) 
    {
        if(n==1) return 1;
        long long ans=1LL*n*n+1LL*(n-1)*(n-1);
        return ans;
    }
};
