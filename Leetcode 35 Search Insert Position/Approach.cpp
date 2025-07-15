🔍 Problem Statement (সংক্ষেপে)
তোমাকে একটি sorted এবং distinct (অন্যরকম) সংখ্যার array দেওয়া আছে এবং একটি target সংখ্যা দেওয়া আছে।
তোমার কাজ হচ্ছে -

যদি target array-তে থাকে, তাহলে তার index return করতে হবে।

যদি না থাকে, তাহলে সে কোথায় insert করলে order ঠিক থাকবে, সেই index return করতে হবে।

🎯 Example:
cpp
Copy
Edit
Input: nums = [1, 3, 5, 6], target = 5
Output: 2  // কারণ 5 আছে এবং index 2-তে

Input: nums = [1, 3, 5, 6], target = 2
Output: 1  // কারণ 2 যদি insert করি, তাহলে 1 এর পরে 3 এর আগে হবে → index 1

Input: nums = [1, 3, 5, 6], target = 7
Output: 4  // কারণ 7 সবার শেষে যাবে → index 4
💡 Observation (বোঝার চেষ্টা):
এখানে array sorted → আমরা Binary Search ব্যবহার করতে পারি, যাতে runtime হয় O(log n)।

✅ Binary Search দিয়ে কীভাবে করব?
আমরা Binary Search দিয়ে:

যদি target পাই, সরাসরি mid return করব।

যদি না পাই, তাহলে search এর শেষে low pointer যেখানে দাঁড়াবে, সেটা হবে insert করার সঠিক position।

🎯 কারণ?
Binary Search যখন শেষ হয়, তখন low > high হয়ে যায়। তখন low হলো সেই index যেখান থেকে target বড় হয়ে যাবে — সেখানেই insert করতে হবে।

✅ Code Explanation (Line by Line):
cpp
Copy
Edit
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;                        // শুরুতে array-এর শুরু
        int high = nums.size() - 1;        // array-এর শেষ index

        while (low <= high) {
            int mid = low + (high - low) / 2; // Overflow এড়াতে safe mid

            if (nums[mid] == target) {
                return mid;               // Target পাওয়া গেছে
            }

            if (nums[mid] < target) {
                low = mid + 1;            // ডানদিকে খুঁজবো
            } else {
                high = mid - 1;           // বামদিকে খুঁজবো
            }
        }

        return low;  // Not found → insert করার সঠিক position
    }
};
✅ Code Dry Run/Test Case:
cpp
Copy
Edit
nums = [1,3,5,6], target = 2

Initial: low = 0, high = 3
Step 1: mid = 1 → nums[1]=3 > 2 → high = mid-1 = 0
Step 2: low = 0, high = 0 → mid = 0 → nums[0]=1 < 2 → low = mid+1 = 1
Now: low=1, high=0 → loop ends → return low = 1 ✅
🔁 অন্য Test Case:
cpp
Copy
Edit
nums = [1,3,5,6], target = 7

Step 1: mid=1 → nums[1]=3 < 7 → low=2
Step 2: mid=2 → nums[2]=5 < 7 → low=3
Step 3: mid=3 → nums[3]=6 < 7 → low=4
low=4 > high=3 → return 4 ✅
🤔 কিভাবে নিজে নিজে ভাববো?
প্রশ্নে যদি বলে sorted array → চিন্তা করো Binary Search।

যদি বলে target না থাকলে কোথায় insert করব → চিন্তা করো index-টা কি হতে পারে?

Binary Search শেষ হলে low pointer কোন position দেখায় তা খেয়াল করো।

Binary Search loop শেষ হলে low হচ্ছে তোমার insertion index।

📌 Complexity:
Time: O(log n)

Space: O(1)

✅ Summary in Bangla:
প্রশ্নে "sorted" → Binary Search

মিললে mid return

না মিললে শেষে low হবে insert position

এই লজিক 100% accepted হবে কারণ efficient ও optimized।

Full Code:
-----------

  class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
          int mid=low+(high-low)/2;
          if(nums[mid]==target)
          {
            return mid;
          }
          if(nums[mid]<target)
          {
            low=mid+1;
          }
          else
          {
            high=mid-1;
          }
        }
        return low;
           }
};
