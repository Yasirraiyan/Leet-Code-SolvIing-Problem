class Solution 
{
public:
    bool checkDivisibility(int n) 
    {
        int sum=0;
        long long p=1;
        int original=n;
        while(n>0)
        {
          int rem=n%10;
          sum+=rem;
          p*=rem;
          n=n/10;
        }
        long long result=p+sum;
        bool check=false;
        if(original%result==0)
        {
          check=true;
        }
return check;
    }
};
