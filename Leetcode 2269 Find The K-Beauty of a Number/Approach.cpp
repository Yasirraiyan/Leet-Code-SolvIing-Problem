🔍 সমস্যা বোঝা (Problem Understanding in Bangla):

ধরা যাক num = 240, k = 2
এখন num কে string হিসাবে পড়লে → "240"

এই string এর প্রতিটি length = k = 2 এর substring বের করতে হবে, যেমন:

"24" → 24 % 240 == 0 → ✔️

"40" → 40 % 240 == 0 → ✔️

Total = 2 → ✅



---

📌 লক্ষ্য (Objective):

কয়টি substring আছে যা:

1. দৈর্ঘ্যে k


2. 0 না (কারণ 0 দিয়ে ভাগ করা যায় না)


3. num কে নিঃশেষে ভাগ করতে পারে (divisor হতে হবে)



এটাই হল k-beauty।


---

🔎 Approach / ভাবনা (Step-by-Step):

ধরি:
num = 430043 এবং k = 2

Step 1:

👉 প্রথমে num কে string এ convert করবো → "430043"

Step 2:

👉 তারপর k দৈর্ঘ্যের সব substring বের করবো:

"43", "30", "00", "04", "43"

Step 3:

👉 প্রতিটি substring কে number এ রূপান্তর করবো
👉 যদি সেই সংখ্যা ≠ 0 এবং num % value == 0, তাহলে beauty বাড়াবো


---

✅ Accepted Code Explanation:

class Solution {
public:
    int divisorSubstrings(int num, int k) 
    {
        string nums = to_string(num);  // Step 1: int → string
        vector<string> v;
        for (int i = 0; i <= nums.size() - k; i++)  // Step 2: Substrings of length k
        {
            v.push_back(nums.substr(i, k));  // nums.substr(start, length)
        }

        int beauty = 0;
        for (int j = 0; j < v.size(); j++)  // Step 3: Loop through all substrings
        {
            int val = stoi(v[j]);  // convert string → integer
            if (val != 0 && num % val == 0)  // val should not be 0, and divisor of num
            {
                beauty++;  // valid divisor, count it
            }
        }

        return beauty;  // Return total k-beauty
    }
};


---

💡 Mathematical Explanation (Bangla):

ধরো, num = 430043

String form: "430043"
k = 2

Substrings:

"43" → 430043 % 43 == 0 → ✔️

"30" → 430043 % 30 ≠ 0 → ✖️

"00" → invalid → ✖️ (0 divisor না)

"04" → 4, 430043 % 4 ≠ 0 → ✖️

"43" → ✔️


✅ Total = 2


---

📊 Complexity:

Type	Value

Time Complexity	O(n * k) → Actually O(n)
Space Complexity	O(n) for storing substrings



---

✅ টেস্ট কেস যাচাই (Test Case Validation):

Test 1:

Input: num = 240, k = 2
String: "240"
Substrings: "24", "40" → both are valid divisors
Output: 2

Test 2:

Input: num = 430043, k = 2
Substrings: "43", "30", "00", "04", "43"
Valid divisors: "43", "43"
Output: 2


---

🧠 তুমি কীভাবে চিন্তা করবে (Thinking Strategy):

1. সমস্যা থেকে বুঝবে:

Substring কনসেপ্ট

Divisibility



2. Input কে string এ রূপান্তর


3. Loop চালিয়ে প্রতিটি substring বের করে integer এ convert করো


4. Valid হলে count বাড়াও


5. Return final count




---

✍️ তোমার চিন্তার Code লেখা পদ্ধতি:

Step by Step Plan:

int divisorSubstrings(int num, int k)
{
    string nums = to_string(num);   // Step 1: num → string
    int count = 0;

    for (int i = 0; i <= nums.size() - k; i++)  // Step 2: Get substrings of length k
    {
        string sub = nums.substr(i, k);  // Step 3: Substring
        int val = stoi(sub);             // Step 4: Convert to number
        if (val != 0 && num % val == 0)  // Step 5: Check valid divisor
        {
            count++;
        }
    }

    return count;
}


---

✅ উপসংহার (Summary):

Substring জেনারেট করো

প্রতিটা substring কে নাম্বারে রূপান্তর করো

valid হলে count বাড়াও

Time Complexity efficient (O(n))


Full Code:
-------------

  class Solution 
{
public:
    int divisorSubstrings(int num, int k) 
    {
        string nums=to_string(num);
       vector<string>v;
        for(int i=0;i<=nums.size()-k;i++)
            {
                v.push_back(nums.substr(i,k));
            }
        int beauty=0;
        for(int j=0;j<v.size();j++)
            {
                int val=stoi(v[j]);
                if(val!=0&&num%val==0)
                {
                    beauty++;
                }
            }
        return beauty;
    }
};
