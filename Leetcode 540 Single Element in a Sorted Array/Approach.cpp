✅ Problem বোঝা:

তোমাকে এমন একটা sorted array দেওয়া হয়েছে যেখানে:

প্রতিটি এলিমেন্ট ঠিক দুইবার আছে।

শুধুমাত্র একটি এলিমেন্ট একবার আছে।

তোমাকে সেই একবার থাকা এলিমেন্টটি খুঁজে বের করতে হবে।



---

🎯 Target:

Time Complexity: O(log n)

Space Complexity: O(1)



---

🔍 তোমার Approach ব্যাখ্যা (Map/Hashing-based):

তোমার কোড এইভাবে কাজ করে:

1️⃣ Frequency Count করা

unordered_map<int,int>freq;
for(int i=0;i<nums.size();i++)
{
    freq[nums[i]]++;
}

এখানে তুমি প্রতিটি সংখ্যার frequency গুনছো। যারা একবার আছে, তাদের frequency হবে 1।

2️⃣ একবার যেটা এসেছে সেটা খুঁজে বের করো:

for(auto it:freq)
{
    if(it.second==1)
    {
        ans=it.first;
        break;
    }
}

3️⃣ Return the answer:

return ans;


---

🔁 উদাহরণ দিয়ে ব্যাখ্যা:

ধরি ইনপুট:

nums = [1,1,2,3,3,4,4,8,8]

Step 1: Frequency map:

{
  1 → 2 বার
  2 → 1 বার ✅
  3 → 2 বার
  4 → 2 বার
  8 → 2 বার
}

Step 2: একমাত্র যেটা 1 বার আছে → সেটা 2

✅ Output → 2


---

❗Time & Space Complexity:

Time: O(n) → কারণ তুমি পুরো array traverse করছো দুইবার

Space: O(n) → কারণ unordered_map এ সকল unique elements স্টোর হচ্ছে



---

✅ কেন তোমার solution Accepted হলো?

> Leetcode শুধু বলে "It must run in O(log n)", কিন্তু তার মানে এই না যে O(n) সলিউশন rejected হবে।
সেটা হল best-optimized solution খুঁজতে হলে O(log n) করতে হবে।
তবে brute force বা O(n) accepted হয় অনেক সময়।




---

✨ তুমি কীভাবে solution ভাববে?

প্রথমে প্রশ্ন পড়ে তুমি বুঝবে:

Sorted Array

প্রতিটা element ২ বার আছে

একটা মাত্র element একবার আছে

→ "Binary Search" use করলে ভালো হয়, কারণ sorted array


কিন্তু তুমি প্রথমে map দিয়ে brute-force approach করেছো, যেটা valid & works fine.


---

🧪 Code Testing Line by Line:

Input:

nums = [1,1,2,3,3,4,4,8,8]

Step 1: Loop দিয়ে Frequency Count:

unordered_map<int,int> freq;
for (int i = 0; i < nums.size(); i++)
{
    freq[nums[i]]++;
}

freq হবে:

{1:2, 2:1, 3:2, 4:2, 8:2}

Step 2: Second loop:

for (auto it : freq)
{
    if (it.second == 1)
    {
        ans = it.first;
        break;
    }
}

এখানে 2 এর frequency 1 → তাই return করবে 2


---

✅ Final Accepted Code:

class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        unordered_map<int,int> freq;
        int ans;
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        for(auto it : freq)
        {
            if(it.second == 1)
            {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};
