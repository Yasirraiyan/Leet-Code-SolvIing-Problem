তুমি যেই প্রবলেমটা সলভ করেছো সেটা হলো:
"Find all elements in an array that appear more than ⌊n/3⌋ times"
এবং তুমি যেই কোড দিয়েছো তা সঠিকভাবে কাজ করে, এখন আমি এর Bangla ব্যাখ্যা নিচে দিলাম যাতে তুমি ভবিষ্যতে পড়লে সহজে বুঝতে পারো।

🧠 প্রবলেম ব্যাখ্যা (In Bangla):
তোমাকে একটা nums নামের integer array দেওয়া আছে যার size n।
তুমি এমন সব সংখ্যাগুলো বের করবে যেগুলো array-তে ⌊n/3⌋ এর চেয়ে বেশি বার এসেছে।

🔹 উদাহরণস্বরূপ:

যদি n = 9, তাহলে ⌊n/3⌋ = 3, তাই এমন সংখ্যা বের করতে হবে যেগুলো 3-এর চেয়ে বেশি বার এসেছে।

🔹 গুরুত্বপূর্ণ বিষয়:
একটি array-তে সর্বোচ্চ ২টি সংখ্যা এমন থাকতে পারে যেগুলো ⌊n/3⌋ এর বেশি বার এসেছে।

✅ তোমার কোডের ব্যাখ্যা (Line by Line - Bangla):
cpp
Copy
Edit
vector<int>ans;
unordered_map<int,int>freq;
🔸 unordered_map ব্যবহার করে আমরা প্রতিটা সংখ্যার frequency count করছি।
🔸 ans vector এ আমরা ফলাফল রাখবো।

cpp
Copy
Edit
for(int i=0;i<nums.size();i++)
{
    freq[nums[i]]++;
}
🔸 প্রতিটা সংখ্যা নিয়ে map-এ তার frequency বাড়ানো হচ্ছে।
🔸 এই loop এর শেষে আমাদের হাতে একটা map থাকবে: number → frequency

cpp
Copy
Edit
int n=nums.size();
for(auto it:freq)
{
    if(it.second > n/3)
    {
        ans.push_back(it.first);
    }
}
🔸 n কে দিয়ে n/3 বের করছি।
🔸 তারপর map থেকে যেসব সংখ্যার frequency n/3 এর চেয়ে বেশি, সেগুলোকে ans-এ রাখছি।

cpp
Copy
Edit
return ans;
🔸 শেষে সেই সব সংখ্যার list return করছি।

🧪 উদাহরণ দিয়ে বোঝানো:
উদাহরণ 1:
cpp
Copy
Edit
Input: nums = [3,2,3]
Step 1: freq = {3: 2, 2: 1}
n = 3 → n/3 = 1
Step 2: 3 has freq 2 → > 1 ✅ → ans = [3]
Output: [3]
উদাহরণ 2:
cpp
Copy
Edit
Input: nums = [1]
Step 1: freq = {1: 1}
n = 1 → n/3 = 0
Step 2: 1 has freq 1 > 0 ✅ → ans = [1]
Output: [1]
উদাহরণ 3:
cpp
Copy
Edit
Input: nums = [1, 2]
Step 1: freq = {1: 1, 2: 1}
n = 2 → n/3 = 0
Step 2: both freq > 0 → ans = [1, 2]
Output: [1, 2]
⏱️ Time & Space Complexity:
✅ Time Complexity: O(n)

❌ Space Complexity: O(n) (map ইউজ করার কারণে)

🎯 
