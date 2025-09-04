সমস্যা বোঝা:

আমাদের আছে nums array।

আমরা exactly k operations করতে পারব।

এক operation মানে:

একটি index i বেছে নেওয়া।

score বাড়ানো nums[i] দিয়ে।

তারপর nums[i] কে ceil(nums[i]/3) দিয়ে replace করা।

আমাদের লক্ষ্য: score maximize করা।

কী intuition আসে?

আমরা সর্বদা সেই element নেব যা largest।

কারণ বড় সংখ্যা নিলে score বেশি বাড়বে।

ছোট হলে score কম।

এটা greedy approach।

Step 1: Use Max Heap

বড় সংখ্যাকে দ্রুত access করতে max-heap ব্যবহার করব।

Heap থেকে largest element নেব, score বাড়াবো, তারপর নতুন value push করব heap-এ।

কেন?

Heap ব্যবহার করলে largest element O(log n) সময়ে পাই।

যেহেতু k ও n অনেক বড় হতে পারে (up to 10^5), direct search (O(n*k)) slow হবে।

Step 2: Code Approach (C++ style)
int maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq; // max heap
    for (int x : nums) pq.push(x);

    long long score = 0;
    while (k--) {
        int top = pq.top();
        pq.pop();
        score += top;
        pq.push((top + 2) / 3); // ceil(top/3)
    }
    return score;
}


Important Notes:

ceil(top/3) can be written as (top + 2)/3 (integer math)।

Each operation:

Largest element বের করা।

Score increase।

Reduce element & put back।

Step 3: Test Case Analysis
Example 1:
nums = [10,10,10,10,10], k = 5


Max heap: [10,10,10,10,10]

Operation 1: pick 10 → score=10 → replace 10 with 4 → heap=[10,10,10,10,4]

Operation 2: pick 10 → score=20 → replace 10 with 4 → heap=[10,10,4,4,10]

… repeat …

সব 5 operations পরে score = 50 ✅

Example 2:
nums = [1,10,3,3,3], k = 3


Max heap: [10,3,3,3,1]

Operation 1: pick 10 → score=10 → replace 10 with 4 → heap=[4,3,3,3,1]

Operation 2: pick 4 → score=14 → replace 4 with 2 → heap=[3,3,3,2,1]

Operation 3: pick 3 → score=17 → replace 3 with 1 → heap=[3,2,1,1,1]

Final score = 17 ✅

সংক্ষিপ্ত Bangla Summary:

সর্বদা largest element pick করো।

Score update করো।

Element reduce করে heap-এ push করো।

Repeat k times।

Max-heap makes it efficient, otherwise TLE হবে।

Complexity:

Full CXode:
------------

  class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
     priority_queue<int>pq;
     for(int i=0;i<nums.size();i++)
     {
        pq.push(nums[i]);
     } 
     int count=0;
     long long score=0;
     while(!pq.empty()&&count<k)  
     {
         int top=pq.top();
         score+=top;
         pq.pop();
         count++;
         pq.push((top+2)/3);
         if(count==k)
         {
            break;
         }
     }
     return score;
    }
};
