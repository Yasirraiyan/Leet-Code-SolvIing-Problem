class Solution 
{
public:
    int findMiddleIndex(vector<int>& nums) 
{
       int totalsum=0;
       int pivot=-1;
       int leftsum=0;
       int rightsum;
       for(int i=0;i<nums.size();i++)
       {
        totalsum+=nums[i];
       }
        for(int j=0;j<nums.size();j++)
        {
           rightsum= totalsum-leftsum;
           leftsum+=nums[j];
           if(leftsum==rightsum)
           {
            pivot=j;
            break;
           }
        }
        return pivot;
    }
};
