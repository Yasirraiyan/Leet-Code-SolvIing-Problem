Amar 1 ta array ase amar lagbe number ber kora jeta maximum o na ar minimum o na.
First e a initial max=nums[0];
                  min=nums[0] dhori.
1 ta for loop chalai i=0 to i<n porjonto array traverse kori.
check kori condition
if(nums[i]<min)
            {
                min=nums[i];
            }
            if(nums[i]>max)
            {
                max=nums[i];
            }

aro 1 ta for loop chalai j=0 to  j<n porjonto check
 if(nums[j]!=min&&nums[j]!=max)
       {
            ans=nums[j];
       }
return kori ans.
  Full code:
-----------

  class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int min=nums[0];
        int max=nums[0];
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<min)
            {
                min=nums[i];
            }
            if(nums[i]>max)
            {
                max=nums[i];
            }
            
            
        }
       for(int j=0;j<nums.size();j++)
       {
        if(nums[j]!=min&&nums[j]!=max)
       {
            ans=nums[j];
       }
       }
        return ans;
        
    }
};
