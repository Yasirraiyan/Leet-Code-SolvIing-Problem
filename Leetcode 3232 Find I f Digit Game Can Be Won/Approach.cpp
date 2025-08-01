🔶 Problem টা কি বলছে?
তোমাকে একটা পজিটিভ ইনটিজার অ্যারে nums দেওয়া আছে।

Alice দুইটা অপশন থেকে একটা বেছে নিতে পারবে:

শুধুমাত্র সব single-digit (1 থেকে 9) নাম্বার নেবে।

অথবা সব double-digit (10 থেকে 99) নাম্বার নেবে।

Bob বাকি সব নাম্বার পাবে।

Alice জিতবে যদি তার নাম্বারগুলোর sum > Bob এর নাম্বারগুলোর sum হয়।

🔍 উদাহরণ:
Example 1:

cpp
Copy
Edit
nums = [1,2,3,4,10]
Single digits sum = 1+2+3+4 = 10
Double digits sum = 10

Total = 20

If Alice chooses:
- Single → Alice=10, Bob=10 → Not greater
- Double → Alice=10, Bob=10 → Not greater

Output: false
Example 2:

cpp
Copy
Edit
nums = [1,2,3,4,5,14]
Single digits sum = 15
Double digits sum = 14
Total = 29

If Alice chooses:
- Single → Alice=15, Bob=14 → ✅ Alice wins

Output: true
🧠 সমাধান ভাবার ধাপ (Approach):
প্রতিটি নাম্বার যদি 1 <= x <= 9 → Single-digit সেগুলো যোগ করে singsum

যদি 10 <= x <= 99 → Double-digit → যোগ করে doubsum

সবগুলোর যোগফল বের করো → totsum

এখন Alice যদি singsum > totsum - singsum বা doubsum > totsum - doubsum হয় — তাহলে সে জিতবে।

✅ তোমার কোডের Line-by-Line ব্যাখ্যা (Bangla):
cpp
Copy
Edit
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singsum = 0;      // Single-digit সংখ্যা গুলোর যোগফল
        int doubsum = 0;      // Double-digit সংখ্যা গুলোর যোগফল
        int totsum = 0;       // সব সংখ্যার মোট যোগফল
        bool alice = false;   // Alice কি জিতবে কিনা

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0 && nums[i] <= 9) {
                singsum += nums[i];  // যদি single-digit হয়
            }
            if(nums[i] >= 10 && nums[i] <= 99) {
                doubsum += nums[i];  // যদি double-digit হয়
            }
            totsum += nums[i];       // সব নাম্বারের sum
        }

        // Alice জয়ী হবে যদি তার কোন একটা sum Bob এর চেয়ে strictly বেশি হয়
        if((singsum > totsum - singsum) || (doubsum > totsum - doubsum)) {
            alice = true;
        }

        return alice;
    }
};
✅ কেন কোড Accepted হয়?
Time Complexity: O(n) — একবারই লুপ চালিয়ে সব হিসাব করছো

Space Complexity: O(1) — শুধু কয়েকটা ভেরিয়েবল ব্যবহার হয়েছে

🔎 Test Cases Walkthrough:
🔹 Test Case 1:
cpp
Copy
Edit
Input: nums = [1, 2, 3, 4, 10]
singsum = 1+2+3+4 = 10
doubsum = 10
totsum = 20

Try:
- Alice: 10 vs Bob: 10 → Not strictly greater
→ Output: false
🔹 Test Case 2:
cpp
Copy
Edit
Input: nums = [1,2,3,4,5,14]
singsum = 1+2+3+4+5 = 15
doubsum = 14
totsum = 29

Try:
- Alice (single): 15 > 14 → ✅
→ Output: true
🔹 Test Case 3:
cpp
Copy
Edit
Input: nums = [5,5,5,25]
singsum = 5+5+5 = 15
doubsum = 25
totsum = 40

Try:
- Alice (double): 25 > 15 → ✅
→ Output: true

Full Code:
-----------

  class Solution 
{
public:
bool canAliceWin(vector<int>&nums)
{
    int singsum=0;
    int doubsum=0;
    int totsum=0;
    bool alice=false;
    for(int i=0;i<nums.size();i++)
    {
      if(nums[i]>=0&&nums[i]<=9)
      {
        singsum+=nums[i];

      }
      if(nums[i]>=10&&nums[i]<=99)
      {
        doubsum+=nums[i];

      }
      totsum+=nums[i];
    }
      if((singsum>totsum-singsum)||(doubsum>totsum-doubsum))
      {
         alice =true;
      }
    return alice;
        }
    
};
