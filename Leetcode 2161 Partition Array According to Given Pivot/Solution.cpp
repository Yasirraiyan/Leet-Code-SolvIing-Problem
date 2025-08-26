class Solution 
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
     {
       vector<int>v1;
       vector<int>v2;
       vector<int>v3;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]<pivot)
        {
            v1.push_back(nums[i]);
        }
         if(nums[i]==pivot)
        {
            v2.push_back(nums[i]);
        }
         if(nums[i]>pivot)
        {
            v3.push_back(nums[i]);
        }
       }
       vector<int>ans;
       for(int j=0;j<v1.size();j++)
       {
        ans.push_back(v1[j]);
       }
       for(int k=0;k<v2.size();k++)
       {
        ans.push_back(v2[k]);
       }
       for(int j=0;j<v3.size();j++)
       {
        ans.push_back(v3[j]);
       }
     return ans;
    }
};
