🔍 উদাহরণ ও লক্ষ্য:
Input: nums = [1,2,3,4,5,4]
👉 এখানে 4 দুইবার এসেছে, আর 2 হলো প্রাইম।
✅ So, output: true.

Input: nums = [1,2,3,4,5]
👉 সব সংখ্যার ফ্রিকোয়েন্সি 1, কিন্তু 1 প্রাইম না।
❌ So, output: false.

✅ কোডের পুরো ধারাবাহিক ও ব্যাখ্যা:
cpp
Copy
Edit
class Solution {
public:
✅ CheckPrime() ফাংশন:
cpp
Copy
Edit
  bool CheckPrime(int n)
  {
    bool isprime=true;
🔹 isprime ধরে নিচ্ছি true — পরে যদি divisor পাই তাহলে false করব।

cpp
Copy
Edit
    if(n<=1) 
    {
      isprime=false;
    }
🔹 1 বা তার কম মান কখনোই প্রাইম না — তাই সরাসরি false।

cpp
Copy
Edit
    for(int i=2;i*i<=n;i++)
    {
      if(n%i==0)
      {
        isprime=false;
        break;
      }
    }
🔹 Prime চেক করার স্ট্যান্ডার্ড লজিক — 2 থেকে sqrt(n) পর্যন্ত চেক করি। যদি কোন ভাগ হয়, তাহলে এটা প্রাইম না।

cpp
Copy
Edit
    return isprime;
  }
🔹 শেষে true/false রিটার্ন করি।

✅ মূল কাজের ফাংশন checkPrimeFrequency():
cpp
Copy
Edit
    bool checkPrimeFrequency(vector<int>& nums) 
    {
        bool check=false;
        unordered_map<int,int>freq;
🔹 একটা ম্যাপ নিয়ে প্রতিটা সংখ্যার ফ্রিকোয়েন্সি গুনছি।

cpp
Copy
Edit
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
🔹 পুরো অ্যারেটা ঘুরে গিয়ে ম্যাপে ইনপুট সংখ্যাগুলোর ফ্রিকোয়েন্সি কাউন্ট করলাম।

✅ এখন ফ্রিকোয়েন্সিগুলো নিয়ে প্রাইম কিনা চেক করব:
cpp
Copy
Edit
        for(auto it:freq)
        {
          if(CheckPrime(it.second))
          {
            check=true;
            break;
          }
        }
🔹 যতগুলো সংখ্যার frequency আছে সেগুলোর frequency (মানে it.second) প্রাইম কিনা চেক করব।
🔹 যদি কোনো একটা প্রাইম পাই, check = true করে break করি।

cpp
Copy
Edit
        return check;
    }
};
🔹 শেষে true/false রিটার্ন করলাম।

🔢 উদাহরণ দিয়ে কোড এক্সিকিউশন বিশ্লেষণ:
Input: nums = [2,2,2,4,4]
🔸 ফ্রিকোয়েন্সি ম্যাপ হবে:

rust
Copy
Edit
2 -> 3
4 -> 2
🔸 CheckPrime(3): ✅ প্রাইম
🔸 CheckPrime(2): ✅ প্রাইম

🔸 যেহেতু কমপক্ষে একটির ফ্রিকোয়েন্সি প্রাইম, return true

✅ কেন Accepted হচ্ছে?
সময় সীমা: O(n) ম্যাপ তৈরি + O(√m) প্রাইম চেক = efficient

ইনপুট constraint ছোট (100 এর মধ্যে), তাই brute-force check prime acceptable

unordered_map এর কারণে ফ্রিকোয়েন্সি খুব সহজে বের করতে পারি

Full Code:
------------

  class Solution 
{
public:
  bool CheckPrime(int n)
  {
    bool isprime=true;
    if(n<=1) 
    {
      isprime=false;
    }
    for(int i=2;i*i<=n;i++)
    {
      if(n%i==0)
      {
        isprime=false;
        break;
      }
    }
    return isprime;
  }
    bool checkPrimeFrequency(vector<int>& nums) 
    {
        bool check=false;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        for(auto it:freq)
        {
          if(CheckPrime(it.second))
          {
            check=true;
            break;
          }
        }
        return check;
    }
};
