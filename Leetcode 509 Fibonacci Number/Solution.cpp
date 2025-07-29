class Solution
{
public:
    int fib(int n) 
    {
        if(n==0||n==1) return n;
        vector<int>v(n+1);
     v[0]=0;
    v[1]=1;
        if(n>1)
        {
            for(int i=2;i<=n;i++)
                {
                    v[i]=v[i-1]+v[i-2];
                }
        }
    int ans=v[v.size()-1];
        return ans;
    }
};
