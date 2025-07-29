🔶 প্রশ্ন বিশ্লেষণ:

Fibonacci Sequence:

এটি একটি সংখ্যা ক্রম যেখানে,


F(0) = 0,\quad F(1) = 1

F(n) = F(n-1) + F(n-2), \text{ যেখানে } n > 1

মানে, প্রতিটি সংখ্যা তার আগের দুটি সংখ্যার যোগফল।



---

🔶 উদাহরণ:

Example 1:

Input: n = 2
F(2) = F(1) + F(0) = 1 + 0 = 1
Output: 1

Example 2:

Input: n = 4
F(4) = F(3) + F(2) = 2 + 1 = 3
Output: 3


---

🔶 সমাধানের ধারণা কীভাবে তৈরি করবো?

প্রশ্ন পড়ে বোঝা যাচ্ছে এটা Fibonacci সিরিজ। আমরা যদি প্রত্যেকটি মান আগের দুটি মান থেকে হিসেব করি, তাহলে সহজে Dynamic Programming বা bottom-up approach ব্যবহার করতে পারি।

চিন্তার ধাপগুলো:

1. Base Case নির্ধারণ করি:

F(0) = 0
F(1) = 1


2. এরপর প্রতিবার F(i) হিসেব করি আগের দুটি মান যোগ করে:

F(i) = F(i - 1) + F(i - 2)


3. এজন্য আমরা একটা vector<int> v(n+1) নেই যাতে প্রতিটি মান স্টোর করতে পারি।




---

🔶 কোড ব্যাখ্যা (Line by Line):

class Solution
{
public:
    int fib(int n) 
    {

🔹 fib নামের ফাংশন যা int n ইনপুট হিসেবে নেয় এবং F(n) রিটার্ন করে।

if(n==0||n==1) return n;

🔹 Base Case: যদি n 0 বা 1 হয়, সরাসরি n রিটার্ন করি কারণ:

F(0) = 0

F(1) = 1


vector<int>v(n+1);

🔹 আমরা v নামের একটি ভেক্টর নেই যেটা n+1 সাইজের, যাতে 0 থেকে n পর্যন্ত মান রাখি।

v[0]=0;
        v[1]=1;

🔹 শুরুতে F(0) ও F(1) সেট করি, কারণ এগুলো ফিবোনাচ্চির ভিত্তি।

if(n>1)
        {
            for(int i=2;i<=n;i++)
            {
                v[i]=v[i-1]+v[i-2];
            }
        }

🔹 যদি n > 1 হয়, তাহলে 2 থেকে n পর্যন্ত লুপ চালাই। প্রতিবার:

v[i] = v[i-1] + v[i-2]

int ans=v[v.size()-1];
        return ans;
    }
};

🔹 ভেক্টরের শেষ মানটাই F(n) — সেটা ans এ নিয়ে রিটার্ন করি।


---

🔶 Time & Space Complexity:

⏱️ Time Complexity: O(n) – কারণ n বার লুপ চলছে।

🧠 Space Complexity: O(n) – কারণ ভেক্টর v তে n+1 ঘর লাগছে।



---

✅ টেস্ট কেস ধরে পরীক্ষা:

Test Case 1:

Input: n = 3

F(0) = 0

F(1) = 1

F(2) = F(1) + F(0) = 1 + 0 = 1

F(3) = F(2) + F(1) = 1 + 1 = 2 ✅ Output: 2



---

Full Code:
-----------

class Solution
{
public:
    int fib(int n) 
    {
        if(n==0||n==1) return n;
        vector<int>v(n+1);
v[0]=0;
v[1]=1;
        if(n>1)
        {
            for(int i=2;i<=n;i++)
                {
                    v[i]=v[i-1]+v[i-2];
                }
        }
    int ans=v[v.size()-1];
        return ans;
    }
};  
