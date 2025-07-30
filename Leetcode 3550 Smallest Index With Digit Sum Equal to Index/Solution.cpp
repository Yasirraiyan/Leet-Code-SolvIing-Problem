class Solution 
{
public:
int CalculateDigitSum(int n)
{
  int sum=0;
  while(n>0)
  {
    int rem=n%10;
    sum+=rem;
    n=n/10;
  }
  return sum;
}
    int smallestIndex(vector<int>& nums) 
    {
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
          if(CalculateDigitSum(nums[i])==i)
          {
            ans=i;
            break;
          }
        }
        return ans;
    }
};
