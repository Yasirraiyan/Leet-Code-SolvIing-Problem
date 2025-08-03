class Solution
{
public:
    bool TestPrime(int n)
    {
        if(n<2) return false;
        bool test =true;
        for(int i=2;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    test=false;
                    break;
                }
            }
        return test;
    }
    vector<vector<int>> findPrimePairs(int n)
    {
        vector<vector<int>>v;
        for(int i=2;i<=n/2;i++)
            {
                int a=i;
                int b=n-i;
                if(TestPrime(a)&&TestPrime(b))
                {
                    v.push_back({a,b});
                }
            }
        return v;
    }
};
