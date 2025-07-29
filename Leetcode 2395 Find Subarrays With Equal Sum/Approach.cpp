🔍 Problem Understanding (প্রশ্ন বিশ্লেষণ)

তোমাকে একটি 0-indexed integer array দেওয়া হবে nums নামে। এখন তোমাকে বের করতে হবে:

ঐ অ্যারেতে length 2 এর দুটি ভিন্ন সাবঅ্যারে (subarray) আছে কি না যাদের sum একই।

সাবঅ্যারে মানে একটানা ২টি উপাদান।

দুই সাবঅ্যারে একই ইনডেক্স থেকে শুরু করতে পারবে না, তবে তাদের মান এক হতে পারে।



---

🧠 Thought Process (সমস্যা বুঝে কীভাবে চিন্তা করব)

1. যেহেতু সাবঅ্যারে-র দৈর্ঘ্য নির্দিষ্ট (২), তাই আমরা শুধুমাত্র সব ধারাবাহিক জোড়া দেখতে পারি:

nums[0], nums[1]

nums[1], nums[2]

nums[2], nums[3]

... এভাবে n-2 ইনডেক্স পর্যন্ত।



2. প্রত্যেক জোড়া nums[i] + nums[i+1] এই ফর্মে থাকবে। যদি আগে দেখা কোনো সাবঅ্যারে-এর sum আবার আসে, তাহলে উত্তর true।


3. এজন্য আমরা একটা hash set/map ব্যবহার করব যেটাতে আমরা প্রতিটি sum সেভ করব। যদি কোনো sum এর আগে থেকে অস্তিত্ব থাকে, তাহলে আমরা ধরে নেব যে সমান দুটি সাবঅ্যারে পাওয়া গেছে।

🔎 Line-by-line Code Explanation (তোমার কোড বিশ্লেষণ)

class Solution {
public:
    // একটি ফাংশন যা একটি ভেক্টরের সব উপাদান যোগফল করে
    int CalculateSum(vector<int>&v)
    {
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
        }
        return sum;
    }

🔹 এখানে CalculateSum ফাংশনটা অতিরিক্ত কারণ তুমি শুধু দুইটা উপাদান যোগ করছো। সরাসরি nums[i]+nums[j] লিখলে সেটা আরও সহজ হতো।


---

bool findSubarrays(vector<int>& nums)
    {
        unordered_map<int,int>freq; // sum গুলো গণনা রাখবে

🔹 আমরা map ব্যবহার করছি যাতে একই sum কয়বার আসছে তা গণনা করতে পারি।


---

for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                int subarraysize=j-i+1;
                if(subarraysize==2)
                {
                    vector<int>sub={nums[i],nums[j]};
                    freq[CalculateSum(sub)]++;
                }
            }
        }

🔹 তুমি প্রত্যেক i থেকে j পর্যন্ত সব pair নিচ্ছো এবং যখন j-i+1 == 2, তখন সেই দুইটা উপাদান নিয়ে সাবঅ্যারে তৈরি করছো।

🟡 এই জায়গায় দুইটি optimization করা যেত:

তুমি শুধু adjacent i এবং i+1 ইনডেক্স দেখতে পারো কারণ দুই উপাদানের সাবঅ্যারে adjacent হতে হবে।

এখনকার কোড O(n^2) টাইম নিচ্ছে। ছোট ইনপুটে Accepted হবে, কিন্তু বড় ইনপুটে সমস্যা হতো।



---

bool find=false;
        for(auto it:freq)
        {
            if(it.second>1)
            {
                find=true;
                break;
            }
        }
        return find;
    }
};

🔹 map-এর মধ্যে যদি কোনো sum একাধিকবার আসে (value > 1), তাহলে সেই সাবঅ্যারে একাধিকবার পাওয়া গেছে।


---

🔢 Mathematical Logic

Suppose array = [a, b, c, d]

All subarrays of size 2:

[a, b] → sum = a + b

[b, c] → sum = b + c

[c, d] → sum = c + d


We just check if any two of these sums are equal.


---

🧪 Test Cases with Trace

Example 1:

nums = [4,2,4]
Sums: 
[4,2] = 6
[2,4] = 6 → already seen → return true

Example 2:

nums = [1,2,3,4,5]
Sums:
[1,2] = 3
[2,3] = 5
[3,4] = 7
[4,5] = 9 → all unique → return false

Example 3:

nums = [0,0,0]
Sums:
[0,0] = 0
[0,0] = 0 → already seen → return true


---

📚 Summary

বিষয়	ব্যাখ্যা

প্রশ্ন	দুইটি ভিন্ন ইনডেক্সে শুরু হওয়া ২ সাইজের সাবঅ্যারে-এর sum কি সমান?
কৌশল	প্রত্যেক i তে nums[i]+nums[i+1] বের করে আগের দেখা sum গুলো সাথে মেলানো
টাইম কমপ্লেক্সিটি	তোমার কোডে O(n^2), কিন্তু efficient হলে O(n)
ডেটা স্ট্রাকচার	unordered_map বা unordered_set


Full Code:
-----------

  class Solution
{
public:
    int CalculateSum(vector<int>&v)
    {
        int sum=0;
        for(int i=0;i<v.size();i++)
            {
                sum+=v[i];
            }
        return sum;
    }
    bool findSubarrays(vector<int>& nums)
    {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=i;j<nums.size();j++)
                    {
                        int subarraysize=j-i+1;
                                if(subarraysize==2)
                               {
                                vector<int>sub={nums[i],nums[j]};
                                {
                                    freq[CalculateSum(sub)]++;         
                                }
                            }
                    }
                    }
        bool find=false;
        for(auto it:freq)
            {
                if(it.second>1)
                {
                    find=true;
                    break;
                }
            }
        return find;
    }
};
