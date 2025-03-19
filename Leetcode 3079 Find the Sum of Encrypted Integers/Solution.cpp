class Solution 
{
public:
  int findencrypted(int n)
  {
    vector<int>reserve;
    vector<int>encrypt;
    while(n>0)
    {
      int rem=n%10;
      reserve.push_back(rem);
      n=n/10;
    }
    int max=reserve[0];
    for(int i=1;i<reserve.size();i++)
    {
      if(reserve[i]>max)
      {
        max=reserve[i];
      }
    }
    for(int j=0;j<reserve.size();j++)
    {
      reserve[j]=max;
    }
    int sum=0;
    for(int k=0;k<reserve.size();k++)
    {
      sum+=reserve[k]*pow(10,reserve.size()-k-1);
    }
    return sum;
  }
    int sumOfEncryptedInt(vector<int>& nums) 
    {
        int result=0;
        for(int m=0;m<nums.size();m++)
        {
          result+=findencrypted(nums[m]);
        }
        return result;
    }
};
