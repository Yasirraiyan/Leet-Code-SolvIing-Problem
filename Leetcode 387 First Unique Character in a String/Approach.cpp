তুমি জানতে চাচ্ছো — কীভাবে প্রথম non-repeating ক্যারেক্টার খুঁজে বের করা হয়, এবং এটা নিজে কোডে লেখার আগে কিভাবে পরিকল্পনা করতে পারো। এখানে আমি ধাপে ধাপে ব্যাখ্যা করবো যে কীভাবে তুমি এই সমাধানটি লিখতে পারো এবং এর পেছনে কী যুক্তি থাকতে পারে।

1. Problem Analysis (সমস্যার বিশ্লেষণ):
তোমার কাছে একটি string দেওয়া হয়েছে।

তোমাকে string-এর প্রথম non-repeating (unique) character খুঁজে বের করতে হবে এবং তার index রিটার্ন করতে হবে।

যদি এমন কোন character না থাকে যা একবারই এসেছে, তবে -1 রিটার্ন করতে হবে।

2. Step-by-step Approach:
Step 1: Frequency Count
প্রথম কাজ হচ্ছে, string-এর প্রতিটি character কতবার এসেছে তা গুনতে হবে।

এই কাজের জন্য আমি একটি unordered_map ব্যবহার করবো যেখানে key হবে character এবং value হবে তার frequency (কতবার এসেছে)।

cpp
Copy
Edit
unordered_map<char, int> freq;
Step 2: Count Frequencies of All Characters
String-এর উপর একবার loop চালিয়ে প্রতিটি character-এর frequency গুনে নেওয়া হবে।

cpp
Copy
Edit
for (int i = 0; i < s.size(); i++) {
    freq[s[i]]++; // frequency count
}
এখানে freq[s[i]]++ দিয়ে প্রতিটি character-এর frequency বৃদ্ধি করছি।

Step 3: Find First Unique Character
এরপর আবার string-এর উপর loop চালিয়ে প্রথম character খুঁজে বের করতে হবে যার frequency 1 (মানে সেটি non-repeating character)।

cpp
Copy
Edit
for (int j = 0; j < s.size(); j++) {
    if (freq[s[j]] == 1) {
        return j; // First unique character found
    }
}
যদি string-এর মধ্যে এমন একটি character পাওয়া যায় যার frequency 1, তখন তার index রিটার্ন করবে।

Step 4: No Unique Character Found
যদি string-এর কোনো character এর frequency 1 না থাকে, তাহলে আমরা -1 রিটার্ন করবো, যেহেতু কোন unique character নেই।

cpp
Copy
Edit
return -1; // No unique character found
3. Full Code Explanation:
এখন পুরো কোডটা একত্রে দেখে নেওয়া যাক:

cpp
Copy
Edit
class Solution {
public:
   int firstUniqChar(string s)
   {
     unordered_map<char,int>freq;  // Step 1: Frequency map to store character counts
     
     int ans = -1;  // Step 2: Variable to store the result, initially -1
     
     // Step 3: Counting frequencies of all characters in the string
     for (int i = 0; i < s.size(); i++) {
        freq[s[i]]++;  // Increase frequency count for each character
     }
    
    // Step 4: Searching for the first non-repeating character
    for (int j = 0; j < s.size(); j++) {
        if (freq[s[j]] == 1) {  // If frequency is 1, it is a unique character
           ans = j;  // Store the index of the first unique character
           break;  // No need to check further, we found the answer
        }
    }
    return ans;  // Return the index of the first unique character (or -1 if not found)
   }
};
4. Detailed Explanation of Code (line-by-line in Bangla):
unordered_map<char, int> freq;

এখানে একটি unordered_map তৈরি করা হচ্ছে যা character গুলির frequency সংরক্ষণ করবে।

char হলো key (character) এবং int হলো value (frequency of the character)।

int ans = -1;

ans ভেরিয়েবলটি ইনিশিয়ালাইজ করা হচ্ছে -1 দিয়ে। এটি পরবর্তী সময়ে প্রথম non-repeating character-এর index রাখবে।

for (int i = 0; i < s.size(); i++) { freq[s[i]]++; }

এই লুপটি string s-এর প্রতিটি character এর জন্য frequency count করবে।

যেমন freq[s[i]]++ দিয়ে প্রতিটি character-এর frequency বাড়িয়ে দেওয়া হচ্ছে।

for (int j = 0; j < s.size(); j++) { if (freq[s[j]] == 1) { ans = j; break; } }

এবার, দ্বিতীয় লুপটি string s-এর প্রতিটি character কে চেক করবে।

যদি কোন character এর frequency 1 হয়, তবে সেটা প্রথম non-repeating character এবং তার index ans এ স্টোর হবে। এরপর break দিয়ে লুপ বন্ধ করা হবে।

return ans;

শেষে ans রিটার্ন করা হবে। যদি কোন unique character না পাওয়া যায়, তবে ans থাকবে -1, যা রিটার্ন হবে।

5. Example Walkthrough:
Example 1:
Input: s = "leetcode"

প্রথম লুপের শেষে freq হবে:

cpp
Copy
Edit
freq = {'l': 1, 'e': 3, 't': 1, 'c': 1, 'o': 1, 'd': 1}
দ্বিতীয় লুপে প্রথম non-repeating character পাওয়া যাবে l (index 0), তাই output হবে 0।

Example 2:
Input: s = "loveleetcode"

প্রথম লুপের শেষে freq হবে:

cpp
Copy
Edit
freq = {'l': 2, 'o': 2, 'v': 1, 'e': 4, 't': 1, 'c': 1, 'd': 1}
দ্বিতীয় লুপে v (index 2) প্রথম unique character, তাই output হবে 2।

Example 3:
Input: s = "aabb"

প্রথম লুপের শেষে freq হবে:

cpp
Copy
Edit
freq = {'a': 2, 'b': 2}
দ্বিতীয় লুপে কোন unique character পাওয়া যাবে না, তাই output হবে -1।

6. Conclusion:
এই কোডটি খুবই সাধারণ এবং two-pass approach ব্যবহার করে।

প্রথম pass-এ frequency count করা হচ্ছে,

দ্বিতীয় pass-এ প্রথম unique character খুঁজে বের করা হচ্ছে।
এটি O(n) টাইম কমপ্লেক্সিটি এবং O(n) স্পেস কমপ্লেক্সিটিতে সমাধান প্রদান করে।



Test Code how it is accepted:
-----------------------------
  তুমি যেটা জানতে চাচ্ছো — সেটা হলো এই কোডটি কেন ঠিকভাবে কাজ করে এবং প্রতিটি লাইন কী কাজ করছে, সেটা যেন তুমি ভবিষ্যতে ভালোভাবে বুঝতে পারো।

তাই আমি নিচে তোমার কোডটি লাইন বাই লাইন ব্যাখ্যা করলাম — বাংলায় উদাহরণসহ, যাতে তুমি সহজে বুঝতে পারো এবং ভবিষ্যতে নিজেই এর মতো সমস্যার সমাধান করতে পারো।

✅ কোড:
cpp
Copy
Edit
class Solution 
{
public:
   int firstUniqChar(string s)
   {
     unordered_map<char,int>freq;
  
     int ans=-1;
     for(int i=0;i<s.size();i++)
     {
        freq[s[i]]++;
     }
    
     for(int j=0;j<s.size();j++)
     {
        if(freq[s[j]]==1)
        {
           ans=j;
           break;
        }
     }
     return ans;
   }
};
✅ ধাপে ধাপে ব্যাখ্যা:
🔹 Step 1:
cpp
Copy
Edit
unordered_map<char,int> freq;
ব্যাখ্যা:
এখানে আমরা একটি unordered_map ব্যবহার করেছি যেখানে:

Key: char → স্ট্রিংয়ের প্রতিটি ক্যারেক্টার

Value: int → সেই ক্যারেক্টার কয়বার এসেছে (frequency)

➡️ এই map ব্যবহার করে আমরা প্রতিটি ক্যারেক্টারের frequency গুনবো।

🔹 Step 2:
cpp
Copy
Edit
int ans = -1;
ব্যাখ্যা:
এটি আমরা ধরে নিচ্ছি যে যদি কোনো non-repeating character না পাওয়া যায়, তাহলে -1 রিটার্ন করবো।

🔹 Step 3:
cpp
Copy
Edit
for(int i=0;i<s.size();i++)
{
    freq[s[i]]++;
}
ব্যাখ্যা:
এখানে আমরা s স্ট্রিংয়ের প্রতিটি ক্যারেক্টারকে একবার করে ঘুরে দেখছি।

⏩ উদাহরণ:

cpp
Copy
Edit
Input: s = "leetcode"
freq map হবে:
{
  'l' => 1,
  'e' => 3,
  't' => 1,
  'c' => 1,
  'o' => 1,
  'd' => 1
}
সুতরাং আমরা এখন জানি কে কতবার এসেছে।

🔹 Step 4:
cpp
Copy
Edit
for(int j=0;j<s.size();j++)
{
    if(freq[s[j]]==1)
    {
        ans = j;
        break;
    }
}
ব্যাখ্যা:

এবার আবার string s-এর উপর loop চালাই, এবং দেখি:

যেই ক্যারেক্টারের frequency 1 → অর্থাৎ non-repeating

সেই ক্যারেক্টারটার index আমরা ans-এ রেখে break করি

⏩ উদাহরণ:

cpp
Copy
Edit
s = "leetcode"

j = 0 → s[0] = 'l' → freq['l'] == 1 → তাই ans = 0 → break

Output: 0 ✅
⏩ Example 2:

cpp
Copy
Edit
s = "loveleetcode"

j=0 → 'l' = 1  
j=1 → 'o' = 2  
j=2 → 'v' = 1 → freq['v']==1 → ✅

Output: 2
⏩ Example 3:

cpp
Copy
Edit
s = "aabb"

freq:
'a' = 2  
'b' = 2  
→ কখনই freq[s[j]]==1 হবে না

→ ans = -1 → return -1
🔹 Step 5:
cpp
Copy
Edit
return ans;
ব্যাখ্যা:
শেষে আমরা ans রিটার্ন করি, যেটা হবে:

যদি non-repeating ক্যারেক্টার পাওয়া যায় → তার index

না পাওয়া গেলে → -1

✅ কেন এই সমাধান Accepted?
Time Complexity: O(n) → প্রথম লুপে স্ট্রিং ট্রাভার্স, দ্বিতীয় লুপেও তাই

Space Complexity: O(1) → কারণ unordered_map<char, int> → সর্বোচ্চ 26 lowercase letter থাকবে

Efficient এবং Clean কোড

সব constraint মেনে চলে

🔚 উপসংহার (Recap):
unordered_map দিয়ে frequency গুনে নিই

দ্বিতীয় লুপে প্রথম ক্যারেক্টার দেখি যার frequency 1 → এটাই উত্তর

না পেলে -1






