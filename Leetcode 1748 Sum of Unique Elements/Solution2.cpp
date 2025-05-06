class Solution 
{
public:
    int sumOfUnique(vector<int>& nums) 
{
      unordered_map<int,int>freq;
       for(int i=0;i<nums.size();i++)
       {
       freq[nums[i]]++;
       }
       int sum=0;
       for(auto it:freq)
       {
        if(it.second==1)
        {
          sum+=it.first;
        }
       }
       return sum;
    }
};
