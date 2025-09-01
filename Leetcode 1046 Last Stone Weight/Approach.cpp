Problem Reading থেকে Solution Approach

Problem বুঝা:

আমাদের কাছে একটি array stones[] আছে, যেখানে প্রতিটি stone-এর weight আছে।

প্রতিবার আমরা দুটি সবচেয়ে ভারী stone নেব। ধরো, ওরা হলো x এবং y এবং x <= y।

Rules:

যদি x == y → দুটো stone ধ্বংস হবে।

যদি x != y → ছোটটি ধ্বংস হবে, বড়টির weight হবে y - x।

শেষ পর্যন্ত একটা stone বা কোনো stone না থাকলে return করতে হবে।

Key Observation:

প্রতিবার আমরা সবচেয়ে ভারী দুইটি stone নেব। এইটাই মনে রাখলে আমরা sorted array বা max-heap ব্যবহার করতে পারি।

Step 1: কিভাবে ভাবো কোডিং

Max selection প্রয়োজন।

Problem বলছে, “choose heaviest two stones”.

তাই sorted array বা max-heap (priority_queue) ব্যবহার করাই সহজ।

While loop until one or zero stones left।

যতক্ষণ pq.size() > 1, আমরা loop চালাবো।

pq.top() দিয়ে সবচেয়ে ভারী stone পাওয়া যায়।

Smash Logic:

if(top1 != top2)
    pq.push(top1 - top2);


যদি x != y → নতুন stone আবার pq তে push করতে হবে।

যদি x == y → কোন push করতে হবে না, দুইটি stone ধ্বংস হবে।

Loop শেষে

যদি pq empty না হয় → pq.top() return করো।

যদি empty → 0 return করো।

Step 2: Priority Queue ব্যবহার করার কারণ

Max selection repeated প্রয়োজন।

Priority Queue (C++ STL priority_queue) automatically descending order maintain করে।

তাই প্রতিবার O(log n) তে heaviest stone পাই।

Sorting প্রতি iteration করলে O(n log n) লাগবে, repeated sort করলে time waste।

Step 3: Dry Run Example

Input: [2,7,4,1,8,1]

pq: [8,7,4,2,1,1] → top1=8, top2=7 → push 8-7=1 → pq=[4,2,1,1,1,1]

pq: [4,2,1,1,1,1] → top1=4, top2=2 → push 2 → pq=[2,1,1,1,1]

pq: [2,1,1,1,1] → top1=2, top2=1 → push 1 → pq=[1,1,1,1]

pq: [1,1,1,1] → top1=1, top2=1 → equal → push nothing → pq=[1,1]

pq: [1,1] → top1=1, top2=1 → equal → push nothing → pq=[ ]

Loop ends → pq empty → last stone = 0

Correction: Dry run shows final stone=1, কারণ pq শেষ পর্যায়ে [1] থাকে।

Step 4: কোড Accepted হওয়ার কারণ

Priority Queue ব্যবহার → efficient O(n log n)

Smash logic exactly question অনুযায়ী implement করা হয়েছে।

Edge case: single stone বা empty handled।

Constraints small (n<=30), so complexity acceptable।

Step 5: Summary in Bangla

Problem-কে heaviest selection ও smash rules হিসেবে চিন্তা করো।

Max-heap (priority_queue) সবচেয়ে natural choice।

Loop until pq.size()>1, top1 & top2 নাও, smash করো।

Push নতুন weight back if needed।

Loop শেষে check pq.empty() → return top() or 0।

💡 Tip:

যে problem repeated max selection বা min selection চায়, সেখানে priority queue use করা competitive programming এ standard।

Stone smashing type problem → “last remaining element after pair operations” → always think heap / pq / greedy approach।


  Full Code:
----------

  class Solution
 {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
       // sort(stones.begin(),stones.end());
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1)
        {
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
        //   if(pq.size()==1) break;
               /*if(top1==top2)
               {
                top1=0;
                top2=0;
               }
               */
               if(top1!=top2)
               {
              int x=top1-top2;
                pq.push(x);
              
               }
            int size=pq.size();
          //  size-=2;

        }
        if(!pq.empty())
         return pq.top();
         else
   return 0;
    }
};
