🔍 Problem:
একটি integer array nums দেওয়া আছে, যেখানে প্রতিটি সংখ্যা ঠিক ৩ বার এসেছে, শুধু একটি সংখ্যা বাদে — সেটি এসেছে একবার।
তোমার কাজ হলো সেই একবার আসা সংখ্যাটি বের করে return করা।

🧪 উদাহরণ:
Example 1:
makefile
Copy
Edit
Input:  nums = [2,2,3,2]
Output: 3
কারণ ২ এসেছে ৩ বার, আর ৩ এসেছে একবার।
Example 2:
makefile
Copy
Edit
Input:  nums = [0,1,0,1,0,1,99]
Output: 99
কারণ 0,1 এসেছে ৩ বার করে। আর 99 এসেছে একবার।
✅ তোমার কোড:
cpp
Copy
Edit
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int single;
        unordered_map<int,int> freq;

        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        for(auto it : freq)
        {
            if(it.second == 1)
            {
                single = it.first;
                break;
            }
        }

        return single;
    }
};
🔍 কোড ব্যাখ্যা (Bangla Step-by-Step):
🔸 Step 1: Frequency Count
cpp
Copy
Edit
unordered_map<int,int> freq;
for(int i=0; i<nums.size(); i++)
{
    freq[nums[i]]++;
}
➤ প্রতিটি সংখ্যার কয়বার এসেছে সেটা unordered_map-এ গুনে রাখা হচ্ছে।
➤ map তৈরি হবে এভাবে:
[2,2,3,2] → {2: 3, 3: 1}

🔸 Step 2: যেটা একবার এসেছে সেটা খোঁজা
cpp
Copy
Edit
for(auto it : freq)
{
    if(it.second == 1)
    {
        single = it.first;
        break;
    }
}
➤ map থেকে যেটার frequency 1, সেটাই আমাদের উত্তর।
➤ প্রথমেই পেয়ে গেলে loop থেকে break করে বের হয়ে আসা হচ্ছে।

✅ কেন Accepted হয়েছে?
✔️ কারণ তোমার কোড:

O(n) time ব্যবহার করেছে (একবার loop, আরেকবার map traversal)

সব edge case হ্যান্ডেল করেছে

সব input constraint এর মধ্যে ছিলো

সমস্যার মূল শর্ত (একটাই সংখ্যা একবার আসবে) ঠিকভাবে অনুসরণ করেছে।

