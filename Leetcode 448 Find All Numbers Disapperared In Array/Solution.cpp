class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
     {
      unordered_map<int,int>freq;
      int n=nums.size();
      vector<int>reserve;
         vector<int>ans;
      for(int i=1;i<=n;i++)
      {
           reserve.push_back(i);
      }
      for(int j=0;j<nums.size();j++)
      {
        freq[nums[j]]++;
      }
   
      for(int k=0;k<reserve.size();k++)
      {
        if(freq[reserve[k]]==0)
        {
          ans.push_back(reserve[k]);
        }
      }
      return ans;
    }
};
