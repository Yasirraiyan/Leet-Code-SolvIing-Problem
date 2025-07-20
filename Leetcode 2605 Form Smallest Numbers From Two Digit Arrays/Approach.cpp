🔶 Problem Statement Summary (Bangla):
তোমাকে দুটি অ্যারে দেওয়া আছে nums1 এবং nums2, যেখানে প্রতিটি অ্যারেতে ইউনিক ডিজিট (1-9 এর মধ্যে) আছে। তোমার কাজ হলো এমন একটি ছোটতম সংখ্যা বের করা যা কমপক্ষে একটি ডিজিট nums1 থেকে এবং একটি ডিজিট nums2 থেকে রাখে।

🔷 উদাহরণ:
cpp
Copy
Edit
nums1 = [4,1,3], nums2 = [5,7]
→ উত্তর: 15 (1 nums1 থেকে, 5 nums2 থেকে)
nums1 = [3,5,2,6], nums2 = [3,1,7]
→ উত্তর: 3 (উভয় অ্যারেতে আছে)
🔶 কীভাবে চিন্তা করবে (Approach Thinking in Bangla):
✅ Step 1:
দুই অ্যারেতেই যদি একই ডিজিট থাকে (যেমন 3), তাহলে সেটা সরাসরি উত্তর কারণ এটা দুই অ্যারেরই digit।

✅ Step 2:
না থাকলে, তখন তোমাকে nums1 থেকে সবচেয়ে ছোট digit এবং nums2 থেকে সবচেয়ে ছোট digit নিয়ে দুইটা সংখ্যার কম্বিনেশন বানাতে হবে — a*10 + b এবং b*10 + a। এদের মধ্যে যেটা ছোট সেটা হবে উত্তর।

🔷 Full Code with Step-by-Step Bangla Explanation:
cpp
Copy
Edit
class Solution 
{
public:
    // এই ফাংশনটি একটি অ্যারে থেকে সবচেয়ে ছোট ডিজিট বের করে
    int findMin(const vector<int>& arr) 
    {
        int mini = arr[0]; // প্রথম উপাদানকে ছোট ধরে নিচ্ছি

        for (int i = 1; i < arr.size(); i++) 
        {
            if (arr[i] < mini) {
                mini = arr[i]; // যদি তার চেয়ে ছোট কিছু পাই, সেটাই রাখি
            }
        }

        return mini; // সবচেয়ে ছোট উপাদান ফেরত দাও
    }

    int minNumber(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> set1;       // nums1-এর সব ডিজিট এখানে রাখব
        vector<int> commonDigits;      // দুই অ্যারেতে মিল আছে এমন ডিজিট
        int ans;

        // Step 1: nums1-এর সব উপাদান set-এ রাখি যাতে দ্রুত খুঁজে পাওয়া যায়
        for (int j = 0; j < nums1.size(); j++)
        {
            set1.insert(nums1[j]);
        }

        // Step 2: nums2-এর প্রতিটি উপাদান চেক করি nums1-এ আছে কিনা
        for (int k = 0; k < nums2.size(); k++)
        {
            if (set1.find(nums2[k]) != set1.end())
            {
                // দুই অ্যারেতে থাকা ডিজিট commonDigits-এ রাখি
                commonDigits.push_back(nums2[k]);
            }
        }

        // Step 3: যদি commonDigits ফাঁকা না হয়, তাহলে তার মধ্যে সবচেয়ে ছোটটাই উত্তর
        if (!commonDigits.empty())
        {
            ans = findMin(commonDigits);
        }
        else
        {
            // Otherwise, nums1 ও nums2 থেকে সবচেয়ে ছোট দুটি ডিজিট নিই
            int a = findMin(nums1);
            int b = findMin(nums2);

            // দুইভাবে কম্বিনেশন বানিয়ে ছোটটা রাখি
            if (a < b)
            {
                ans = a * 10 + b;
            }
            else
            {
                ans = b * 10 + a;
            }
        }

        return ans;
    }
};
🔶 কেন এই Solution Accepted হয়:
✅ Time Complexity: O(n + m), যেখানে n = nums1.size() এবং m = nums2.size()।

✅ Space Complexity: O(n) — কারণ আমরা একটা set ব্যবহার করেছি।

✅ Efficient কারণ আমরা দুই অ্যারেতে একবার করে traversal করেছি।

✅ Constraints ছোট (≤9) তাই brute-force বা sort দরকার হয়নি।

✅ সঠিকভাবে common digit থাকলে সেটাই return করছি — আর না থাকলে combination করে smallest বানাচ্ছি।

✅ Extra Test Cases:
cpp
Copy
Edit
nums1 = [2, 5, 8], nums2 = [1, 3]
→ common নেই → মিন(2,1) = 1, 2 → 12 or 21 → 12 ✅

nums1 = [9], nums2 = [9]
→ common = 9 → ✅

nums1 = [1,2,3,4,5,6,7,8,9], nums2 = [9]
→ common = 9 → ✅
🔚 উপসংহার (Conclusion in Bangla):
এই সমস্যা সমাধানে আমরা দুইটা কৌশল একসাথে ব্যবহার করেছি:

প্রথমে common digit খুঁজি।

যদি না পাই, তাহলে দুইটা অ্যারে থেকে সবচেয়ে ছোট digit নিয়ে সবথেকে ছোট দুই digit-সংখ্যা বানাই।


  Full Code:
----------------

  class Solution 
{
public:
 int findMin(const vector<int>& arr) 
 {
    int mini = arr[0]; // Assume first element is minimum

    for (int i = 1; i < arr.size(); i++) 
    {
        if (arr[i] < mini) {
            mini = arr[i]; // Update if a smaller value is found
        }
    }

    return mini;
}
    int minNumber(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int>set1;
        vector<int>reserve;
        vector<int>v;
        int ans;
       
        for(int j=0;j<nums1.size();j++)
        {
          set1.insert(nums1[j]);
        }
        for(int k=0;k<nums2.size();k++)
        {
            if(set1.find(nums2[k])!=set1.end())
            {
                reserve.push_back(nums2[k]);
            }
            
          
        }
        if(!reserve.empty())
        {

        
      ans=findMin(reserve);
        }
        else{
        int a;
        int b;
        a=findMin(nums1);
         b=findMin(nums2);
      if(a<b)
      {
        ans=a*10+b;
      }
      else if(a>b)
      {
        ans=b*10+a;
      }
        }
      return ans;
    }
};
