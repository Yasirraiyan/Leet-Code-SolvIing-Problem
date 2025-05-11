class Solution 
{
public:
    bool divideArray(vector<int>& nums) 
    {
        bool divideispossible=true;
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
        for(int j=0;j<reserve.size();j++)
        {
          if(reserve[j]%2!=0)
          {
            divideispossible=false;
            break;
          }
        }
        return divideispossible;
    }
};
