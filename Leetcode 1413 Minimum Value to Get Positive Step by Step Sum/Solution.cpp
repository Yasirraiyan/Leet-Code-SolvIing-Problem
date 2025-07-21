class Solution 
{
public:
  int findmin(vector<int>& nums)
  {
    int min=nums[0];
    for(int k=1;k<nums.size();k++){
      if(nums[k]<min)
      {
        min=nums[k];
      }
    }
    return min;
  }
    int minStartValue(vector<int>& nums)
{
      vector<int>psum(nums.size(),0);
      psum[0]=nums[0];
      for(int i=1;i<nums.size();i++ )
      {
        psum[i]=psum[i-1]+nums[i];
      } 
      int startvalue=findmin(psum);
      if(startvalue<0)
      {
        startvalue=1-startvalue;
      }
      else
      {
       startvalue= 1;
      }
      
      return startvalue;

    }
};
