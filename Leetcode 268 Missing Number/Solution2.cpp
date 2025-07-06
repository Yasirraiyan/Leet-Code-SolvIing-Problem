class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
       unordered_set<int>set1;
       vector<int>reserve;
       int n=nums.size();
       int miss;
       for(int i=0;i<=n;i++)
       {
       reserve.push_back(i);
       }
       for(int j=0;j<nums.size();j++)
       {
        set1.insert(nums[j]);
       }
       for(int k=0;k<reserve.size();k++)
       {
        if(set1.find(reserve[k])==set1.end())
        {
          miss=reserve[k];
          break;
        }
       }
       return miss;
    }
};
