Amar 1 ta array ase.Ei array te 2 ta number sudhu 1 bar kore ase  .Amar tader k array akare return korte hbe.

So,
  first e ami 1 ta unorderd map nei ja int number gular frequency count kore
  Range based for loop chalai jader frequency =1 means
if(it.second==1)
{
  ans.push_back(it.first)
}
kori
ans name vector array nei karon return type vector
ans return kori

Full Code:
----------
  class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        for(auto it:freq)
        {
            if(it.second==1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

Test Code:
-----------
  আপনার দেওয়া C++ কোডটি একটি নির্দিষ্ট সমস্যার সমাধান করে, যেখানে একটি পূর্ণসংখ্যার অ্যারেতে ঠিক দুটি উপাদান একবার করে উপস্থিত থাকে এবং বাকি সব উপাদান দুইবার করে উপস্থিত থাকে। আপনার কোডটি এই দুটি ইউনিক উপাদান খুঁজে বের করে। নিচে ধাপে ধাপে ব্যাখ্যা করা হলো:

🔍 আপনার কোডের ব্যাখ্যা
cpp
Copy
Edit
class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        vector<int> ans;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        for (auto it : freq)
        {
            if (it.second == 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
ধাপ ১: ফ্রিকোয়েন্সি ম্যাপ তৈরি করা
cpp
Copy
Edit
unordered_map<int, int> freq;
for (int i = 0; i < nums.size(); i++)
{
    freq[nums[i]]++;
}
এখানে, unordered_map ব্যবহার করে প্রতিটি সংখ্যার ঘনত্ব (frequency) গণনা করা হয়েছে।

উদাহরণস্বরূপ, যদি nums = [1, 2, 1, 3, 2, 5] হয়, তাহলে freq হবে {1:2, 2:2, 3:1, 5:1}।

ধাপ ২: ইউনিক উপাদান খুঁজে বের করা
cpp
Copy
Edit
for (auto it : freq)
{
    if (it.second == 1)
    {
        ans.push_back(it.first);
    }
}
এখানে, freq ম্যাপ থেকে যেসব সংখ্যার ঘনত্ব ১, সেগুলো ans ভেক্টরে যোগ করা হয়েছে।

আমাদের উদাহরণ অনুযায়ী, ans হবে [3, 5]।

ধাপ ৩: ফলাফল ফেরত দেওয়া
cpp
Copy
Edit
return ans;
অবশেষে, ans ভেক্টরটি ফেরত দেওয়া হয়েছে, যা দুটি ইউনিক সংখ্যার সমন্বয়ে গঠিত।
