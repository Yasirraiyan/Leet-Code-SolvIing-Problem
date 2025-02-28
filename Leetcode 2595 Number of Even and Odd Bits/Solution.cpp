class Solution 
{
public:
    vector<int> evenOddBit(int n) 
{
        vector<int>ans;
        int even=0;
        int odd=0;
        vector<int>result;
        while(n>0)
        {
          int rem=n%2;
          ans.push_back(rem);
          n=n/2;
        }
        for(int i=0;i<ans.size();i++)
        {
          if((i%2==0)&&(ans[i]==1))
          {
                even++;
               
          }
        if((i%2!=0)&&(ans[i]==1))
          {
                odd++;
               
        }
        }
        result.push_back(even);
        result.push_back(odd);
        return result;
    }
};
