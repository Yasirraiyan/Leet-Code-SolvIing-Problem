class Solution 
{
public:
    bool TestPrime(int n)
    {
        if(n<2) return false;
        bool isprime=true;
        for(int i=2;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    isprime=false;
                    break;
                }
            }
        return isprime;
    }
    long long findfact(int n)
    {
        const int MOD=1e9+7;
        long long p=1;
        for(int i=n;i>=1;i--)
            {
                p=(p*i)%MOD;
            }
        return p;
    }
    int numPrimeArrangements(int n) 
    {
        const int MOD=1e9+7;
        int pc=0;
        int npc;
        for(int i=1;i<=n;i++)
            {
                if(TestPrime(i))
                {
                    pc++;
                }
            }
        npc=n-pc;
        int ans=(findfact(pc)*findfact(npc))%MOD;
        return ans;
    }
};
