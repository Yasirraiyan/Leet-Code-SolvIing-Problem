Without Sort Function
------------------------

  class Solution 
{
public:
    void sortColors(vector<int>& nums) 
{
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                if(nums[i]>nums[j])
                {
                    int temp=nums[i];
                    nums[i]=nums[j];
            nums[j]=temp;
                }
            }

                    
