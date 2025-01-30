#include<vector>
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count=0;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++)
        {
            int m=nums2.size();
            for(int j=0;j<m;j++)
        {
            if((0<=i)&&(i<=n-1))
            {
                if((0<=j)&&(j<=m-1))
                {
                     if(nums1[i]%(nums2[j]*k)==0)
                     {
                         count++;
                     }
                }
            }
            
        }
        }
        return count;
    }
};
