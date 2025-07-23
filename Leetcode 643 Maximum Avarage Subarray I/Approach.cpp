✅ Problem Summary (Bangla):
তোমাকে একটি integer array nums দেওয়া আছে এবং একটি integer k দেওয়া আছে।
তোমার কাজ হলো — এমন একটি contiguous subarray খুঁজে বের করা যার দৈর্ঘ্য k, এবং যার average value সর্বোচ্চ। তারপর সেই maximum average রিটার্ন করতে হবে।

✅ Example:
Input:
nums = [1, 12, -5, -6, 50, 3], k = 4

Explanation:
আমরা যেসব subarray পেতে পারি যার দৈর্ঘ্য 4:

[1, 12, -5, -6] → sum = 2 → avg = 0.5

[12, -5, -6, 50] → sum = 51 → avg = 12.75 ✅

[-5, -6, 50, 3] → sum = 42 → avg = 10.5

Maximum average = 12.75

✅ কিভাবে চিন্তা করবে এই প্রশ্ন সমাধানে?
🔍 Step-by-step চিন্তাভাবনা:
কী চাইছে প্রশ্নে?
→ length = k এর সব possible subarray গুলোর average বের করতে হবে।
→ তারপর, যেটার average সর্বোচ্চ সেটি রিটার্ন করতে হবে।

Brute-force করলে কী হবে?
প্রতিটি k-length subarray ধরে ধরে average বের করবো → time complexity: O(n × k)
কিন্তু n হতে পারে 10⁵ পর্যন্ত, তাই এই পদ্ধতিতে Time Limit Exceeded হবে।

Efficient উপায় কী?
আমরা জানি যে fixed size subarray এর ক্ষেত্রে আমরা Sliding Window Technique ব্যবহার করতে পারি।

✅ Sliding Window Technique ব্যাখ্যা (Bangla):
🎯 উদ্দেশ্য:
প্রথমে k উপাদান নিয়ে একটি window তৈরি করো। এরপর একধাপে একঘর করে ডানে সরাও, এবং সর্বোচ্চ sum (বা average) রাখো।

✨ Time Complexity:
O(n) → পুরো অ্যারে একবারই স্ক্যান করছি।

✅ Code + Line by Line Bangla Explanation:
cpp
Copy
Edit
class Solution 
{
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int sum = 0;
🔸 এখানে আমরা প্রথমে k elements এর জন্য sum বের করবো।

cpp
Copy
Edit
        for (int i = 0; i < k; i++) 
        {
            sum += nums[i]; // প্রথম k উপাদান যোগ করছি
        }
🔸 এবার আমরা sum এর মান দিয়ে শুরু করলাম maxsum।

cpp
Copy
Edit
        int maxsum = sum;
🔸 এখন আমরা sliding window শুরু করবো index k থেকে:

cpp
Copy
Edit
        for (int j = k; j < nums.size(); j++) 
        {
            sum += nums[j] - nums[j - k]; // নতুন element যোগ করছি, পুরাতন বাদ দিচ্ছি
            maxsum = std::max(sum, maxsum); // সর্বোচ্চ sum হালনাগাদ করছি
        }
🔸 শেষে average বের করছি:

cpp
Copy
Edit
        double ans = (double)maxsum / k;
        return ans;
    }
};
✅ Test Case Walkthrough (nums = [1,12,-5,-6,50,3], k = 4):
Step 1:
sum = 1 + 12 + (-5) + (-6) = 2 → maxsum = 2

Step 2:
j = 4 → new element = 50, remove = 1
sum = 2 + 50 - 1 = 51 → maxsum = max(2, 51) = 51

Step 3:
j = 5 → new element = 3, remove = 12
sum = 51 + 3 - 12 = 42 → maxsum = max(51, 42) = 51

শেষে average = 51 / 4 = 12.75

✅ কেন এই সমাধান Accepted?
O(n) time এবং O(1) space → Efficient

Sliding window এমন সমস্যার জন্য পারফেক্ট যেখানে fixed-length subarray নিয়ে কাজ করতে হয়

Brute-force এর তুলনায় অনেক দ্রুত এবং সীমা পেরোয় না

✅ কোন Technique ইউজ করা হয়েছে?
Sliding Window Technique → যখন contiguous fixed-size subarray এর মধ্যে maximum/minimum/sum/average বের করতে হয়

Full Code:
-----------

  class Solution 
{
public:

    double findMaxAverage(vector<int>& nums, int k) 
    {
       int sum=0;
       for(int i=0;i<k;i++)
       {
        sum+=nums[i];
       }
       int maxsum=sum;
       int windowsum=sum;
       for(int j=k;j<nums.size();j++)
       {
            sum+=nums[j]-nums[j-k];
            maxsum=std::max(sum,maxsum);
       }
       double ans=(double)maxsum/k;
       return ans;
    }
};
