class Solution 
{
bool BinarySearch(vector<int>&v,int target)
  {
    int low=0;
    int high=v.size()-1;
    int mid;
    bool find=false;
    while(low<=high)
    {
      mid=low+(high-low)/2;
      if(v[mid]<target)
      {
           low=mid+1;
      }
      if(v[mid]>target)
      {
           high=mid-1;
      }
     
      if(v[mid]==target)
      {
        find=true;
        break;
      }
    }
    return find;
  }
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
{
    int ans=-1;
        for(int j=0;j<nums2.size();j++)
      {

      
        if(BinarySearch(nums1,nums2[j]))
        {
          ans=nums2[j];
          break;
        }
      }
return ans;
    }
};
    
