🔸 একটি পূর্ণসংখ্যার অ্যারে (nums) দেওয়া আছে। তোমাকে এই অ্যারেটিকে দুইটি অ্যারেতে ভাগ করতে হবে — A এবং B।

যেসব ইনডেক্স প্রাইম (prime), ঐ ইনডেক্সের ভ্যালুগুলো যাবে Array A তে।

বাকি ইনডেক্সগুলোর ভ্যালু যাবে Array B তে।


শেষে, এই দুইটি অ্যারের যোগফলের অ্যাবসোলিউট ডিফারেন্স (|sum(A) - sum(B)|) রিটার্ন করতে হবে।


---

🔍 Step-by-Step Thinking Approach (বাংলায়):

➤ Step 1: প্রশ্নটি পড়ে কী বোঝা গেলো?

আমরা nums নামের একটি পূর্ণসংখ্যার অ্যারে পেয়েছি।

👉 আমাদের কাজ:

1. প্রত্যেক ইনডেক্স i চেক করবো।


2. যদি i prime number হয় → তাহলে nums[i] যাবে A তে।


3. না হলে → nums[i] যাবে B তে।


4. তারপর A ও B এর যোগফল বের করে তাদের অ্যাবসোলিউট পার্থক্য (|A - B|) বের করবো।




---

✏️ উদাহরণ দিয়ে বুঝি (Example 2):

nums = [-1, 5, 7, 0]
index =  0   1  2  3

Prime indices: 2, 3 → A = [7, 0]

Non-prime indices: 0, 1 → B = [-1, 5]

sum(A) = 7 + 0 = 7

sum(B) = -1 + 5 = 4

Output = |7 - 4| = 3 ✅



---

✅ কোডের প্রতিটি অংশ বিশ্লেষণ (line-by-line in Bangla):

class Solution
{
public:

➤ Solution নামের একটি ক্লাস তৈরি করা হয়েছে।


---

long long findsum(vector<int>&v)
    {
        long long sum=0;
        for(int k=0;k<v.size();k++)
        {
            sum+=v[k];
        }
        return sum;
    }

✅ findsum() ফাংশনটা একটা অ্যারের সব উপাদান যোগফল বের করে রিটার্ন করে। long long ব্যবহার করা হয়েছে কারণ সংখ্যাগুলো বড় হতে পারে।


---

bool Prime(int n)
    {
        bool isprime=true;
        if(n<2) return false;
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

✅ Prime() ফাংশন:

চেক করে n প্রাইম কিনা।

যদি n < 2 হয় → সেটা প্রাইম না।

তারপর i = 2 থেকে √n পর্যন্ত চেক করা হয় n কি i দিয়ে বিভাজ্য কিনা।

যদি হয় → প্রাইম না।



---

long long splitArray(vector<int>& nums) 
    {
        vector<int>v1;  // A
        vector<int>v2;  // B

✅ মূল ফাংশন splitArray:

দুটি ভেক্টর তৈরি করা হয়েছে: v1 (প্রাইম ইনডেক্সের ভ্যালু), v2 (বাকি সব)।



---

for(int j=0;j<nums.size();j++)
        {
            if(Prime(j))
            {
                v1.push_back(nums[j]);  // প্রাইম ইনডেক্সে A তে যায়
            }
            else
            {
                v2.push_back(nums[j]);  // non-prime ইনডেক্সে B তে যায়
            }
        }

✅ nums এর প্রতিটি ইনডেক্স j নিয়ে:

যদি j প্রাইম হয় → nums[j] কে v1 তে রাখা হয়।

নাহলে → v2 তে রাখা হয়।



---

long long primesum = findsum(v1);
        long long nonprimesum = findsum(v2);

✅ v1 ও v2 এর যোগফল বের করা হলো।


---

long long result = abs(primesum - nonprimesum);
        return result;
    }
};

✅ অবশেষে, তাদের মধ্যে অ্যাবসোলিউট পার্থক্য বের করে রিটার্ন করা হয়েছে।


---

📌 Time & Space Complexity:

Time Complexity:

প্রাইম চেকিং = O(√n) × n ইনডেক্স = approx O(n√n)

যোগফল বের করা = O(n)


Space Complexity: O(n) for storing v1 and v2



---

✅ Accepted হওয়ার কারণ:

Efficient প্রাইম চেকিং লজিক।

আলাদা করে A ও B কে স্টোর করা হয়েছে।

সীমিত ইনডেক্স রেঞ্জে √n এর ভেতরেই লুপ চলছে।

লজিক পুরোপুরি প্রশ্ন অনুযায়ী তৈরি।



---

✅ How to think for similar problems:

1. প্রশ্নে কীভাবে অ্যারে বিভাজন করতে বলা হয়েছে তা লক্ষ্য করো।


2. শর্তমতো যেসব ইনডেক্স বা মান প্রয়োজন সেগুলা আলাদা করে রাখো।


3. প্রাইম বা বিশেষ কন্ডিশনের জন্য সাবফাংশন বানাও — readable এবং reusable।


4. সঠিক Math operation (sum, abs, etc.) প্রয়োগ করো।


  Full Code:
---------------

class Solution
{
public:
    long long findsum(vector<int>&v)
    {
        long long sum=0;
        for(int k=0;k<v.size();k++)
            {
                sum+=v[k];
            }
        return sum;
    }
    bool Prime(int n)
    {
        bool isprime=true;
        if(n<2) return false;
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
    long long splitArray(vector<int>& nums) 
    {
        vector<int>v1;
        vector<int>v2;
        for(int j=0;j<nums.size();j++)
            {
                if(Prime(j))
                {
                    v1.push_back(nums[j]);
                }
                else
                {
                    v2.push_back(nums[j]);
                }
            }
    long long  primesum=findsum(v1);
        long long  nonprimesum=findsum(v2);
        long long result=abs(primesum-nonprimesum);
        return result;
    }
};
