সমাধানের ধারণা
শর্ত দুটোই চেক করতে হবে:

'A' (Absent) মোট করা হবে < 2 (মানে 0 বা 1 হতে পারে)

কোনো সময় ৩ টা ক্রমাগত 'L' (Late) থাকা যাবে না ("LLL" substring গুলো উপস্থিত নেই)

আসলে সহজ ভেবে: স্ট্রিংটি একবার পড়লেই বা দুটো আলাদা চেক করলে আমরা সিদ্ধান্ত নিতে পারি — time complexity O(n), space O(1)।

তোমার দেয়া কোড — সারাংশ ও সমস্যা
তোমার CheckLate ফাংশনটি "LLL" খুঁজে বের করার চেষ্টা করছে — কিন্তু তাতে একটি index-out-of-range সমস্যা থাকতে পারে কারণ for-loop এ শর্ত ভুলভাবে লিখেছে (i থেকে i+2 অ্যাক্সেস করা হচ্ছে কিন্তু লুপ শেষ ঠিক ধরে রাখা হয় না)। আর checkRecord ফাংশন ঠিকই 'A' গোনে এবং !CheckLate(s) দেখে। লজিক ঠিক, কিন্তু CheckLate-এ লুপের ম্যাক্স সীমা ঠিক করা দরকার।

লাইনে লাইনে সংক্ষিপ্ত ব্যাখ্যা (তোমার কোডকে একটু ঠিক করে)
cpp
Copy
Edit
class Solution 
{
public:
  // CheckLate: স্ট্রিং-এ LLL আছে কি না চেক করবে
  bool CheckLate(const string &s)
  {
    // (সঠিক করা অংশ): শুধু এমন i-তে যাচাই কর যেখানে i+2 বৈধ।
    for (int i = 0; i + 2 < (int)s.size(); i++)
    {
      if (s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L')
      {
        return true; // LLL পাওয়া গেছে
      }
    }
    return false; // LLL নেই
  }

  bool checkRecord(string s) 
  {
    int a = 0;
    // সব চর ধরে 'A' গোনা
    for (int i = 0; i < (int)s.size(); i++)
    {
      if (s[i] == 'A') a++;
    }
    // দুটো শর্ত: a < 2 এবং LLL নেই
    return (a < 2 && !CheckLate(s));
  }
};
লাইন-বাই-লাইন (সংক্ষেপে Bangla):

CheckLate — স্ট্রিং এ তিনটি পরপর 'L' আছে কি না চেক করে; যদি পায় true রিটার্ন করে (অর্থাৎ শর্ত ভাঙে)।

checkRecord — অ্যাবসেন্স (a) কাউন্ট করে; শেষে a<2 এবং CheckLate না থাকলে true রিটার্ন করে।

কেন এই সমাধান accepted হয়
আমরা সার্বিকভাবে স্ট্রিং একবার/দুইবার পড়ি → O(n) সময়।

অতিরিক্ত মেমরি লাগেনা → O(1) স্পেস।
উদাহরণ টেস্ট—কেন কাজ করে
"PPALLP": absences = 1 (<2), কোন "LLL" নেই → true

"PPALLL": absences = 1 কিন্তু শেষের দিকে "LLL" আছে → false

  Full Code:
--------------

  class Solution 
{
public:
bool CheckLate(string s)
{
  bool check=false;
  if(s.size()>=3)
  {
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L')
      {
        check=true;
        break;
      }
    }
  }
  return check;
}
    bool checkRecord(string s) 
    {
        bool check=false;
        int l=0;
        int a=0;
        for(int i=0;i<s.size();i++)
        {
          if(s[i]=='A')
          {
            a++;
          }
          
        }
        if(a<2&&!CheckLate(s))
        {
          check=true;
        }
        return check;
    }
};
শর্তগুলো সরাসরি প্রশ্নে যা বলা আছে সেটার অনুবাদ — তাই সব টেস্ট কভার হয় (except the index bug which আমরা ঠিক করেছি)।
