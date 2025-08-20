১️⃣ প্রশ্নটা পড়ে কিভাবে তুমি approach বুঝবে:

প্রশ্ন থেকে key points:

তোমাকে একটি ascending sorted array দেওয়া হয়েছে, কিন্তু সেটা left-rotated হতে পারে।

উদাহরণ: [0,1,2,4,5,6,7] → left rotate by 3 → [4,5,6,7,0,1,2]

তুমি একটি target খুঁজবে।

Runtime O(log n) চাওয়া হয়েছে → এটা মানে Binary Search বা তার variation ব্যবহার করতে হবে।

সমস্ত value unique, তাই duplicate নিয়ে ভাবার দরকার নেই।

এই ধরনের questionে technique:

Modified Binary Search → কারণ array partially sorted।

মূল ধারণা: সদা sorted portion চিনে বের করা এবং তার মধ্যে target খুঁজে দেখা।

২️⃣ Code Approach ব্যাখ্যা
class Solution {
public:


আমরা একটি Solution class বানাচ্ছি যা LeetCode style।

২.১ BinarySearch function
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


Line-by-line explanation:

while(low<=high) → standard binary search loop।

mid=low+(high-low)/2 → avoid overflow।

if(nums[mid]==target) → target পাওয়া গেলে index return।

else if(nums[mid]<target) → target right side এ আছে, so low = mid+1।

else → target left side, so high = mid-1।

যদি loop শেষ হয়ে যায়, return -1 → target নেই।

✅ এটা normal binary search। আমরা পরে search function-এ partially sorted portion চিনে এটা call করব।

২.২ Main search function
int search(vector<int>& nums, int target)
{
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target) return mid;


Binary search start।

mid calculate।

যদি nums[mid] == target → return immediately।

২.৩ Left portion sorted check
        if(nums[low]<=nums[mid])
        {
            if(nums[low]<=target && target<nums[mid])
            {
               return BinarySearch(nums,low,mid-1,target);
            }
            else
            {
                low=mid+1;
            }
        }


Logic:

nums[low] <= nums[mid] → left portion sorted।

যদি target এই sorted left portion এর মধ্যে থাকে (nums[low]<=target<nums[mid]) → normal binary search use করে index খুঁজে নাও।

অন্যথায় → target right portion এ, so low = mid+1।

২.৪ Right portion sorted check
        else
        {
            if(nums[mid]<target && nums[high]>=target)
            {
               return BinarySearch(nums,mid+1,high,target);
            }
            else
            {
                high=mid-1;
            }
        }


Logic:

যদি left portion sorted না হয়, মানে right portion sorted।

যদি target right portionে থাকে → normal binary search call।

অন্যথায় → target left portion এ, so high = mid-1।

২.৫ Loop শেষ হলে
    }
    return -1;
}
};


যদি loop শেষ হয় → target array তে নেই।

৩️⃣ কেন এই code accepted হচ্ছে?

O(log n) time complexity → শুধু half portion চেক করে recursion/binary search।

All edge cases handle করা হয়েছে:

Single element [1]

Target absent

Target at rotation point

৪️⃣ Example walkthrough

Example: nums = [4,5,6,7,0,1,2], target = 0

low=0, high=6, mid=3 → nums[3]=7

left portion sorted [4,5,6,7]

target 0 left portionে নেই, so low=mid+1=4

low=4, high=6, mid=5 → nums[5]=1

left portion sorted [0,1]

target 0 left portionে আছে, so BinarySearch on [4,4] → nums[4]=0

Found → return 4 ✅

৫️⃣ Key takeaway (Bangla)

Rotated array → partially sorted।

Modified Binary Search technique → sorted portion চেনা।

Target সেই portionে থাকলে normal binary search, না থাকলে অন্য portion explore।

Time complexity O(log n), space O(1)।

সব edge cases cover করা হয়েছে।


Full Code:
------------

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
