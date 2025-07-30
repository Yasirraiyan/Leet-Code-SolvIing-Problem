✅ সমস্যা:

তোমাকে একটা অ্যারে nums দেওয়া আছে যেখানে সব সংখ্যা দ্বিগুণ করে আছে, কিন্তু শুধুমাত্র একটা সংখ্যা একবার আছে।
তুমি সেই একবার থাকা সংখ্যাটা বের করবে।

উদাহরণ:

Input:  nums = [4,1,2,1,2]
Output: 4


---

🔷 সমাধান (XOR ব্যবহার করে):

আমরা জানি:

a ^ a = 0 (একই সংখ্যার XOR হলে ০ হয়)

a ^ 0 = a (যেকোনো সংখ্যার সাথে ০-এর XOR = সেই সংখ্যাই)


এখন যদি আমরা সবগুলো সংখ্যাকে XOR করি:

4 ^ 1 ^ 2 ^ 1 ^ 2

তাহলে pair-wise যেগুলো একই:

= 1 ^ 1 = 0
= 2 ^ 2 = 0

সেটা বাদ দিয়ে থাকবে:

4 ^ 0 ^ 0 = 4


---

🔶 C++ কোড:

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // result = result ^ num
        }
        return result;
    }
};

✅ টাইম কমপ্লেক্সিটি: O(n)
✅ স্পেস কমপ্লেক্সিটি: O(1)


---

🔸 গাণিতিক ব্যাখ্যা (বাংলায়):

ধরো একটি অ্যারেতে n সংখ্যার মধ্যে শুধুমাত্র একটা সংখ্যা x একবার আছে, আর বাকিগুলো সব 2 বার করে।

তাহলে:

x ^ a ^ a ^ b ^ b ^ c ^ c = x ^ 0 ^ 0 ^ 0 = x

কারণ:

a ^ a = 0

b ^ b = 0

c ^ c = 0


অর্থাৎ শেষে x থেকেই যায়।


---

🔸 উপসংহার:

🔹 XOR-এর অসাধারণ প্রপার্টির জন্য nested loop বা frequency table দরকার হয় না।
🔹 এটি সবচেয়ে efficient ও elegant সমাধান।


Full Code:
-----------
class Solution 
{
public:
    int xorBeauty(vector<int>& nums)
    {
        int result=0;
        for(int i=0;i<nums.size();i++)
            {
                result^=nums[i];
            }
        return result;
    }
};
