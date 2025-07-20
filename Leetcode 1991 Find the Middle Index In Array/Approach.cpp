🔍 প্রবলেম বুঝি (Understanding the Problem)
তোমাকে একটা nums নামের integer array দেওয়া হয়েছে। তোমাকে এমন একটা middleIndex খুঁজতে হবে, যেটা satisfy করে এই condition:

bash
Copy
Edit
sum(nums[0] + nums[1] + ... + nums[middleIndex-1]) 
== 
sum(nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[n-1])
অর্থাৎ, index টার বামে যেসব সংখ্যার যোগফল আছে, আর index টার ডানে যেসব সংখ্যার যোগফল আছে — এই দুইটা সমান হতে হবে।

✅ টেস্ট কেস এনালাইসিস
Example 1:
nums = [2,3,-1,8,4]
Index 3:
Left sum = 2 + 3 + (-1) = 4
Right sum = 4
✅ Match করেছে → Return 3

🧠 ব্যবহৃত টেকনিক: Prefix Sum + Running Sum
এই সমস্যায় আমরা prefix sum কনসেপ্ট ব্যবহার করি কারণ এতে করে আমরা প্রতি index এর বামে ও ডানে থাকা উপাদানগুলোর যোগফল efficiently বের করতে পারি।

🧮 ধাপে ধাপে সমাধান (Approach Step-by-Step)
Step 1: পুরো অ্যারেটার Total Sum বের করো
আমরা জানি:

ini
Copy
Edit
totalSum = sum of all elements in nums
Step 2: Loop চালিয়ে প্রতিটি index এর জন্য check করো
আমরা চলতি পর্যন্ত যোগফল রাখবো leftSum নামে। ধরো আমরা index i তে আছি।

তাহলে,

ini
Copy
Edit
rightSum = totalSum - leftSum - nums[i]
কারণ, totalSum = leftSum + nums[i] + rightSum

⇒ Rearranged করলে:
rightSum = totalSum - leftSum - nums[i]

Step 3: যদি leftSum == rightSum হয়, তাহলে সেটাই middleIndex
Step 4: না পেলে return -1
💻 কোড ব্যাখ্যা সহ (Line by Line with Bangla Explanation)
cpp
Copy
Edit
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;     // পুরো অ্যারেটার total যোগফল রাখবো এখানে
        int leftSum = 0;      // প্রতিটি index এর আগ পর্যন্ত উপাদানের যোগফল
        
        // Step 1: Total sum বের করলাম
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // Step 2: প্রতিটি index এ চেক করবো
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i]; // current index বাদ দিয়ে ডানের sum
            
            if (leftSum == rightSum) {
                return i; // এটাই middleIndex → leftmost পাওয়া গেলেই return
            }

            leftSum += nums[i]; // পরবর্তী index এর জন্য leftSum আপডেট
        }

        // কোনো index middleIndex না হলে
        return -1;
    }
};
🧪 Test Case দিয়ে Step-by-Step Code Walkthrough
Input: nums = [2,3,-1,8,4]
totalSum = 2 + 3 + (-1) + 8 + 4 = 16

Loop start:

i=0:
leftSum=0, rightSum = 16 - 0 - 2 = 14 → ❌
leftSum = 0 + 2 = 2

i=1:
leftSum=2, rightSum = 16 - 2 - 3 = 11 → ❌
leftSum = 2 + 3 = 5

i=2:
leftSum=5, rightSum = 16 - 5 - (-1) = 16 - 5 + 1 = 12 → ❌
leftSum = 5 + (-1) = 4

i=3:
leftSum=4, rightSum = 16 - 4 - 8 = 4 ✅ match → return 3

✅ Time & Space Complexity Analysis
Time Complexity: O(n)
একবার totalSum বের করতে O(n) এবং একবার লুপ চালাতে O(n) = মোট O(n)

Space Complexity: O(1)
কোনো extra array বা ডাটা স্ট্রাকচার লাগছে না।

🧠 কিভাবে বুঝবা এই Technique লাগবে?
এই ধরনের সমস্যা দেখলে চিন্তা করো:

Index এর বামের যোগফল এবং ডানের যোগফল compare করতে বলা হচ্ছে?
⇒ তাহলে prefix sum বা running sum লাগবে

একাধিক বার যোগফল বের করতে বলা হলে brute force O(n^2) হয়ে যাবে
⇒ Efficient সমাধানে prefix sum/total sum approach দরকার

✅ Accepted কেন হলো?
Efficient O(n) solution

সমস্ত edge case handle করছে:

beginning index (left sum = 0)

last index (right sum = 0)

📌 উপসংহার
এই সমস্যা বোঝার মূল কনসেপ্ট:

prefix sum = চলতি পর্যন্ত যোগফল

total sum - left sum - current = right sum

যে index এর ক্ষেত্রে left এবং right sum সমান, সেটাই উত্তর।

  Full Code:
--------------

  class Solution
 {
public:
    int findMiddleIndex(vector<int>& nums) 
    {
       int totalsum=0;
       int pivot=-1;
       int leftsum=0;
       int rightsum;
       for(int i=0;i<nums.size();i++)
       {
        totalsum+=nums[i];
       }
        for(int j=0;j<nums.size();j++)
        {
           rightsum= totalsum-leftsum;
           leftsum+=nums[j];
           if(leftsum==rightsum)
           {
            pivot=j;
            break;
           }
        }
        return pivot;
    }
};
