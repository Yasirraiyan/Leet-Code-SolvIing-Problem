class Solution 
{
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        while(freq[original]>0)
        {
          original=original*2;
          if(freq[original]==0)
          {
            break;
          }
        }
        return original;
    }
};
