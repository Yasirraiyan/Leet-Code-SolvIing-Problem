class Solution 
{
public:
  bool CheckDistinct(vector<int>&arr)
  {
    bool distinct=true;
    unordered_map<int,int>freq;
    for(int j=0;j<arr.size();j++)
    {
        freq[arr[j]]++;
    }
    for(auto it:freq)
    {
        if(it.second>2)
        {
            distinct=false;
            break;

        }
    }
    return distinct;
  }
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int>v1;
        vector<int>v2;
        bool ispossible=false;
       
        if(CheckDistinct(nums))
        {
            ispossible=true;
        }
        return ispossible;
    }
};
