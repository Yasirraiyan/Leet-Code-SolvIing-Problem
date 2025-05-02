class Solution 
{
public:
  
  
    vector<int> leftRightDifference(vector<int>& nums)
     {
        int leftsum=0;
        int rightsum=0;
        int n=nums.size();
        vector<int>reserve1(n,0);
        reserve1[0]=0;
        vector<int>reserve2(n,0);
        vector<int>ans(n);
        for(int i=1;i<nums.size();i++)
        {
           reserve1[i]=reserve1[i-1]+nums[i-1];
        }
        reserve2[nums.size()-1]=0;
        for(int j=nums.size()-2;j>=0;j--)
        {
          reserve2[j]=reserve2[j+1]+nums[j+1];
        }
        for(int k=0;k<reserve1.size();k++)
        {
          for(int m=0;m<reserve2.size();m++)
          {
            if((k==m)&&(k<reserve2.size()))
            {
              ans[k]=abs(reserve1[k]-reserve2[m]);
            }
          }
        }
        return ans;

    }
};
