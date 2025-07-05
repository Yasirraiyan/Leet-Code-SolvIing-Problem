🔶 প্রবলেম বুঝি:
প্রবলেম:
একটা স্ট্রিং s দেওয়া আছে যেখানে ছোট হাতের ইংরেজি অক্ষর এবং ডিজিট (0-9) মিশানো থাকতে পারে।
তোমাকে সেই ডিজিট গুলোর মধ্যে দ্বিতীয় সর্বোচ্চ সংখ্যাটি বের করতে হবে।
যদি শুধু একটা বা একটাও ডিজিট না থাকে, তাহলে -1 রিটার্ন করবে।

✅ উদাহরণ ১:
Input: "dfa12321afd"
Digits Found: 1, 2, 3
Sorted Unique Digits: 1, 2, 3
➡️ 2 is the second highest

📘 তোমার কোড ব্যাখ্যা
cpp
Copy
Edit
class Solution 
{
public:
🔸 Solution নামক ক্লাস ডিফাইন করেছো — যেটা লীকোডের কাঠামো অনুযায়ী ঠিক আছে।

🔷 Step 1: Find Max Number
cpp
Copy
Edit
int findmax(vector<int>&arr)
{
  int max=arr[0];
  for(int k=1;k<arr.size();k++)
  {
    if(arr[k]>max)
    {
      max=arr[k];
    }
  }
  return max;
}
🔸 একটি হেল্পার ফাংশন যা একটা vector<int> এর মধ্যে সর্বোচ্চ সংখ্যা বের করে।

🔷 Step 2: Find Min Number
cpp
Copy
Edit
int findmin(vector<int>&arr)
{
  int min=arr[0];
  for(int k=1;k<arr.size();k++)
  {
    if(arr[k]<min)
    {
      min=arr[k];
    }
  }
  return min;
}
🔸 ঠিক আগের মতোই, এটা সর্বনিম্ন সংখ্যা বের করে।

🔷 Step 3: Extract Digits from String
cpp
Copy
Edit
int secondHighest(string s) 
{
  vector<int>v;
  for(int i=0;i<s.size();i++)
  {
    if(isdigit(s[i]))
    {
      v.push_back(s[i]-'0');
    }
  }
🔸 এখানে তুমি স্ট্রিং থেকে প্রতিটা ক্যারেক্টার চেক করছো:

যদি সেটা ডিজিট হয় (isdigit(s[i]))

তাহলে char থেকে int করতে s[i]-'0' করে ভেক্টরে v তে রাখছো।

Example:
'2' - '0' → 2
'3' - '0' → 3

🔷 Step 4: Frequency Count (For Uniqueness)
cpp
Copy
Edit
unordered_map<int,int>freq;
for(int j=0;j<v.size();j++)
{
  freq[v[j]]++;
}
🔸 তুমি এখানে প্রতিটি সংখ্যা কতবার আছে তা কাউন্ট করছো।
🔸 এটা করার উদ্দেশ্য: শুধু ইউনিক ডিজিট রাখতে চাইলে frequency map দিয়ে পরে key গুলো আলাদা করে নিতে পারো।

🔷 Step 5: Only Unique Digits রাখো
cpp
Copy
Edit
vector<int>vv;
for(auto it:freq)
{
  vv.push_back(it.first);
}
🔸 এখন vv তে রাখছো শুধু ইউনিক সংখ্যাগুলো (freq map এর key)।

🔷 Step 6: Size Check (যদি একটার কম হয়)
cpp
Copy
Edit
if(vv.size()<2)return -1;
🔸 যদি ইউনিক ডিজিট ২টার কম হয়, তাহলে দ্বিতীয় সর্বোচ্চ নেই → return -1;

🔷 Step 7: Sort + Final Result
cpp
Copy
Edit
int ans;
sort(vv.begin(), vv.end()); // Ascending sort
if(vv.size()>=2)
{
  if(vv.size()==3)
  {
    for(int i=0;i<vv.size();i++)
    {
      if(vv[i]!=findmax(vv)&&vv[i]!=findmin(vv))
      {
          ans=vv[i];
          break;
      }
    }
  }
}
ans=vv[vv.size()-2]; // second last -> 2nd highest
return ans;
🔸 তুমি sort করে নিছে রেখেছো:

সবসময় vv[vv.size()-2] হবে দ্বিতীয় সর্বোচ্চ সংখ্যা

এমনকি যদি তিনটা ইউনিক সংখ্যা থাকে, তুমি চেক করে মধ্যেরটা নিচ্ছো (যেটা একটু বাড়তি precaution, কিন্তু sort করায় এটা দরকার হয় না)

✅ সারসংক্ষেপ (How You Thought & Solved)
🔹 তুমি নিচের ধাপে চিন্তা করেছো:

ডিজিট গুলো আলাদা করো স্ট্রিং থেকে

একই ডিজিট বাদ দিয়ে ইউনিক ডিজিট বের করো

দ্বিতীয় সর্বোচ্চ সংখ্যা নির্ণয় করো

কেস হ্যান্ডেল করো যেখানে ডিজিটই নাই বা একটা মাত্র

✅ এই লজিকে ভুল নাই, কোড কাজ করে।

Input: s = "dfa12321afd"
Digits: [1, 2, 3]
Sorted: [1, 2, 3]
2nd Highest = 2 ✅

Input: s = "abc1111"
Digits: [1]
Unique: [1]
return -1 ✅


Full Code:
-----------

class Solution 
{
public:
 int findmax(vector<int>&arr)
 {
  int max=arr[0];
  for(int k=1;k<arr.size();k++)
  {
    if(arr[k]>max)
    {
      max=arr[k];
    }
  }
  return max;
 }
 int findmin(vector<int>&arr)
 {
  int min=arr[0];
  for(int k=1;k<arr.size();k++)
  {
    if(arr[k]<min)
    {
      min=arr[k];
    }
  }
  return min;
 }
    int secondHighest(string s) 
    {
      vector<int>v;
      for(int i=0;i<s.size();i++)
      {
        if(isdigit(s[i]))
        {
          v.push_back(s[i]-'0');
        }
      }
      unordered_map<int,int>freq;
      for(int j=0;j<v.size();j++)
      {
        freq[v[j]]++;
      }
      vector<int>vv;
      for(auto it:freq)
      {
        vv.push_back(it.first);
      }
      if(vv.size()<2)return -1;
      int ans;
        sort(vv.begin(), vv.end());
      if(vv.size()>=2)
      {
          if(vv.size()==3)
          {
            for(int i=0;i<vv.size();i++)
            {
              if(vv[i]!=findmax(vv)&&vv[i]!=findmin(vv))
              {
                  ans=vv[i];
                  break;
              }
            }
          }
      }
      ans=vv[vv.size()-2];
      return ans;
    }
};
