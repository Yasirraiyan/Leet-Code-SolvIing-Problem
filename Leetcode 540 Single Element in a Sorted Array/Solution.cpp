class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        unordered_map<int,int>freq;
        int ans;
        for(int i=0;i<nums.size();i++)
            {
                freq[nums[i]]++;
            }
        for(auto it:freq)
            {
                if(it.second==1)
                {
                    ans=it.first;
                    break;
                }
            }
        return ans;
    }
};
