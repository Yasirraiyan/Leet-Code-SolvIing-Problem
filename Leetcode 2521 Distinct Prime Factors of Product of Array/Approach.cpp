✅ 🔶প্রশ্ন বিশ্লেষণ (Problem Analysis in Bangla)

🔸 Problem:

আমাদের কাছে একটি nums array আছে, যেখানে কিছু positive integer আছে। এখন আমাদের কাজ হলো,

> nums এর সব এলিমেন্টের গুণফলের মধ্যে কতগুলো ভিন্ন ভিন্ন (distinct) প্রাইম ফ্যাক্টর (prime factor) আছে সেটা বের করা।




---

✅ 🔶Solution Approach Step-by-Step (Bangla + Math)

🔹 Step 1: Observation

তুমি পুরো array nums = [a1, a2, a3, ..., an] এর product বের করো P = a1 × a2 × a3 × ... × an।

আমরা জানি, যদি P এর প্রাইম ফ্যাক্টর বের করি, তাহলে সেগুলোর মধ্যেই উত্তর লুকিয়ে আছে।

কিন্তু এখানে একটা সমস্যার কথা মাথায় রাখতে হবে:

> Constraint: 1 <= nums.length <= 10⁴ এবং 2 <= nums[i] <= 1000



তাহলে যদি আমরা সবগুলো সংখ্যার গুণফল নেই, সেটি হতে পারে অনেক বড়, যেমন 1000^10000 = huge!
👉 So we cannot compute the full product. তাই সরাসরি product বের করলে overflow হবে।


---

🔹 Step 2: Clever Idea 💡

আমরা nums এর প্রতিটি সংখ্যার prime factor individually বের করবো, তারপর যেগুলো unique সেগুলো count করবো।

🔑 এইভাবে:

প্রতিটা সংখ্যার prime factor বের করো।

একটা unordered_set<int>-এ সেই প্রাইম ফ্যাক্টর রাখো যাতে একই প্রাইম বারবার না আসে।

শেষে সেটার size ফেরত দাও (মানে কতগুলো unique prime factor আছে)।



---

✅ 🔶Mathematical Example:

Suppose: nums = [2, 4, 3, 7, 10, 6]

প্রতিটা সংখ্যার প্রাইম ফ্যাক্টর:

2 => [2]
4 => [2]
3 => [3]
7 => [7]
10 => [2, 5]
6 => [2, 3]

Union of all prime factors = {2, 3, 5, 7} => total 4 distinct primes

So, output = 4 ✅


---

✅ 🔶Line-by-line Code Explanation in Bangla:

class Solution 
{
public:


---

🔸 Helper Function 1: Factors(int n)

vector<int>Factors(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)
  {
    if(n%i==0)
    {
      v.push_back(i); // n এর যেসব সংখ্যায় ভাগ যায় (মানে factor), সেগুলো সংগ্রহ করছি
    }
  }
  return v;
}

➡️ এখানে তুমি এমন সব সংখ্যাকে নিচ্ছো যেগুলো n এর factor (ভাগ যায়)। কিন্তু শুধু factor জানলে হবে না, আমাদের লাগবে prime factor।


---

🔸 Helper Function 2: TestPrime(int n)

bool TestPrime(int n)
{
  if(n<2) return false; // 0 এবং 1 প্রাইম না
  for(int j=2;j*j<=n;j++)
  {
    if(n%j==0)
    {
       return false;
    }
  }
  return true; // কোন ভাগ যায়নি মানে এটা প্রাইম
}

➡️ এটা দিয়ে তুমি যাচাই করছো একটা সংখ্যা প্রাইম কিনা।


---

🔸 Main Function: distinctPrimeFactors

int distinctPrimeFactors(vector<int>& nums) 
{
    unordered_set<int>set1; // unique factor রাখার জন্য
    unordered_map<int,int>freq; // কোন কোন প্রাইম ফ্যাক্টর পাওয়া গেছে সেটা মনে রাখার জন্য

for(int k=0;k<nums.size();k++)
    {
        vector<int> vv=Factors(nums[k]); // nums[k] এর সব factor বের করলাম
        for(int j=0;j<vv.size();j++)
        {
            set1.insert(vv[j]); // সব factor set-এ ঢুকিয়ে দিলাম
        }
    }

➡️ উপরে প্রতিটা সংখ্যার factor বের করে set1 এ ঢুকিয়ে দিলাম। এখন set1 এ সব রকমের factor আছে, including non-primes.


---

vector<int>r;
    for(auto it:set1)
    {
        if(TestPrime(it))
        {
            freq[it]++; // যদি কোনো factor প্রাইম হয়, সেটার গননা করো
        }
    }

➡️ এখানে set1 থেকে প্রাইমগুলো ছাঁকছি, এবং freq map এ রাখছি।


---

for(auto it:freq)
    {
        r.push_back(it.first); // freq-এ যেসব প্রাইম আছে, সেগুলো r তে রাখছি
    }
    return r.size(); // ভিন্ন ভিন্ন প্রাইম ফ্যাক্টর এর সংখ্যা
}


---

✅ 🔶Output Explanation:

Example 1:

Input: [2,4,3,7,10,6]
Product = 2 × 4 × 3 × 7 × 10 × 6 = 10080
Prime Factors = {2, 3, 5, 7}
Output = 4

Example 2:

Input: [2,4,8,16]
Product = 1024 = 2^10
Prime Factors = {2}
Output = 1


---

Full Code:
------------

  class Solution 
{
public:
vector<int>Factors(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)
  {
    if(n%i==0)
    {
      v.push_back(i);
    }
  }
  return v;
}
bool TestPrime(int n)
{
  if(n<2) return false;
  bool test=true;
  for(int j=2;j*j<=n;j++)
  {
    if(n%j==0)
    {
       test=false;
       break;
    }
  }
  return test;
}
    int distinctPrimeFactors(vector<int>& nums) 
{
        unordered_set<int>set1;
        unordered_map<int,int>freq;
        for(int k=0;k<nums.size();k++)
        {
   vector<int> vv=Factors(nums[k]);
            for(int j=0;j<vv.size();j++)
        {
            set1.insert(vv[j]);
        }
        }
        int count=0;
        vector<int>r;
        for(auto it:set1)
            {
                if(TestPrime(it))
                    {
                        freq[it]++;
                    }
            }
        for(auto it:freq)
            {
                r.push_back(it.first);
            }
        count=r.size();
        return count;
    }
}; 
 
