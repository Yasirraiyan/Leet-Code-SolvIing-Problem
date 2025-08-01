class Solution 
{
public:
bool canAliceWin(vector<int>&nums)
{
    int singsum=0;
    int doubsum=0;
    int totsum=0;
    bool alice=false;
    for(int i=0;i<nums.size();i++)
    {
      if(nums[i]>=0&&nums[i]<=9)
      {
        singsum+=nums[i];

      }
      if(nums[i]>=10&&nums[i]<=99)
      {
        doubsum+=nums[i];

      }
      totsum+=nums[i];
    }
      if((singsum>totsum-singsum)||(doubsum>totsum-doubsum))
      {
         alice =true;
      }
    return alice;
        }
    
};
