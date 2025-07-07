class Solution 
{
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
{
        unordered_set<int>set1;
        unordered_set<int>set2;
        int count1=0;
        int count2=0;
        for(int i=0;i<nums1.size();i++)
        {
          set1.insert(nums1[i]);
        }
        for(int j=0;j<nums2.size();j++)
        {
          set2.insert(nums2[j]);
        }
        vector<int>ans;
        for(int k=0;k<nums1.size();k++)
        {
          if(set2.find(nums1[k])!=set2.end())
          {
            count2++;
          }
        }
        for(int i=0;i<nums2.size();i++)
        {
          if(set1.find(nums2[i])!=set1.end())
          {
            count1++;
          }
        }
        ans.push_back(count2);
        ans.push_back(count1);
        return ans; 
    }
};
