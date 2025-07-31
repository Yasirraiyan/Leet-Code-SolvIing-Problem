class Solution
{
public:
    long long findsum(vector<int>&v)
    {
        long long sum=0;
        for(int k=0;k<v.size();k++)
            {
                sum+=v[k];
            }
        return sum;
    }
    bool Prime(int n)
    {
        bool isprime=true;
        if(n<2) return false;
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
    long long splitArray(vector<int>& nums) 
    {
        vector<int>v1;
        vector<int>v2;
        for(int j=0;j<nums.size();j++)
            {
                if(Prime(j))
                {
                    v1.push_back(nums[j]);
                }
                else
                {
                    v2.push_back(nums[j]);
                }
            }
    long long  primesum=findsum(v1);
        long long  nonprimesum=findsum(v2);
        long long result=abs(primesum-nonprimesum);
        return result;
    }
};
