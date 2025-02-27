class Solution 
{
public:
    int hammingWeight(int n) 
{
      vector<int> ans;
      int hw=0;
        while(n>0)
        {
          int rem=n%2;
          ans.push_back(rem);
          n=n/2;
        }
        for(int i=0;i<ans.size();i++)
        {
          if(ans[i]==1)
          {
            hw++;
          }

        }
        return hw;
    }
};
