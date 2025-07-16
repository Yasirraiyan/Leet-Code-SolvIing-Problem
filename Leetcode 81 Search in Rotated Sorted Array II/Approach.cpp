✅ তোমার কোডের পূর্ণ ব্যাখ্যা:
🔸 Step 1: sort(nums.begin(), nums.end());
cpp
Copy
Edit
sort(nums.begin(), nums.end());
➡️ এই লাইনে তুমি rotated sorted array কে সম্পূর্ণভাবে normal sorted array বানিয়ে ফেলছো।

🔁 উদাহরণ:
Input:
nums = [2,5,6,0,0,1,2]
After sorting:
nums = [0,0,1,2,2,5,6]

🔹 Time complexity of sort(): O(n log n)

🔸 Step 2: Binary Search ব্যবহার করে খোঁজা
cpp
Copy
Edit
int low=0;
int high=nums.size()-1;
bool find=false;
while(low<=high)
{
    int mid = low + (high - low) / 2;
    if(nums[mid] < target) low = mid + 1;
    else if(nums[mid] > target) high = mid - 1;
    else {
        find = true;
        break;
    }
}
return find;
➡️ এখন তুমি classic Binary Search algorithm ব্যবহার করছো।

🔁 Example:

Sorted nums = [0,0,1,2,2,5,6]

Let's say target = 0

Binary search efficiently খুঁজে বের করবে 0 আছে কিনা।

🔹 Binary search এর time complexity: O(log n)

✅ Final Time Complexity:
Sorting: O(n log n)

Binary Search: O(log n)

Total: O(n log n)

🔸 যেহেতু input size ≤ 5000, তাই এই approach এখনো acceptable.

Full Code:
-----------

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
