প্রশ্নটি বোঝা

তোমাকে দেওয়া হয়েছে একটি integer array nums যার দৈর্ঘ্য 2n। আমাদের কাজ হলো এই array এর elements-গুলোকে n pair এ ভাগ করা (যেমন (a1, b1), (a2, b2), …, (an, bn)) যাতে প্রতিটি pair এর min(ai, bi) এর sum সর্বাধিক হয়।

ধাপে ধাপে বুঝা:

যদি আমরা pair করি (x, y) এবং x < y, তাহলে min(x, y) = x।

আমাদের লক্ষ্য হলো sum of all min(ai, bi) সর্বাধিক করা।

ধারাবাহিকভাবে চিন্তা করা (Thinking Process)

ধরা যাক array = [1, 4, 3, 2]

প্রথমে ভাবা যায় সব possible pair try করতে পারি।

(1,4),(2,3) → sum = 1+2=3

(1,3),(2,4) → sum = 1+2=3

(1,2),(3,4) → sum = 1+3=4 ✅

আমরা দেখতে পাচ্ছি (1,2),(3,4) pairing gives maximum sum।

একটি প্যাটার্ন লক্ষ্য করুন:

যদি array sort করি → [1,2,3,4]

তারপর পরপর elements pair করি (1,2),(3,4) → sum = 1+3 ✅

যে কারণে এটি কাজ করে:

min সর্বদা ছোট element।

বড় element গুলোকে একসাথে pair করলে ছোট element গুলোও বড় element গুলোর সাথে pair হবে না।

তাই array sort → take every 2nd element starting from index 0 gives maximum sum.

এটা হলো Greedy approach: সবসময় ছোট element গুলোকে ছোটের সাথে pair করো।

কোডের লাইন বাই লাইন ব্যাখ্যা
class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end()); // Step 1: array sort করি


প্রথমেই array sort করি যাতে ছোট থেকে বড় ক্রমে আসে।

উদাহরণ: [1,4,3,2] → [1,2,3,4]

        int sum = 0;  // Step 2: sum রাখার জন্য variable initialize করি


আমরা শেষ পর্যন্ত sum calculate করবো।

        for(int j = 0; j < nums.size(); j++)
        {
            if(j % 2 == 0)  // Step 3: index even হলে take nums[j]
            {
                sum += nums[j];
            }
        }


কারণ sort করার পর array-এ consecutive pair করলে প্রথম element সবসময় min হবে।

উদাহরণ: [1,2,3,4] → pairs = (1,2),(3,4)

min(1,2) = 1 → nums[0]

min(3,4) = 3 → nums[2]

তাই even index elements add করলেই sum of min হবে।

        return sum;  // Step 4: final maximum sum return করি
    }
};

টেস্ট কেসে পরীক্ষা (Step by Step)

Input: [1,4,3,2]

Sort → [1,2,3,4]

sum = 0

Loop through array:

j=0 → even → sum += 1 → sum=1

j=1 → odd → skip

j=2 → even → sum += 3 → sum=4

j=3 → odd → skip

return 4 ✅

Input: [6,2,6,5,1,2]

Sort → [1,2,2,5,6,6]

sum = 0

Loop:

j=0 → sum+=1 → sum=1

j=2 → sum+=2 → sum=3

j=4 → sum+=6 → sum=9 ✅

সংক্ষিপ্ত নোট (Technique Used)

Sorting → ascending order

Greedy Approach → প্রতিটি smallest possible element pair smallest remaining element-র সাথে

Iteration → take every even index after sorting

Time Complexity: O(n log n) (sorting)

Space Complexity: O(1)

যদি তুমি চাও, আমি একটা ছোট Bangla flowchart


Full Code:
------------

  class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int j=0;j<nums.size();j++)
        {
            if(j%2==0)
            {
                sum+=nums[j];
            }
        }
        return sum;
    }
};
