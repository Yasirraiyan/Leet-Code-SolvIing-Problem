✅ Step 1: প্রশ্ন বুঝে চিন্তা করা

কী চাচ্ছে?

তোমাকে এমন i, j জোড়ার সংখ্যা গুনতে হবে যেখানে:

0 <= i < j < nums.length

nums[i] এর প্রথম ডিজিট এবং nums[j] এর শেষ ডিজিট coprime (gcd = 1)



---

✅ Step 2: কোড লেখার আগে চিন্তা করো - প্রয়োজনীয় ফাংশনগুলো

প্রথমে সমস্যা ভেঙে ভেঙে দেখি:

1. একটা ফাংশন লাগবে কোনো সংখ্যার প্রথম ডিজিট বের করতে ➤ findfirst()


2. আরেকটা ফাংশন লাগবে শেষ ডিজিট বের করতে ➤ findlast()
যদিও শেষ ডিজিট n % 10 করলেই পাওয়া যায়।


3. একটা ফাংশন লাগবে gcd বের করার জন্য ➤ findgcd()




---

✅ Step 3: লজিক ভাবনা (অ্যালগরিদম)

সব i < j জোড়ার উপর লুপ চালাও

প্রতিটি জোড়ার জন্য:

nums[i] থেকে first digit

nums[j] থেকে last digit

তাদের gcd == 1 কিনা চেক করো → coprime

হলে count বাড়াও




---

✅ Step 4: তোমার কোড ব্যাখ্যা (লাইন বাই লাইন)

class Solution 
{
public:

একটি Solution ক্লাস খুলেছো — LeetCode স্টাইল অনুসারে।


---

int findgcd(int a,int b)
    {
        while(b!=0)
        {
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

📌 GCD বের করার ফাংশন (Euclidean Algorithm)
ধরি a = 8, b = 5 → gcd(8, 5)
→ a % b = 8 % 5 = 3, তারপর a = 5, b = 3
→ a % b = 5 % 3 = 2
→ a = 3, b = 2 → ... যতক্ষণ না b = 0, তখন a হবে GCD.


---

int findfirst(int n)
    {
        vector<int>v;
        while(n>0)
        {
            int rem=n%10;
            v.push_back(rem);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        return v[0];
    }

📌 findfirst ফাংশন: সংখ্যার প্রথম ডিজিট বের করার জন্য। উদাহরণ: n = 2932
→ v = {2, 9, 3, 2}
→ v[0] = 2 ⇒ এটা হলো প্রথম ডিজিট।

📌 এটি একটু optimize করা যেত — নিচে বলবো।


---

int findlast(int n)
    {
        vector<int>v;
        while(n>0)
        {
            int rem=n%10;
            v.push_back(rem);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        return v[v.size()-1];
    }

📌 findlast: এটি আসলে বেশি জটিল করা হয়েছে। → শেষ ডিজিট হচ্ছে n % 10 — পুরো vector ও reverse দরকার নেই।


---

int countBeautifulPairs(vector<int>& nums) 
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(findgcd(findfirst(nums[i]), findlast(nums[j])) == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }

📌 মূল লজিক:

সব i < j জোড়ার উপর লুপ

nums[i] থেকে first digit, nums[j] থেকে last digit

যদি তাদের GCD = 1 → count++

শেষে count return



---

✅ Test Case: nums = [2,5,1,4]

আমরা চেক করি কয়টা beautiful pair আছে:

i	j	first(nums[i])	last(nums[j])	gcd	coprime

0	1	2	5	1	✅
0	2	2	1	1	✅
0	3	2	4	2	❌
1	2	5	1	1	✅
1	3	5	4	1	✅
2	3	1	4	1	✅


✅ মোট 5টি beautiful pair → Output = 5


---
Full Code:
-------------

  class Solution 
{
public:
    int findgcd(int a,int b)
    {
        int ans;
        while(b!=0)
            {
                int temp=b;
                b=a%b;
                a=temp;
            }
        return a;
    }
    int findfirst(int n)
    {
        vector<int>v;
        while(n>0)
            {
                int rem=n%10;
                v.push_back(rem);
                n=n/10;
            }
        reverse(v.begin(),v.end());
        int first=v[0];
        return first;
        
    }
    int findlast(int n)
    {
        vector<int>v;
        while(n>0)
            {
                int rem=n%10;
                v.push_back(rem);
                n=n/10;
            }
        reverse(v.begin(),v.end());
        int last=v[v.size()-1];
        return last;
        
    }
    int countBeautifulPairs(vector<int>& nums) 
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                    {
                        if(i!=j)
                        {
                            if(findgcd(findfirst(nums[i]),findlast(nums[j]))==1)
                            {
                                count++;
                            }
                        }
                    }
            }
        return count;
    }
};
