তুমি যে সমস্যাটির সমাধান করতে চাইছো সেটি হলো — একটি অ্যারেতে যতগুলো সম্ভাব্য সাবঅ্যারে রয়েছে, প্রতিটি সাবঅ্যারে-র মধ্যে যতটি ভিন্ন ভিন্ন মান (distinct element) আছে তার স্কয়ার (square) বের করে সবগুলো সাবঅ্যারের জন্য যোগফল বের করা।

✅ উদাহরণ দিয়ে সমস্যাটি বুঝি:
উদাহরণ: nums = [1, 2, 1]
সাবঅ্যারে গুলো:

Subarray	Distinct Count	Square
[1]	1	1
[2]	1	1
[1]	1	1
[1,2]	2	4
[2,1]	2	4
[1,2,1]	2	4
Total		15

🧠 কিভাবে প্রশ্ন পড়েই সমাধান ভাববো?
প্রশ্নে বলছে:

প্রতিটি সাবঅ্যারে এর distinct element গুনে বের করতে হবে।

তারপর তার স্কয়ার করতে হবে।

সবগুলোর স্কয়ারের যোগফল রিটার্ন করতে হবে।

তাহলে আমাদের দরকার:

প্রতিটি সাবঅ্যারে বের করা → ২টা লুপ দিয়ে করা যায়।

প্রতিটি সাবঅ্যারে-তে কতগুলো ভিন্ন সংখ্যা আছে তা গোনা → unordered_map দিয়ে efficiently করা যায়।

🧱 Time Complexity:
মোট সাবঅ্যারে: O(n^2)

প্রতিটি সাবঅ্যারে থেকে ভিন্ন মান বের করা: সর্বোচ্চ O(n)

মোট সময়: O(n^3) (acceptable for n ≤ 100)

✅ কোড বিশ্লেষণ (Line by Line Bangla Explanation):
cpp
Copy
Edit
class Solution 
{
public:
    // Helper function: একটি সাবঅ্যারে পাস করলে সেটার মধ্যে কতটি ভিন্ন মান আছে তা গুনে রিটার্ন করে
    int findDistinctvalue(vector<int>& nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++; // প্রতিটি সংখ্যার frequency বাড়ানো
        }
        return freq.size(); // মোট কতটি unique key আছে (অর্থাৎ ভিন্ন মান)
    }

    int sumCounts(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0; // Final উত্তর সংরক্ষণ করবে

        // সব সম্ভাব্য সাবঅ্যারে তৈরি করতে nested loop
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                vector<int> sub; // নতুন সাবঅ্যারে তৈরি
                for (int k = i; k <= j; k++)
                {
                    sub.push_back(nums[k]); // i থেকে j পর্যন্ত উপাদান sub তে ঢোকানো
                }

                int distinct = findDistinctvalue(sub); // sub array এর মধ্যে কয়টা ভিন্ন সংখ্যা
                ans += distinct * distinct; // তার স্কয়ার করে যোগ করা
            }
        }

        return ans; // সব স্কয়ার যোগফল রিটার্ন
    }
};
🧪 Test Case Walkthrough:
cpp
Copy
Edit
nums = [1, 2, 1]
i = 0:

j = 0 → sub = [1] → distinct = 1 → ans += 1

j = 1 → sub = [1,2] → distinct = 2 → ans += 4

j = 2 → sub = [1,2,1] → distinct = 2 → ans += 4

i = 1:

j = 1 → sub = [2] → distinct = 1 → ans += 1

j = 2 → sub = [2,1] → distinct = 2 → ans += 4

i = 2:

j = 2 → sub = [1] → distinct = 1 → ans += 1

Total = 1 + 4 + 4 + 1 + 4 + 1 = 15 ✅

Full Code:
-----------

  class Solution 
{
public:
  int findDistinctvalue(vector<int>& nums)
  {
    unordered_map<int,int>freq;
    for(int i=0;i<nums.size();i++)
    {
      freq[nums[i]]++;
    }
    vector<int>v;
    for(auto it:freq)
    {
      v.push_back(it.first);
    }
    int ans=freq.size();
    return ans;
  }
    int sumCounts(vector<int>& nums) 
    {
      int n=nums.size();
      int ans=0;
     // vector<int> sub;
      for(int i=0;i<nums.size();i++)
      {
        for(int j=i;j<nums.size();j++)
        {
             vector<int> sub; 
          for(int k=i;k<=j;k++)
          {
            // ans+=findDistinctvalue(sub)*findDistinctvalue(sub);
            sub.push_back(nums[k]);
          }
            int distinct=findDistinctvalue(sub);
             ans+=distinct*distinct;
        }
      }
    
      return ans;
    }
};
