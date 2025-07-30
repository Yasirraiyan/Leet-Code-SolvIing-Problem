🔍 প্রশ্ন বিশ্লেষণ (Problem Understanding)
প্রশ্ন বলছে:

একটা nums[] integer অ্যারে দেওয়া আছে।
আমাদের এমন একটা সবচেয়ে ছোট index i খুঁজে বের করতে হবে যেন nums[i] এর digit sum = i হয়।
না থাকলে -1 return করতে হবে।

✅ উদাহরণ ১: nums = [1, 3, 2]
i = 0 → digit sum of 1 = 1 ≠ 0 ❌

i = 1 → digit sum of 3 = 3 ≠ 1 ❌

i = 2 → digit sum of 2 = 2 ✅

Output → 2

✅ উদাহরণ ২: nums = [1, 10, 11]
i = 0 → 1 → digit sum = 1 ≠ 0 ❌

i = 1 → 10 → 1+0 = 1 ✅

i = 2 → 11 → 1+1 = 2 ✅
Smallest index = 1

🧠 চিন্তা করার পদ্ধতি (Thinking Process)
প্রতি ইন্ডেক্স i তে গিয়ে nums[i] এর digit sum বের করো।

যদি সেই digit sum == i হয়, তাহলে এটিই উত্তর।

প্রথম যেই i এর ক্ষেত্রে মিল পাবে, সেটাই সবচেয়ে ছোট হবে।

কোনো index না মিলে গেলে -1 return করো।

✅ কোড ব্যাখ্যা ধাপে ধাপে বাংলায়
cpp
Copy
Edit
class Solution 
{
public:
একটা Solution ক্লাস বানানো হয়েছে।

🔹 Digit Sum Calculator Function
cpp
Copy
Edit
int CalculateDigitSum(int n)
{
  int sum = 0;
  while(n > 0)
  {
    int rem = n % 10;
    sum += rem;
    n = n / 10;
  }
  return sum;
}
🔸 এই ফাংশনটি একটি সংখ্যার digit sum বের করে।
যেমনঃ 123 → 1+2+3 = 6

🔹 Main Function: Smallest Index Checker
cpp
Copy
Edit
int smallestIndex(vector<int>& nums) 
{
    int ans = -1;
প্রথমে ধরছি, কোনো মিল নাই — তাই ans = -1

cpp
Copy
Edit
    for(int i = 0; i < nums.size(); i++)
    {
        if(CalculateDigitSum(nums[i]) == i)
        {
            ans = i;
            break;
        }
    }
🔸 প্রতিটি index i এর জন্য:

nums[i] এর digit sum বের করি।

যদি সেই sum == i হয়, তাহলে সেটিই উত্তর।

যেহেতু প্রথম মিল পেলেই বের হয়ে যাই (break), তাই সবচেয়ে ছোট index টাই পাওয়া যাবে।

cpp
Copy
Edit
    return ans;
}
শেষে উত্তর return করো।

✅ Test Case চেকিং — ধাপে ধাপে Bangla বিশ্লেষণ
🧪 Test Case 1:
cpp
Copy
Edit
nums = [1, 3, 2]
i = 0 → digit sum(1) = 1 ≠ 0 ❌

i = 1 → digit sum(3) = 3 ≠ 1 ❌

i = 2 → digit sum(2) = 2 ✅ → Return 2

🧪 Test Case 2:
cpp
Copy
Edit
nums = [1, 10, 11]
i = 0 → digit sum(1) = 1 ≠ 0 ❌

i = 1 → digit sum(10) = 1+0 = 1 ✅ → Return 1 (earliest match)

🧪 Test Case 3:
cpp
Copy
Edit
nums = [1, 2, 3]
i = 0 → digit sum(1) = 1 ≠ 0 ❌

i = 1 → digit sum(2) = 2 ≠ 1 ❌

i = 2 → digit sum(3) = 3 ≠ 2 ❌
→ কোনো মিল নাই → Return -1

⏱️ Time & Space Complexity
বিষয়	মান
Time	O(n * D) → যেখানে D = digit count of nums[i]
Space	O(1)

✅ কেন তোমার কোড Accepted হলো?
✅ Efficient loop

✅ সঠিক digit sum function

✅ প্রথম match পাওয়ার পরই break করছো → minimal index পাচ্ছো

✅ Edge case handled → -1 return করা হয়েছে

🔚 সংক্ষেপে
ধাপ	কাজ
Step 1	প্রতি index i এর জন্য nums[i] এর digit sum বের করো
Step 2	যদি digit sum == i হয় → return i
Step 3	কোনো match না থাকলে → return -1

  Full Code:
------------

  class Solution 
{
public:
int CalculateDigitSum(int n)
{
  int sum=0;
  while(n>0)
  {
    int rem=n%10;
    sum+=rem;
    n=n/10;
  }
  return sum;
}
    int smallestIndex(vector<int>& nums) 
    {
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
          if(CalculateDigitSum(nums[i])==i)
          {
            ans=i;
            break;
          }
        }
        return ans;
    }
};
