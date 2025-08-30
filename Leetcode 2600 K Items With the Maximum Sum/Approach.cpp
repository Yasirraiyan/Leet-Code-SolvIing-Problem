১️⃣ সমস্যা বোঝা

Problem:
আমাদের কাছে একটা ব্যাগ আছে যেখানে 1, 0, এবং -1 লেখা কিছু আইটেম আছে।

numOnes সংখ্যক 1

numZeros সংখ্যক 0

numNegOnes সংখ্যক -1

আমাদের k টি আইটেম নিতে হবে যতটা সম্ভব বড় যোগফল (sum) পাওয়ার জন্য।

Example:

numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
ব্যাগ: {1, 1, 1, 0, 0}
সর্বোচ্চ যোগফল = 3 (তিনটি 1 + একটি 0)

২️⃣ সমাধানের কৌশল (Approach / Technique)
Step 1: Observation

আমরা চাই সর্বোচ্চ যোগফল, তাই সবসময় 1 এর আইটেম আগে নিব।

যদি 1 শেষ হয়ে যায় এবং এখনও k কম নেওয়া হয়, 0 নিলে sum বাড়ে না কিন্তু কমবে না।

সবশেষে যদি 1 এবং 0 শেষ হয়ে যায়, -1 নেওয়ার কোনো উপায় নেই, sum কমবে।

এটি Greedy Technique।

Greedy logic:

যতটা সম্ভব 1 নাও।

যদি k এখনও কম হয়, 0 নাও।

তারপর -1 নাও যদি প্রয়োজন হয়।

Step 2: কেন Greedy কাজ করছে

আমরা চাই sum maximize।

1 > 0 > -1

তাই সর্বোচ্চ value আইটেম আগে নেওয়াই logical।

এই ধরনের সমস্যায় sorting বা predefined priority দিয়ে greedy choice ঠিক থাকে।

৩️⃣ কোড ব্যাখ্যা (Line by line)
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        vector<int> v;
        for(int i = 0; i < numOnes; i++) v.push_back(1);      // 1 add করা
        for(int i = 0; i < numZeros; i++) v.push_back(0);     // 0 add করা
        for(int i = 0; i < numNegOnes; i++) v.push_back(-1);  // -1 add করা

        int count = 0;
        int sum = 0;
        int i = 0;

        while(count < k && i < v.size()) {
            sum += v[i];   // প্রতিটি item যোগ করা
            i++;
            count++;
        }
        return sum;
    }
};


✅ ধাপে ধাপে ব্যাখ্যা:

vector v তৈরি করা হলো যেখানে সব 1, 0, -1 sequentially রাখা হলো।

sum calculate করা হলো প্রথম k item নিয়ে।

Vector-এ 1 আগে, 0 পরে, -1 পরে রাখার কারণে প্রথম k element নেওয়া sum maximize করে।

৪️⃣ কোড কিভাবে কাজ করে টেস্ট কেসে
Test Case 1:
numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
v = {1,1,1,0,0}
sum = v[0] + v[1] = 1 + 1 = 2

Test Case 2:
numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
v = {1,1,1,0,0}
sum = v[0]+v[1]+v[2]+v[3] = 1+1+1+0 = 3

Test Case 3:
numOnes = 1, numZeros = 2, numNegOnes = 3, k = 5
v = {1,0,0,-1,-1,-1}
sum = 1+0+0+(-1)+(-1) = -1


✅ সব ক্ষেত্রে sum maximize হয়েছে।

৫️⃣ সহজ Version / Optimization

আসলে vector তৈরি করা দরকার নেই, শুধু count ব্যবহার করলেই হবে।

কোড হবে:

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int takeOnes = min(k, numOnes);
    k -= takeOnes;
    int takeZeros = min(k, numZeros);
    k -= takeZeros;
    int takeNegOnes = min(k, numNegOnes);
    return takeOnes*1 + takeZeros*0 + takeNegOnes*(-1);
}


এই version এ O(1) time, কোনো extra space লাগে না।

৬️⃣ মূল পয়েন্ট

Technique: Greedy

Reason: Largest numbers প্রথমে নেওয়া sum maximize করে

Vector ব্যবহার: সহজে বোঝার জন্য

Optimized approach: Count ব্যবহার করে সরাসরি sum হিসাব করা

টেস্ট কেস: সব ধরনের 1,0,-1 সমন্বয় দিয়ে পরীক্ষা করা


  Full Code:
---------------

  class Solution
 {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
     {
        vector<int>v;
        for(int i=0;i<numOnes;i++)
        {
            v.push_back(1);
        }
         for(int i=0;i<numZeros;i++)
         {
            v.push_back(0);
         }
         for(int i=0;i<numNegOnes;i++)
        {
            v.push_back(-1);
        }
        //if(numOnes==0) return 0;
       int count=0;
       int sum=0;
       int i=0;
       while(count<=k&&i<k&&i<v.size())
       {
         sum+=v[i];
         i++;
         count++;
       }
       return sum;

    }
};
