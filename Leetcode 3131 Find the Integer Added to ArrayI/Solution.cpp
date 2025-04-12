class Solution 
{
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans;
        vector<int>result;
        if(nums1.size()==1&&nums2.size()==1)
        {
            ans=nums2[0]-nums1[0];
        }
          int sum1=0;
          int sum2=0;
          if(nums1.size()>1&&nums2.size()>1)
          {
          if(nums1.size()==nums2.size())
          {
          for(int i=0;i<nums1.size();i++)
          {
            sum1+=nums1[i];
          }
          for(int j=0;j<nums2.size();j++)
          {
            sum2+=nums2[j];
          }
          int result=sum2-sum1;
          ans=result/static_cast<int>(nums1.size());
        //ans=result/(nums1.size());
          }
          }
          return ans;
          
    }
};
