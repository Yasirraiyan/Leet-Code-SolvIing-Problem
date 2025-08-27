class Solution
 {
public:
    vector<int> applyOperations(vector<int>& nums)
     {
     int i=0;
     int j=1;
     vector<int>v(nums.size());
     while(/*i<nums.size()&&*/j<nums.size())
     {
        if(nums[i]==nums[j])
        {
          nums[i]*=2;
          nums[j]=0;
          i=j;
          j++;
        }
        else
        {
            i++;
            j++;
        }
     }
     vector<int>v1;
     vector<int>v2;
     for(int k=0;k<nums.size();k++)
     {
        if(nums[k]!=0)
        {
            v1.push_back(nums[k]);
        }
        else
        {
            v2.push_back(nums[k]);
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
     return ans;
    }
};
