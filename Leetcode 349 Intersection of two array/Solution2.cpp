class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
      unordered_set<int>set1;
      vector<int>ans;
      for(int i=0;i<nums1.size();i++)
      {
        set1.insert(nums1[i]);
      }  
      for(int j=0;j<nums2.size();j++)
      {
        if(set1.find(nums2[j])!=set1.end())
        {
            ans.push_back(nums2[j]);
        }
      }
      unordered_map<int,int>freq1;
      vector<int>result;
      for(int k=0;k<ans.size();k++)
      {
        freq1[ans[k]]++;
      }
      for(auto it:freq1)
      {
        result.push_back(it.first);
      }
      return result;
    }
};
