n=1 hoy return 1 karon ans 1;
n=2 hoy ans=5 5=4+1=2*2+1*1=n*n+(n-1)*(n-1)
  return n*n+(n-1)*(n-1)

  Full Code:
--------------

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
