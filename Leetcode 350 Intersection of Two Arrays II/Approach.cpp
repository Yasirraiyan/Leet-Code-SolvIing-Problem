✅ Problem:
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays.

📝 Input:

cpp
Copy
Edit
nums1 = [1,2,2,1], nums2 = [2,2]
🔁 Expected Output:

cpp
Copy
Edit
[2,2]
🔍 তুমি যেভাবে চিন্তা করেছো (Approach Explained in Bangla):
🧠 Step-by-step Thinking:
🔍 "Each element in the result must appear as many times as it shows in both arrays."

মানে nums1 এ কোনো সংখ্যা ২ বার থাকলে, আর nums2 তে সেটা ৩ বার থাকলে, তাহলে 2 বারই output এ থাকবে (i.e., min(2,3) বার)

🧠 তাই তুমি চিন্তা করেছো:

প্রতিটা array এর জন্য frequency count করো

তারপর যেগুলা দুইটা array-তে common → তাদের minimum frequency অনুযায়ী output এ রাখো

✅ তোমার কোড: লাইন বাই লাইন Bangla ব্যাখ্যা সহ
cpp
Copy
Edit
class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
🔹 intersect নামের function নিচ্ছে দুইটা vector nums1 এবং nums2
🔹 এবং return করবে intersection values-এর vector

cpp
Copy
Edit
{
    unordered_set<int>set1;
    unordered_set<int>set2;
🔹 এখানে set1 এবং set2 তৈরি করা হয়েছে — যাতে আমরা শুধু unique elements রাখি
🔹 পরে চেক করার সময় efficient হয়

cpp
Copy
Edit
    vector<int>ans;
    unordered_map<int,int>freq1;
    unordered_map<int,int>freq2;
🔹 ans হচ্ছে final output vector
🔹 freq1 এবং freq2 → দুইটা frequency map → nums1 এবং nums2 এর মধ্যে প্রতিটা সংখ্যার count রাখা হবে

cpp
Copy
Edit
    for(int i=0;i<nums1.size();i++)
    {
        set1.insert(nums1[i]);
        freq1[nums1[i]]++;
    }
🔹 nums1 এর প্রতিটা সংখ্যা set1-এ রাখা হচ্ছে (unique value check এর জন্য)
🔹 freq1-এ তার frequency বাড়ানো হচ্ছে

cpp
Copy
Edit
    for(int j=0;j<nums2.size();j++)
    {
        set2.insert(nums2[j]);
        freq2[nums2[j]]++;
    }
🔹 একই কাজ nums2 এর জন্য — unique check (set2) এবং frequency count (freq2)

cpp
Copy
Edit
    for(int k=0;k<nums1.size();k++)
🔹 এবার আবার nums1 ঘুরে দেখা হচ্ছে

cpp
Copy
Edit
    {
        if((set2.find(nums1[k])!=set2.end()))
🔹 যদি nums1[k] সংখ্যা nums2 তেও থাকে (মানে set2 তে আছে)

cpp
Copy
Edit
        {
            int occur = min(freq1[nums1[k]], freq2[nums1[k]]);
🔹 তাহলে আমরা এই সংখ্যাটার minimum frequency বের করলাম
যেমন:

nums1 = [1,2,2,1], nums2 = [2,2] →
2 আছে: nums1 এ 2 বার, nums2 এ 2 বার
→ output এ 2 বার রাখতে হবে

cpp
Copy
Edit
            while(occur--)
            {
                ans.push_back(nums1[k]);
            }
🔹 occur যতবার হবে ততবার nums1[k] কে ans এ রাখা হচ্ছে

cpp
Copy
Edit
            freq1[nums1[k]] = 0;
            freq2[nums1[k]] = 0;
🔹 পরে যেন এই সংখ্যা আবার না নেয়া হয়, তাই frequency reset করে দিচ্ছো
(ভালো practice, না দিলে duplicate হয়ে যেতো)

cpp
Copy
Edit
        }
    }
    return ans;
}
🔹 সবশেষে result vector ans return করছো

🔎 Test Case 1 Walkthrough (Line by Line):
Input:
cpp
Copy
Edit
nums1 = [1,2,2,1]
nums2 = [2,2]
Execution:
freq1: {1:2, 2:2}

freq2: {2:2}

Loop nums1:

1: set2-এ নাই → skip

2: আছে → min(2,2) = 2 → ans = [2,2], freq reset

2: freq1[2] = 0 → skip

1: set2-এ নাই → skip

✅ Final Output: [2,2]

🔎 Test Case 2:
Input:
cpp
Copy
Edit
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]
Execution:
freq1: {4:1, 9:1, 5:1}

freq2: {9:2, 4:2, 8:1}

Loop:

4: set2-এ আছে → min(1,2) = 1 → ans: [4]

9: set2-এ আছে → min(1,2) = 1 → ans: [4,9]

5: set2-এ নাই → skip

✅ Final Output: [4,9] or [9,4]

🧠 Time & Space Complexity:
✅ Time: O(n + m) → n = size of nums1, m = size of nums2

✅ Space: O(n + m) → set + frequency map

✅ কেন এই কোড Accepted হবে:
তুমি প্রশ্নে যা চাওয়া হয়েছে তা একদম সুন্দরভাবে handle করেছো:

Frequency match ✅

Minimum বার নেয়া ✅

Order important না — যেকোনো order acceptable ✅

📝 তোমার কোড ফাইল হিসেবে সংক্ষেপে:
cpp
Copy
Edit
// Intersection with frequency count
class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> set1, set2;
        unordered_map<int,int> freq1, freq2;
        vector<int> ans;

        for(int i=0; i<nums1.size(); i++) {
            set1.insert(nums1[i]);
            freq1[nums1[i]]++;
        }
        for(int j=0; j<nums2.size(); j++) {
            set2.insert(nums2[j]);
            freq2[nums2[j]]++;
        }

        for(int k=0; k<nums1.size(); k++) {
            if(set2.find(nums1[k]) != set2.end()) {
                int occur = min(freq1[nums1[k]], freq2[nums1[k]]);
                while(occur--) {
                    ans.push_back(nums1[k]);
                }
                freq1[nums1[k]] = 0;
                freq2[nums1[k]] = 0;
            }
        }

        return ans;
    }
};
