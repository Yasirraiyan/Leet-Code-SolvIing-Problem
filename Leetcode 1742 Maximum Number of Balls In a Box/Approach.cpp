Approach:
----------
  🔍 সমস্যা বিশ্লেষণ (Problem Analysis)
তোমার কাজ:

lowLimit থেকে highLimit পর্যন্ত প্রতিটি বলের জন্য:

সেই বলের ডিজিটগুলোর যোগফল বের করো (e.g., 321 → 3+2+1 = 6),

যোগফল = বক্স নম্বর → ওই বক্সে বলটি রাখো,

সবগুলো বল রাখার পর, দেখো কোন বক্সে সবচেয়ে বেশি বল আছে → সেই সংখ্যাটা return করো।

✅ তোমার সমাধানের স্টেপ বাই স্টেপ বিশ্লেষণ
cpp
Copy
Edit
int digitsum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
🔹 digitsum() ফাংশন:
এই ফাংশন প্রতিটি সংখ্যার ডিজিটগুলোর যোগফল বের করে।
যেমন 123 → 1+2+3 = 6

cpp
Copy
Edit
int countBalls(int lowLimit, int highLimit)
{
    int n=highLimit-lowLimit+1;
    unordered_map<int,int>freq;
    for(int i=lowLimit;i<=highLimit;i++)
    {
        freq[digitsum(i)]++;
    }
🔹 unordered_map freq:

Key = box number (i.e., digit sum)

Value = সেই বক্সে কতটি বল গেছে

তুমি lowLimit থেকে highLimit পর্যন্ত প্রতিটি সংখ্যার ডিজিট যোগফল বের করেছো এবং সেই box-এ count বাড়িয়েছো।

cpp
Copy
Edit
    vector<int>reserve;
    for(auto it:freq)
    {
        reserve.push_back(it.second);
    }
🔹 এখানে তুমি freq map থেকে সব value (ball count per box) একটি reserve vector-এ তুলেছো।
যার উদ্দেশ্য: max খুঁজে বের করা।

cpp
Copy
Edit
    int max=reserve[0];
    for(int j=1;j<reserve.size();j++)
    {
        if(reserve[j]>max)
        {
            max=reserve[j];
        }
    }
    return max;
}
🔹 সব value-এর মধ্যে সর্বোচ্চটা বের করে max হিসেবে return করেছো।

📌 তুমি যেভাবে চিন্তা করেছিলে (তোমার চিন্তাধারা বিশ্লেষণ)
তুমি বুঝেছিলে – প্রতিটি সংখ্যা একটি unique box-এ যাবে, যেটার নম্বর হবে তার digit sum।

তুমি বুঝেছিলে – আমাদের জানতে হবে, কোন box-এ কতগুলো বল জমেছে।

তুমি unordered_map ব্যবহার করেছো – কারণ এর মাধ্যমে তুমি efficiently প্রতিটি box-এর বল count রাখতে পারো (O(1) time per insert)।

তারপর তুমি সব values বের করে maximum count খুঁজে বের করেছো।

এগুলো সব একদম perfect logical flow।

🔥 কেন তোমার কোড Accepted হয়েছে?
✔️ তুমি constraints মেনেই O(N) time-complexity-তে efficiently সমাধান করেছো।
✔️ তুমি কোনো library বা অন্য solution দেখে করোনি — logic-টা নিজের থেকেই তৈরি করেছো।
✔️ তুমি corner cases-ও handle করেছো যেমন lowLimit == highLimit।

🧠 ভবিষ্যতের জন্য মনে রাখার মতো:
digit sum → কোনো সংখ্যাকে “কোন box-এ যাবে” সেটা ঠিক করে

unordered_map → fast frequency count এর জন্য best

value গুলোর মধ্যে max বের করাই মূল লক্ষ্য

How Accepted Test by test case:
----------------------------------
  চল একেবারে লাইন বাই লাইন তোমার কোডটা ব্যাখ্যা করি এবং প্রতিটি অংশ কিভাবে কাজ করছে তা তিনটা টেস্ট কেসে কেমনভাবে চলছে সেটা উদাহরণসহ বুঝি — Bangla তে।

✅ তোমার কোড:
cpp
Copy
Edit
class Solution 
{
public:
  int digitsum(int n)
  {
    int sum=0;
    while(n>0)
    {
      sum+=n%10;
      n=n/10;
    }
    return sum;
  }

  int countBalls(int lowLimit, int highLimit)
  {
    int n = highLimit - lowLimit + 1;
    unordered_map<int, int> freq;

    for(int i = lowLimit; i <= highLimit; i++)
    {
      freq[digitsum(i)]++;
    }

    vector<int> reserve;
    for(auto it: freq)
    {
      reserve.push_back(it.second);
    }

    int max = reserve[0];
    for(int j = 1; j < reserve.size(); j++)
    {
      if(reserve[j] > max)
      {
        max = reserve[j];
      }
    }

    return max;
  }
};
🔍 লাইন বাই লাইন বিশ্লেষণ Bangla-তে:
✅ int digitsum(int n)
এই ফাংশন কোনো সংখ্যা n এর digit গুলোর যোগফল বের করে।

যেমন: 123 → 1+2+3 = 6

cpp
Copy
Edit
while(n > 0)
{
  sum += n % 10;  // শেষ digit যোগ করো
  n = n / 10;     // শেষ digit বাদ দাও
}
✅ int countBalls(int lowLimit, int highLimit)
n = মোট কয়টি বল আছে → highLimit - lowLimit + 1

✅ Unordered Map: freq[digitsum(i)]++
প্রতিটি বলের নম্বর i এর digitsum(i) বের করে সে box নম্বরে count বাড়ানো হচ্ছে।

উদাহরণ (Test Case 1):

i = 1 → digitsum(1) = 1 → box 1 → freq[1] = 1

i = 10 → digitsum(10) = 1 → freq[1] = 2

✅ Vector-এ মান রাখা
cpp
Copy
Edit
for(auto it : freq)
{
  reserve.push_back(it.second); // প্রতিটি বক্সে কয়টা বল আছে সেটা vector এ রাখি
}
Test Case 1-এর জন্য:

freq = {1:2, 2:1, 3:1, ..., 9:1}

reserve = [2,1,1,1,...]

✅ Max বের করা:
cpp
Copy
Edit
int max = reserve[0];
for(int j = 1; j < reserve.size(); j++)
{
  if(reserve[j] > max)
    max = reserve[j];
}
এই অংশে সর্বোচ্চ কয়টা বল কোন বক্সে আছে সেটা বের করা হয়।

🧪 Test Case 1: lowLimit=1, highLimit=10
Process:
cpp
Copy
Edit
for(i = 1; i <= 10; i++)
  freq[digitsum(i)]++;
i = 1 → sum = 1 → freq[1] = 1

i = 10 → sum = 1 → freq[1] = 2

freq:

vbnet
Copy
Edit
1 → 2 balls
2 to 9 → 1 ball each
max = 2 → ✅ Output: 2

🧪 Test Case 2: lowLimit=5, highLimit=15
Process:
cpp
Copy
Edit
for(i = 5; i <= 15; i++)
i = 5 → sum = 5

i = 14 → sum = 5 → freq[5] = 2

i = 6,15 → sum = 6 → freq[6] = 2

freq:

Copy
Edit
5 → 2 balls
6 → 2 balls
others → 1
max = 2 → ✅ Output: 2

🧪 Test Case 3: lowLimit=19, highLimit=28
Process:
i = 19 → sum = 10 → freq[10] = 1

i = 28 → sum = 10 → freq[10] = 2

freq:

Copy
Edit
10 → 2 balls
others → 1
max = 2 → ✅ Output: 2

✅ Summary (Bangla):
তুমি প্রথমে প্রতিটি সংখ্যার digit sum বের করছো।

সেটা কোন box number সেটা ধরে count বাড়াচ্ছো।

শেষে সব box এর মধ্যে কোনটার count বেশি সেটা বের করছো।

  Full Code:
---------------
  class Solution 
{
public:
  int digitsum(int n)
  {
    int sum=0;
    while(n>0)
    {
      sum+=n%10;
      n=n/10;
    }
    return sum;
  }
    int countBalls(int lowLimit, int highLimit)
     {
        int n=highLimit-lowLimit+1;
        unordered_map<int,int>freq;
        for(int i=lowLimit;i<=highLimit;i++)
        {
       
            freq[digitsum(i)]++;
         
        }
        vector<int>reserve;
        for(auto it:freq)
        {
            reserve.push_back(it.second);
        }
        int max=reserve[0];
        for(int j=1;j<reserve.size();j++)
        {
          if(reserve[j]>max)
          {
            max=reserve[j];
          }
        }
        return max;

    }
};
