🔍 প্রশ্নটি বোঝা (Mathematical Analysis):

প্রশ্ন:
তোমাকে একটি ইন্টিজার nums অ্যারে দেওয়া হয়েছে। তোমার কাজ হলো:

তৃতীয় সর্বোচ্চ আলাদা সংখ্যাটি (third distinct maximum) বের করে রিটার্ন করা।

যদি তিনটি আলাদা সংখ্যা না থাকে, তাহলে সর্বোচ্চ সংখ্যাটি রিটার্ন করো।



---

🧠 কিভাবে চিন্তা করব?

1. ডুপ্লিকেট সংখ্যা বাদ দিতে হবে। তাই আলাদা সংখ্যা খুঁজে বের করতে হবে।


2. সেই সংখ্যা গুলো বড় থেকে ছোট ক্রমে সাজাতে হবে।


3. তারপর দেখা যাবে তৃতীয় সর্বোচ্চ সংখ্যা আছে কি না:

থাকলে সেটা রিটার্ন করো।

না থাকলে সর্বোচ্চ সংখ্যাটি রিটার্ন করো।





---

🧮 উদাহরণ দিয়ে বুঝি:

উদাহরণ 1:

Input: [3, 2, 1]
→ Distinct values: [3, 2, 1]
→ Sorted descending: [3, 2, 1]
→ Third max = 1 ✅

উদাহরণ 2:

Input: [1, 2]
→ Distinct values: [2, 1]
→ Third max doesn't exist ⇒ return max = 2 ✅

উদাহরণ 3:

Input: [2, 2, 3, 1]
→ Distinct values: [3, 2, 1]
→ Third max = 1 ✅


---

✅ তোমার কোডের লজিক (Accepted):

class Solution {
public:
    int findmax(vector<int>& nums)
    {
        int max = nums[0];
        for(int j = 1; j < nums.size(); j++)
        {
            if(nums[j] > max)
            {
                max = nums[j];
            }
        }
        return max;
    }

    int thirdMax(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>freq;
        int ans;

        // Step 1: Frequency map তৈরি করে ডুপ্লিকেট বাদ
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        // Step 2: শুধু আলাদা ভ্যালুগুলো vector-এ তোলা
        for(auto it : freq)
        {
            v.push_back(it.first);
        }

        // Step 3: বড় থেকে ছোট সাজানো
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        // Step 4: তৃতীয় সর্বোচ্চ আছে কি না দেখা
        if(v.size() >= 3)
        {
            ans = v[2];
        }
        else
        {
            ans = findmax(v);
        }

        return ans;
    }
};


---

🔍 Bangla Line-by-Line Explanation:

int findmax(vector<int>& nums)

➤ nums অ্যারেটির মধ্যে সবচেয়ে বড় সংখ্যা খুঁজে বের করার জন্য এই ফাংশন।

int max = nums[0];

➤ শুরুতে ধরে নিই প্রথম সংখ্যাটাই সবচেয়ে বড়।

for(int j = 1; j < nums.size(); j++)

➤ অ্যারেটির বাকি সংখ্যাগুলো ঘুরি।

if(nums[j] > max) max = nums[j];

➤ যদি নতুন কোনো সংখ্যা বড় হয়, তাহলে সেটাকেই নতুন max ধরি।


---

unordered_map<int,int> freq;

➤ একটি ম্যাপ নেই, যাতে প্রতিটি সংখ্যার frequency রাখা যায়। এতে ডুপ্লিকেট সহজে বাদ দেওয়া যাবে।

for(int i = 0; i < nums.size(); i++) freq[nums[i]]++;

➤ প্রতিটি সংখ্যার জন্য count বাড়ানো হচ্ছে।

for(auto it : freq) v.push_back(it.first);

➤ ডুপ্লিকেট বাদ দিয়ে শুধু unique সংখ্যাগুলো v তে তোলা হচ্ছে।

sort(v.begin(), v.end());
reverse(v.begin(), v.end());

➤ সংখ্যা গুলো বড় থেকে ছোট সাজানো হলো।

if(v.size() >= 3) ans = v[2];

➤ যদি ৩ বা তার বেশি আলাদা সংখ্যা থাকে, তাহলে তৃতীয়টি return করব (index 2)।

else ans = findmax(v);

➤ না থাকলে v-এর মধ্যে সবচেয়ে বড় সংখ্যাটি return করব।


---

🧪 Test Case by Test Case বিশ্লেষণ:

Test Case: [3,2,1]

freq: {1:1, 2:1, 3:1}

v: [3,2,1]

v[2] = 1 → ✅


Test Case: [1,2]

freq: {1:1, 2:1}

v: [2,1]

v.size() < 3 → return max(v) = 2 → ✅


Test Case: [2,2,3,1]

freq: {1:1, 2:2, 3:1}

v: [3,2,1]

v[2] = 1 → ✅



---

✅ Time Complexity:

Map তৈরিতে সময়: O(n)

Unique গুলো sort + reverse করতে সময়: O(k log k) যেখানে k = unique values ≤ n

Final Complexity: O(n log n) (worst case), তবে accepted ✅

  Full Code:
---------------

  class Solution 
{
public:
    int findmax(vector<int>& nums)
    {
        int max =nums[0];
        for(int j=1;j<nums.size();j++)
            {
                if(nums[j]>max)
                {
                    max=nums[j];
                }
            }
        return max;
    }

    int thirdMax(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>freq;
        int ans;
        for(int i=0;i<nums.size();i++)
            {
                freq[nums[i]]++;
            }
        for(auto it:freq)
            {
                v.push_back(it.first);
            }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        if(v.size()>=3)
        {
            ans= v[2];
        }
        if(v.size()<3)
        {
            ans=findmax(v);
        }
        return ans;
    }
};
