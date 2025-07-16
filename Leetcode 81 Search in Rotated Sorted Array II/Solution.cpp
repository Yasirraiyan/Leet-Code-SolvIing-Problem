class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size()-1;
        bool find=false;
        int mid;
        while(low<=high)
        {
              mid=low+(high-low)/2;
              if(nums[mid]<target)
              {
                low=mid+1;
              }
              if(nums[mid]>target)
              {
                high=mid-1;
              }
          if(nums[mid]==target)
              {
                find=true;
                break;
                //return mid;

              }
        }
        return find;
    }
};
