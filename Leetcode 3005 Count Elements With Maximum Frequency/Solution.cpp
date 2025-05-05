class Solution 
{
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        vector<int>reserve;
        for(auto it:freq)
        {
          reserve.push_back(it.second);
        }
        int max=reserve[0];
        for(int j=1;j<reserve.size();j++)
        {
          if(reserve[j]>max)
          {
            max=reserve[j];
          }
        }
        int sum=0;
        for(int k=0;k<reserve.size();k++)
        {
          if(reserve[k]==max)
          {
            sum+=reserve[k];
          }
        }
       return sum;
    }
};
