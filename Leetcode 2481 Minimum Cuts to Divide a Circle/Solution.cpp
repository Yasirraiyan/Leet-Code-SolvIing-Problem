class Solution 
{
public:
    int numberOfCuts(int n) 
    {
      int ans;
      if(n==1)
      {
        ans=0;
      }
      if(n>1)
      {

      
        if(n%2==0)
        {
          ans=n/2;
        }
        if(n%2!=0)
        {
          ans=n;
        }
      }
        return ans;
    }
};
