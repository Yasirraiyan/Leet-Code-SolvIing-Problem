🧠 সমস্যার বিশ্লেষণ (Problem Analysis in Bangla)
প্রতিটি index i-র জন্য একটি subarray তৈরি করতে হবে যেটার শুরু start = max(0, i - nums[i]) থেকে এবং শেষ i পর্যন্ত।
তারপর, ঐ subarray-র সবগুলো উপাদানের যোগফল বের করে সবগুলো index-এর জন্য যোগ করতে হবে।

🔍 উদাহরণ বিশ্লেষণ (Example Analysis)
Input: nums = [2, 3, 1]
চল তোমরা একেকটা index দেখে দেখি কী হয়:

i	nums[i]	start = max(0, i - nums[i])	Subarray	Sum
0	2	max(0, 0 - 2) = 0	nums[0] = [2]	2
1	3	max(0, 1 - 3) = 0	nums[0..1] = [2, 3]	5
2	1	max(0, 2 - 1) = 1	nums[1..2] = [3, 1]	4

👉 মোট যোগফল = 2 + 5 + 4 = 11

✅ সমাধানের পদ্ধতি (Approach Explanation in Bangla)
Step-by-step:
প্রতিটি index i-র জন্য start = max(0, i - nums[i]) বের করো।

তারপর start থেকে i পর্যন্ত subarray-এর সব উপাদানের যোগফল বের করো।

প্রত্যেকটি index এর জন্য এই sum যোগ করো total ভেরিয়েবলে।

✅ কোড ব্যাখ্যা (Code Explanation in Bangla)
cpp
Copy
Edit
class Solution {
public:
   // সাবঅ্যারে-র যোগফল বের করার হেলপার ফাংশন
   int sum(int start, int end, vector<int>& nums)
   {
     int sum = 0;
     for (int j = start; j <= end; j++)
     {
        sum += nums[j];
     }
     return sum;
   }

   // মূল ফাংশন
   int subarraySum(vector<int>& nums) {
       int total = 0;
       int start;
       
       for (int i = 0; i < nums.size(); i++)
       {
         // সাবঅ্যারে-র শুরু নির্ধারণ
         start = std::max(0, i - nums[i]);
         
         // সাবঅ্যারে যোগ করে মোট যোগফলে যোগ করা
         total += sum(start, i, nums);
       } 

       return total;
   }
};
🧪 উদাহরণ দিয়ে কোড টেস্ট (Test with Example)
cpp
Copy
Edit
int main() {
    Solution obj;
    vector<int> nums1 = {2, 3, 1};
    cout << obj.subarraySum(nums1) << endl; // Output: 11

    vector<int> nums2 = {3, 1, 1, 2};
    cout << obj.subarraySum(nums2) << endl; // Output: 13

    return 0;
}
✅ কেন এই কোড Accept হয়?
Input constraint ছোট (n ≤ 100), তাই প্রতি index-এ loop চালানো এবং subarray sum বের করা performance সমস্যায় ফেলবে না।

Time Complexity: O(n^2) — কারণ প্রতিটি index-এ আবার একটা O(n) পর্যন্ত loop হচ্ছে worst case-এ।

Full Code:
----------

  class Solution {
public:
   int sum(int start,int end ,vector<int>& nums)
   {
     int sum=0;
     //start=0;
     for(int j=start;j<=end;j++)
     {
      sum+=nums[j];
     }
     return sum;
   }
    int subarraySum(vector<int>& nums) {
       int total=0;
       int start;
       for(int i=0;i<nums.size();i++)
       {
         start=std::max(0,i-nums[i]);
         total+=sum(start,i,nums);
       } 
  return total;
    }
};
