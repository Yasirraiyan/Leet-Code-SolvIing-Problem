প্রশ্নের বোঝাপড়া

আমাদের কাছে একটি sorted integer array আছে (অর্থাৎ non-decreasing order এ sorted)।
উদাহরণ: [0,0,1,1,1,2,2,3,3,4]

আমাদের কাজ: duplicate remove করা in-place (অর্থাৎ নতুন array বানানো যাবে না, মূল array তেই কাজ করতে হবে)।

Output:

k → unique element এর সংখ্যা

nums array এর প্রথম k টি element হবে unique elements, relative order ধরে রেখে।

বাকি elements এর মান important নয়।

Approach: Two Pointer Technique

এই problem এ আমরা two-pointer approach ব্যবহার করেছি।

ধাপ ধাপে ধারণা:

Pointer i → এটা points করবে last unique element এ।

Pointer j → এটা points করবে পরবর্তি element যা check করা হবে duplicate কিনা।

কেন two-pointer?

Sorted array এ duplicate সবসময় একসাথে থাকে।

তাই আমরা একটা pointer দিয়ে last unique element track করতে পারি, আর অন্য pointer দিয়ে remaining elements check করতে পারি।

যখন একটি নতুন unique element পাই, আমরা সেটাকে i+1 index এ রাখি।

Code ব্যাখ্যা (line by line Bangla)
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
          if(nums.empty()) return 0;


প্রথমে check করি array empty কিনা।

যদি empty হয় → return 0, কারণ কোন element নেই।

        int i=0;
        int j=1;


i = 0 → প্রথম unique element এর index

j = 1 → পরবর্তী element check করার জন্য

        while(j<nums.size())
        {
            if(nums[i]==nums[j])
            {
                j++;
            }


while loop → চলবে যতক্ষণ না j array এর শেষ পর্যন্ত পৌঁছায়।

যদি nums[i] == nums[j] → মানে duplicate → আমরা শুধু j++ করি।

            else
            {
                 i++;
                 nums[i]=nums[j];
            }


যদি nums[i] != nums[j] → মানে নতুন unique element পেলাম।

i++ করি → next unique position ready করি।

nums[i] = nums[j] → নতুন unique element কে next position এ রাখি।

        int ans=i+1;
        return ans;


마지막 পর্যন্ত i index দেখায় last unique element এর index।

ans = i+1 → total unique element count।

Example Run (nums = [0,0,1,1,1,2,2,3,3,4])
i	j	nums	Explanation
0	1	[0,0,1,1,1,2,2,3,3,4]	nums[i]=0, nums[j]=0 → duplicate → j++
0	2	[0,0,1,1,1,2,2,3,3,4]	nums[i]=0, nums[j]=1 → new unique → i++ → nums[i]=nums[j] → nums=[0,1,...]
1	3	[0,1,1,1,1,2,2,3,3,4]	nums[i]=1, nums[j]=1 → duplicate → j++
1	5	[0,1,1,1,1,2,2,3,3,4]	nums[i]=1, nums[j]=2 → new unique → i++ → nums[i]=nums[j] → nums=[0,1,2,...]
...	...	...	একইভাবে শেষ পর্যন্ত nums = [0,1,2,3,4,...]

শেষ unique element এর index = 4 → ans = 5 → output

Technique Summary

Two-pointer technique → in-place duplicate removal এর জন্য perfect।

Time Complexity: O(n) → একবার array traverse করেছি।

Space Complexity: O(1) → extra space ব্যবহার হয়নি।

Key Idea:

Sorted array → duplicate সবসময় contiguous।

একটি pointer last unique track করে, আর অন্য pointer iterate করে।

New unique element পেলে i++ এবং overwrite করে।

Bangla Summary

Array sorted → easy to detect duplicates।

Two-pointer: i last unique, j scan করতে থাকবে।

Duplicate হলে skip।

নতুন unique element → next position এ write।

শেষ পর্যন্ত i+1 = unique element count।

✅ এই কারণে LeetCode test case pass করে।

Full Code:
--------------

  class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
          if(nums.empty()) return 0;
        int i=0;
        int j=1;
        while(/*i<j&&i<nums.size()&&*/j<nums.size())
        {
            if(nums[i]==nums[j])
            {
                j++;
            }
            else
            {
                 i++;
                  nums[i]=nums[j];
           
          
            }
        }
        int ans=i+1;
        return ans;
    }
};
