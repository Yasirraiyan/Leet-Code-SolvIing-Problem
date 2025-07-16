class Solution 
{
public:
    int mySqrt(int x) 
    {
        int ans;
       long long  high=x;
        long long low=1;
         if(x == 0) return 0;
        while(low<=high)
        {

    long long mid=low+(high-low)/2;
          if(mid*mid<x)
          {
            ans=(int)mid;
            low=mid+1;
          }
       else   if(mid*mid==x)
          {
            ans=(int)mid;
            break;
          }
          else
          {
            high=mid-1;
          }

        }
        return ans;
    }
};
