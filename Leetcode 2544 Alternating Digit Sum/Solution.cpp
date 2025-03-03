#include <algorithm>
#include <vector>
class Solution 
{
public:
    int alternateDigitSum(int n)
    {
      vector<int>reserve;
      int rem;
      int sum=0;
      while(n>0)
      {
         rem=n%10;
         reserve.push_back(rem);
         n=n/10;
      }
      reverse(reserve.begin(),reserve.end());
      for(int i=0;i<reserve.size();i++ )
      {
        if(i%2!=0)
        {
          sum+=(-1)*reserve[i];
        }
        if(i%2==0)
        {
          sum+=reserve[i];
        }
      }
      
      return sum;
    }
    
};
    
