class Solution 
{
  int findmin(vector<int>& v)
  {
    int min=v[0];
    for(int k=1;k<v.size();k++)
    {
            if(v[k]<min)
            {
              min=v[k];
            }
    }
    return min;
  }
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1;
        int ans;
        for(int i=0;i<nums1.size();i++)
        {
          set1.insert(nums1[i]);
        }
        vector<int>v;
        for(int j=0;j<nums2.size();j++)
        {
          if(set1.find(nums2[j])!=set1.end())
          {
            v.push_back(nums2[j]);
          }
          else
          {
            ans=-1;
          }
        }
        if(v.empty()) return -1;
        ans=findmin(v);
        return ans;
    }
};
