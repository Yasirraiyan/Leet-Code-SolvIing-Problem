class Solution 
{
public:
    void moveZeroes(vector<int>& nums)
     {
        int nonzeroindex=0;
        int zeroindex=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[nonzeroindex]=nums[i];
                nonzeroindex++;
            }
            
            
        }
        for(int j=nonzeroindex;j<nums.size();j++)
        {
            nums[j]=0;
        }
    }
};
