class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
     int single;
     unordered_map<int,int>freq;
     for(int i=0;i<nums.size();i++)
     {
      freq[nums[i]]++;
     }
        for(auto it:freq)
        {
          if(it.second==1)
          {
            single=it.first;
            break;
          }
        }
        return single;
    }
};
