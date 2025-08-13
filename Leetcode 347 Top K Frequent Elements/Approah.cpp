Question Analysis (কোড লিখার আগে কীভাবে চিন্তা করা যায়)
প্রশ্নটি বলছে:

Given an integer array nums and an integer k, return the k most frequent elements.

তাহলে প্রথমে ভাবো:

আমরা কি চাইছি?

Array থেকে প্রতিটি element কতবার এসেছে সেটা বের করতে হবে।

তারপর সবচেয়ে frequent k elements বের করতে হবে।

Constraints:

Array এর size বড় হতে পারে (up to 10⁵)।

Answer unique (same frequency element সমস্যা নেই)।

Time complexity O(n log n) এর চেয়ে ভালো লাগবে।

তাহলে logical approach হবে:

Step 1: Frequency count করতে হবে → unordered_map দিয়ে করা সহজ।

Step 2: Frequency অনুযায়ী top k elements বের করতে হবে।

Code Analysis
Step 1: Frequency Map বানানো
cpp
Copy
Edit
unordered_map<int,int>freq;
for(int i=0;i<nums.size();i++)
{
    freq[nums[i]]++;
}
এখানে আমরা unordered_map ব্যবহার করছি, যেখানে key = element, value = frequency।

Example: nums = [1,1,1,2,2,3]

map হবে {1:3, 2:2, 3:1}

✅ এটা correctly element frequency বের করছে।

Step 2: Frequency values নিয়ে vector বানানো
cpp
Copy
Edit
vector<int>v;
for(auto it:freq)
{
    v.push_back(it.second);
}
আমরা শুধু frequency গুলো বের করে একটি vector v তে রাখলাম।

Example: [3,2,1]

Step 3: Sort এবং reverse করা
cpp
Copy
Edit
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
আমরা frequency vector কে descending order এ সাজালাম।

এখন v = [3,2,1]

✅ Top frequency বের করার জন্য এই কাজটা দরকার।

Step 4: Top k frequency বের করা
cpp
Copy
Edit
vector<int>vv;
for(int j=0;j<v.size();j++)
{
    vv.push_back(v[j]);
    if(vv.size()==k)
    {
        break;
    }
}
আমরা শুধু top k frequency নিলাম।

উদাহরণ: k = 2 → vv = [3,2]

Step 5: Answer elements বের করা
cpp
Copy
Edit
vector<int>ans;
for(auto it:freq)
{
    for(int j=0;j<vv.size();j++)
    {
        if(it.second==vv[j])
        {
            ans.push_back(it.first);
            vv.erase(vv.begin() + j); // remove used frequency
            break; 
        }
    }
    if(ans.size()==k) break;
}
আমরা map থেকে দেখছি কোন element এর frequency top k frequency এর মধ্যে আছে।

যদি আছে, তাহলে সেটিকে answer vector ans এ push করি।

একবার frequency ব্যবহার করলে আমরা vv.erase() দিয়ে remove করি যাতে duplicate না হয়।

loop break করি যখন ans.size() == k।

উদাহরণ:

freq map: {1:3, 2:2, 3:1}

vv: [3,2]

Step by step:

it = (1,3) → 3 in vv → ans.push_back(1), vv becomes [2]

it = (2,2) → 2 in vv → ans.push_back(2), vv empty → stop

Output: [1,2] ✅

Step 6: Return
cpp
Copy
Edit
return ans;
Top k frequent elements return হচ্ছে।

কেন এটা কাজ করছে
Map দিয়ে frequency calculate করা হচ্ছে।

Frequency vector সাজানো হচ্ছে descending order এ।

Top k frequency বের করা হচ্ছে।

Map iterate করে matching frequency elements answer এ push করা হচ্ছে।

Test case Example:

cpp
Copy
Edit
nums = [1,1,1,2,2,3], k = 2
Step 1: freq map → {1:3, 2:2, 3:1}

Step 2: v → [3,2,1]

Step 3: vv → [3,2]

Step 4: ans → [1,2] ✅

nums = [1], k = 1
Step 1: freq map → {1:1}

Step 2: v → [1]

Step 3: vv → [1]

Step 4: ans → [1] ✅

Code Approach ভাবার Logic (যখন প্রশ্ন পড়ো)
কতোবার element এসেছে → frequency map

Top k frequency বের করতে → sort frequency

Frequency এর সাথে match করে element collect করা → final answer

Full Code:
----------

  class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
     {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
         vector<int>v;
         for(auto it:freq)
         {
            v.push_back(it.second);
         }
         sort(v.begin(),v.end());
         reverse(v.begin(),v.end());
         vector<int>vv;
         for(int j=0;j<v.size();j++)
         {
            vv.push_back(v[j]);
            if(vv.size()==k)
            {
                break;
            }
         }
         vector<int>ans;
         for(auto it:freq)
         {
         for(int j=0;j<vv.size();j++)
         {
             if(it.second==vv[j])
             {
                ans.push_back(it.first);
                 vv.erase(vv.begin() + j); // remove used frequency
                    break; 
             }
         }
         if(ans.size()==k) break;
         }
         return ans;
    }
};
