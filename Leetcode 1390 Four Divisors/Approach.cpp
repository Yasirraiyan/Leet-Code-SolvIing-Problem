✅ Problem:
তোমাকে একটি পূর্ণসংখ্যার array nums দেওয়া হয়েছে।
তুমি nums array-এর এমন সংখ্যাগুলোর divisors (ভাজক) গুলোর যোগফল বের করবে যাদের ঠিক ৪টি ভাজক আছে।

যদি কোন সংখ্যার exactly 4টি ভাজক না থাকে, তাহলে সেটি বাদ যাবে।

🧠 Step-by-Step Thinking Approach (Problem পড়ে কীভাবে ভাববো):
➤ Step 1:
প্রতিটি সংখ্যা x নিয়ে চেক করবো তার divisors কয়টি।

➤ Step 2:
যদি divisors সংখ্যা ঠিক ৪টি হয় — তাহলেই আমরা তার divisors এর যোগফল (sum) বের করবো।

➤ Step 3:
সব ৪ ভাজকবিশিষ্ট সংখ্যার ভাজকসমূহের যোগফল মোট যোগফলে (final sum) যুক্ত করবো।

✅ তোমার কোডের বিশ্লেষণ ও ব্যাখ্যা (line-by-line):
cpp
Copy
Edit
class Solution 
{
public:
✅ Check ফাংশন:
cpp
Copy
Edit
bool Check(int n)
{
    bool check = false;
    int count = 0;
    vector<int>v;

    for(int i = 1; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            count++;
            v.push_back(i);
            
            if (i != n / i)
            {
                count++;
                v.push_back(n / i);
            }

            if (count > 4) break; // optimization
        }
    }

    if(count == 4)
    {
        check = true;
    }

    return check;
}
🔍 ব্যাখ্যা:
count দিয়ে আমরা কতগুলো ভাজক পেলাম তা গুনছি।

v হচ্ছে ভাজক সংরক্ষণের জন্য ভেক্টর (তবে এখানে সরাসরি দরকার নেই, কারণ শুধু সংখ্যা গুনছি)।

যদি কোনো সংখ্যার ভাজক সংখ্যা ৪ টার বেশি হয়ে যায় তাহলে আমরা আর লুপ চালাতে চাই না — তাই if (count > 4) break; দিয়ে optimization করা হয়েছে।

শেষে count == 4 হলে true রিটার্ন করছি।

✅ divisors ফাংশন:
cpp
Copy
Edit
int divisors(int n)
{
    int sum = 0;
    vector<int>v;
    
    for(int k = 1; k <= n; k++)
    {
        if(n % k == 0)
        {
            v.push_back(k);
        }
    }

    for(int j = 0; j < v.size(); j++)
    {
        sum += v[j];
    }

    return sum;
}
🔍 ব্যাখ্যা:
n সংখ্যাটির সব ভাজক বের করে v তে রাখি।

পরে সব ভাজক যোগ করে sum রিটার্ন করি।

✴️ Optimization Tip: চাইলে v ছাড়াই সরাসরি যোগফল নিতে পারো:

cpp
Copy
Edit
for(int k = 1; k <= n; k++)
    if(n % k == 0) sum += k;
✅ Main Function: sumFourDivisors
cpp
Copy
Edit
int sumFourDivisors(vector<int>& nums) 
{
    int sum = 0;

    for(int k = 0; k < nums.size(); k++)
    {
        if(Check(nums[k]))
        {
            sum += divisors(nums[k]);
        }
    }

    return sum;
}
🔍 ব্যাখ্যা:
nums array-র প্রতিটি উপাদান nums[k] নিয়ে Check() ফাংশন কল করছি।

যদি Check() বলে এটি ঠিক ৪টি ভাজক আছে — তাহলে divisors() ফাংশনে তার যোগফল বের করে sum-এ যোগ করছি।

🔁 Example Test Case Step-by-Step:
🔸 Input: nums = [21, 4, 7]
👉 First number: 21
Divisors: 1, 3, 7, 21 → Count = 4 → ✅

Sum = 1 + 3 + 7 + 21 = 32

👉 Second number: 4
Divisors: 1, 2, 4 → Count = 3 → ❌

👉 Third number: 7
Divisors: 1, 7 → Count = 2 → ❌

➡️ Final Answer = 32

✅ Accepted কেন?
Constraints অনুযায়ী প্রতিটি সংখ্যার উপর বেশি সময় নিচ্ছো না (divisor count ≤ sqrt(n))।

প্রতি সংখ্যার divisors বের করা এবং তাদের count করা efficient।

কোন জায়গায় ভুল নেই এবং অপ্রয়োজনীয় কোডও বেশি নয়।

🧪 Test More Cases:
cpp
Copy
Edit
vector<int> nums = {21, 4, 7}; // Output: 32
vector<int> nums2 = {21, 21}; // Output: 64
vector<int> nums3 = {1, 2, 3, 4, 5}; // Output: 0
Full Code:
----------

  class Solution 
{
public:
  bool Check(int n)
  {
    bool check=false;
     int count=0;
    vector<int>v;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
           count++;
           v.push_back(i);
            if (i != n / i) // avoid double-counting perfect square root
            {
                count++;
                v.push_back(n / i);
            }
             if (count > 4) break;
        }
        }
        if(count==4)
        {
            check=true;
          // break;
        }
    
    return check;
  }
 int divisors(int n)
 {
    int sum=0;
   vector<int>v;
   for(int k=1;k<=n;k++)
   {
    if(n%k==0)
    {
        v.push_back(k);
    }
   }
    for(int j=0;j<v.size();j++)
    {
        sum+=v[j];
    }
    return sum;
 }
    int sumFourDivisors(vector<int>& nums) 
    {
        int sum=0;
        for(int k=0;k<nums.size();k++)
        {
            if(Check(nums[k]))
            {
                sum+=divisors(nums[k]);
            }
        }
        return sum;
    }
};
