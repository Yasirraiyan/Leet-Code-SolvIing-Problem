তুমি যে LeetCode প্রবলেমটা দিয়েছো, সেটি হচ্ছে:


---

🔢 1175. Prime Arrangements

> Statement (Bengali Translation):
তোমাকে সংখ্যা 1 থেকে n পর্যন্ত সব সংখ্যার একটি পারমুটেশন (বিন্যাস) বের করতে হবে, যেখানে প্রাইম সংখ্যা গুলো প্রাইম ইনডেক্সে থাকবে (ইনডেক্স 1-based)।
ফলাফলটি অনেক বড় হতে পারে, তাই 10^9 + 7 দিয়ে mod নিতে হবে।




---

🔍 উদাহরণ:

Input: n = 5
Output: 12
Explanation:
n = 5 → [1, 2, 3, 4, 5]
প্রাইম ইনডেক্স → 2, 3, 5
এই ইনডেক্সগুলোতে কেবল প্রাইম সংখ্যা রাখতে পারবে।
প্রাইম সংখ্যা → 2, 3, 5
এই তিনটি প্রাইম সংখ্যা তিনটি প্রাইম ইনডেক্সে যেকোনোভাবে বসতে পারে → 3! = 6 উপায়ে
বাকি সংখ্যাগুলো (1, 4) বাকি ইনডেক্সে বসবে → 2! = 2 উপায়ে
মোট পারমুটেশন = 6 × 2 = 12


---

✅ Step-by-Step Approach (Bangla বিশ্লেষণ)


---

💡 Step 1: বুঝতে হবে – কোন সংখ্যা গুলো প্রাইম?

প্রথমে 1 থেকে n পর্যন্ত কতগুলো প্রাইম সংখ্যা আছে তা বের করব।

bool TestPrime(int n)

এই ফাংশনটি একটি সংখ্যা n প্রাইম কিনা তা বলে।
অ্যালগরিদম:

2 এর নিচে সব সংখ্যা প্রাইম না।

তারপর 2 থেকে √n পর্যন্ত চেক করি n কি কোনো সংখ্যা দিয়ে ভাগ যায়?

যদি যায়, তাহলে প্রাইম না।

যদি না যায়, তাহলে প্রাইম।


⏱️ Time Complexity: O(√n)


---

💡 Step 2: কতগুলো প্রাইম আছে তা গুনে নেই

for(int i=1;i<=n;i++)
{
    if(TestPrime(i))
    {
        pc++; // প্রাইম কাউন্ট
    }
}

pc = প্রাইম সংখ্যা গুলোর সংখ্যা
npc = n - pc = নন-প্রাইম সংখ্যার সংখ্যা


---

💡 Step 3: কতোভাবে বসানো যায়?

আমরা জানি,

প্রাইম সংখ্যা গুলো প্রাইম ইনডেক্স গুলোতে বসবে

নন-প্রাইম সংখ্যা গুলো বাকি ইনডেক্সে বসবে


ধরি:

প্রাইম সংখ্যা গুলো pc! উপায়ে সাজানো যাবে

নন-প্রাইম সংখ্যা গুলো npc! উপায়ে সাজানো যাবে


int ans = (findfact(pc) * findfact(npc)) % MOD;


---

💡 Step 4: Factorial ফাংশন

long long findfact(int n)
{
    const int MOD=1e9+7;
    long long p=1;
    for(int i=n;i>=1;i--)
    {
        p=(p*i)%MOD;
    }
    return p;
}

এই ফাংশন n! % MOD রিটার্ন করে
(যাতে overflow না হয়)


---

✅ Code Summary:

class Solution 
{
public:
    bool TestPrime(int n)
    {
        if(n<2) return false;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }

    long long findfact(int n)
    {
        const int MOD=1e9+7;
        long long p=1;
        for(int i=n;i>=1;i--)
        {
            p=(p*i)%MOD;
        }
        return p;
    }

    int numPrimeArrangements(int n) 
    {
        const int MOD=1e9+7;
        int pc=0;
        for(int i=1;i<=n;i++)
        {
            if(TestPrime(i))
                pc++;
        }
        int npc=n-pc;
        return (findfact(pc)*findfact(npc))%MOD;
    }
};


---

📊 Mathematical Summary:

Total positions = n

Prime numbers count = pc

Prime indices count = pc (1-based indices: 2, 3, 5, 7, ...)

Valid arrangements = pc! * (n - pc)!

Final result = (pc! * npc!) % 1e9+7



---

🧪 Test Case ব্যাখ্যা:

Input: n = 5

Prime numbers: 2, 3, 5 → pc = 3

Non-prime numbers: 1, 4 → npc = 2

Total valid permutations: 3! * 2! = 6 * 2 = 12


Input: n = 100

Total primes from 1 to 100 = 25 (pre-known or count with sieve)

So pc = 25, npc = 75

Result = 25! * 75! % 1e9+7 = 682289015



---

🧠 বুঝে কোড লেখার কৌশল:

1. প্রশ্নে বলা হয়েছে “prime numbers should be at prime indices” → মনে রাখতে হবে 1-based indexing।


2. তাহলে কাজটা হয়ে গেল:

Total কতগুলো প্রাইম আছে তা বের করা

তাদের factorial বের করা

বাকিদের factorial বের করা

গুণ করা



3. যতবারই factorial বের করব, সবসময় MOD নিতে হবে।




---

🔁 Time Complexity:

Prime Count: O(n√n)

Factorial: O(n)
Total: O(n√n)



---

✅ Accepted হওয়ার কারণ:

সব constraint (1 ≤ n ≤ 100) এর মধ্যে efficient solution

Modulo overflow রক্ষা

Simple, correct logic based on combinatorics



---

Full Code:
-------------

  class Solution 
{
public:
    bool TestPrime(int n)
    {
        if(n<2) return false;
        bool isprime=true;
        for(int i=2;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    isprime=false;
                    break;
                }
            }
        return isprime;
    }
    long long findfact(int n)
    {
        const int MOD=1e9+7;
        long long p=1;
        for(int i=n;i>=1;i--)
            {
                p=(p*i)%MOD;
            }
        return p;
    }
    int numPrimeArrangements(int n) 
    {
        const int MOD=1e9+7;
        int pc=0;
        int npc;
        for(int i=1;i<=n;i++)
            {
                if(TestPrime(i))
                {
                    pc++;
                }
            }
        npc=n-pc;
        int ans=(findfact(pc)*findfact(npc))%MOD;
        return ans;
    }
};
