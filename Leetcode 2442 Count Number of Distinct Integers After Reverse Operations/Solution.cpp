class Solution 
{
public:
    int findrev(int n)
    {
        int rev=0;
        while(n>0)
            {
                int digit=n%10;
                rev=rev*10+digit;
                n=n/10;
            }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) 
    {
        int originalsize=nums.size();
        for(int i=0;i<originalsize;i++)
            {
                nums.push_back(findrev(nums[i]));
            }
        unordered_map<int,int>freq;
        for(int j=0;j<nums.size();j++)
            {
                freq[nums[j]]++;
            }
        vector<int>v;
        for(auto it:freq)
            {
                v.push_back(it.first);
            }
        int ans=v.size();
        return ans;
    }
};
