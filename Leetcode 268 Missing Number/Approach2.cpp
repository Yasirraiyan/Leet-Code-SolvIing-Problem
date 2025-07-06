তুমি যেই সমস্যার সমাধান করেছো সেটি হচ্ছে LeetCode-এর Missing Number প্রবলেম।

🔍 প্রশ্নটি কী বলছে?
তোমাকে একটা array nums দেওয়া আছে যেটিতে n টি distinct সংখ্যা আছে। এই সংখ্যাগুলো 0 থেকে n পর্যন্ত রেঞ্জের মধ্যে, তবে একটি সংখ্যা মিসিং।

তোমার কাজ: মিসিং সংখ্যাটি খুঁজে বের করা।

🧠 তুমি কীভাবে চিন্তা করেছো?
প্রথমে তুমি প্রশ্ন পড়ে বুঝেছো:

nums-এ আছে n টি সংখ্যা → কিন্তু রেঞ্জ হচ্ছে 0 থেকে n (মানে n+1 সংখ্যার মধ্যে ১টা নেই)।

মানে: পুরো রেঞ্জ হচ্ছে [0, 1, 2, ..., n] → মোট সংখ্যা n+1

তুমি চিন্তা করেছো: যদি আমরা [0, ..., n] লিস্ট বানিয়ে নিই, এবং তার মধ্যে থেকে nums-এ যেটা নেই সেটা বের করি — তাহলেই মিসিং নাম্বার পেয়ে যাবো।

এই কারণে তুমি:

unordered_set ব্যবহার করেছো যেন nums এর সব নাম্বারকে fast way-তে খুঁজে পাওয়া যায়।

0 থেকে n পর্যন্ত একটা লিস্ট বানিয়েছো → reserve

তারপর reserve-এর প্রতিটা নাম্বারকে দেখে চেক করছো: যদি সেটা nums-এ না থাকে → ঐটাই মিসিং।

✅ কোড ব্যাখ্যা (Line-by-Line in Bangla)
cpp
Copy
Edit
unordered_set<int> set1; 
🔹 একটা unordered_set নিচ্ছো যাতে nums এর সব নাম্বার রাখো।
unordered_set এর খোঁজার সময় complexity O(1) average case-এ।

cpp
Copy
Edit
vector<int> reserve;
🔹 এখানে তুমি 0 থেকে n পর্যন্ত সব সংখ্যা রাখবে।

cpp
Copy
Edit
int n = nums.size();
int miss;
🔹 n হচ্ছে nums-এর সাইজ। আমরা জানি মিসিং নাম্বার 0 থেকে n এর মধ্যে হবে।

cpp
Copy
Edit
for(int i = 0; i <= n; i++) {
    reserve.push_back(i);
}
🔹 তুমি reserve ভরছো 0 থেকে n পর্যন্ত সব সংখ্যা দিয়ে।
👉 Total n+1 সংখ্যা।

cpp
Copy
Edit
for(int j = 0; j < nums.size(); j++) {
    set1.insert(nums[j]);
}
🔹 এখন nums এর সব সংখ্যা set1-এ ঢুকিয়ে রাখলে future-এ খোঁজা সহজ হবে।

cpp
Copy
Edit
for(int k = 0; k < reserve.size(); k++) {
    if(set1.find(reserve[k]) == set1.end()) {
        miss = reserve[k];
        break;
    }
}
🔹 reserve-এর সব সংখ্যার ভিতর দিয়ে যাচ্ছো।
🔍 যদি কোনো সংখ্যা set1 (মানে nums) এ না থাকে → সেটাই মিসিং।

cpp
Copy
Edit
return miss;
🔹 মিসিং সংখ্যাটি রিটার্ন করছো।

🔎 উদাহরণ দিয়ে ব্যাখ্যা (Test Case Walkthrough)
✅ Test Case: nums = [3,0,1]
n = 3 → 0 to 3 পর্যন্ত থাকা উচিত → [0,1,2,3]

nums → [3,0,1]

reserve → [0,1,2,3]

set1 → {0,1,3}

reserve-এর মধ্যে 2 কে খুঁজে পাবে না → ✅ উত্তর: 2

✅ Test Case: nums = [0,1]
n = 2

reserve = [0,1,2]

set1 = {0,1}

2 নাই → ✅ উত্তর: 2

✅ Test Case: nums = [9,6,4,2,3,5,7,0,1]
n = 9

reserve = [0,1,2,3,4,5,6,7,8,9]

set1-এ সব আছে ছাড়া 8 → ✅ উত্তর: 8

✅ কেন এই সমাধান Accepted হলো?
সঠিকভাবে 0 থেকে n এর রেঞ্জ তৈরি করেছো

unordered_set দিয়ে nums-এ দ্রুত খোঁজা করেছো → efficient

Overall time complexity → O(n)

Space complexity → O(n)

এটাই কারণ — কোড সঠিকভাবে কাজ করছে এবং efficiency ভালো।

Full Code:
----------

  class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
      unordered_set<int>set1;
       vector<int>reserve;
       int n=nums.size();
       int miss;
       for(int i=0;i<=n;i++)
       {
       reserve.push_back(i);
       }
       for(int j=0;j<nums.size();j++)
       {
        set1.insert(nums[j]);
       }
       for(int k=0;k<reserve.size();k++)
       {
        if(set1.find(reserve[k])==set1.end())
        {
          miss=reserve[k];
          break;
        }
       }
       return miss;
    }
};
