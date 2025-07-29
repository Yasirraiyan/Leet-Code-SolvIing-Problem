🔢 Tribonacci Sequence কী?

Tribonacci sequence Fibonacci-এর মতই, তবে এখানে পূর্বের 3টি সংখ্যার যোগফল পরবর্তী সংখ্যা নির্ধারণ করে।

নির্ধারণ:

T(0) = 0
T(1) = 1
T(2) = 1
T(n) = T(n-1) + T(n-2) + T(n-3)  // for n ≥ 3


---

🎯 উদাহরণ:

ধরো n = 4, তাহলে:

T(0) = 0
T(1) = 1
T(2) = 1
T(3) = T(2) + T(1) + T(0) = 1 + 1 + 0 = 2
T(4) = T(3) + T(2) + T(1) = 2 + 1 + 1 = 4

✅ Output হবে 4.


---

🧠 কীভাবে চিন্তা করবে সমাধানটা?

প্রশ্নে recursive সম্পর্ক দেয়া আছে:
T(n) = T(n-1) + T(n-2) + T(n-3)

তুমি এটা দেখেই বুঝতে পারবে যে এটি Dynamic Programming (DP) এর মত, কারণ:

Overlapping subproblems আছে (bar bar T(n-1), T(n-2), etc. দরকার হচ্ছে)

তাই তুমি memoization বা bottom-up DP (tabulation) দিয়ে সমাধান করতে পারো


তুমি যেটা করছো সেটা Bottom-Up DP।


---

✅ কোড বিশ্লেষণ (Line by Line):

class Solution 
{
public:
    int tribonacci(int n)

🔹 আমরা n-th Tribonacci সংখ্যা বের করব।

vector<int>v(n+3);

🔹 আমরা একটা vector নিচ্ছি যাতে আমরা T(0) থেকে T(n) পর্যন্ত সব value রাখতে পারি।
n+3 নিচ্ছি কারণ v[0], v[1], v[2] পর্যন্ত initialize করা লাগবে, আর n এর জন্য নিশ্চিতভাবে জায়গা থাকবে।

v[0]=0;
        v[1]=1;
        v[2]=1;

🔹 Initial condition set করলাম।

for(int i=3;i<=n;i++)
        {
            v[i]=v[i-1]+v[i-2]+v[i-3];
        }

🔹 এখন Bottom-Up হিসাব করবো।
🔁 i = 3 থেকে n পর্যন্ত loop চালাবো।

🔸 প্রত্যেক ধাপে v[i] = v[i-1] + v[i-2] + v[i-3]

উদাহরণ:
i = 4 → v[4] = v[3] + v[2] + v[1]

int ans=v[n];

🔹 আমরা চাই n-th Tribonacci মান। তাই সেটা নিয়ে নিলাম।

return ans;
    }
};

🔚 অবশেষে সেটা return করলাম।


---

🧪 Test Case Analyses:

✅ Test Case 1: n = 4

v[0]=0
v[1]=1
v[2]=1
v[3]=1+1+0 = 2
v[4]=2+1+1 = 4
Return: v[4] = 4 ✅

✅ Test Case 2: n = 25

Loop 3 থেকে 25 পর্যন্ত যাবে, এবং প্রত্যেকটার মান হিসাব করবে।

ফলাফল: 1389537 হবে — যেটা ঠিক ✅


---

✅ Time & Space Complexity:

🕒 Time Complexity: O(n) — কারণ loop একবারই চলবে n বার।

💾 Space Complexity: O(n) — কারণ আমরা n+3 size এর vector নিচ্ছি।


(তবে চাইলে v[i-1], v[i-2], v[i-3] ৩টা ভ্যারিয়েবলেই হিসাব করে Space O(1) করা যেত)


---

📘 Summary:

বিষয়	ব্যাখ্যা

ধরণ	Dynamic Programming (Bottom-Up)
সূত্র	T(n) = T(n-1) + T(n-2) + T(n-3)
কোড ধারণা	vector দিয়ে আগের মান রেখে পরের মান হিসাব
Input Constraint	0 <= n <= 37, তাই Iterative method যথেষ্ট
Complexity	Time: O(n), Space: O(n)

Full Code:
-------------

class Solution 
{
public:
    int tribonacci(int n)
    {
        vector<int>v(n+3);
        v[0]=0;
        v[1]=1;
        v[2]=1;
        for(int i=3;i<=n;i++)
            {
                v[i]=v[i-1]+v[i-2]+v[i-3];
            }
        int ans=v[n];
        return ans;
    }
};
