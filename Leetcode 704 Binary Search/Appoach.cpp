তুমি যে কোডটি লিখেছো সেটা হলো Binary Search Algorithm এর ক্লাসিক ইমপ্লিমেন্টেশন, এবং এটা সঠিকভাবে কাজ করে। নিচে আমি line-by-line Bangla explanation দিবো, সাথে গাণিতিক ব্যাখ্যা, উদাহরণ, এবং কেন low = mid + 1 এবং high = mid - 1 হয় তার ব্যাখ্যাও দিবো।

🔢 কোডঃ
cpp
Copy
Edit
class Solution 
{
public: 
    int search(vector<int>& nums, int target) 
    {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
};
📘 Line-by-Line Bangla Explanation:
🔹 int low=0;
🔸 খোঁজ শুরু হবে অ্যারের শুরু থেকে, তাই low রাখলাম 0-তে।

🔹 int high=nums.size()-1;
🔸 খোঁজ শেষ হবে অ্যারের শেষ পর্যন্ত, তাই high রাখলাম size - 1 (যেহেতু index 0 থেকে শুরু হয়)।

🔄 while(low<=high)
🔸 যতক্ষণ low এবং high এর মাঝে খোঁজার জায়গা আছে, খোঁজা চলবে।
🔸 যখন low > high হয়ে যাবে, তখন বুঝবো খোঁজার জায়গা শেষ — মানে target নাই।

🔹 int mid=low+(high-low)/2;
🔸 এটা হলো মাঝখানের ইনডেক্স বের করার উপায়।
🔸 যদি low = 2 এবং high = 6 হয়,

ini
Copy
Edit
mid = 2 + (6 - 2)/2 = 2 + 4/2 = 4
🔸 কেন low + (high - low)/2?
➡️ কারণ যদি low আর high অনেক বড় সংখ্যা হয়, তাহলে low + high করলে overflow হতে পারে।

🔹 if(nums[mid]==target)
🔸 যদি মাঝখানে থাকা উপাদানটা target এর সমান হয়, তাহলে সোজা mid রিটার্ন করবো। খুঁজে পাওয়া গেছে।

🔹 if(nums[mid]<target)
🔸 যদি মাঝখানের মান target থেকে ছোট হয়, তাহলে বুঝবো target ডান পাশে আছে।

উদাহরণ:
text
Copy
Edit
nums = [1, 3, 5, 7, 9]
target = 9
low = 0, high = 4 → mid = 2 → nums[2] = 5 < 9
➡️ তাহলে খোঁজ করার দরকার শুধু ডান পাশে:

text
Copy
Edit
low = mid + 1 = 3
🔸 তাই করি low = mid + 1

🔹 else → high = mid - 1;
🔸 যদি nums[mid] > target, তাহলে বুঝবো target বাম পাশে আছে।

উদাহরণ:
text
Copy
Edit
nums = [1, 3, 5, 7, 9]
target = 3
low = 0, high = 4 → mid = 2 → nums[2] = 5 > 3
➡️ তাহলে খোঁজ করার দরকার শুধু বাম পাশে:

text
Copy
Edit
high = mid - 1 = 1
🔸 তাই করি high = mid - 1

🔚 return -1;
🔸 যদি কখনও nums[mid] == target না হয়, এবং low > high হয়ে যায়, তাহলে বুঝবো target নাই, তাই -1 রিটার্ন করবো।

🔢 গাণিতিকভাবে ব্যাখ্যা (Binary Search Logic):
Binary Search = প্রতিবার search space অর্ধেক করে।

ধরো তোমার কাছে অ্যারে আছে 16 সাইজের। তাহলে প্রথমবারেই তুমি 8 নম্বর ইনডেক্সে গিয়ে চেক করবে।

যদি না মেলে, তুমি 8 এর ডানে বা বামে যাবে। অর্থাৎ অর্ধেক বাদ যাবে।

সেজন্য Binary Search এর টাইম কমপ্লেক্সিটি হয়:
O(log₂N)

✅ কেন Accepted হয়:
Input size বড় হলেও প্রতি ধাপে অর্ধেক বাদ দিয়ে দিচ্ছি।

Search space efficiently narrow করছি low = mid + 1 এবং high = mid - 1 দিয়ে।

Edge cases যেমন:

1টি উপাদান

target প্রথমে বা শেষে আছে

target নেই

সবই handle করে এই কোড।

🎯 Example Walkthrough:
text
Copy
Edit
nums = [2, 4, 6, 8, 10, 12]
target = 10

Step 1: low = 0, high = 5 → mid = 2 → nums[2] = 6 < 10 → low = 3
Step 2: low = 3, high = 5 → mid = 4 → nums[4] = 10 → return 4
🧠 Binary Search মূল ভাবনা:
Binary Search চলে একটা রেঞ্জে – যেটা আমরা ধরে নিই [low, high]
➡️ এই রেঞ্জের ভিতরে আমরা জানি, target যদি থাকে, তাহলে এই রেঞ্জের মধ্যেই থাকবে।

🔁 কনসেপ্ট: [low, high] Range এ কাজ হচ্ছে
আমরা প্রতি স্টেপে এই রেঞ্জে একটা mid বের করি।

তারপর nums[mid] এর সাথে target compare করি।

✅ যদি nums[mid] == target:
➡️ মিল পেয়ে গেছি, return mid

✅ যদি nums[mid] < target হয়:
আমাদের current range: [low, high]

আমরা mid বের করলাম: mid = (low + high)/2

এখন যেহেতু nums[mid] < target, আমরা নিশ্চিত যে:

target কখনোই mid বা তার বামের মধ্যে থাকবে না

কারণ nums[mid] এর মান target এর চেয়ে ছোট

তাহলে target থাকলে এই রেঞ্জে থাকবে:

csharp
Copy
Edit
[mid + 1, high]  ✅
➡️ তাই আমরা করিঃ

cpp
Copy
Edit
low = mid + 1;
🔸 mid বাদ দিচ্ছি, কারণ mid তো আগেই চেক করে ফেলেছি — আর সেটা target না, এটা আমরা জানি।

✅ যদি nums[mid] > target হয়:
তখন target mid এর চেয়ে ছোট মানে বাম পাশে থাকতে পারে

তাহলে আমাদের search range হবে:

csharp
Copy
Edit
[low, mid - 1] ✅
➡️ তাই আমরা করিঃ

cpp
Copy
Edit
high = mid - 1;
🔸 mid বাদ দিচ্ছি, কারণ mid চেক করা হয়ে গেছে — কিন্তু ওটা target না, কারণ সেটা বড়।

📊 চল দেখি রেঞ্জ কিভাবে ছোট হয় (Efficiency Proof)
ধরো,

cpp
Copy
Edit
nums = [1, 3, 5, 7, 9, 11, 13, 15]
target = 13
Initial:

makefile
Copy
Edit
low = 0, high = 7
Range = [0, 7]
mid = 3 → nums[3] = 7 < 13
➡️ target must be in [4, 7] → low = mid + 1 = 4
Next:

makefile
Copy
Edit
low = 4, high = 7
mid = 5 → nums[5] = 11 < 13
➡️ target must be in [6, 7] → low = mid + 1 = 6
Next:

ini
Copy
Edit
low = 6, high = 7
mid = 6 → nums[6] = 13 == target → found
দেখো কীভাবে প্রতিবার search space অর্ধেক হচ্ছে:
css
Copy
Edit
[0,7] → [4,7] → [6,7] → found
🔍 যদি আমরা low = mid করতাম?
তাহলে একই mid বারবার চেক হতে পারত।

Example:

text
Copy
Edit
low = 6, high = 7
mid = 6

nums[6] = 13 < 15 → low = mid (wrong!) → আবার mid = 6 হবে → stuck!
➡️ তাই low = mid + 1 না করলে infinite loop হতে পারে।

🧾 Summary Table:
Condition	Logic	Action	Reason
nums[mid] == target	Match	return mid	Target found
nums[mid] < target	Right	low = mid+1	Mid এর ডানে থাকতে পারে, mid বাদ
nums[mid] > target	Left	high=mid-1	Mid এর বামে থাকতে পারে, mid বাদ

✅ Binary Search Efficiency:
প্রতি ধাপে [low, high] রেঞ্জ অর্ধেক হয়ে যায়

তাই time complexity হয় O(log₂N)

Efficiency আসে এই mid+1 আর mid-1 এর মাধ্যমে checked value বাদ দেয়ার জন্য
→ কারণ Binary Search already checked value নিয়ে আর কাজ করে না

🔚 শেষ কথা:
🔁 আমরা low = mid+1 করি কারণ আমরা mid আগেই check করে ফেলেছি এবং বুঝেছি target ডান পাশে। তাই mid বাদ দিয়ে ডানে যাই — [mid+1, high]
🔁 আমরা high = mid-1 করি কারণ mid আগেই check করা হয়েছে এবং বুঝেছি target বাম পাশে। তাই mid বাদ দিয়ে বামে যাই — [low, mid-1]


Full Code:
-----------

  class Solution 
{
public: 
    int search(vector<int>& nums, int target) 
    {
     
      int low=0;
      int high=nums.size()-1;
      while(low<=high)
      {
        int mid=low+(high-low)/2;
        if(nums[mid]==target)
        {
          return mid;
        }
        if(nums[mid]<target)
        {
          low=mid+1;
        }
        else
        {
          high=mid-1;
        }
      }
      return -1;
    }
};
