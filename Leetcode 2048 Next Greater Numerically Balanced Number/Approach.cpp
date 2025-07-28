✅ Problem Summary (বাংলায়):


---

আমরা একটি সংখ্যা n পেয়েছি।

আমাদের কাজ:

n-এর চেয়ে বড় এমন সবচেয়ে ছোট সংখ্যা খুঁজে বের করা, যেটা numerically balanced।


🔍 Numerically Balanced Number কাকে বলে?

যে সংখ্যায়:

প্রতিটি ডিজিট d তার মান অনুসারে ঠিক d বার এসেছে।


👉 যেমন:

22: ২ দুই বার এসেছে → balanced ✅

3133: ৩ তিন বার, ১ একবার এসেছে → balanced ✅

1022: 0 এসেছে একবার → কিন্তু 0 কোনো সংখ্যা একবারও থাকতে পারবে না → unbalanced ❌



---

🧠 How to Think (Approach):


---

প্রথমে প্রশ্ন পড়ে ভাবতে হবে:

1. Constraints ছোট → n <= 10^6, সুতরাং brute force করলেও চলে।


2. আমরা n+1 থেকে শুরু করে এক এক করে চেক করবো, যতক্ষণ না একটা balanced number পাই।


3. যেহেতু সর্বোচ্চ balanced সংখ্যা 1224444 পর্যন্ত গিয়েও তৈরি করা যায় (max 7-digit), আমরা ঐ পর্যন্ত সীমা রাখবো।


4. প্রতিটি সংখ্যার ডিজিট গুলো বের করে গণনা করবো – যদি digit সংখ্যাটি digit বার থাকে → ঠিক আছে, না হলে বাদ।




---

🔧 Function Overview:


---

HasZero(int n):

যদি কোনো ডিজিট 0 থাকে, false return করবে।

কারণ 0 এর 0 বার আসা লাগবে। কিন্তু কোনো সংখ্যায় যদি 0 থাকে, সে কখনই balanced হতে পারে না।


Balanced(int n):

প্রথমে চেক করবে, যদি 0 থাকে → false

তারপর প্রতিটি ডিজিট count করবে

প্রতিটি ডিজিট যদি তার count-এর সমান হয় → true


nextBeautifulNumber(int n):

n+1 থেকে শুরু করে প্রতি সংখ্যা Balanced() দিয়ে চেক করবে

যে প্রথম সংখ্যা balanced হবে, সেটাই return করবে।



---

📘 Full Code Line-by-Line Explanation:


---

class Solution 
{
public:

➡️ Solution ক্লাস তৈরি করলাম।


---

bool HasZero(int n)
{
    bool haszero = false;
    while(n > 0)
    {
        int digit = n % 10;
        if(digit == 0)
        {
            haszero = true;
            break;
        }
        n = n / 10;
    }
    return haszero;
}

🔍 এই ফাংশন দেখে:

প্রতিটি সংখ্যার শেষ ডিজিট বের করে

যদি সেটা 0 হয় → haszero = true

কারণ 0 ডিজিট কোনো balanced number-এ থাকতে পারবে না।

যেমন: 120 → unbalanced ❌



---

bool Balanced(int n)
{
    if(HasZero(n)) return false;

➡️ যদি n-এ 0 থাকে → সরাসরি false


---

vector<int> v;
    while(n > 0)
    {
        int rem = n % 10;
        if(rem == 0) return false;
        v.push_back(rem);
        n = n / 10;
    }

➡️ সংখ্যাটিকে ভেঙে তার প্রতিটি ডিজিট v ভেক্টরে রাখছে


---

unordered_map<int, int> freq;
    for(int i = 0; i < v.size(); i++)
    {
        freq[v[i]]++;
    }

➡️ প্রতিটি ডিজিট কয়বার এসেছে তা গণনা করছি।


---

for(auto it : freq)
    {
        if(it.first != it.second)
        {
            return false;
        }
    }
    return true;
}

➡️ প্রতিটি ডিজিট যদি তার মান অনুসারে আসে → true, না হলে false


---

int nextBeautifulNumber(int n)
{
    int ans;
    for(int j = n+1; j <= 1224444; j++)
    {
        if(Balanced(j))
        {
            ans = j;
            break;
        }
    }
    return ans;
}

➡️ এক এক করে সংখ্যা চেক করে Balanced() দিয়ে। ➡️ যে প্রথম balanced number পাওয়া যায়, সেটাই ans হিসেবে return করবে।


---

🧪 Test Case by Case Analysis:


---

✅ Test 1:

Input: n = 1
Output: 22

n+1 = 2 → not balanced

3 → not balanced

11 → 1 এসেছে দুইবার ❌

22 → 2 এসেছে দুইবার ✅ → return 22



---

✅ Test 2:

Input: n = 1000
Output: 1333

একে একে ট্রাই করলে 1333 আসবে → 1 এসেছে একবার, 3 এসেছে তিনবার ✅



---

✅ Test 3:

Input: n = 3000
Output: 3133

3 এসেছে তিনবার, 1 একবার ✅



---

🧮 Mathematical Justification:


---

প্রতি সংখ্যার ডিজিট d → count(d) = d হওয়া লাগবে

0 কখনো আসতে পারবে না

উপরের শর্ত মেটা এমন সব থেকে ছোট সংখ্যা খুঁজবো



---
Full Code:
------------

class Solution 
{
public:
    bool HasZero(int n)
    {
        bool haszero=false;
        while(n>0)
            {
                int digit=n%10;
                if(digit==0)
                {
                    haszero=true;
                    break;
                }
                n=n/10;
            }
        return haszero;
    }
    bool Balanced(int n)
    {
        if(HasZero(n)) return false;
        vector<int>v;
        while(n>0)
            {
                int rem=n%10;
                if(rem==0) return false;
                v.push_back(rem);
                n=n/10;
            }
        bool balanced=true;
        unordered_map<int,int>freq;
        for(int i=0;i<v.size();i++)
            {
                freq[v[i]]++;
            }
        for(auto it:freq)
            {
                if(it.first!=it.second)

                {
                    balanced=false;
                    break;
                }
            }

return balanced;   
    }
    int nextBeautifulNumber(int n)
    {
        int ans;
        for(int j=n+1;j<=1224444;j++)
            {
                
                if(Balanced(j))
                {
                    ans=j;
                    break;
                }
            }
        return ans;
    }
};  
