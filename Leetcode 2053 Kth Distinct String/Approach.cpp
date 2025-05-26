🧠 প্রশ্নটা কী চাচ্ছে?
প্রশ্ন:

তোমাকে একটা string array দেওয়া হবে (যেমন: ["a", "b", "a", "c", "b", "d"])

তোমাকে বের করতে হবে k-th distinct string, মানে এমন একটা string যা array-তে মাত্র ১ বার এসেছে।

এবং অবশ্যই array যেভাবে দেওয়া আছে, সেই অনুযায়ী প্রথম, দ্বিতীয়, ... k-th বলতে হবে। (insertion order important)

যদি total distinct string এর সংখ্যা k-এর চেয়ে কম হয়, তাহলে "" (empty string) রিটার্ন করতে হবে।

✅ তোমার কোডে যেই ধাপে ধাপে সমাধান করেছো — সেটা একেবারে সঠিক।
এখন নিচে তোমার কোডের প্রতিটি লাইন এবং test case চালিয়ে ব্যাখ্যা করছি বাংলায়, যাতে বুঝতে সহজ হয়।

🔍 তোমার কোড বিশ্লেষণ (Bangla তে ব্যাখ্যা) 👇
cpp
Copy
Edit
class Solution 
{
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map<string,int>freq;
🟢 ধাপ ১: প্রথমে একটা unordered_map বানিয়েছো, যেখানে আমরা প্রতিটা string-এর frequency গুনে রাখবো।
freq[str]++ করলে map-এ ওই string কয়বার আছে তা জমা হবে।

cpp
Copy
Edit
        string ans="";
🟢 ans ভেরিয়েবল তৈরি করছো, যেখানে পরে k-th distinct string রাখবে।

cpp
Copy
Edit
        for(int i=0;i<arr.size();i++)
        {
          freq[arr[i]]++;
        }
🟢 ধাপ ২: পুরো arr-এর উপর লুপ চালিয়ে প্রতিটা string এর frequency হিসাব করছো।
যেমন:
Input: ["d", "b", "c", "b", "c", "a"]
Output map: { "d":1, "b":2, "c":2, "a":1 }

cpp
Copy
Edit
        vector<string>reserve;
        for(int i=0;i<arr.size();i++)
        {
          if(freq[arr[i]]==1)
          {
            reserve.push_back(arr[i]);
          }
        }
🟢 ধাপ ৩: এখন আবার arr এর উপর লুপ চালাও।
এইবার চেক করো যে যেই string এর frequency 1 — সেটা distinct
✅ তুমি insertion order ঠিক রাখতে এখানে arr দিয়ে লুপ চালিয়ে খুব বুদ্ধিমানের কাজ করেছো।
unordered_map দিয়ে করলে order হারিয়ে যেতো।

reserve এর মধ্যে শুধু মাত্র distinct গুলা জমা করছো।

যেমন:
Input: ["d", "b", "c", "b", "c", "a"]
Output: reserve = ["d", "a"]

cpp
Copy
Edit
        for(int j=0;j<reserve.size();j++)
        {
          if(j==k-1&&k <= reserve.size())
          {
              ans=reserve[j];
          }
        }
🟢 ধাপ ৪: এখন reserve array থেকে k-th element বের করো।
Index k-1 হয় কারণ array 0-based indexing.

যদি k > reserve.size(), তাহলে ans খালি থাকবে — এটাও ঠিক।

cpp
Copy
Edit
        return ans;
    }
};
🟢 ধাপ ৫: এখন ans রিটার্ন করো — যা k-th distinct string।

✅ এখন আমরা কিছু Test Case দিয়ে তোমার কোড কিভাবে কাজ করছে তা দেখবো।
🔷 Test Case 1:
cpp
Copy
Edit
arr = ["d","b","c","b","c","a"], k = 2
Step-by-step:

Frequency map:

cpp
Copy
Edit
{ "d":1, "b":2, "c":2, "a":1 }
Distinct in order = ["d", "a"]

k = 2 → index = 1 → reserve[1] = "a"
✅ Output: "a"

🔷 Test Case 2:
cpp
Copy
Edit
arr = ["aaa","aa","a"], k = 1
freq = { "aaa":1, "aa":1, "a":1 }

reserve = ["aaa", "aa", "a"]

k = 1 → reserve[0] = "aaa"
✅ Output: "aaa"

🔷 Test Case 3:
cpp
Copy
Edit
arr = ["a", "b", "a"], k = 3
freq = { "a":2, "b":1 }

reserve = ["b"]

k = 3 > reserve.size() → return ""
✅ Output: ""

📌 তোমার সমাধান যেভাবে চিন্তা করেছো তা সুন্দরভাবে বোঝানো হলো:
✅ তোমার চিন্তার ধাপগুলো:
"Frequency map" দিয়ে প্রতিটা string কয়বার এসেছে সেটা জানার দরকার — তুমি ঠিক map ইউজ করেছো।

যেসব string 1 বার এসেছে, তাদের reserve নামক vector-এ রেখেছো — এবং insertion order মেনটেইন করেছো।

পরে k-th index এর string রিটার্ন করেছো — আর যদি নাই থাকে, তাহলে empty string — এটাও প্রশ্ন অনুযায়ী।

✅ তোমার কোড accepted হবে কারণ:
Time Complexity: O(n) (দুইটা লুপ চালায়, একবার frequency count, একবার result collect)

Space Complexity: O(n) (map + reserve)

Full Code:
----------
  class Solution 
{
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map<string,int>freq;
        string ans="";
        for(int i=0;i<arr.size();i++)
        {
          freq[arr[i]]++;
        }
        vector<string>reserve;
        for(int i=0;i<arr.size();i++)
        {
         // if(it.second==1)
          if(freq[arr[i]]==1)
          {
            reserve.push_back(arr[i]);
          }
        }
        for(int j=0;j<reserve.size();j++)
        {
          if(j==k-1&&k <= reserve.size())
          {
              ans=reserve[j];
              
          }
        }
        return ans;
    }
};
