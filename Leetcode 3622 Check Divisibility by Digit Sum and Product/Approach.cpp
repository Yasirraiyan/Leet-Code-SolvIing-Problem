🔶 প্রশ্নটি কী বলছে?
তোমাকে একটি সংখ্যা n দেওয়া হবে।
তুমি দেখতে চাও n কি এর digit sum আর digit product এর যোগফল দিয়ে বিভাজ্য কিনা।

উদাহরণ:
n = 99

digit sum = 9 + 9 = 18

digit product = 9 × 9 = 81

sum + product = 18 + 81 = 99

এখন দেখি 99 % (18+81) = 0 → ✅ divisible → return true

🔷 সমাধানের ভাবনা কীভাবে করা যায়?
প্রশ্নটা যখন পড়লে তখন তুমি দেখতে পাচ্ছো:

Digit Sum: প্রতিটি অংকের যোগফল।

Digit Product: প্রতিটি অংকের গুণফল।

তারপর, এই দুইটার যোগফল দিয়ে n কে ভাগ করতে হবে।

🧠 এই অনুযায়ী চিন্তাভাবনার ধাপ:
n-এর প্রতিটি digit বের করো → %10 এবং /10 ব্যবহার করে।

প্রতিটি digit যোগ করো → sum এ রাখো।

একইসাথে প্রতিটি digit গুণ করো → product এ রাখো।

শেষে sum + product বের করে চেক করো n % (sum + product) == 0 কিনা।

✅ কোড ব্যাখ্যা (Line by Line Bangla)
cpp
Copy
Edit
class Solution 
{
public:
    bool checkDivisibility(int n) 
    {
        int sum = 0;             // digit sum রাখতে
        long long p = 1;         // digit product রাখতে (large value হতে পারে তাই long long)
        int original = n;        // n এর copy রেখে দিচ্ছি, কারণ loop এ n পরিবর্তন হবে
cpp
Copy
Edit
        while(n > 0)             // যতক্ষণ পর্যন্ত n শেষ না হয় (0 না হয়)
        {
            int rem = n % 10;   // শেষ digit বের করলাম
            sum += rem;         // sum এ যোগ করলাম
            p *= rem;           // product এ গুণ করলাম
            n = n / 10;         // n থেকে শেষ digit বাদ দিলাম
        }
cpp
Copy
Edit
        long long result = p + sum;  // digit sum + digit product
cpp
Copy
Edit
        bool check = false;     // default ভ্যালু false
        if(original % result == 0) // যদি divisible হয়
        {
            check = true;
        }
        return check;           // true অথবা false return করবো
    }
};
✅ এখন কয়েকটি Test Case দিয়ে চলো দেখি:
🔸 Test Case 1:
cpp
Copy
Edit
n = 99
rem = 9, sum = 9, product = 9

rem = 9, sum = 18, product = 81

result = 18 + 81 = 99

99 % 99 = 0 → ✅ true

🔸 Test Case 2:
cpp
Copy
Edit
n = 23
rem = 3, sum = 3, product = 3

rem = 2, sum = 5, product = 6

result = 5 + 6 = 11

23 % 11 = 1 → ❌ false

🔸 Test Case 3:
cpp
Copy
Edit
n = 101
rem = 1, sum = 1, product = 1

rem = 0, sum = 1, product = 0 (⚠️ important: 0 গুণ করলে সবই 0 হয়ে যাবে)

rem = 1, sum = 2, product = 0

result = 2 + 0 = 2

101 % 2 = 1 → ❌ false

💡 কেন কোড Accepted হচ্ছে?
✅ Efficient: প্রতিটি digit নিয়ে loop → O(log n) time

✅ Edge case handle করেছে (0 product হলেও handle করে)

✅ Constraint এর মধ্যে long long use করা ভালো সিদ্ধান্ত

🔚 সংক্ষেপে:
Step	Description
1	প্রতিটি digit বের করে sum ও product হিসাব
2	এরপর sum + product বের করো
3	n % (sum + product) == 0 হলে true

Full Code:
-----------

  class Solution 
{
public:
    bool checkDivisibility(int n) 
    {
        int sum=0;
        long long p=1;
        int original=n;
        while(n>0)
        {
          int rem=n%10;
          sum+=rem;
          p*=rem;
          n=n/10;
        }
        long long result=p+sum;
        bool check=false;
        if(original%result==0)
        {
          check=true;
        }
return check;
    }
};
