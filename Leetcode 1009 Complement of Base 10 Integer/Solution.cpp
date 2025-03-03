#include<vector>
class Solution 
{
public:
    int bitwiseComplement(int n) 
    {
      if(n==0)
      {
        return 1;
      }
      vector<int>reserve;
      vector<int>convert;
      int ans=0;
        while(n>0)
        {
          int rem=n%2;
          reserve.push_back(rem);
          n=n/2;
        }
        for(int i=0;i<reserve.size();i++)
        {
          if(reserve[i]==1)
          {
            convert.push_back(0);
          }
          if(reserve[i]==0)
          {
            convert.push_back(1);
          }
        }
        for(int j=0;j<convert.size();j++)
        {
          
            ans+=convert[j]*pow(2,j);
        }
        return ans;
    }
};
