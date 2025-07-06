🔶 প্রশ্ন বিশ্লেষণ (From the problem)
nums অ্যারে-তে মোট n টা সংখ্যা আছে, এবং প্রতিটা সংখ্যা 1 থেকে n এর মধ্যে। কিছু সংখ্যা মিসিং (মানে, 1 থেকে n এর মধ্যে কিছু সংখ্যা nums-এ নেই)। তোমাকে বলতে হবে, কোন কোন সংখ্যা nums-এ নেই।

🧠 তুমি যেটা ভেবেছো:
nums-এ কোন সংখ্যা আছে সেটা খেয়াল রাখতে হবে।

তারপর 1 থেকে n পর্যন্ত ঘুরে দেখা — কোন সংখ্যা পাওয়া যায়নি, মানে সেটাই তো মিসিং।

✅ তোমার কোডের ব্যাখ্যা:
cpp
Copy
Edit
vector<int> findDisappearedNumbers(vector<int>& nums)
🔹 এখানে ফাংশনটা nums ইনপুট হিসেবে নিচ্ছে এবং রিটার্ন করবে একটা ভেক্টর, যেটায় থাকবে মিসিং নাম্বারগুলো।

cpp
Copy
Edit
int n = nums.size(); 
vector<int> ans;
unordered_set<int> set1;
🔹 n হচ্ছে nums-এর সাইজ।

🔹 ans — যেখানে মিসিং নাম্বারগুলো জমা হবে।

🔹 set1 — একটা সেট বানাচ্ছো, যাতে তুমি nums-এ কোন সংখ্যা আছে সেটা সংরক্ষণ করো।

cpp
Copy
Edit
for (int j = 0; j < nums.size(); j++) {
    set1.insert(nums[j]);
}
🔹 এখানে তুমি nums-এর সব সংখ্যা set1-এ রাখছো।
কারণ: সেটে কোন সংখ্যা আছে সেটা খুব সহজে (O(1) time) দেখে ফেলা যায়।

উদাহরণ:
nums = [4,3,2,7,8,2,3,1]
তাহলে set1 = {1,2,3,4,7,8} হবে। (Duplicate যেমন 2, 3 থাকবে একবারই)

cpp
Copy
Edit
for (int i = 1; i <= n; i++) {
    if (set1.find(i) == set1.end()) {
        ans.push_back(i);
    }
}
🔹 এখন 1 থেকে n পর্যন্ত ঘুরে ঘুরে যাচ্ছো।

🔹 যদি set1-এ i নাই থাকে, তাহলে ওটা missing number — তাই ans-এ রেখে দাও।

উদাহরণ অনুযায়ী:

cpp
Copy
Edit
n = 8
i: 1 2 3 4 5 6 7 8
set1: {1,2,3,4,7,8}
missing: 5, 6
cpp
Copy
Edit
return ans;
🔹 অবশেষে সব missing নাম্বার রিটার্ন করে দিচ্ছো।

🎯 তোমার কোড Accepted হলো কেন?
✅ Time Complexity: O(n) — একবার nums ট্রাভার্স, একবার 1 থেকে n ট্রাভার্স।

✅ Space Complexity: O(n) — কারণ unordered_set ব্যবহার করছো।

✅ যুক্তিসংগত ও ক্লিন সমাধান।

📚 উদাহরণ বিশ্লেষণ:
Input:
cpp
Copy
Edit
nums = [4,3,2,7,8,2,3,1]
set1 → {1,2,3,4,7,8}

i from 1 to 8 → check which i not in set1 → [5,6]

Output:
csharp
Copy
Edit
[5,6]
✅ কীভাবে তুমি সমাধানটা ভেবেছো?
তুমি প্রশ্নে দেখেছো — nums-এ ১ থেকে n পর্যন্ত সব নাম্বার না-ও থাকতে পারে।
তাই তুমি ভেবেছো —

“আমি যদি nums-এ যেসব নাম্বার আছে, সেগুলো আলাদা করে রাখি (set-এ), তাহলে 1 থেকে n পর্যন্ত ঘুরে দেখে বলতে পারবো — কোনগুলো নেই।”

এটা হচ্ছে hashing-based approach। Efficient এবং সহজবোধ্য। তাই Accepted হয়েছে।

Full Code:
----------

  class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
     { 
        int n=nums.size();
      vector<int>ans;
      unordered_set<int>set1;
      for(int j=0;j<nums.size();j++)
      {
            set1.insert(nums[j]);
      }
      for(int i=1;i<=n;i++)
      {
        if(set1.find(i)==set1.end())
        {
          ans.push_back(i);
        }
      }
      return ans;
    }
};
