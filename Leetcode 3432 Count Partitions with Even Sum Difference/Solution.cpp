class Solution
 {
public:
    int countPartitions(vector<int>& nums) 
    {
      int count=0;
        int sum=0;
        vector<int>psum(nums.size(),0);
        psum[nums.size()-1]=nums[nums.size()-1];
         for(int i=0;i<nums.size();i++)
         {
          sum+=nums[i];
         }
        for(int i=nums.size()-2 ;i>=0;i--)
        {
        
          psum[i]=psum[i+1]+nums[i];
        }
        int sum3=0;
        for(int i=0;i<nums.size()-1;i++)
        {
          sum3+=nums[i];
          int sum2=sum3-psum[i+1];
          if((abs(sum2))%2==0)
          {
            count++;
          }
        }
        return count;
    }
};
