class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int>set1;
         unordered_set<int>set2;
         vector<int>ans;
         unordered_map<int,int>freq1;
          unordered_map<int,int>freq2;
        for(int i=0;i<nums1.size();i++)
        {
          set1.insert(nums1[i]);
          freq1[nums1[i]]++;
        }
         for(int j=0;j<nums2.size();j++)
        {
          set2.insert(nums2[j]);
          freq2[nums2[j]]++;
        }
        for(int k=0;k<nums1.size();k++)
        {
          if((set2.find(nums1[k])!=set2.end()))
          {
            int occur=min(freq1[nums1[k]],freq2[nums1[k]]);
            while(occur--)
            {

            
            ans.push_back(nums1[k]);
            }
            freq1[nums1[k]] = 0;
                freq2[nums1[k]] = 0;
            
            
          }
        }
        return ans;
    }
};
