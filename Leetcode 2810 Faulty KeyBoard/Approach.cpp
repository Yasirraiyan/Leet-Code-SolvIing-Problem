Amar 1 ta string ase .Jokhon ami string e i lettter pabo tokhon oi letter er index theke 0 porjonto reverse korbo r bakigula mane i er porer index er character same 
order e hbe and string return korbo
  So,
  Helper Function:
--------------------

  string reverse(string s)
  {
    string ans="";
    for(int i=s.size()-1;i>=0;i--)
    {
      ans+=s[i];
    }
    return ans;
  }
Explain:
---------
  Ami first e 1 ta function banai string reverse er jonno main function er baire.1 ta string nei ans="";
ব্যাখ্যা: কেন i = s.size() - 1 থেকে শুরু করে i >= 0 পর্যন্ত চলে?
🔷 ১. string s = "hello";
Index	Character
0	h
1	e
2	l
3	l
4	o
👉 এখানে s.size() = 5
👉 কিন্তু লাস্ট ক্যারেক্টার "o" এর ইনডেক্স = 4 = s.size() - 1

🔁 লুপ ব্যাখ্যা:
cpp
Copy
Edit
for(int i = s.size() - 1; i >= 0; i--)
👉 এই লুপটি কাজ করে পিছন দিক থেকে — অর্থাৎ:

প্রথমে i = 4 → s[4] = 'o'

তারপর i = 3 → s[3] = 'l'

...

শেষবার i = 0 → s[0] = 'h'

এভাবে লুপ চলতে চলতে পুরো স্ট্রিংটি উল্টে ans এ গিয়ে জমে যায়।

✅ কেন decreasing order?
কারণ আমরা স্ট্রিং-এর শেষ ক্যারেক্টার থেকে শুরু করে প্রথম ক্যারেক্টার পর্যন্ত যেতে চাই।

increasing হলে আমরা s[0], s[1], ... পেতাম (মানে forward direction),

কিন্তু reverse করতে হলে আমাদের দরকার: s[n-1], s[n-2], ..., s[0] (মানে backward direction)

🔚 সোজা কথায়:
এই লুপটি decreasing order এ চলে কারণ আমরা স্ট্রিংটিকে উল্টো দিক থেকে পড়তে চাই, যেন নতুন স্ট্রিংয়ে তা reverse আকারে জমে।
Main Function:
---------------
string finalString(string s) 
    {
        string final="";
        for(int j=0;j<s.size();j++)
        {
          //final+=s[j];
          if(s[j]=='i')
          {
            final=reverse(final);
          }
          else
          {
            final+=s[j];
          }
        }
        return final;
    }
};
Explain:
----------
  1. string finalString(string s)
এটি একটি ফাংশন ঘোষণা। ফাংশনটির নাম finalString এবং এটি একটি string টাইপের ইনপুট গ্রহণ করে। ইনপুট স্ট্রিং s হিসাবে চিহ্নিত করা হয়েছে। এই ফাংশনটি একটি string টাইপের আউটপুট প্রদান করবে।

2. string final="";
এখানে একটি খালি স্ট্রিং final তৈরি করা হচ্ছে। এটি ফাংশনের ভিতরে স্ট্রিংটি তৈরি করবে এবং এর মাধ্যমে স্ট্রিংটি ধীরে ধীরে পরিবর্তন হবে।

3. for(int j=0;j<s.size();j++)
এটি একটি লুপ যা s.size() পর্যন্ত চলবে। s.size() হচ্ছে স্ট্রিংটির দৈর্ঘ্য। অর্থাৎ, এই লুপটি s স্ট্রিংয়ের প্রতিটি অক্ষরের জন্য একে একে কাজ করবে।

4. if(s[j]=='i')
এই শর্তটি পরীক্ষা করছে যে, যদি স্ট্রিংয়ের বর্তমান অক্ষরটি 'i' হয়, তবে নির্দিষ্ট কিছু কাজ করবে। এখানে s[j] মানে হচ্ছে স্ট্রিং s এর j-তম (ইনডেক্সে) অক্ষর।

5. final=reverse(final);
যদি বর্তমান অক্ষরটি 'i' হয়, তবে final স্ট্রিংটি উল্টানো হবে। এটি একটি ফাংশন, তবে C++-এর reverse() ফাংশন এখানে ব্যবহৃত হয়েছে, যা একটি স্ট্রিং বা অ্যারে উল্টানোর জন্য ব্যবহৃত হয়। তবে, এখানে reverse(final) ব্যবহার করা সঠিক নয়, কারণ C++-এ reverse() ফাংশন স্ট্যান্ডার্ড লাইব্রেরি থেকে আসে এবং তা স্ট্রিংয়ে সরাসরি কাজ করতে পারে না। সঠিক কোড হবে reverse(final.begin(), final.end());।

6. else
এটি একটি বিকল্প শর্ত, অর্থাৎ যদি বর্তমান অক্ষরটি 'i' না হয়, তাহলে else ব্লকটি কার্যকর হবে।

7. final+=s[j];
যদি 'i' না হয়, তবে বর্তমান অক্ষরটি final স্ট্রিংয়ে যোগ করা হবে। += অপারেটরটি স্ট্রিংয়ের শেষে নতুন অক্ষরটি যোগ করে।

8. return final;
এই লাইনটি শেষের দিকে রয়েছে এবং ফাংশনটির আউটপুট হিসেবে final স্ট্রিংটি রিটার্ন করছে। ফাংশনটি সম্পূর্ণ হলে final স্ট্রিংটি রিটার্ন হবে, যেটি বর্তমান প্রক্রিয়ার পরে স্ট্রিংয়ের পরিবর্তিত সংস্করণ হবে।

সারাংশ:
এই ফাংশনটি একটি স্ট্রিং ইনপুট হিসেবে নেয় এবং স্ট্রিংয়ের প্রতিটি অক্ষর চেক করে যদি কোনো অক্ষর 'i' হয়, তাহলে এখন পর্যন্ত তৈরি হওয়া স্ট্রিংটি উল্টে দেওয়া হয়। অন্যথায়, সেই অক্ষরটি স্ট্রিংয়ের শেষে যোগ করা হয়। ফাংশনটির শেষে পুরো স্ট্রিংটি রিটার্ন করা হয়।

উল্লেখ্য: reverse(final) ব্যবহারটি ভুল, কারণ reverse() স্ট্যান্ডার্ড লাইব্রেরি ফাংশনটি কন্টেইনারের উপর কাজ করে, তাই এটি সঠিকভাবে কাজ করবে না।


Full Code:
----------

class Solution 
{
public:
  string reverse(string s)
  {
    string ans="";
    for(int i=s.size()-1;i>=0;i--)
    {
      ans+=s[i];
    }
    return ans;
  }
    string finalString(string s) 
    {
        string final="";
        for(int j=0;j<s.size();j++)
        {
          //final+=s[j];
          if(s[j]=='i')
          {
            final=reverse(final);
          }
          else
          {
            final+=s[j];
          }
        }
        return final;
    }
};





