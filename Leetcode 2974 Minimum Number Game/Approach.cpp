প্রথমে প্রশ্নের বিশ্লেষণ (Problem Understanding)

তোমাকে দেওয়া হয়েছে:

nums — একটি even length array।

খেলার নিয়ম (Game rules):

প্রতি রাউন্ডে:

Alice প্রথমে nums থেকে minimum element remove করবে।

তারপর Bob minimum element remove করবে।

তারপর append করতে হবে arr-এ:

Bob তার remove করা element প্রথমে append করবে।

Alice তার remove করা element দ্বিতীয়ে append করবে।

এইভাবে চলতে থাকবে যতক্ষণ nums খালি না হয়।

উদাহরণ 1:

nums = [5,4,2,3]
Round 1:
- Alice removes min: 2
- Bob removes min: 3
- arr: [3, 2]

Round 2:
- Alice removes min: 4
- Bob removes min: 5
- arr: [3, 2, 5, 4]


আমরা চাই final arr = [3, 2, 5, 4]

তোমার সলিউশনের ভাবনা (Thinking Approach)

আমরা চাই প্রতি রাউন্ডে সর্বনিম্ন 2টি সংখ্যা remove করতে।

তাদের order-এ arr-এ push করতে হবে: Bob এর value আগে, Alice এর value পরে।

priority_queue ব্যবহার করে minimum number efficient remove করা যায়।

Step-by-step সলিউশন
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        vector<int> v; // এটা হবে আমাদের answer array arr
        priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap

        // সব nums এর element min-heap এ push করলাম
        for(int j = 0; j < nums.size(); j++)
        {
            minHeap.push(nums[j]);
        }

        // যতক্ষণ minHeap খালি না, প্রতিবার 2 element remove করব
        while(!minHeap.empty() && minHeap.size() >= 2)
        {
            int top1 = minHeap.top(); // min element (Alice remove)
            minHeap.pop();

            int top2 = minHeap.top(); // next min element (Bob remove)
            minHeap.pop();

            // push করার order: Bob এর পরে Alice
            v.push_back(top2);
            v.push_back(top1);
        }

        return v;
    }
};

Step-by-step Bangla ব্যাখ্যা

1️⃣ vector<int> v;

এটা হবে arr যেটা আমরা return করব।

2️⃣ priority_queue<int, vector<int>, greater<int>> minHeap;

এখানে আমরা minHeap তৈরি করছি।

greater<int> মানে smallest element উপর থাকবে, তাই efficiently minimum remove করা যায় O(log n)।

3️⃣ for(int j = 0; j < nums.size(); j++) minHeap.push(nums[j]);

nums array-র সব element minHeap-এ push করলাম।

এখন minHeap ready, smallest element সবসময় top-এ থাকবে।

4️⃣ while(!minHeap.empty() && minHeap.size() >= 2)

আমরা প্রতি রাউন্ডে 2টি element remove করি।

তাই loop চলবে যতক্ষণ দুই বা তার বেশি element আছে।

5️⃣ int top1 = minHeap.top(); minHeap.pop();

Alice remove করবে minimum element।

6️⃣ int top2 = minHeap.top(); minHeap.pop();

Bob remove করবে next minimum element।

7️⃣ v.push_back(top2); v.push_back(top1);

Order important!

Bob প্রথমে append করবে → top2

Alice পরে append করবে → top1

8️⃣ return v;

শেষ পর্যন্ত আমরা answer array return করি।

Mathematical/Logical Understanding

ধরো nums = [5,4,2,3]

Step 1: push সব nums → minHeap: [2,3,5,4] (heap order may vary, logically sorted: 2,3,4,5)

Round 1:

Alice removes min → top1 = 2

Bob removes min → top2 = 3

Append order → [3,2]

Round 2:

Alice removes min → top1 = 4

Bob removes min → top2 = 5

Append order → [3,2,5,4]

✅ Output matches expected

Test Case Check

1️⃣ Example 1:

nums = [5,4,2,3]
Output = [3,2,5,4]


Step by step দেখিয়েছি, correct

2️⃣ Example 2:

nums = [2,5]
- Alice removes 2
- Bob removes 5
- Append: [5,2]


✅ Output correct

3️⃣ Even Length Assumption

Problem states nums length is even → minHeap always >= 2 → while loop safe

Time Complexity Analysis

priority_queue push: O(n log n) → n elements

Remove 2 elements per round → n/2 rounds × O(log n) per pop = O(n log n)

Total complexity: O(n log n)

Space: O(n) → minHeap + answer array

Summary (Bangla)

আমরা minHeap দিয়ে efficiently minimum remove করি।

প্রতিটি রাউন্ডে:

Alice remove smallest → top1

Bob remove next smallest → top2

Append order: Bob, Alice

Loop শেষ পর্যন্ত চলবে যতক্ষণ nums খালি না হয়।

Output array arr return করি।

Full Code:
--------------

  class Solution 
{
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        vector<int>v;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int j=0;j<nums.size();j++)
        {
            minHeap.push(nums[j]);
        }
        while(!minHeap.empty()&&minHeap.size()>=2)
        {
            int top1=minHeap.top();
             
            minHeap.pop();
            int top2=minHeap.top();
            minHeap.pop();
              v.push_back(top2);
               v.push_back(top1);
          

        }
        return v;
    }
};
