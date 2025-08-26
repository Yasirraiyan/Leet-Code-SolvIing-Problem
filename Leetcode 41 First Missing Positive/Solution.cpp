class Solution
 {
public:
 int findmax(vector<int>& nums)
 {
    int max=nums[0];
    for(int j=1;j<nums.size();j++)
    {
        if(nums[j]>max)
        {
            max=nums[j];
        }
    }
    return max;
 }
 int findmin(vector<int>&arr)
 {
    int min=arr[0];
    for(int k=1;k<arr.size();k++)
    {
        if(arr[k]<min)
        {
            min=arr[k];
        }
    }
    return min;
 }
    int firstMissingPositive(vector<int>& nums)
     {
        vector<int>v;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]>0)
            {
                v.push_back(nums[j]);
            }
        }
          if (v.empty()) return 1;
        int max=findmax(v);
        int min=findmin(v);
      long long ans=(long long)max+1;
        unordered_set<int>set1;
        for(int k=0;k<nums.size();k++)
        {
            set1.insert(nums[k]);
        }
        for(int j=1;j<=max;j++)
        {
            if(set1.find(j)==set1.end())
            {
                ans=j;
                break;
            }
        }
      return (int)ans;
    }
};
