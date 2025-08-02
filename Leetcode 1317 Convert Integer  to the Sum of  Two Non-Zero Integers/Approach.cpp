🔶 Problem Summary:

তোমাকে একটি positive integer n দেওয়া হবে। তোমাকে এমন দুটি positive integers a ও b বের করতে হবে যাতে:

a + b = n হয় এবং

a ও b দুটোই No-Zero integer, অর্থাৎ যেসব সংখ্যার ডিজিটে কোনো 0 নেই (যেমন 10, 20, 105 → invalid)।



---

🔷 উদাহরণ:

উদাহরণ ১:

Input: n = 2
Output: [1,1]
Explanation: 1 + 1 = 2, এবং দুটোতেই কোনো '0' নেই। valid ✅

উদাহরণ ২:

Input: n = 11
Output: [2, 9] ✅
অথবা [8, 3], [4, 7] এসবও valid


---

🧠 Approaching the Problem (বাংলায় চিন্তা করার ধাপ):

Step 1:

আমরা জানি a + b = n হবে, এবং a, b-তে 0 থাকা যাবে না।
তাহলে n এর জন্য সম্ভাব্য a নেও, b = n - a বের করো — তারপর চেক করো a ও b তে 0 আছে কি না।

যদি না থাকে, তাহলে এই pair valid ✅
তুমি যেকোনো একটাই return করতে পারো।


---

✅ Mathematical Approach:

তুমি এমন i নাও (১ থেকে n-1 পর্যন্ত),
তারপর a = i, b = n - i
তারপর চেক করো a ও b তে 0 আছে কি না।


---

🧩 Code Explanation (Line by Line in Bangla):

class Solution 
{
public:
    bool HasZero(int n)

➡️ HasZero ফাংশনটা চেক করবে কোনো সংখ্যার মধ্যে 0 আছে কিনা।


---

{
        bool has=false;
        while(n>0)
        {
            int rem=n%10;

➡️ সংখ্যাটির প্রতিটি ডিজিট নেব (mod 10 দিয়ে)।


---

if(rem==0)
            {
                has=true;
                break;
            }

➡️ যদি কোনো ডিজিট 0 হয়, তাহলে has true করে return করবো।


---

n=n/10;
        }
        return has;
    }

➡️ যতক্ষণ না সব ডিজিট চেক করা হচ্ছে, ততক্ষণ লুপ চলবে। শেষ পর্যন্ত true বা false return করবে।


---

এখন মূল কাজের ফাংশন:

vector<int> getNoZeroIntegers(int n)
    {
        vector<int>v;

➡️ ভেক্টরে [a, b] স্টোর করবো।


---

for(int i=1;i<n;i++)
        {
            int a=i;
            int b=n-i;

➡️ i ধরে a = i, b = n - i ধরলাম।


---

if(!HasZero(a)&&!HasZero(b)&&a<n&&b<n)
            {
                v.push_back(a);
                v.push_back(b);
                break;
            }

➡️ যদি a ও b তে 0 না থাকে (মানে No-Zero), তাহলে ওদের ভেক্টরে রাখো।
➡️ break; করে দাও কারণ একটাই উত্তরই যথেষ্ট।


---

}
        return v;
    }
};


---

🧪 Test Case Analysis:

Test Case 1:

Input: n = 2

Loop:

i = 1 → a = 1, b = 1
→ HasZero(1) = false
→ valid ✅ → return [1, 1]



---

Test Case 2:

Input: n = 11

Loop:

i = 1 → a=1, b=10 → b has zero ❌

i = 2 → a=2, b=9 → both ok ✅
→ return [2, 9]



---

🔍 Time Complexity:

O(n) worst case (যদি অনেক i try করতে হয়)

O(1) space (একটাই pair রাখছি)



---

📌 সংক্ষেপে Summary:

প্রতিটি সম্ভাব্য a নিয়ে দেখি b = n - a-তে কোনো 0 আছে কি না।

কোনো pair-এ 0 না থাকলেই return করি।



---

✅ তোমার নিজের মত চিন্তা করে সমাধান করার কৌশল:

1. প্রশ্নে বলা ছিল a + b = n, তাই চিন্তা করো a ধরলে b = n - a হয়ে যাবে।


2. Check করতে হবে "0 আছে কিনা", তাই একটা হেল্পার ফাংশন HasZero(n) লিখে ফেলো।


3. তারপর 1 to n-1 পর্যন্ত ঘুরিয়ে প্রতিটি a ও b নিয়ে যাচাই করে valid পেলেই return।



Full Code:
-------------

class Solution 
{
public:
    bool HasZero(int n)
    {
        bool has=false;
        while(n>0)
            {
                int rem=n%10;
                if(rem==0)
                {
                    has=true;
                    break;
                }
                n=n/10;
            }
        return has;
    }
    vector<int> getNoZeroIntegers(int n)
    {
         vector<int>v;
        for(int i=1;i<n;i++)
            {
        int a=i;
                int b=n-i;
                if(!HasZero(a)&&!HasZero(b)&&a<n&&b<n)
                {
                    v.push_back(a);
                    v.push_back(b);
                    break;
                }
            }
        return v;
    }
};
