class Solution
{
public:
 bool BinarySearch(vector<int>& nums, int target)
 {
  bool find=false;
  int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
          int mid=(low+high)/2;
          if(nums[mid]<target)
          {
             low=mid+1;
          }
          if(nums[mid]>target)
          {
            high=mid-1;
          }
          if(nums[mid]==target)
          { find=true;
              break;
          }
        }
        return find;
 }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
      vector<int>ans;
      int first=-1;
      int last=-1;
          if(!BinarySearch(nums,target))
          {
              ans.push_back(-1);
              ans.push_back(-1);
              return ans;
          }
              for(int k=0;k<nums.size();k++)
              {
                if(nums[k]==target)
                {
                  if(first==-1) first=k;
                  last=k;
                }
              }
                 ans.push_back(first);
              ans.push_back(last);
        return ans;
    }
};
