🧠 প্রশ্নটি পড়েই যা বোঝা গেল:
দুইটি integer array দেওয়া আছে → nums1 এবং nums2

কাজ হচ্ছে → এই দুইটিতে যেসব সংখ্যা common আছে, সেগুলো বের করা

কিন্তু output-এ প্রতিটা সংখ্যা একবারই আসবে (unique)

💡 তুমি যেভাবে সমস্যাটা ভেঙেছো:
✅ Step 1:
"Intersection" মানে এমন কিছু সংখ্যা যেগুলো দুইটা array-তেই আছে।

তুমি চিন্তা করেছো:

যদি আমি nums1 এর সব সংখ্যাকে একটা set-এ রাখি, তাহলে সেই set এ থাকা মানেই সেই সংখ্যা nums1-এ ছিল।

✅ Step 2:
তারপর nums2 এর প্রতিটা সংখ্যাকে একে একে দেখে:

যদি nums1 এর set-এ থাকে, তাহলে এই সংখ্যা দুইটাতেই আছে।

তাই তাকে একটা আলাদা ভেক্টরে (ans) রাখো।

✅ Step 3:
কিন্তু nums2-এর মধ্যে যদি একটাই সংখ্যা অনেকবার থাকে (যেমন [2,2,2]), তাহলে ans-এর মধ্যে সেই সংখ্যাটা multiple বার থাকবে।
তাই তুমি চিন্তা করেছো:

“আমার output-এ তো unique সংখ্যা চাওয়া হয়েছে।”

তাহলে ans vector থেকে ডুপ্লিকেট বাদ দিতে হবে।

✅ Step 4:
তুমি clever ভাবে unordered_map (frequency map) ইউজ করেছো:

যার মাধ্যমে প্রতিটা সংখ্যার frequency count করেছো

তারপর যেসব সংখ্যা map-এ আছে, সেগুলোর key অর্থাৎ unique সংখ্যাগুলোকে result ভেক্টরে রেখেছো

Line by Line:
---------------
  নিশ্চয়ই! নিচে তোমার দেওয়া C++ কোডের প্রতি লাইন বাংলা ব্যাখ্যা সহ একেবারে test case walkthrough সহ, এবং কেন এই সমাধানটি accepted হয় সেটাও ব্যাখ্যা করেছি। আমি পুরো সমাধানটা একটিমাত্র ফাইলে কমেন্ট সহ লিখে দিচ্ছি, যাতে তুমি সরাসরি দেখে বুঝতে পারো এবং চালাতে পারো।

✅ কোড: intersection.cpp (Fully Commented in Bangla)
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        // set1 তৈরি করা হলো nums1 এর unique এলিমেন্ট রাখার জন্য
        unordered_set<int> set1;
        vector<int> ans;

        // nums1 এর সব এলিমেন্ট set1 এ রাখা হলো (ডুপ্লিকেট বাদ যাবে)
        for(int i = 0; i < nums1.size(); i++)
        {
            set1.insert(nums1[i]);
        }

        // এখন nums2 এর প্রতিটি এলিমেন্ট চেক করছি set1 এ আছে কিনা
        // থাকলে ans নামক vector এ রেখে দিচ্ছি
        for(int j = 0; j < nums2.size(); j++)
        {
            if(set1.find(nums2[j]) != set1.end())
            {
                ans.push_back(nums2[j]);
            }
        }

        // এখন ans এর মধ্যে ডুপ্লিকেট থাকতে পারে
        // তাই frequency count করার জন্য freq1 map নিচ্ছি
        unordered_map<int,int> freq1;
        vector<int> result;

        // ans এর প্রতিটি সংখ্যা map এ গণনা করছি
        for(int k = 0; k < ans.size(); k++)
        {
            freq1[ans[k]]++;
        }

        // এখন শুধুমাত্র unique সংখ্যাগুলো result এ রাখছি
        for(auto it : freq1)
        {
            result.push_back(it.first);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // ✅ Test Case 1:
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> output1 = sol.intersection(nums1, nums2);
    
    cout << "Test Case 1 Output: ";
    for(int val : output1) {
        cout << val << " ";
    }
    cout << endl;

    // ✅ Test Case 2:
    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    vector<int> output2 = sol.intersection(nums3, nums4);

    cout << "Test Case 2 Output: ";
    for(int val : output2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
🧪 Test Case 1 Walkthrough: nums1 = [1,2,2,1], nums2 = [2,2]
Step by Step:
Step 1: set1 becomes {1,2}

Step 2: Loop through nums2

2 → found → ans = [2]

2 → found → ans = [2,2]

Step 3: frequency map = {2:2}

Step 4: result = [2]

✅ Final Output: 2

🧪 Test Case 2 Walkthrough: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Step by Step:
Step 1: set1 becomes {4,9,5}

Step 2: Loop through nums2

9 → found → ans = [9]

4 → found → ans = [9,4]

9 → found → ans = [9,4,9]

8 → not found

4 → found → ans = [9,4,9,4]

Step 3: frequency map = {9:2, 4:2}

Step 4: result = [9,4] or [4,9]

✅ Final Output: 9 4 (or 4 9, যেকোনো অর্ডার acceptable)

✅ কেন এই কোডটি Accepted হয়?
প্রশ্নে চাওয়া হয়েছে Intersection, Unique সহ:
আমরা set1 দিয়ে প্রথম array এর unique সংখ্যা রেখে দ্বিতীয়টার মধ্যে তা খুঁজেছি।

Duplicate রিমুভ করার জন্য frequency map ব্যবহার:
একই সংখ্যা multiple বার পাওয়া গেলেও আমরা frequency map দিয়ে একবারই রেখেছি।

Constraints (length ≤ 1000) অনুযায়ী Efficient:

set, map → O(1) average time

সামগ্রিকভাবে Time: O(n + m) এবং Space: O(n)

Full Code:
-----------
  class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
      unordered_set<int>set1;
      vector<int>ans;
      for(int i=0;i<nums1.size();i++)
      {
        set1.insert(nums1[i]);
      }  
      for(int j=0;j<nums2.size();j++)
      {
        if(set1.find(nums2[j])!=set1.end())
        {
            ans.push_back(nums2[j]);
        }
      }
      unordered_map<int,int>freq1;
      vector<int>result;
      for(int k=0;k<ans.size();k++)
      {
        freq1[ans[k]]++;
      }
      for(auto it:freq1)
      {
        result.push_back(it.first);
      }
      return result;
    }
};
