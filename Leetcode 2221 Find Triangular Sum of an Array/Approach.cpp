✅ Problem Understanding (প্রশ্ন বুঝি)
প্রশ্নে বলা হচ্ছে:

তোমাকে একটা integer array nums দেওয়া আছে, যেটার প্রতিটি উপাদান 0 থেকে 9-এর মধ্যে একটি digit।

আমরা একটা প্রক্রিয়া চালাবো যতক্ষণ পর্যন্ত nums-এর দৈর্ঘ্য ১ না হয়:

nums[i] এবং nums[i+1] যোগ করবো এবং mod 10 নেবো (মানে 10 দিয়ে ভাগ করে বাকি কত থাকে)।

এরকম করে আমরা n-1 দৈর্ঘ্যের নতুন একটা array বানাবো।

এই নতুন array দিয়েই আবার একই প্রক্রিয়া চালাবো।

যখন অবশেষে মাত্র ১টা সংখ্যা থাকবে, সেটা return করবো।

✅ চিন্তার প্রক্রিয়া (Approach thinking)
প্রশ্নটা পড়ার পর আমরা বুঝতে পারি:

এটা একটা simulation problem।

ধাপে ধাপে এক একটা লেভেল তৈরি হয়, আর প্রতিটা লেভেলে আগের লেভেলের ২টা উপাদান যোগ করে পরবর্তী লেভেল বানানো হয়।

এটা দেখতে অনেকটা Pascal's Triangle (mod 10) এর মতো।

উদাহরণ দিয়ে বুঝি:
Input: nums = [1,2,3,4,5]

perl
Copy
Edit
Level 0: [1, 2, 3, 4, 5]
Level 1: [(1+2)%10, (2+3)%10, (3+4)%10, (4+5)%10] = [3,5,7,9]
Level 2: [ (3+5)%10, (5+7)%10, (7+9)%10 ] = [8,2,6]
Level 3: [ (8+2)%10, (2+6)%10 ] = [0,8]
Level 4: [ (0+8)%10 ] = [8] ✅

So, final triangular sum = 8
✅ কোড ব্যাখ্যা (Line-by-Line in Bangla)
cpp
Copy
Edit
class Solution 
{
public:
    // Helper function: দুই পাশের সংখ্যাগুলোর যোগফল করে নতুন array তৈরি করবে
    vector<int> trianguler(vector<int>& nums) 
    {
        vector<int>v(nums.size()-1, 0);  // আগের চেয়ে ১টা ছোট array তৈরি করি
        for(int i = 0; i < nums.size() - 1; i++)
        {
            v[i] = (nums[i] + nums[i+1]) % 10;  // নতুন array-এর i-তম মান
        }
        return v; // নতুন লেভেল ফেরত দিচ্ছি
    }

    // মূল ফাংশন যা প্রশ্নে চাওয়া হয়েছে
    int triangularSum(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0]; // একটার বেশি না থাকলে সেটাই উত্তর
        
        while(nums.size() > 1)
        {
            nums = trianguler(nums); // ধাপে ধাপে নতুন লেভেল তৈরি করছি
        }

        return nums[0]; // শেষে একটা সংখ্যা থাকবে, সেটাই উত্তর
    }
};
✅ Test Case Walkthrough
Test Case 1:
Input: [1,2,3,4,5]

text
Copy
Edit
Level 0: 1 2 3 4 5
Level 1: 3 5 7 9          → (1+2)%10, (2+3)%10, ...
Level 2: 8 2 6            → (3+5)%10, (5+7)%10, ...
Level 3: 0 8              → (8+2)%10, (2+6)%10
Level 4: 8                → (0+8)%10

Output: 8 ✅
Test Case 2:
Input: [5]

text
Copy
Edit
Only one element → directly return 5 ✅
Test Case 3:
Input: [9,9,9,9]

text
Copy
Edit
Level 0: 9 9 9 9
Level 1: (9+9)%10 = 8 → 8 8 8
Level 2: (8+8)%10 = 6 → 6 6
Level 3: (6+6)%10 = 2 → 2

Output: 2 ✅
✅ Time & Space Complexity Analysis (গাণিতিক বিশ্লেষণ)
Time Complexity:
প্রথম ধাপে n-1 বার যোগ হচ্ছে

দ্বিতীয় ধাপে n-2

তারপর n-3 ……… ১

এই ধরণের যোগফল:

(
𝑛
−
1
)
+
(
𝑛
−
2
)
+
…
+
1
=
𝑛
(
𝑛
−
1
)
2
(n−1)+(n−2)+…+1= 
2
n(n−1)
​
 
So, Time Complexity: O(n^2)

Space Complexity:
প্রতি ধাপে আমরা নতুন array বানাই যার সাইজ n-1, n-2, ... down to 1

কিন্তু আমরা পুরনো array-টা replace করে ফেলি, তাই অতিরিক্ত কোনো বড় জায়গা লাগে না।

So, Space Complexity: O(n) (for current array only)

✅ কেন Accept হয়েছে?
সমস্যা ঠিকমতো বুঝে সরাসরি simulation implement করেছো

Mod 10 condition ঠিকমতো মেনেছো

Edge case (nums size == 1) ধরেছো

Time এবং Space Efficient হিসেবে acceptable

তাই কোডটা LeetCode-তে Accepted ✅ হয়েছে

✅ Summary:
দিক	ব্যাখ্যা
Approach	Simulation / Level-wise addition
Technique	Iterative, mod 10 at each step
Time Complexity	O(n²)
Space Complexity	O(n)
Edge Case handled?	Yes (nums.size() == 1)
Accepted?	✅ Yes, correct and efficient

Full Code:
------------

  class Solution 
{
public:
vector<int> trianguler(vector<int>& nums) 
 {
  vector<int>v(nums.size()-1,0);
        for(int i=0;i<nums.size()-1;i++)
        {
          v[i]=(nums[i]+nums[i+1])%10;
        }
        return v;
 }
    int triangularSum(vector<int>& nums) 
    {
      if(nums.size()==1) return nums[0];
       while(nums.size()>1)
       {
            nums=trianguler(nums);
       }
       int ans=nums[0];
       return ans;
    }
};
