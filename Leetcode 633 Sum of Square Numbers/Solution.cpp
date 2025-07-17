class Solution 
{
public:
 bool IsSquare(int  a)
 {
  int low=0;
  int high=a;
  bool issquare=false;
  while(low<=high)
  {
    int mid=(low+high)/2;
    if(1LL*mid*mid==a)
    {
             issquare=true;
             break;
    }
  else if(1LL*mid*mid<a)
  {
  low=mid+1;
  }
 else
 {
  high=mid-1;
 }
}
return issquare;
 }
bool judgeSquareSum(int c) 
 {
     long long low=0;
     long long high=(long long)c;
     bool judge=false;
      for(long long i=low;i*i<=high;i++)
       {
              long long b=high-i*i;
              if(b>=0&&b<=INT_MAX&&IsSquare((int)b))
              {
                   judge=true;
                   break;
              }
       }
        return judge;
    }
    };

