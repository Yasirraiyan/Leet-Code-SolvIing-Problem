🔍 সমস্যার বর্ণনা (Problem Description):
প্রশ্ন: একটা nums নামের পূর্ণসংখ্যার অ্যারে দেওয়া আছে। যদি কোনো সংখ্যার মান অন্তত দুইবার থাকে, তাহলে true রিটার্ন করো, নইলে false। অর্থাৎ, চেক করতে হবে — কোনো duplicate element আছে কিনা।

✅ সমাধান করার তোমার নিজস্ব চিন্তাধারা (Approach in Bangla):
Step by Step ভাবনা:
প্রতিটি সংখ্যার কতবার এসেছে সেটা গোনার জন্য একটা unordered_map ব্যবহার করেছো।

পুরো অ্যারেটা লুপ করে প্রত্যেক সংখ্যার frequency গুনেছো।

তারপর map এর value গুলাকে আলাদা একটা vector-এ রেখে আবার লুপ করে চেক করেছো যদি কোনো সংখ্যা 2 বা তার বেশি বার থাকে।

যদি এমন কিছু থাকে, তাহলে true return করেছো, না থাকলে false।

🧠 তোমার কোডের ব্যাখ্যা (Line-by-line Bangla Explanation with Math):
cpp
Copy
Edit
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        bool contain=false;
👉 contain bool ভেরিয়েবল দিয়ে শুরু করেছো যাতে শেষে উত্তর রাখা যায়। শুরুতে false ধরেছি।

cpp
Copy
Edit
        unordered_map<int,int>freq;
👉 unordered_map ব্যবহার করেছো যেখানে key হলো সংখ্যা এবং value হলো ঐ সংখ্যার frequency (কতবার এসেছে)।

cpp
Copy
Edit
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
👉 পুরো অ্যারেটা লুপ করে freq ম্যাপে প্রতিটি সংখ্যার গোনা হচ্ছে।
Example 1 এর জন্য nums = [1,2,3,1] →
লুপ শেষে freq হবে: {1: 2, 2: 1, 3: 1}

cpp
Copy
Edit
        vector<int>reserve;
        for(auto it:freq)
        {
            reserve.push_back(it.second);
        }
👉 ম্যাপের value (অর্থাৎ frequency গুলো) আলাদা একটা reserve নামের vector-এ রাখছো।
এটা একটু অতিরিক্ত কাজ, তুমি চাইলে সরাসরি ম্যাপ থেকেই চেক করতে পারতে।

cpp
Copy
Edit
        for(int j=0;j<reserve.size();j++)
        {
            if(reserve[j]>=2)
            {
                contain=true;
                break;
            }
        }
👉 এবার reserve vector থেকে frequency গুলো দেখে যাচ্ছো — যদি কোনো frequency >=2 হয়, তাহলে বুঝতে পারছো ঐ সংখ্যা অন্তত দুইবার এসেছে। contain=true করে দিচ্ছো এবং লুপ থামিয়ে দিচ্ছো।

cpp
Copy
Edit
        return contain;
    }
};
👉 শেষ পর্যন্ত contain রিটার্ন করছো — যেটা true হবে যদি কোনো ডুপ্লিকেট পাওয়া যায়।

🔁 টেস্ট কেস অনুযায়ী ম্যাথেমেটিক্যাল বিশ্লেষণ (Mathematical Analysis):
✅ Test Case 1:
Input: nums = [1,2,3,1]
freq: {1:2, 2:1, 3:1}
Result: 1 এসেছে 2 বার ⇒ true

✅ Test Case 2:
Input: nums = [1,2,3,4]
freq: {1:1, 2:1, 3:1, 4:1}
Result: সবগুলো একবারই এসেছে ⇒ false

✅ Test Case 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
freq: {1:3, 3:3, 4:2, 2:2}
Result: অনেক সংখ্যাই একাধিকবার এসেছে ⇒ true

🧮 সময় এবং জটিলতা বিশ্লেষণ (Time & Space Complexity):
✅ Time Complexity: O(n) — কারণ পুরো অ্যারেতে একবার লুপ, এবং ম্যাপে insertion ও lookup সময় লাগে O(1)

✅ Space Complexity: O(n) — কারণ worst case-এ সব সংখ্যা ইউনিক হলে freq ম্যাপে n টা এন্ট্রি থাকবে।

📂 GitHub Description লেখার মত রেডিমেড Bangla Summary:
markdown
Copy
Edit
### 🧠 Problem: Contains Duplicate

একটা পূর্ণসংখ্যার অ্যারে `nums` দেওয়া আছে। চেক করতে হবে — কোনো সংখ্যা দুইবার বা তার বেশি এসেছে কিনা। যদি আসে তাহলে `true` রিটার্ন করবো, না হলে `false`।

---

### ✅ Approach (নিজস্ব চিন্তাধারা):
1. একটা `unordered_map` দিয়ে প্রতিটি সংখ্যার frequency গুনেছি।
2. frequency গুলো `reserve` vector-এ রেখে চেক করেছি যদি কোনো frequency ≥ 2 হয়।
3. পেলে `contain = true` করে দিচ্ছি।

---

### ⏱️ Time Complexity: O(n)
### 📦 Space Complexity: O(n)

---

### 🔁 উদাহরণ বিশ্লেষণ:
- [1,2,3,1] → `1` দুইবার → ✅ `true`
- [1,2,3,4] → সব ইউনিক → ❌ `false`
- [1,1,1,3,3,4,3,2,4,2] → অনেক সংখ্যা বারবার → ✅ `true`
