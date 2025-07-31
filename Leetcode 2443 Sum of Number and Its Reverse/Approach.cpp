🔹 প্রশ্নের সংক্ষিপ্তসার
একটি non-negative integer num দেওয়া থাকবে। তোমাকে বের করতে হবে —
num কি এমন একটি non-negative integer x এবং তার reverse rev(x) এর যোগফল?
অর্থাৎ,

num = x + reverse(x)

এই রকম কোনো x আছে কি না সেটা বের করতে হবে।


---

✅ উদাহরণ:

1. Input: num = 443
➤ x = 172 হলে reverse(172) = 271,
➤ 172 + 271 = 443 ✅
⟹ উত্তর: true


2. Input: num = 63
➤ এমন কোনো x নেই যার reverse যোগ করলে 63 পাওয়া যায় ❌
⟹ উত্তর: false


3. Input: num = 181
➤ x = 140 হলে reverse(140) = 41,
➤ 140 + 41 = 181 ✅
⟹ উত্তর: true




---

🧠 কীভাবে চিন্তা করব এই প্রশ্নটা সমাধান করতে?

প্রথমেই মাথায় আসে:
আমরা যদি x + reverse(x) = num ধরণের কোনো x খুঁজি, তাহলে আমরা x এর মান 0 থেকে num পর্যন্ত চালিয়ে দেখতে পারি।

প্রতিটা x এর জন্য আমরা reverse(x) বের করবো, তারপর তাদের যোগফল যদি num এর সমান হয়, তাহলে উত্তর true.


---

🔍 Step-by-Step Code & ব্যাখ্যা (Bangla)

class Solution
{
public:
    int findreverse(int n)

🔸 এটা একটা helper function — যেটা একটা integer এর reverse বের করে।

{
        int rev=0;
        while(n>0)
        {
            int digit=n%10;        // শেষ digit বের করলাম
            rev=rev*10+digit;      // reverse বানানোর ফর্মুলা
            n=n/10;                // n থেকে শেষ digit বাদ দিলাম
        }
        return rev;
    }

➡ উদাহরণস্বরূপ: n = 172
rev = 0 → 2 → 27 → 271
শেষে rev = 271 return করবে।


---

bool sumOfNumberAndReverse(int num) 
    {
        if(num==0) return true;

🔸 যদি num = 0 হয়, তাহলে 0 + reverse(0) = 0
⟹ সরাসরি true


---

bool possible=false;
        for(int i=1;i<num;i++)

🔸 আমরা 1 থেকে শুরু করে num-1 পর্যন্ত x (মানে i) ধরে ধরে চেক করবো।


---

{
            if(i+findreverse(i)==num)

🔸 যদি i + reverse(i) == num হয়, তাহলে আমরা পেয়ে গেছি এমন একটা সংখ্যা।

{
                possible=true;
                break;
            }
        }
        return possible;

🔸 পেয়ে গেলে লুপ বন্ধ করি এবং true return করি। না পেলে false.


---

💡 কেন এটা Accepted হচ্ছে? (Complexity)

আমরা সর্বোচ্চ num বার লুপ চালাই।

প্রতিটা সংখ্যার reverse বের করতে সময় লাগে O(log(num))

সর্বোচ্চ সময় জটিলতা: O(num * log(num)) (যেহেতু reverse করতে digit গুনে কাজ করি)


⟹ এই জিনিসটা efficiently কাজ করে, তাই Accepted হয়।


---

🧪 Test Case ব্যাখ্যা (Line-by-line)

✅ Example: num = 443

🔹 আমরা লুপ চালাবো:
i = 1 to 442

🔹 যখন i = 172,
➡ reverse(172) = 271
➡ 172 + 271 = 443
➡ মিলে গেল ⟹ possible = true

🔹 আমরা লুপ থামিয়ে দেই।
⟹ উত্তর: true


---

❌ Example: num = 63

🔹 আমরা i = 1 to 62 চালাই
🔹 কোনো i + reverse(i) = 63 মেলে না।
⟹ return false


---
Full Code:
----------

  class Solution
{
public:
    int findreverse(int n)
    {
        int rev=0;
        while(n>0)
            {
                int digit=n%10;
                rev=rev*10+digit;
                n=n/10;
            }
        return rev;
    }
    bool sumOfNumberAndReverse(int num) 
    {
        if(num==0) return true;
        bool possible=false;
        for(int i=1;i<num;i++)
            {
                if(i+findreverse(i)==num)
                {
                    possible=true;
                    break;
                }
            }
        return possible;
    }
};
