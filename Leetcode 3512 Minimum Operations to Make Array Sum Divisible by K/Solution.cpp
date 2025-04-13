class Solution 
{
public:
 int findsum(vector<int>& nums)
 {
  int sum=0;
  for(int i=0;i<nums.size();i++)
  {
    sum+=nums[i];
  }
  return sum;
 }
    int minOperations(vector<int>& nums, int k) 
    {
      int op=0;
      int a=findsum(nums);
      //while(findsum(nums)%k!=0)
      while(a%k!=0)
      {
          if(a!=k)
          {
            a--;
          }
          
          op++;
          if(a%k==0)
          {
            break;
          }
      }
      return op;
    }
};
