তুমি যে সমস্যাটা দিলে, সেটার নাম হতে পারে:
"Minimum Common Element in Two Sorted Arrays"

🔍 Problem টা বুঝি:
তোমাকে দুইটা array nums1 এবং nums2 দেওয়া আছে যেগুলো sorted in non-decreasing order।
তোমার কাজ হলো, এই দুইটাতে common (যে উভয়ে আছে) এমন সবচেয়ে ছোট (minimum) সংখ্যাটা return করা।
যদি কোন সংখ্যা common না থাকে, তাহলে -1 return করতে হবে।

✅ উদাহরণ:
Example 1:
makefile
Copy
Edit
nums1 = [1, 2, 3]
nums2 = [2, 4]

common: [2] → return 2
Example 2:
makefile
Copy
Edit
nums1 = [1, 2, 3, 6]
nums2 = [2, 3, 4, 5]

common: [2, 3] → ছোটটা হলো 2 → return 2
🔎 Approach (ভাবার পদ্ধতি):
🔹 Step 1: Sorted Arrays = Binary Search ব্যবহার করা যাবে
যেহেতু দুইটা array sorted, তুমি চাইলে Binary Search ইউজ করে দেখতে পারো — দ্বিতীয় array-এর প্রতিটা element প্রথম array-তে আছে কিনা।

🔹 Step 2: nums2 এর প্রতিটা সংখ্যা নিয়ে, nums1-এ Binary Search চালাও।
যদি পাই, তাহলে সেটাই প্রথম পাওয়া common এবং সবচেয়ে ছোট হবে কারণ array টা sorted (অল্পতেই পেয়ে যাবো)।

🔹 Step 3: প্রথম common পাওয়া মাত্র return করে দাও, কারণ এরপরে বড় সংখ্যাগুলা আসবে।
✅ তোমার Solution:
তুমি ঠিক এই চিন্তাটাই Follow করেছো।
nums2-এর প্রতিটা সংখ্যা ধরে ধরে nums1-এ Binary Search করছো।

🔧 তোমার Code:
cpp
Copy
Edit
class Solution {
  bool BinarySearch(vector<int>& v, int target) {
    int low = 0;
    int high = v.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (v[mid] < target) {
        low = mid + 1;
      } else if (v[mid] > target) {
        high = mid - 1;
      } else {
        return true; // মিললে সাথে সাথে true
      }
    }
    return false; // না মিললে false
  }

public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    for (int j = 0; j < nums2.size(); j++) {
      if (BinarySearch(nums1, nums2[j])) {
        return nums2[j]; // প্রথম common মান return
      }
    }
    return -1; // কিছু না মিললে
  }
};
🧪 Test Case দিয়ে ব্যাখ্যা (Bangla)
Test Case:
ini
Copy
Edit
nums1 = [1, 2, 3, 6]
nums2 = [2, 3, 4, 5]
Step-by-step:
nums2[0] = 2
→ Binary Search চালানো হবে nums1 = [1,2,3,6] এর মধ্যে।
→ mid = 2 → nums1[2] = 3 > 2 → high কমে যাবে
→ এরপর mid = 0, nums1[0] = 1 < 2 → low বেড়ে যাবে
→ তারপর mid = 1, nums1[1] = 2 → মিলেছে! ✅
→ Return 2

✅ Time Complexity:
Binary Search: O(log n)

Outer loop: O(m) (nums2 এর size m)

Final Time: O(m * log n)
যেখানে m = nums2.size() এবং n = nums1.size()

Full Code;
----------

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
