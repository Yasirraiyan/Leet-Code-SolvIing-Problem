🧠 Problem Summary (বাংলায়):

তোমাকে একটি nums array দেওয়া আছে যেখানে শুধুমাত্র positive integers আছে।
তোমার কাজ হলো:

1. প্রত্যেক সংখ্যার digit reverse করে সেই সংখ্যাটি array-এর শেষে যোগ করা।


2. তারপর এই নতুন array-এ কতগুলো ভিন্ন ভিন্ন সংখ্যা (distinct integers) আছে, সেটা বের করা।




---

✅ উদাহরণ:

Input:

nums = [1,13,10,12,31]

Reverse গুলো:

1 → 1
13 → 31
10 → 01 → 1
12 → 21
31 → 13

Final array:

[1, 13, 10, 12, 31, 1, 31, 1, 21, 13]

Distinct values:

{1, 10, 12, 13, 21, 31} → total = 6


---

🧭 সমাধানের কৌশল (Approach):

আমরা প্রথমে প্রশ্ন পড়ে কীভাবে চিন্তা করবো?

1. প্রথম ধাপ: প্রতিটা সংখ্যার reverse বের করবো।


2. দ্বিতীয় ধাপ: এই reverse গুলো মূল array-এর শেষে যোগ করবো।


3. তৃতীয় ধাপ: পুরা array-তে এখন কতগুলো ভিন্ন ভিন্ন (distinct) সংখ্যা আছে, সেটা গুনবো।




---

🧮 Line-by-line বিশ্লেষণ (বাংলায় ব্যাখ্যা সহ):

class Solution 
{
public:
    // একটি helper function যেটা একটা সংখ্যা reverse করে
    int findrev(int n)
    {
        int rev=0;
        while(n>0)  // যতক্ষণ না n শেষ হচ্ছে
        {
            int digit=n%10;       // শেষ digit নেওয়া
            rev=rev*10+digit;     // reverse-এ সেটি যোগ করা
            n=n/10;               // পরের digit এর জন্য n ছোট করা
        }
        return rev;
    }

👉 এই findrev() function টা কাজ করছে একটি সংখ্যাকে reverse করে return করার জন্য।
উদাহরণ:
findrev(13) → 31
findrev(10) → 1


---

int countDistinctIntegers(vector<int>& nums) 
    {
        int originalsize=nums.size();  // মূল array-এর আকার মনে রাখা

👉 আমরা শুধু মূল array-এর উপরে reverse apply করবো, তাই size আগে ধরে রাখি।


---

for(int i=0;i<originalsize;i++)
        {
            nums.push_back(findrev(nums[i]));  // reverse গুলো শেষের দিকে যোগ করছি
        }

👉 এখানে আমরা প্রথম থেকে originalsize পর্যন্ত গিয়ে প্রতিটি সংখ্যার reverse বের করে nums এ append করছি।


---

unordered_map<int,int>freq;
        for(int j=0;j<nums.size();j++)
        {
            freq[nums[j]]++;   // frequency গণনা করছি, একটিবার এলেই map-এ থাকবে
        }

👉 unordered_map ব্যবহার করে প্রতিটি সংখ্যাকে map করছি।
এখানে শুধু key গুলো important — key মানেই unique/distinct সংখ্যা।


---

vector<int>v;
        for(auto it:freq)
        {
            v.push_back(it.first);   // map থেকে সব unique সংখ্যা নিচ্ছি
        }

👉 map-এর key গুলো নিয়ে একটা vector বানালাম। এটি শুধুই distinct সংখ্যা ধরার জন্য।


---

int ans=v.size();   // total কতটি distinct সংখ্যা
        return ans;
    }
};

👉 অবশেষে return করলাম সেই সংখ্যা যেগুলো distinct ছিল।


---

⏳ Time Complexity:

Reversing: O(n * D), যেখানে D হচ্ছে সংখ্যা গুলোর digit সংখ্যা (কমবেশি log₁₀(num))

Insertion into map: O(n)

Overall: O(n) অ্যাভারেজ কেসে।



---

✅ Accepted কেন?

কারণ তুমি কেবল original element গুলোর উপরে কাজ করছো।

তুমি reverse গুলো শুধু once যোগ করছো।

তারপর unordered_map দিয়ে efficiently distinct বের করছো।



---

🔍 Test Case দিয়ে যাচাই:

Input:

nums = [2,2,2]

Reverse: 2 → 2 → 2
Final array: [2,2,2,2,2,2]
Distinct: {2}
Output: 1 ✅


---

🔚 উপসংহার (Summary):

তুমি প্রথমে original সংখ্যা গুলোর reverse বের করেছো।

তারপর সেগুলো array-তে যোগ করেছো।

সবশেষে, unordered_map দিয়ে unique সংখ্যা গুনেছো।

কোডটি efficient কারণ map-এর key গুলো distinct রাখে।




Full Code:
--------------
class Solution 
{
public:
    int findrev(int n)
    {
        int rev=0;
        while(n>0)
            {
                int digit=n%10;
                rev=rev*10+digit;
                n=n/10;
            }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) 
    {
        int originalsize=nums.size();
        for(int i=0;i<originalsize;i++)
            {
                nums.push_back(findrev(nums[i]));
            }
        unordered_map<int,int>freq;
        for(int j=0;j<nums.size();j++)
            {
                freq[nums[j]]++;
            }
        vector<int>v;
        for(auto it:freq)
            {
                v.push_back(it.first);
            }
        int ans=v.size();
        return ans;
    }
};  
