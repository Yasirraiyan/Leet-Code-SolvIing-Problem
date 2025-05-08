class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
       vector<int>ans;
       unordered_map<int,int>freq;
       for(int i=0;i<nums.size();i++)
       {
        freq[nums[i]]++;
       }
       int n=nums.size();
       for(auto it:freq)
       {
        if(it.second>n/3)
        {
          ans.push_back(it.first);
         
        }
       }
       return ans;
    }
};
