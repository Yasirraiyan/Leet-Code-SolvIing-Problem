class Solution 
{
public:
    int returnToBoundaryCount(vector<int>& nums) 
    {
      vector<int>psum(nums.size(),0);
        psum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
          psum[i]=psum[i-1]+nums[i];
        }
 int count=0;
 for(int j=0;j<psum.size();j++)
        {
          if(psum[j]==0)
          {
          count++;
        }
        }
       
       return count;

    }
};
