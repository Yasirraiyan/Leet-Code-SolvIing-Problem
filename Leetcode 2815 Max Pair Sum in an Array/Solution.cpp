class Solution 
{
public:
 int findmaxarray(vector<int>&nums)
 {
  int max=nums[0];
  for(int i=1;i<nums.size();i++)
  {
    if(nums[i]>max)
    {
      max=nums[i];
    }
  }
  return max;
 }
  bool CanMakePair(int a,int b)
  {
    bool can=false;
    vector<int>reserve1;
    vector<int>reserve2;
    while(a>0)
    {
      int rem1=a%10;
      reserve1.push_back(rem1);
      a=a/10;
    }
    while(b>0)
    {
      int rem2=b%10;
       reserve2.push_back(rem2);
      b=b/10;
    }
    int max1=findmaxarray(reserve1);
    int max2=findmaxarray(reserve2);
    if(max1==max2)
    {
      can=true;
    }
    return can;
  }
  int findmax(int a,int b)
  {
    int max=a;
    if(b>max)
    {
      max=b;
    }
    return max;
  }
    int maxSum(vector<int>& nums) 
    {
        int max=-1;
        vector<int>reserve;
        for(int j=0;j<nums.size();j++)
        {
          for(int k=j+1;k<nums.size();k++)
          {

          if(j!=k)
          {
          if(CanMakePair(nums[j],nums[k]))
          {
               reserve.push_back(nums[j]+nums[k]);
          }
          }
        }
        }
          if (reserve.empty()) return -1; 
        int arraymax=findmaxarray(reserve);
        max=findmax(arraymax,max);
        return max;
    }
};
