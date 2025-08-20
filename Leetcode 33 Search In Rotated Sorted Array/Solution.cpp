class Solution {
public:
  int BinarySearch(vector<int>& nums,int low,int high,int target)
  {
   while(low<=high)
   {
    int mid=low+(high-low)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target)
    {
        low=mid+1;
    }
    else
    {
        high=mid-1;
    }
   
   }
 return -1;
  }
    int search(vector<int>& nums, int target)
     {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[low]<=nums[mid])
            {
            if(nums[low]<=target&&target<nums[mid])
            {
               return BinarySearch(nums,low,mid-1,target);
            }
            else
            {
                low=mid+1;
            }
        }
        else
        {
            if(nums[mid]<target&&nums[high]>=target)
            {
               return  BinarySearch(nums,mid+1,high,target);
            }
            else
            {
                high=mid-1;
            }
        }
        }
        return -1;
    }
};
