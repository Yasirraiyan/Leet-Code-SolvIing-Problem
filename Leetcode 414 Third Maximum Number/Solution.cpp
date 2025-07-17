class Solution 
{
public:
    int findmax(vector<int>& nums)
    {
        int max =nums[0];
        for(int j=1;j<nums.size();j++)
            {
                if(nums[j]>max)
                {
                    max=nums[j];
                }
            }
        return max;
    }

    int thirdMax(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>freq;
        int ans;
        for(int i=0;i<nums.size();i++)
            {
                freq[nums[i]]++;
            }
        for(auto it:freq)
            {
                v.push_back(it.first);
            }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        if(v.size()>=3)
        {
            ans= v[2];
        }
        if(v.size()<3)
        {
            ans=findmax(v);
        }
        return ans;
    }
};
