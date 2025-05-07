class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int>reserve;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
          reserve.push_back(i);
        }
        vector<int>result;
        unordered_map<int,int>freq;
        for(int j=0;j<nums.size();j++)
        {
          freq[nums[j]]++;
        }
        for(auto it:freq)
        {
          if(it.second==2)
          {
            result.push_back(it.first);
            break;
          }
        }
        int actualsum=0;
       
       
        int ans;
        int arraysum=0;
        for(int m=0;m<nums.size();m++)
        {
          arraysum+=nums[m];
        }
           for(int i=1;i<=n;i++)
        {
          actualsum+=i;
        }
        int resultsum=0;
        for(int k=0;k<result.size();k++)
        {
          resultsum+=result[k];
        }
          ans=actualsum-arraysum+resultsum;
         result.push_back(ans);
         return result;
    }
};
