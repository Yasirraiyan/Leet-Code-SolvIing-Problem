✅ প্রথমে প্রশ্ন বুঝে নেওয়া:
তোমাকে বলা হয়েছে:

একটা sentence দেওয়া আছে, যেখানে কিছু শব্দ আছে এবং প্রতিটি শব্দের মাঝে একটি করে space আছে।

একটি searchWord দেওয়া আছে।

তোমার কাজ হলো: sentence এর কোনো শব্দের শুরু কি searchWord দিয়ে হচ্ছে কিনা সেটা চেক করা।

যদি হয়, তাহলে সেই শব্দের 1-based index (মানে গণনা 1 থেকে শুরু হবে) রিটার্ন করো।

যদি একাধিক শব্দ থাকে যেগুলো শুরু হয় searchWord দিয়ে, তাহলে প্রথম যেটা পাওয়া যায়, সেটার index রিটার্ন করো।

আর যদি কোনো শব্দেই prefix মিলে না যায়, তাহলে -1 রিটার্ন করো।

✅ তোমার চিন্তা-ভাবনার ধাপ:
পুরো sentence কে টুকরো টুকরো করে শব্দে ভাগ করেছো।

প্রতিটি শব্দের সাথে searchWord টা prefix হিসেবে মিলে কিনা সেটা চেক করেছো।

যদি prefix মিলে যায়, তাহলে সেই index রিটার্ন করেছো।

যদি কোনোটাই না মেলে, তাহলে -1 রিটার্ন করেছো।

✅ তোমার কোড বিশ্লেষণ (লাইন বাই লাইন ব্যাখ্যা)
cpp
Copy
Edit
class Solution 
{
public:
এখানে তুমি একটি Solution নামের class ডিফাইন করেছো, যেটা LeetCode এর ফরম্যাট অনুযায়ী করা হয়েছে।

cpp
Copy
Edit
bool CheckPrefix(string a,string  b)
{
    bool isprefix=false;
    string ans="";
    for(int i=0;i<a.size();i++)
    {
        ans+=a[i];
        if(ans==b)
        {
            isprefix=true;
            break;
        }
    }
    return isprefix;
}
🔹 CheckPrefix ফাংশন:

এটা চেক করে b কি a-এর prefix কিনা।

একটি খালি string ans বানাও।

a string এর প্রতিটি ক্যারেক্টার একে একে ans এ যোগ করো।

যখন ans == b হয়, তখন isprefix = true করে break করো।

শেষে true/false রিটার্ন করো।

তুমি এখানে নিজে হাতে prefix মিলিয়ে দেখার জন্য স্টেপ-বাই-স্টেপ string বানিয়ে যাচ্ছো।

উদাহরণ: CheckPrefix("burger", "burg") ➝ ans হবে:

"b" → না

"bu" → না

"bur" → না

"burg" → হ্যাঁ, মিলেছে → return true

cpp
Copy
Edit
int isPrefixOfWord(string sentence, string searchWord) {
    int ans=-1;
🔹 প্রথমে ans = -1 ধরে নিও, কারণ যদি কিছুই না মেলে তাহলে -1 return করতে হবে।

cpp
Copy
Edit
    stringstream ss(sentence);
    string word;
    vector<string> reserve;
    while(ss >> word)
    {
        reserve.push_back(word);
    }
🔹 তুমি sentence কে stringstream দিয়ে টুকরো করে একেকটা word বানিয়ে নিচ্ছো।
🔹 reserve vector-এ সব শব্দগুলো স্টোর করছো।

উদাহরণ:
sentence = "i love eating burger" → reserve = ["i", "love", "eating", "burger"]

cpp
Copy
Edit
    for(int j=0;j<reserve.size();j++)
    {
        if(CheckPrefix(reserve[j],searchWord))
        {
            ans=j+1;
            break;
        }
    }
🔹 সব শব্দ ঘুরে চেক করছো searchWord সেটা reserve[j] এর prefix কিনা।
🔹 যদি prefix মিলে, তাহলে index (1-based তাই j+1) দিয়ে ans সেট করো এবং break করো।

cpp
Copy
Edit
    return ans;
}
🔹 সব চেক করার পর ans return করো। যদি কোনো prefix না মেলে, তাহলে -1 রিটার্ন হবে।

✅ Test Case Analysis (উদাহরণ)
Test Case 1:
cpp
Copy
Edit
sentence = "i love eating burger";
searchWord = "burg";
➝ reserve = ["i", "love", "eating", "burger"]

"i" → না

"love" → না

"eating" → না

"burger" → "burg" দিয়ে শুরু → মিলেছে

✅ Output = 4

Test Case 2:
cpp
Copy
Edit
sentence = "this problem is an easy problem";
searchWord = "pro";
reserve = ["this", "problem", "is", "an", "easy", "problem"]

"this" → না

"problem" → হ্যাঁ → 2
(6 নম্বরেও মিলবে, কিন্তু ২য়েই break হয়ে গেছে)

✅ Output = 2

Test Case 3:
cpp
Copy
Edit
sentence = "i am tired";
searchWord = "you";
reserve = ["i", "am", "tired"] → কেউই "you" দিয়ে শুরু হয় না

✅ Output = -1

✅ সংক্ষেপে:
তুমি নিজে prefix চেক করার জন্য ছোট ফাংশন লিখে নিয়েছো (যেটা STL starts_with() ফাংশনের বিকল্প)।

তোমার কোড Efficiently কাজ করে কারণ তুমি প্রথম যেটা পাও, সেটাই রিটার্ন করো।

তোমার কোড সব টেস্ট কেস পাস করবে।

Full Code:
-----------

  class Solution 
{
public:
   bool CheckPrefix(string a,string  b)
   {
    bool isprefix=false;
    string ans="";
    for(int i=0;i<a.size();i++)
    {
      ans+=a[i];
      if(ans==b)
      {
        isprefix=true;
        break;
      }
    }
    return isprefix;
   }
    int isPrefixOfWord(string sentence, string searchWord) 
{
        int ans=-1;
        stringstream ss(sentence);
        string word;
        vector<string>reserve;
        while(ss>>word)
        {
             reserve.push_back(word);
        }
        for(int j=0;j<reserve.size();j++)
        {
          if(CheckPrefix(reserve[j],searchWord))
          {
            ans=j+1;
            break;
          }
        }
        return ans;
    }
};
