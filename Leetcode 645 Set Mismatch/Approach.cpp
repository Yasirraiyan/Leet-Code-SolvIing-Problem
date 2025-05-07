Amar 1 ta array ase.Ei array te 1 to n porjonto sob integer thakar kotha.But unfortunately amar ei array te 1 ta number repeat ase mane 1 bar er veshi base ba 2 bar ase.
  And 1 ta number missing from the range:[1,n]
  Amar jei number missing ar repeat ase tader both k amr array akare return korte hbe.
  Ami first e 1 ta vector nei reserve jekhane [1,n] n=nums.size(); porjonto sob number rakhbo.Tai 1 ta variable nei n jekhane n=nums.size()
  1 ta for loop chalaai i=1 to i<=n porjonto i++ kori traverse the range [1,n]
  reserve e push kori i;
1 ta vector nei result 
তোমার দেওয়া কোডটি Accepted হচ্ছে কারণ এটি সঠিকভাবে দুটি সংখ্যাকে বের করতে পারছে:

যে সংখ্যা দুইবার এসেছে (duplicate)

যে সংখ্যা মিসিং (missing)

এটি সমস্যার নির্ভুল বিশ্লেষণ করে সমাধান করছে।

🔍 প্রশ্নটা ভালোভাবে বোঝা (Bangla Explanation):
প্রশ্ন:

একটি সেটে (set) 1 থেকে n পর্যন্ত সব সংখ্যা থাকার কথা ছিল। কিন্তু ভুলবশতঃ একটি সংখ্যা দুইবার এসেছে এবং একটি সংখ্যা হারিয়ে গেছে।
এখন তোমাকে একটি অ্যারে nums দেওয়া হবে যেখানে সেই ভুলের ফলাফল আছে।
তোমার কাজ হলো [duplicate, missing] এই দুইটি সংখ্যা বের করে ফেরত দেওয়া।

🧠 উদাহরণ বিশ্লেষণ:
উদাহরণ ১:
cpp
Copy
Edit
Input: nums = [1, 2, 2, 4]
Set হওয়ার কথা ছিল: [1, 2, 3, 4]
→ ২ বার এসেছে: 2
→ হারিয়েছে: 3
Output: [2, 3]
উদাহরণ ২:
cpp
Copy
Edit
Input: nums = [1, 1]
Set হওয়ার কথা ছিল: [1, 2]
→ ২ বার এসেছে: 1
→ হারিয়েছে: 2
Output: [1, 2]
✅ সমাধানের ধারণা (Approach Explanation in Bangla):
তোমার কোডের প্রতিটি অংশ বিশ্লেষণ করি:

Step 1: Frequency Count
cpp
Copy
Edit
unordered_map<int,int> freq;
for (int j = 0; j < nums.size(); j++) 
{
    freq[nums[j]]++;
}
👉 প্রতিটি সংখ্যার কয়বার এসেছে তা গণনা করা হচ্ছে।

Step 2: খুঁজে বের করো কোন সংখ্যা ২ বার এসেছে
cpp
Copy
Edit
for (auto it : freq) 
{
    if (it.second == 2)
    {  
      here,it.second=freq
        result.push_back(it.first); // প্রথম ইনডেক্সে রাখা হলো ডুপ্লিকেট নাম্বার.
        break;  it.first=number
    }
}
Step 3: গণনা করো মোট যোগফল
cpp
Copy
Edit
int arraysum = 0;
for (int m = 0; m < nums.size(); m++) 
{
    arraysum += nums[m];
}
Step 4: হিসাব করো ১ থেকে n পর্যন্ত আসল যোগফল
cpp
Copy
Edit
int actualsum = 0;
for (int i = 1; i <= n; i++) 
{
    actualsum += i;
}
Step 5: হারানো নাম্বার খুঁজে বের করো
cpp
Copy
Edit
int resultsum = result[0]; // ডুপ্লিকেট নাম্বার
int ans = actualsum - arraysum + resultsum;
result.push_back(ans); // দ্বিতীয় ইনডেক্সে রাখা হলো missing নাম্বার
⚙️ Mathematical Logic:
ধরো:

ডুপ্লিকেট = x

মিসিং = y

nums এর যোগফল: sum = actualsum - y + x

👉 তাহলে missing: y = actualsum - arraysum + x

✅ উদাহরণ দিয়ে পরীক্ষা (Manual Test):
Input: [1, 2, 2, 4]
actualsum = 1+2+3+4 = 10

arraysum = 1+2+2+4 = 9

duplicate = 2

missing = 10 - 9 + 2 = 3

➡️ Output: [2, 3] ✅

Input: [1, 1]
actualsum = 1 + 2 = 3

arraysum = 1 + 1 = 2

duplicate = 1

missing = 3 - 2 + 1 = 2

➡️ Output: [1, 2] ✅

📘 ভবিষ্যতে বুঝতে হলে (Bangla Summary for Future):
ধাপ	ব্যাখ্যা
1️⃣	প্রতিটি সংখ্যার frequency count করো
2️⃣	যেটা ২ বার এসেছে, সেটা হলো duplicate
3️⃣	অ্যারেতে থাকা সব সংখ্যার যোগফল বের করো
4️⃣	1 থেকে n পর্যন্ত প্রকৃত যোগফল বের করো
5️⃣	Missing number বের করতে: missing = actualsum - arraysum + duplicate
6️⃣	Return করো [duplicate, missing]

🔚 উপসংহার:
এই সমাধানটি সমস্যা অনুযায়ী যথাযথভাবে কাজ করে কারণ:

এটি frequency count ব্যবহার করে ডুপ্লিকেট খুঁজে পায় ✅

গণিতের মাধ্যমে missing নাম্বার নির্ভুলভাবে হিসাব করে ✅

সময় জটিলতা: O(n) এবং জায়গা জটিলতা: O(n)

চাইলে আমি তোমাকে একটি clean optimized version দিতেও পারি — চাইলে জানাও!

Full Code:
-----------
class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int>reserve;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
          reserve.push_back(i);
        }
        vector<int>result;
        unordered_map<int,int>freq;
        for(int j=0;j<nums.size();j++)
        {
          freq[nums[j]]++;
        }
        for(auto it:freq)
        {
          if(it.second==2)
          {
            result.push_back(it.first);
            break;
          }
        }
        int actualsum=0;
       
       
        int ans;
        int arraysum=0;
        for(int m=0;m<nums.size();m++)
        {
          arraysum+=nums[m];
        }
           for(int i=1;i<=n;i++)
        {
          actualsum+=i;
        }
        int resultsum=0;
        for(int k=0;k<result.size();k++)
        {
          resultsum+=result[k];
        }
          ans=actualsum-arraysum+resultsum;
         result.push_back(ans);
         return result;
    }
};





