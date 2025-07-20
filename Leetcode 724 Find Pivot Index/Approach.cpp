🔍 প্রবলেমটা কী বলছে?
আমরা এমন একটি index খুঁজবো যেখানে তার বাম পাশের সব উপাদানের যোগফল == তার ডান পাশের সব উপাদানের যোগফল হবে।

✅ ইনপুট:
cpp
Copy
Edit
nums = [1, 7, 3, 6, 5, 6]
আমাদেরকে এমন একটি index return করতে হবে যেখানে:

ini
Copy
Edit
left_sum == right_sum
🔍 কোন টেকনিক ব্যবহার করা হয়েছে?
👉 Prefix Sum Optimization (One Pass Technique)

⚙️ কাজের মূলধারা (Approach):
আমরা চাই না প্রতিটি index-এর জন্য আলাদা করে বাম ও ডান পাশের যোগফল হিসেব করি কারণ এতে সময় লাগবে O(n²) — যা ধীর এবং অকার্যকর।

সেজন্য আমরা প্রথমে সম্পূর্ণ array-টির total sum বের করবো।

এরপর প্রতিটি index-এ যাওয়া অবস্থায় হিসেব করবো:

ini
Copy
Edit
right_sum = total_sum - left_sum - nums[i]
এটা করার মাধ্যমে আমরা খুব সহজেই প্রতিটি index-এ left এবং right sum বের করতে পারি O(n) টাইমে।

🔢 ধাপে ধাপে উদাহরণ দিয়ে বোঝানো:
উদাহরণ:
cpp
Copy
Edit
nums = [1, 7, 3, 6, 5, 6]
Step 1: Total Sum বের করো

cpp
Copy
Edit
total_sum = 1 + 7 + 3 + 6 + 5 + 6 = 28
Step 2: Loop চালাও এবং প্রতিটি index-এ চেক করো

cpp
Copy
Edit
left_sum = 0

i = 0:
  right_sum = 28 - 0 - 1 = 27  => না

i = 1:
  left_sum = 1
  right_sum = 28 - 1 - 7 = 20  => না

i = 2:
  left_sum = 8
  right_sum = 28 - 8 - 3 = 17  => না

i = 3:
  left_sum = 11
  right_sum = 28 - 11 - 6 = 11 => ✅ মিলেছে!
সুতরাং, pivot index = 3

🧠 কেন এই কৌশল কাজ করে?
আমরা শুধু একবার পুরো অ্যারে স্ক্যান করে total_sum বের করি। এরপর একবার মাত্র লুপ চালিয়ে left_sum আপডেট করতে করতে যাচ্ছি।

প্রতিবারে right_sum = total_sum - left_sum - current_element

এই কৌশলটা হলো prefix sum ভিত্তিক Constant Time Right Sum Calculation — অর্থাৎ, right_sum বার বার হিসেব না করে এক রকমের shortcut ব্যবহার করা হয়েছে।

💻 কোড ব্যাখ্যা (Line by Line):
cpp
Copy
Edit
class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    { 
        int totalsum = 0;  // পুরো array-র sum রাখবে
        int leftsum = 0;   // প্রতিটি index-এ যাওয়ার সময় তার বাম দিকের যোগফল

        // 1. Total sum বের করা
        for(int i = 0; i < nums.size(); i++)
        {
            totalsum += nums[i];
        }

        // 2. প্রতিটি index-এ চেক করা
        for(int j = 0; j < nums.size(); j++)
        {
            int rightsum = totalsum - leftsum - nums[j]; // ডান পাশের যোগফল
            
            if(leftsum == rightsum)
            {
                return j; // pivot index পেয়ে গেলে সঙ্গে সঙ্গে return
            }

            leftsum += nums[j]; // পরবর্তী index-এর জন্য left sum আপডেট
        }

        return -1; // না পেলে -1 return
    }
};
✅ Accepted কেন হচ্ছে?
সময় জটিলতা: O(n) (একবার সম্পূর্ণ traverse)

স্থান জটিলতা: O(1) (কোনো অতিরিক্ত array ব্যবহার হয়নি)

Efficient ও Simple হওয়ায় LeetCode-এর Time Limit ও Constraint ঠিকমতো satisfy করছে।

🧪 টেস্ট কেস চালিয়ে দেখা যাক:
Input 1:
cpp
Copy
Edit
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Input 2:
cpp
Copy
Edit
nums = [1, 2, 3]
Output: -1
Input 3:
cpp
Copy
Edit
nums = [2, 1, -1]
Output: 0
✅ উপসংহার:
এই সমস্যায় যেটা আমরা শিখলাম:

Pivot index মানে এক ধরনের balance point

Prefix sum কৌশল ব্যবহার করে একদম efficient ভাবে দুই পাশের যোগফল বের করা যায়

Total sum - left sum - current = right sum এটা বুঝতে পারা মানেই প্রবলেমটা বোঝা

Full Code:
-----------

  class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    { 
     int totalsum=0;
     int leftsum=0;
     int rightsum;
     int pivot=-1;
     for(int i=0;i<nums.size();i++)
     {
      totalsum+=nums[i];
     }
     for(int j=0;j<nums.size();j++)
     {
      //leftsum+=nums[j];
      rightsum=totalsum-leftsum-nums[j];
      if(leftsum==rightsum)
      {
       pivot=j;
        break;
      }
        leftsum += nums[j];
     }
     return pivot;
    }
      
};
