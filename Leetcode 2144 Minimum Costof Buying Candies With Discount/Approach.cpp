সমস্যা সংক্ষেপে বুঝে নাও

আমাদের কাছে ক্যান্ডিগুলোর দাম আছে cost[i]।

Offer: 2 ক্যান্ডি কিনলে 3য় ক্যান্ডি ফ্রি।

কিন্তু: ফ্রি ক্যান্ডির দাম সর্বোচ্চ কিনা দুটি ক্যান্ডির মধ্যে ছোটো ক্যান্ডির দামের সমান বা কম হতে হবে।

আমাদের লক্ষ্য: সর্বনিম্ন খরচে সব ক্যান্ডি কেনা।

ধাপে ধাপে লজিক চিন্তা করা

Sort করা

আমরা প্রথমে cost array কে descending order এ sort করি।

কেন? কারণ আমরা চাই দামী ক্যান্ডি আগে কিনব, যাতে ফ্রি ক্যান্ডি সবসময় সস্তা হয়।

উদাহরণ: [1,2,3,4] → descending → [4,3,2,1]

আমরা 4 ও 3 কিনব → ফ্রি ক্যান্ডি হবে 2 (যা 4 ও 3 এর min ≤ 2, ঠিক আছে)।

Technique: Greedy (always buy the most expensive candies first to maximize discount on expensive ones)

Loop করে 3-টি ক্যান্ডি গ্রুপ করা

আমরা i index ব্যবহার করে array traverse করি।

প্রতিটি iteration এ আমরা:

int a = cost[i];          // 1ম ক্যান্ডি
int b = 0;
if(i+1<cost.size()) b = cost[i+1];   // 2য় ক্যান্ডি
int free = 0;
if(i+2<cost.size()) free = cost[i+2]; // ফ্রি ক্যান্ডি
sum += a+b; // আমরা কেবল দুইটি কিনা ক্যান্ডির দাম যোগ করি
i += 2;     // আমরা তিনটি ক্যান্ডি একবারে process করেছি


এই loop এর মাধ্যমে:

প্রথম দুটি ক্যান্ডি কিনছি → total cost এ যোগ

তৃতীয় ক্যান্ডি (যা ফ্রি) cost এ যোগ হচ্ছ না → offer এর exploit

কেন এই greedy technique accepted হলো

কারণ আমরা দামী ক্যান্ডি প্রথমে কিনছি, তাই সর্বোচ্চ দামী ক্যান্ডির খরচে ফ্রি ক্যান্ডি পাওয়া যায়।

যেহেতু ফ্রি ক্যান্ডি সবসময় ছোট বা সমান হতে হবে কিনা ক্যান্ডির সাথে, তাই descending order sort করলে আমরা সর্বদা এই শর্ত মেনে চলে।

কোন permutation বা combination ব্যর্থ হবে না।

কোডের line-by-line explanation

sort(cost.begin(),cost.end()); // cost array ascending sort
reverse(cost.begin(),cost.end()); // descending sort করা হচ্ছে, দামী ক্যান্ডি আগে


উদ্দেশ্য: দামী ক্যান্ডি আগে কিনে ফ্রি ক্যান্ডি যত কম খরচে নেওয়া যায় তা নিশ্চিত করা।

int sum=0;
for(int i=0;i<cost.size();i++) {
    int a=cost[i];          // প্রথম ক্যান্ডি
    int b=0;
    if(i+1<cost.size()) b=cost[i+1]; // দ্বিতীয় ক্যান্ডি
    int free=0;
    if(i+2<cost.size()) free=cost[i+2]; // ফ্রি ক্যান্ডি (sum এ যোগ হবে না)
    sum += a + b;           // শুধুমাত্র কেনা ক্যান্ডির দাম যোগ করা
    i+=2;                   // তিনটি ক্যান্ডি একবারে process
}
return sum;

Technique analysis

Greedy Technique

Always pick the most expensive candies first → maximize the benefit of the free candy.

Why it works

Free candy constraint: free <= min(a,b)

Descending order → a >= b >= free → সর্বদা satisfy হয়।

কোনো permutation trial দরকার নেই → O(n log n) sorting + O(n) traversal

How you can identify this approach from question

Whenever a question বলছে “buy some items and get cheapest free” → think about sorting + greedy

Constraint about “minimum of purchased items” → hint that descending sort will automatically satisfy it

Example Walkthrough
Input: [6,5,7,9,2,2]

Sort descending → [9,7,6,5,2,2]

Loop:

i=0 → buy 9,7 → free 6 → sum=16

i=3 → buy 5,2 → free 2 → sum=16+7=23

All candies processed → Answer = 23 ✅

Summary (Bangla)

প্রথমে sort descending: দামী ক্যান্ডি আগে

Loop 3-candy batch: প্রথম দুটি কিনো → তৃতীয়টি ফ্রি

Greedy works because: buying expensive candies first automatically satisfies free candy constraint

Time Complexity: O(n log n) + O(n) → efficient

Technique: Greedy + Sorting

Full Code:
----------

  class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int count=0;
        int idx=0;
        int sum=0;
        int it=idx;
        for(int i=it;i<cost.size();i++)
        {
            int a=cost[i];
            int b=0;
            int free=0;
           
            if(i+1<cost.size())
            {
          b=cost[i+1];
            }
            if(i+2<cost.size())
            {
            free=cost[i+2];
            }
            sum+=a+b;
            idx=i+2;
            if(i+3<cost.size())
            {
            it=i+3;
            }
            i+=2;
           

        }
        return sum;
    }
};
