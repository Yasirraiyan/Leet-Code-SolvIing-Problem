class Solution 
{
public:
   int sum(int start,int end ,vector<int>& nums)
   {
     int sum=0;
     //start=0;
     for(int j=start;j<=end;j++)
     {
      sum+=nums[j];
     }
     return sum;
   }
    int subarraySum(vector<int>& nums)
{
       int total=0;
       int start;
       for(int i=0;i<nums.size();i++)
       {
         start=std::max(0,i-nums[i]);
         total+=sum(start,i,nums);
       } 
  return total;
    }
};
