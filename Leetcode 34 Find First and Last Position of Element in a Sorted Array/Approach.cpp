🔶 প্রশ্ন বিশ্লেষণ (Bangla Explanation):
প্রশ্ন:
তোমাকে একটি non-decreasing (মানে increasing অথবা একই সংখ্যার পুনরাবৃত্তি থাকতে পারে) সংখ্যার array nums দেওয়া হয়েছে।
একটি target সংখ্যা দেওয়া থাকবে।
তুমি যদি target খুঁজে পাও, তাহলে ওই target-এর প্রথম এবং শেষ index রিটার্ন করতে হবে।

যদি না পাও, তাহলে [-1, -1] রিটার্ন করবে।

উদাহরণ:

pgsql
Copy
Edit
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]  // কারণ ৮ প্রথম এসেছে index 3-এ, আর শেষ index 4-এ

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1] // ৬ এই array-তে নেই
✅ কী চাইছে প্রশ্নে?
তোমাকে এমন একটি অ্যালগরিদম লিখতে হবে যেটার time complexity O(log n) হবে।

এটা শুনেই বোঝা যাচ্ছে, আমাদের Binary Search ব্যবহার করতে হবে — কারণ Binary Search-এর সময় জটিলতা O(log n)

🔁 কিভাবে চিন্তা করতে পারো?
তুমি যদি Linear Search (line by line ঘেটে দেখো) করো তাহলে Time Complexity হবে O(n), যেটা acceptable না।

Binary Search দিয়ে target আছে কিনা সেটা বের করতে পারো O(log n) এ।

কিন্তু শুধু আছে কিনা না জেনে, প্রথম এবং শেষ occurrence বের করতে হবে।
এটার জন্য তোমাকে দুটি আলাদা Binary Search করতে হবে:

একবার first occurrence খুঁজবে।

আরেকবার last occurrence খুঁজবে।

🔍 তোমার দেওয়া কোড ব্যাখ্যা (Bangla):
cpp
Copy
Edit
bool BinarySearch(vector<int>& nums, int target)
{
    // Binary Search দিয়ে check করছো target আছে কিনা
    bool find = false;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] > target)
            high = mid - 1;
        else
        {
            find = true;
            break;
        }
    }
    return find;
}
এই ফাংশন শুধু বলে দেয় target আছে কিনা।

তারপর searchRange ফাংশনে:

cpp
Copy
Edit
if (!BinarySearch(nums, target)) 
{
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}
তুমি যদি target না পাও, তাহলে [-1, -1] রিটার্ন করো।

আর যদি পাও, তখন তুমি nums array কে আবার O(n) time-এ লাইন ধরে traverse করো for loop দিয়ে — যাতে first এবং last index খুঁজে পাও।

🧪 Test Case Walkthrough:
Test 1:
cpp
Copy
Edit
nums = [5,7,7,8,8,10], target = 8
findFirst → খুঁজবে বাঁ দিক → mid = 2 → nums[2] = 7 → কম → ডানে খুঁজে
→ mid = 3 → nums[3] = 8 → match → high = mid - 1 → বাঁ দিকে খুঁজে
→ শেষ পর্যন্ত first = 3

findLast → খুঁজবে ডান দিক → mid = 2 → nums[2] = 7 → কম → ডানে
→ mid = 3 → 8 → match → low = mid + 1 → ডানে খুঁজবে
→ mid = 4 → nums[4] = 8 → match → low = mid + 1 → শেষ পর্যন্ত last = 4

Final output: [3, 4]

🔚 উপসংহার:
প্রশ্নে বলা ছিল O(log n) → তাই Binary Search দরকার।

একবার না, দু'বার Binary Search করলেই First ও Last পাওয়া যায়।

তোমার কোড accepted হলেও O(n) time নিচ্ছে — তাই উন্নত করা উচিত।

Full Code:
-----------

  class Solution 
{
public:
 bool BinarySearch(vector<int>& nums, int target)
 {
  bool find=false;
  int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
          int mid=(low+high)/2;
          if(nums[mid]<target)
          {
             low=mid+1;
          }
          if(nums[mid]>target)
          {
            high=mid-1;
          }
          if(nums[mid]==target)
          { find=true;
              break;
          }
        }
        return find;
 }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
      vector<int>ans;
      int first=-1;
      int last=-1;
          if(!BinarySearch(nums,target))
          {
              ans.push_back(-1);
              ans.push_back(-1);
              return ans;
          }
              for(int k=0;k<nums.size();k++)
              {
                if(nums[k]==target)
                {
                  if(first==-1) first=k;
                  last=k;
                }
              }
                 ans.push_back(first);
              ans.push_back(last);
        return ans;
    }
};

