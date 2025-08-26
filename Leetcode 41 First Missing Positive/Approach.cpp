প্রশ্নের লক্ষ্য

তোমার কাছে একটি unsorted integer array আছে।
তুমি smallest positive integer বের করতে চাও যা array-এ নেই।

Constraints:

O(n) time

O(1) extra space

এখন তোমার দেওয়া কোডটা আসলে O(n) time কিন্তু O(n) extra space ব্যবহার করছে (কারণ তুমি unordered_set এবং v vector ব্যবহার করেছো)। তবে ধাপে ধাপে বোঝার জন্য এটি ভাল উদাহরণ।

Code Line by Line ব্যাখ্যা
class Solution
{
public:


এখানে আমরা Solution class declare করেছি। LeetCode বা অনুরূপ প্ল্যাটফর্মে এভাবে solution দিতে হয়।

int findmax(vector<int>& nums)
{
    int max=nums[0];
    for(int j=1;j<nums.size();j++)
    {
        if(nums[j]>max)
        {
            max=nums[j];
        }
    }
    return max;
}


findmax function: vector থেকে maximum value বের করে।

আমরা array-এ iteration করি এবং প্রতিটা element চেক করি।

int findmin(vector<int>&arr)
{
    int min=arr[0];
    for(int k=1;k<arr.size();k++)
    {
        if(arr[k]<min)
        {
            min=arr[k];
        }
    }
    return min;
}


findmin function: vector থেকে minimum value বের করে।

purpose হলো, যদি vector খালি না হয়, আমরা range-টা ঠিক করতে পারি।

int firstMissingPositive(vector<int>& nums)
{
    vector<int>v;
    for(int j=0;j<nums.size();j++)
    {
        if(nums[j]>0)
        {
            v.push_back(nums[j]);
        }
    }


এখানে আমরা একটি নতুন vector v তৈরি করেছি, যেখানে positive numbers রাখছি।

negative numbers এবং 0 এখানে রাখছি না, কারণ question শুধু positive integers চায়।

    if (v.empty()) return 1;


যদি কোনো positive number না থাকে, তাহলে smallest positive number 1।

তাই আমরা সরাসরি return করি 1।

    int max=findmax(v);
    int min=findmin(v);
    long long ans=(long long)max+1;


এখন positive numbers থেকে maximum এবং minimum বের করি।

ans initially ধরে নিলাম max+1।

কেন? যদি সব numbers continuous থাকে (1 থেকে max), তাহলে next missing positive হলো max+1।

    unordered_set<int>set1;
    for(int k=0;k<nums.size();k++)
    {
        set1.insert(nums[k]);
    }


আমরা সব numbers একটি set-এ রাখলাম।

set ব্যবহার করার কারণ হলো: O(1) lookup পেতে, কোনো number আছে কি না চেক করতে।

    for(int j=1;j<=max;j++)
    {
        if(set1.find(j)==set1.end())
        {
            ans=j;
            break;
        }
    }


1 থেকে max পর্যন্ত সব number চেক করি।

যদি কোনো number set-এ না থাকে, তাহলে সেটাই smallest missing positive।

তারপর break করি।

    return (int)ans;
}
};


অবশেষে answer return করি।

এখানে cast করা হয়েছে int-এ, কারণ আমরা long long দিয়েছিলাম overflow safe রাখার জন্য।

কোডের ভাবনা step by step

প্রথমেই positive numbers আলাদা করি।

যদি positive number না থাকে → answer 1।

অন্যথায়, maximum এবং minimum বের করি।

সব numbers একটি set-এ রাখি → fast lookup।

1 থেকে max পর্যন্ত iterate করে দেখি কোন number missing।

যদি সব number আছে → answer হলো max+1।

Test Case অনুযায়ী চলা
Example 1: [1,2,0]

Positive numbers: [1,2]

max = 2, min = 1

Set = {0,1,2}

Check 1 → আছে

Check 2 → আছে

Answer = max+1 = 3 ✅

Example 2: [3,4,-1,1]

Positive numbers: [3,4,1]

max = 4, min = 1

Set = {-1,1,3,4}

Check 1 → আছে

Check 2 → নেই → Answer = 2 ✅

Example 3: [7,8,9,11,12]

Positive numbers: [7,8,9,11,12]

max = 12, min = 7

Set = {7,8,9,11,12}

Check 1 → নেই → Answer = 1 ✅

কেন কাজ করে?

আমরা positive numbers শুধু consider করি।

যেকোনো missing number 1 থেকে max পর্যন্ত বের হয়।

যদি সব number continuous থাকে → next positive max+1।

Set usage করে lookup fast।

Full Code:
---------
  class Solution
 {
public:
 int findmax(vector<int>& nums)
 {
    int max=nums[0];
    for(int j=1;j<nums.size();j++)
    {
        if(nums[j]>max)
        {
            max=nums[j];
        }
    }
    return max;
 }
 int findmin(vector<int>&arr)
 {
    int min=arr[0];
    for(int k=1;k<arr.size();k++)
    {
        if(arr[k]<min)
        {
            min=arr[k];
        }
    }
    return min;
 }
    int firstMissingPositive(vector<int>& nums)
     {
        vector<int>v;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]>0)
            {
                v.push_back(nums[j]);
            }
        }
          if (v.empty()) return 1;
        int max=findmax(v);
        int min=findmin(v);
      long long ans=(long long)max+1;
        unordered_set<int>set1;
        for(int k=0;k<nums.size();k++)
        {
            set1.insert(nums[k]);
        }
        for(int j=1;j<=max;j++)
        {
            if(set1.find(j)==set1.end())
            {
                ans=j;
                break;
            }
        }
      return (int)ans;
    }
};
