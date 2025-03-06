class Solution 
{
public:
    int binaryGap(int n) 
    {
        vector<int>ans;
        vector<int>reserve;
        while(n>0)
        {
          int rem=n%2;
          ans.push_back(rem);
          n=n/2;
        }
        for(int i=0;i<ans.size();i++)
        {
          for(int j=i+1;j<ans.size();j++)
          {
              if(i!=j)
              {
                if((ans[i]==1)&&(ans[j]==1))
                {
                reserve.push_back(abs(j-i));
                break;
                }
              }
          }
         
        }
         if(reserve.empty()) 
         {
            return 0;
        }
        int max=reserve[0];
        for(int k=1;k<reserve.size();k++)
        {
          if(reserve[k]>max)
          {
            max=reserve[k];
          }
        }
        return max;
    }
};
