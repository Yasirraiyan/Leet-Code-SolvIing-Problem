🔍 সমস্যার বর্ণনা (Problem Description in Bangla):
তোমাকে একটি nums নামের পূর্ণসংখ্যার অ্যারে দেওয়া আছে।
তুমি চেক করো কোন সংখ্যাগুলো সবচেয়ে বেশিবার এসেছে (maximum frequency)। তারপর ঐ সংখ্যাগুলোর মোট কতবার এসেছে, সেটাই return করবে।

✅ তোমার চিন্তাধারা (Approach by You in Bangla):
frequency count: প্রতিটি সংখ্যার কয়বার এসেছে সেটা গুণতে unordered_map ব্যবহার করেছো।

store frequency: map থেকে frequency গুলো আলাদা করে reserve ভেক্টরে রেখেছো।

find max frequency: reserve ভেক্টরে লুপ করে সবচেয়ে বড় frequency বের করেছো।

sum all max frequency: এরপর যেসব frequency max এর সমান, সেগুলোর যোগফল return করেছো।

📘 কোড এবং লাইনে লাইনে বিশ্লেষণ (Code + Bangla Explanation):
cpp
Copy
Edit
class Solution 
{
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int,int>freq;
👉 unordered_map<int,int> দিয়ে প্রতিটি সংখ্যার frequency গোনার জন্য একটা freq ম্যাপ বানালে।

cpp
Copy
Edit
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
👉 পুরো nums অ্যারেতে লুপ চালিয়ে প্রতিটি সংখ্যার frequency বাড়ানো হচ্ছে।

📌 উদাহরণ:
Input → nums = [1,2,2,3,1,4]
freq → {1:2, 2:2, 3:1, 4:1}

cpp
Copy
Edit
        vector<int>reserve;
        for(auto it:freq)
        {
          reserve.push_back(it.second);
        }
👉 প্রতিটি সংখ্যার frequency আলাদা একটা vector reserve এ রাখা হলো।
এটা একটু অতিরিক্ত কাজ — সরাসরি map থেকেও কাজ করা যেত।

📌 reserve = [2, 2, 1, 1]

cpp
Copy
Edit
        int max=reserve[0];
        for(int j=1;j<reserve.size();j++)
        {
          if(reserve[j]>max)
          {
            max=reserve[j];
          }
        }
👉 লুপ চালিয়ে reserve-এর মধ্যে সবচেয়ে বড় frequency খুঁজে বের করছো।

📌 max = 2 (কারণ 2 বার এসেছে 1 এবং 2)

cpp
Copy
Edit
        int sum=0;
        for(int k=0;k<reserve.size();k++)
        {
          if(reserve[k]==max)
          {
            sum+=reserve[k];
          }
        }
👉 এবার যেসব frequency max এর সমান, তাদের যোগফল বের করছো।
মানে 1 এবং 2 দুইবার করে এসেছে → 2+2 = 4

cpp
Copy
Edit
       return sum;
    }
};
👉 sum রিটার্ন করছো, যেটাই চূড়ান্ত উত্তর।

🧮 ম্যাথেমেটিক্যাল বিশ্লেষণ (Mathematical Explanation on Test Case):
🔢 Example 1:
Input: [1,2,2,3,1,4]
Step 1: frequency: {1:2, 2:2, 3:1, 4:1}
Step 2: max frequency = 2
Step 3: যাদের frequency = 2 → 1 & 2
Step 4: তাদের total occurrence = 2 + 2 = 4 ✅

🔢 Example 2:
Input: [1,2,3,4,5]
Step 1: frequency: {1:1, 2:1, 3:1, 4:1, 5:1}
Step 2: max frequency = 1
Step 3: যাদের frequency = 1 → সবগুলো
Step 4: total occurrence = 1+1+1+1+1 = 5 ✅

🧠 Time & Space Complexity:
Time Complexity: O(n) → একবার nums-এ, একবার freq-এ

Space Complexity: O(n) → unordered_map & reserve vector worst case n elements

📂 GitHub Markdown সংরক্ষণযোগ্যভাবে:
markdown
Copy
Edit
### 🧠 Problem: Max Frequency Elements

তোমাকে একটি পূর্ণসংখ্যার অ্যারে `nums` দেওয়া আছে। কোন সংখ্যাগুলো সবচেয়ে বেশিবার (maximum frequency) এসেছে, তাদের মোট কয়বার এসেছে তা return করতে হবে।

---

### ✅ Approach (নিজস্ব চিন্তাধারা):
1. `unordered_map` দিয়ে প্রতিটি সংখ্যার frequency count করি।
2. frequency গুলো একটি `reserve` ভেক্টরে রাখি।
3. সর্বোচ্চ frequency (max) বের করি।
4. যেসব সংখ্যার frequency == max, তাদের occurrence যোগফল করি।

---

### ⏱️ Time Complexity: O(n)
### 📦 Space Complexity: O(n)

---

### 🔁 উদাহরণ বিশ্লেষণ:

- [1,2,2,3,1,4] → `{1:2, 2:2}` → 2+2 = ✅ `4`
- [1,2,3,4,5] → সব একবার → 1+1+1+1+1 = ✅ `5`
