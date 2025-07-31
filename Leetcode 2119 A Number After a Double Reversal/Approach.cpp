অবশ্যই! তোমার দেওয়া reverseNumber ফাংশনের কোডটা আমি লাইন বাই লাইন ব্যাখ্যা করছি, একটা উদাহরণ দিয়ে।


---

কোড:

int reverseNumber(int n) {
    int rev = 0;
    while (n > 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }
    return rev;
}


---

উদাহরণ:

n = 2021 ইনপুট ধরি।


---

লাইন বাই লাইন বিশ্লেষণ:

1. int rev = 0;

নতুন একটা ভেরিয়েবল rev ডিক্লেয়ার করা হলো, যেখানে উল্টানো সংখ্যা সংরক্ষণ হবে। শুরুতে 0।



2. while (n > 0)

যতক্ষণ n ০ এর বড় থাকবে, লুপ চলবে। মানে যতদিন সংখ্যায় ডিজিট আছে ততদিন।





---

প্রথম iteration (n=2021):

3. int digit = n % 10;

2021 % 10 = 1 → শেষ ডিজিট বের করলাম।

digit = 1



4. rev = rev * 10 + digit;

rev = 0 * 10 + 1 = 1

প্রথম ডিজিট যোগ হলো।



5. n = n / 10;

2021 / 10 = 202 (integer division)

এখন n = 202





---

দ্বিতীয় iteration (n=202):

3. digit = 202 % 10 = 2


4. rev = 1 * 10 + 2 = 12


5. n = 202 / 10 = 20




---

তৃতীয় iteration (n=20):

3. digit = 20 % 10 = 0


4. rev = 12 * 10 + 0 = 120


5. n = 20 / 10 = 2




---

চতুর্থ iteration (n=2):

3. digit = 2 % 10 = 2


4. rev = 120 * 10 + 2 = 1202


5. n = 2 / 10 = 0




---

এখন লুপ শেষ, কারণ n == 0।

6. return rev;

ফাংশন রিটার্ন করবে 1202।





---

সারসংক্ষেপ:

প্রথমে শেষ ডিজিট ধরে, সেটা নতুন সংখ্যায় যোগ করলাম।

পুরনো সংখ্যাকে ১০ ভাগ দিয়ে শেষ digit ফেলে দিলাম।

এই কাজ করেছি যতক্ষণ n ০ না হয়।

শেষে পাওয়া সংখ্যা হলো উল্টানো সংখ্যা।



---

তোমার উদাহরণ:

Input: 2021
Output: 1202

ঠিক যেমন প্রত্যাশা করেছিলাম।
Full Code:
----_---------
class Solution 
{
public:
    int findreverse(int n)
    {
        int ans=0;
        while(n>0)
            {
                int d=n%10;
                ans=d+ans*10;
                n/=10;
            }
        return ans;
    }
    bool isSameAfterReversals(int num) 
    {
        bool same=false;
        int a=findreverse(num);
        int b=findreverse(a);
        if(b==num)
        {
            same=true;
        }
        return same;
    }
};
  
