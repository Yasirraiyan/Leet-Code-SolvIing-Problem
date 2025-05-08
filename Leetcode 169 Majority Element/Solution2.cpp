class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
{
        int ans;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        int  n=nums.size();
        for(auto it:freq)
        {
           if(it.second>n/2)
           {
            ans=it.first;
            break;
           }
        }
        return ans;
    }
};
