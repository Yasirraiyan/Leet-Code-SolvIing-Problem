class Solution
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>>ans(2);
        unordered_set<int>set1(nums1.begin(),nums1.end());
        unordered_set<int>set2(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++)
            {
                set1.insert(nums1[i]);
            }
        for(int j=0;j<nums2.size();j++)
            {
                set2.insert(nums2[j]);
            }
        for(int k=0;k<nums1.size();k++)
            {
                if(set2.find(nums1[k])==set2.end())
                {
                if (find(ans[0].begin(), ans[0].end(), nums1[k]) == ans[0].end())
                {
                    ans[0].push_back(nums1[k]);
                }
                }
            }
        for(int j=0;j<nums2.size();j++)
            {
                if(set1.find(nums2[j])==set1.end())
                {
                    if (find(ans[1].begin(), ans[1].end(), nums2[j]) == ans[1].end()) {
                    ans[1].push_back(nums2[j]);
                    }
            }
            }
        return ans; 
    }
};
