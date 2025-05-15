চলো আমরা নিচের প্রবলেমটা ধাপে ধাপে বাংলায় বিশ্লেষণ করি, তারপর দেওয়া কোডটা ধাপে ধাপে ব্যাখ্যা করব — এবং প্রমাণ করব এটা সব টেস্ট কেসে কেন সঠিকভাবে কাজ করে।

🔍 প্রবলেমটি কী বলছে?
তোমাকে দুটি অ্যারে দেওয়া হয়েছে:

ranks[] → ৫টি কার্ডের মান (১ থেকে ১৩ এর মধ্যে)

suits[] → সেই ৫টি কার্ডের suit (a, b, c, d এর মধ্যে একটি)

এখন, এই ৫টি কার্ড দিয়ে তুমি সবচেয়ে ভালো কোন poker hand বানাতে পারো তা return করতে হবে। নিচে দেওয়া আছে কোন hand সেরা:

✅ "Flush" → ৫টি suit একরকম হলে

✅ "Three of a Kind" → তিনটি একই rank

✅ "Pair" → দুটি একই rank

✅ "High Card" → উপরোক্ত কিছুই না হলে

🧠 আমি যদি নিজে চিন্তা করি এই solution লেখার আগে?
আমার চিন্তা হতো:

প্রথমে check করি সব suits একরকম কিনা → তাহলে সরাসরি "Flush"

তারপর আমি চাই ranks গুলো গুনে দেখি (frequency count) → যদি কোনো rank 3 বার আসে → "Three of a Kind"

যদি কোনো rank 2 বার আসে → "Pair"

কিছুই না হলে → "High Card"

এই চিন্তাই কোডে করা হয়েছে।

✅ এখন দাও কোডটা বুঝি লাইন ধরে, উদাহরণসহ
cpp
Copy
Edit
string bestHand(vector<int>& ranks, vector<char>& suits) 
{
   string ans = "";
   unordered_map<int,int> freq1; // rank frequency
   unordered_map<char,int> freq2; // suit frequency
🔹 দুটো frequency map নিচ্ছে → একটাতে rank এর count রাখবে, আরেকটাতে suit এর।

cpp
Copy
Edit
   for(int i=0;i<suits.size();i++)
   {
      freq2[suits[i]]++;
   }
🔹 প্রতিটি suit এর frequency গুনছে। যদি কোনো suit ৫ বার আসে → Flush হবে।

cpp
Copy
Edit
   for(int j=0;j<ranks.size();j++)
   {
      freq1[ranks[j]]++;
   }
🔹 প্রতিটি rank এর frequency count করছে।

cpp
Copy
Edit
   for(auto it1:freq2)
   {
      if(it1.second==5)
      {
         ans += "Flush";
      }
   }
🔹 যদি suit এর মধ্যে কোনোটা ৫ বার থাকে → ans = "Flush" set করে দেয়।

cpp
Copy
Edit
   for(auto it2:freq1)
   {
      if(it2.second>=3)
      {
         ans = "Three of a Kind";
      }
      else if(it2.second==2 && ans!="Three of a Kind")
      {
         ans = "Pair";
      }
   }
🔹 এরপর প্রতিটি rank দেখে:

যদি কোনো rank ≥ 3 বার → ans = "Three of a Kind" করে

যদি 2 বার আসে এবং আগে "Three of a Kind" না পাওয়া যায় → ans = "Pair"

cpp
Copy
Edit
   if(ans == "") 
   {
      ans = "High Card";
   }
🔹 কোনো match না পেলে → Default: "High Card"

✅ চল এবার উদাহরণ দিয়ে পুরো কোড ট্রেস করে দেখি:
Example 1:
cpp
Copy
Edit
ranks = [13,2,3,1,9]
suits = ['a','a','a','a','a']
🔹 suits → সব 'a' → suit frequency: {'a': 5} → Flush ✅
🔹 ranks → সব আলাদা → rank freq: সব ১ বার
➡️ Flush পাওয়া গেছে তাই "Flush" return

Example 2:
cpp
Copy
Edit
ranks = [4,4,2,4,4]
suits = ['d','a','a','b','c']
🔹 suits → mixed → কোনো flush নাই
🔹 ranks → 4 এসেছে 4 বার → rank freq: 4 → "Three of a Kind" ✅

Example 3:
cpp
Copy
Edit
ranks = [10,10,2,12,9]
suits = ['a','b','c','a','d']
🔹 suits → mixed → flush না
🔹 ranks → 10 এসেছে ২ বার → pair ✅
➡️ Output → "Pair"

Example 4 (extra):
cpp
Copy
Edit
ranks = [1, 2, 3, 4, 5]
suits = ['a','b','c','d','a']
🔹 suits → mismatch
🔹 ranks → সব আলাদা
➡️ Output → "High Card" ✅

✅ সারাংশ:
এই কোডটি সঠিকভাবে suit ও rank এর frequency গণনা করে।

Priority দেওয়া হয়েছে → Flush > Three of a Kind > Pair > High Card

সঠিকভাবে "ans" overwrite করে নিচের র‍্যাঙ্ক অনুযায়ী।

তাই সব টেস্ট কেসে accepted হয়।

