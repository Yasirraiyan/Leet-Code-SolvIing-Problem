🔶 Problem-এর লক্ষ্য:
প্রতিবার যখন পিঁপড়াটি boundary-তে (অর্থাৎ অবস্থান 0 তে) ফিরে আসে, সেটা গুনে দেখা।

✅ Approach বুঝি ধাপে ধাপে:
🔹 Step 1: চলাফেরার পর অবস্থান হিসাব করো (Prefix Sum / Running Sum)
প্রথমে বুঝি পিঁপড়ার অবস্থান কিভাবে পরিবর্তিত হচ্ছে। ধরো,

শুরুতে পিঁপড়া আছে অবস্থান 0-তে।

প্রতি nums[i] মানের জন্য:

যদি nums[i] > 0, তাহলে ডানে যায়।

যদি nums[i] < 0, তাহলে বামে যায়।

তাহলে nums এর প্রতিটি মান যোগ করলে পিঁপড়ার মোট অবস্থান পাওয়া যায় ধাপে ধাপে। একে বলা হয় prefix sum।

🔹 Step 2: প্রতিবার অবস্থান যদি 0 হয় (return to boundary), তাহলে count বাড়াও।
শুধু তখনই count করবো, যখন prefix sum আবার 0 হয়।

পিঁপড়া যখন চলার পর 0 অবস্থানে আসে, তখন return to boundary হিসেবে ধরা হয়।

✅ Code Explanation in Bangla Line-by-Line:
cpp
Copy
Edit
class Solution 
{
public:
    int returnToBoundaryCount(vector<int>& nums) 
    {
        // prefix sum রাখার জন্য psum নামের vector নিচ্ছি
        vector<int> psum(nums.size(), 0);
        
        // প্রথম অবস্থান হল nums[0] অনুযায়ী
        psum[0] = nums[0];

        // পরের অবস্থানগুলো হিসাব করছি
        for(int i = 1; i < nums.size(); i++)
        {
            psum[i] = psum[i - 1] + nums[i];  // প্রতিবার আগের sum + নতুন nums[i]
        }

        int count = 0;

        // প্রতিবার prefix sum 0 হলে, মানে পিঁপড়া boundary তে ফিরেছে
        for(int j = 0; j < psum.size(); j++)
        {
            if(psum[j] == 0)
            {
                count++;  // ফিরে এসেছে বলে count বাড়ালাম
            }
        }

        return count;  // মোট কয়বার ফিরে এসেছে তা return করলাম
    }
};
🧠 তুমি কীভাবে চিন্তা করে এমন approach ভাববে?
✅ যখনই চলাফেরার tracking দরকার হয়, তখন prefix sum ব্যবহার করা যায়।

✅ পিঁপড়ার প্রতিটি মুভমেন্ট তার বর্তমান অবস্থানকে পরিবর্তন করে → তাই চলার পর position গুলা রাখা দরকার।

✅ যদি position == 0, তাহলে বুঝতে পারি পিঁপড়া আবার boundary-তে ফিরেছে।

✅ সব চলার শেষে কতবার position 0 হয়েছে সেটা গুনলে উত্তর পাওয়া যাবে।

🧪 Test Example 1:
cpp
Copy
Edit
Input: nums = [2, 3, -5]
চলাফেরা:

শুরু: 0

move 1: +2 → position = 2

move 2: +3 → position = 5

move 3: -5 → position = 0 ✅ (1 return)

✅ Output: 1

🧪 Test Example 2:
cpp
Copy
Edit
Input: nums = [3, 2, -3, -4]
চলাফেরা:

শুরু: 0

move 1: +3 → position = 3

move 2: +2 → position = 5

move 3: -3 → position = 2

move 4: -4 → position = -2

🔴 কখনোই অবস্থান 0 হয়নি → output: 0

✅ Complexity:
Time: O(n) → prefix sum হিসাব করা এবং একবার traverse করে count করা।

Space: O(n) → psum array ব্যবহার করার কারণে।

Full Code:
----------

  class Solution 
{
public:
    int returnToBoundaryCount(vector<int>& nums) 
    {
      vector<int>psum(nums.size(),0);
        psum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
          psum[i]=psum[i-1]+nums[i];
        }
       
        int count=0;

        for(int j=0;j<psum.size();j++)
        {
          if(psum[j]==0)
          {
          count++;
        }
        }
       
       return count;

    }
};
