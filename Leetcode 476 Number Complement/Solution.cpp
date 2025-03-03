class Solution 
{
public:
    int findComplement(int num) 
    {
        vector<int>reserve;
        vector<int>ans;
        int result=0;
        while(num>0)
        {
          int rem=num%2;
          reserve.push_back(rem);
          num=num/2;
        }
        for(int i=0;i<reserve.size();i++)
        {
          if(reserve[i]==0)
          {
            ans.push_back(1);
          }
           if(reserve[i]==1)
          {
            ans.push_back(0);
          }
        }
        for(int j=0;j<ans.size();j++)
        {
             result+=ans[j]*pow(2,j);
        }
        if(num==1)
        {
          result=0;
        }
        return result;
    }
};
