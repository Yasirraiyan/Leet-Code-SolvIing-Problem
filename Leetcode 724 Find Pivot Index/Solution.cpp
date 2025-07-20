class Solution
{
public:
    int pivotIndex(vector<int>& nums) 
    { 
     int totalsum=0;
     int leftsum=0;
     int rightsum;
     int pivot=-1;
     for(int i=0;i<nums.size();i++)
     {
      totalsum+=nums[i];
     }
     for(int j=0;j<nums.size();j++)
     {
      //leftsum+=nums[j];
      rightsum=totalsum-leftsum-nums[j];
      if(leftsum==rightsum)
      {
       pivot=j;
        break;
      }
        leftsum += nums[j];
     }
     return pivot;
    }
      
};
