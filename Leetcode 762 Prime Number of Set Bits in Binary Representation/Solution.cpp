 int countbits(int n)
{
    vector<int>reserve;
    int count=0;
    while(n>0)
    {
        int rem=n%2;
      if(rem==1)
      {
        count++;
      }
        n=n/2;
    }
    return count;
}
bool isprime(int n)
{
    bool isprime=true;
    if(n<2)
    {
        isprime=false;
    }
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
class Solution
{
public:
    int countPrimeSetBits(int left, int right)
     {
        vector<int> result;
        int count=0;
        for(int j=left;j<=right;j++)
        {
           result.push_back(countbits(j));
        }
       for(int k=0;k<result.size();k++)
       {
        if(isprime(result[k]))
        {
            count++;
        }
       }
        return count;
    }
};
