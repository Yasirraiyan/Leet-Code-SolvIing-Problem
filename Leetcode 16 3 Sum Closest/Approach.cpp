Problem Understanding

আমরা পাই:

একটি integer array nums

একটি integer target

আমাদের কাজ:

এমন তিনটি সংখ্যা বাছাই করতে যা যোগফল target এর সবচেয়ে কাছাকাছি হবে।

একটাই solution assumption আছে।

Technique Used:

Two-pointer approach + sorting

আমরা আগে array কে sort করি।

এরপর প্রতিটি element ধরে দুই pointers (low & high) দিয়ে sum পরীক্ষা করি।

Time Complexity: O(n²), Space Complexity: O(1)

Step-by-step Code Explanation
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {


একটি class Solution তৈরি করা হয়েছে।

function threeSumClosest নিলো array nums এবং integer target।

      sort(nums.begin(), nums.end());


প্রথমে array sort করা হয়েছে।

Sorting করা প্রয়োজন কারণ two-pointer technique ঠিকভাবে কাজ করবে।

Example: nums = [-1,2,1,-4] → sort → [-4,-1,1,2]

      int closeSum = nums[0] + nums[1] + nums[2];


প্রথম তিনটি সংখ্যার sum কে initial closest sum ধরা হয়েছে।

এটা একটি starting point।

      for(int i = 0; i < nums.size(); i++)
      {


একটি loop i এর জন্য, যা ধরে যে nums[i] প্রথম element হবে তিনটির মধ্যে।

        int low = i + 1;
        int high = nums.size() - 1;


Two pointers শুরু করা হয়েছে:

low = পরবর্তী element (i+1)

high = array এর শেষ element

        while(low < high)
        {


যতক্ষণ low pointer high এর কম, loop চালবে।

এখানে আমরা দুইটি pointer দিয়ে sum পরীক্ষা করব।

            if(abs(nums[i] + nums[low] + nums[high] - target) < abs(closeSum - target))
            {
                closeSum = nums[i] + nums[low] + nums[high];
            }


আমরা current triplet sum নিয়ে দেখি এটি target এর কাছাকাছি কি না।

abs(sum - target) দিয়ে distance দেখা হয়।

যদি current sum বেশি কাছাকাছি হয়, আমরা update করি closeSum।

            if(nums[i] + nums[low] + nums[high] < target)
            {
                low++;
            }
            else if(nums[i] + nums[low] + nums[high] > target)
            {
                high--;
            }
            else
                return nums[i] + nums[low] + nums[high];


যদি sum ছোট হয় target থেকে → low++ (sum বড় করার জন্য)

যদি sum বড় হয় target থেকে → high-- (sum ছোট করার জন্য)

যদি sum ঠিক target এর সমান → তৎক্ষণাৎ return, কারণ আর কাছাকাছি হবে না।

        }
      }
      return closeSum;
    }
};


সব iteration শেষ হলে final closeSum return করা হয়।

Test Case Walkthrough
Example 1:
nums = [-1, 2, 1, -4], target = 1


Step 1: Sort

nums = [-4, -1, 1, 2]


Step 2: Initialize

closeSum = -4 + (-1) + 1 = -4


Step 3: Loop i=0 (nums[i] = -4)

low = 1 → nums[low] = -1
high = 3 → nums[high] = 2
sum = -4 + (-1) + 2 = -3
abs(-3 - 1) = 4 < abs(-4 - 1) = 5 → update closeSum = -3
sum < target → low++ → low = 2 → nums[low] = 1
sum = -4 + 1 + 2 = -1
abs(-1 - 1) = 2 < abs(-3 - 1) = 4 → update closeSum = -1
sum < target → low++ → low = 3 → low == high → exit while


Step 4: Loop i=1 (nums[i] = -1)

low = 2 → nums[low] = 1
high = 3 → nums[high] = 2
sum = -1 + 1 + 2 = 2
abs(2 - 1) = 1 < abs(-1 - 1) = 2 → update closeSum = 2
sum > target → high-- → high = 2 → low == high → exit while


Step 5: Loop i=2 (nums[i] = 1) → low=3, high=3 → exit while

Final: closeSum = 2 → correct answer

Example 2:
nums = [0,0,0], target = 1


Sort → [0,0,0]

closeSum = 0 + 0 + 0 = 0

sum = 0, target = 1 → distance = 1

আর কোন better sum → return 0

✅ Output = 0

Key Points (Bangla)

Sort করা জরুরি: two-pointer technique কাজ করার জন্য।

Two-pointer approach: sum ছোট হলে low++, বড় হলে high--।

Closest sum tracking: closeSum দিয়ে সর্বদা update।

Optimal solution: O(n²) → brute-force O(n³)-এর চেয়ে অনেক দ্রুত।


  Full Code:
------------

  class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
      int closeSum=nums[0]+nums[1]+nums[2];
      for(int i=0;i<nums.size();i++)
      {
        int low=i+1;
        int high=nums.size()-1;
        while(low<high)
        {
            if(abs(nums[i]+nums[low]+nums[high]-target)<abs(closeSum-target))
            {
                closeSum=nums[i]+nums[low]+nums[high];
            }
            if(nums[i]+nums[low]+nums[high]<target)
            {
                low++;
            }
          else   if(nums[i]+nums[low]+nums[high]>target)
            {
               high--;
            }
            else
                 return nums[i]+nums[low]+nums[high];
        }
      }
      return closeSum;
    }
};

  
