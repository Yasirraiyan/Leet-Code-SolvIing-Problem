তোমার দেওয়া কোডটি map ব্যবহার করে নির্ধারণ করছে যে কোন সংখ্যাগুলো nums অ্যারেতে অনুপস্থিত (missing)।

এখন আমরা line by line বিশ্লেষণ করব Bangla-তে, সহ test case দিয়ে বুঝাবো কীভাবে কাজ করছে।

🔶 প্রবলেম রিক্যাপ (Bangla):
তোমাকে এমন একটি nums নামের অ্যারে দেওয়া হয়েছে, যাতে n টি সংখ্যা আছে এবং প্রতিটি সংখ্যা [1, n] রেঞ্জের মধ্যে। কিছু সংখ্যা হয়তো একাধিক বার আসবে, আর কিছু সংখ্যা একবারও আসবে না।

তোমার কাজ হলো: ১ থেকে n পর্যন্ত যেসব সংখ্যা nums-এ নাই, সেগুলো খুঁজে বের করা।

✅ তোমার কোড (C++): Line by Line ব্যাখ্যা সহ
cpp
Copy
Edit
class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        unordered_map<int,int> freq; // ➊ ফ্রিকোয়েন্সি ট্র্যাক করার জন্য map
        
        int n = nums.size();         // ➋ nums এর সাইজ n = সংখ্যা কতো
        
        vector<int> reserve;         // ➌ এখানে ১ থেকে n পর্যন্ত সংখ্যা রাখা হবে
        vector<int> ans;             // ➍ শেষে যেগুলো missing সেটা রাখা হবে

        // ➎ Step 1: reserve এ 1 থেকে n সংখ্যা রাখা হচ্ছে
        for(int i = 1; i <= n; i++)
        {
            reserve.push_back(i);
        }

        // ➏ Step 2: nums[] অ্যারে থেকে ফ্রিকোয়েন্সি কাউন্ট করো
        for(int j = 0; j < nums.size(); j++)
        {
            freq[nums[j]]++;  // প্রতিটি nums[j] এর occurrence বাড়ানো হচ্ছে
        }

        // ➐ Step 3: 1 থেকে n এর মধ্যে যেগুলোর ফ্রিকোয়েন্সি 0 → মানে আসে নাই
        for(int k = 0; k < reserve.size(); k++)
        {
            if(freq[reserve[k]] == 0)
            {
                ans.push_back(reserve[k]); // না আসা সংখ্যা push করো
            }
        }

        return ans;  // ➑ missing নাম্বারগুলোর list রিটার্ন করো
    }
};
🔍 উদাহরণ:
cpp
Copy
Edit
Input:  nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
🎯 বিশ্লেষণ:
n = 8

reserve = [1,2,3,4,5,6,7,8]

freq map =

yaml
Copy
Edit
{
  1: 1,
  2: 2,
  3: 2,
  4: 1,
  7: 1,
  8: 1
}
Now check reserve:

freq[1] = 1 → skip

freq[2] = 2 → skip

freq[3] = 2 → skip

freq[4] = 1 → skip

freq[5] = 0 ✅ → missing → push

freq[6] = 0 ✅ → missing → push

freq[7] = 1 → skip

freq[8] = 1 → skip

Output: [5, 6]

✅ Time & Space Complexity বিশ্লেষণ:
Time Complexity:

O(n) → reserve তৈরি করতে

O(n) → ফ্রিকোয়েন্সি কাউন্ট করতে

O(n) → মিসিং চেক করতে

Total: O(n) ✅

Space Complexity:

O(n) → reserve অ্যারে

O(n) → map/freq

O(n) → ans

⚠️ তাই Follow-up constraint (no extra space) পূরণ করে না।

🚫 Follow-up: No Extra Space?
এই কোডটি follow-up requirement:

"Could you do it without extra space and in O(n) runtime?"

→ এটা fulfill করে না, কারণ এখানে:

unordered_map, reserve[], এবং ans[] → extra space নিচ্ছে


Full Code:
----------
  class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
     {
      unordered_map<int,int>freq;
      int n=nums.size();
      vector<int>reserve;
         vector<int>ans;
      for(int i=1;i<=n;i++)
      {
           reserve.push_back(i);
      }
      for(int j=0;j<nums.size();j++)
      {
        freq[nums[j]]++;
      }
   
      for(int k=0;k<reserve.size();k++)
      {
        if(freq[reserve[k]]==0)
        {
          ans.push_back(reserve[k]);
        }
      }
      return ans;
    }
};
