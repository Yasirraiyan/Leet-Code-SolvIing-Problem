class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
     {
       int n=nums.size();
      vector<int>ans;
      unordered_set<int>set1;
      for(int j=0;j<nums.size();j++)
      {
            set1.insert(nums[j]);
      }
      for(int i=1;i<=n;i++)
      {
        if(set1.find(i)==set1.end())
        {
          ans.push_back(i);
        }
      }
      return ans;
    }
};
