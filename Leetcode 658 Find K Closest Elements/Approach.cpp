🔹 Problem বুঝতে হবে

আমাদের দেওয়া আছে:

Sorted array arr

দুটি সংখ্যা: k (কতগুলো element নিতে হবে) আর x (target number)

আমাদের কাজ:
👉 k টা element return করা, যেগুলো x এর সবচেয়ে কাছাকাছি।
আর return করার সময় ascending order এ সাজাতে হবে।

Closest element এর শর্ত:

যদি |a - x| < |b - x| → তাহলে a বেশি কাছে।

যদি |a - x| == |b - x| → ছোট সংখ্যাটাই আগে নেবে।

🔹 তুমি কী approach নিলে?

👉 তুমি Priority Queue (Min-Heap) ব্যবহার করেছো।

ধাপে ধাপে:

Distance হিসাব:
প্রতিটা arr[i] এর জন্য abs(arr[i] - x) বের করছো।
এটা basically বলে দিচ্ছে, element টা x থেকে কতটা দূরে।

int j = abs(arr[i] - x);
pq.push({j, arr[i]});


এখানে priority queue তে (distance, value) push করা হচ্ছে।

যেহেতু তুমি greater<pair<int,int>> ইউজ করছো → এটা min-heap এর মতো behave করছে।

মানে সব সময় smallest distance আর সমান হলে smallest value উপরে থাকবে।

K elements বের করা:
Priority queue থেকে k বার pop করলে পেয়ে যাবো সবচেয়ে কাছের k elements।

while(!pq.empty() && count < k) {
    int top1 = pq.top().second;
    v.push_back(top1);
    pq.pop();
    count++;
}


Ascending order এ সাজানো:
Priority queue distance অনুযায়ী smallest দিচ্ছে, কিন্তু final answer sorted array হতে হবে।
তাই শেষে:

sort(v.begin(), v.end());

🔹 Technique

👉 এখানে আমরা ব্যবহার করেছি Heap / Priority Queue technique

Distance অনুযায়ী element গুলো সাজানো

K টা element নেওয়া

শেষে sort করে answer return

এটা accepted হয়েছে কারণ constraints (array length up to 10^4) এই approach handle করতে পারবে।

🔹 কিভাবে ভাবা যায় Approach (Thinking process)

Problem পড়েই প্রথমে ভাবতে হবে → "আমাকে সবচেয়ে কাছের element চাই"
⇒ তাহলে distance / difference বের করতেই হবে।

Distance অনুযায়ী smallest নিতে হবে।
⇒ এটা natural fit for Min-Heap বা Sorting approach।

যেহেতু k fixed number, তাই Heap ব্যবহার করাটা efficient।

🔹 Test Case দিয়ে বোঝা
Case 1:
arr = [1,2,3,4,5], k = 4, x = 3


Distance হিসাব:

|1-3|=2, |2-3|=1, |3-3|=0, |4-3|=1, |5-3|=2


Heap → [(0,3),(1,2),(1,4),(2,1),(2,5)]

প্রথম 4 pop করলে পাবো → [3,2,4,1]

Sort → [1,2,3,4] ✅

Case 2:
arr = [1,1,2,3,4,5], k = 4, x = -1


Distance হিসাব:

|1-(-1)|=2, |1-(-1)|=2, |2-(-1)|=3, |3-(-1)|=4, |4-(-1)|=5, |5-(-1)|=6


Heap → [(2,1),(2,1),(3,2),(4,3),(5,4),(6,5)]

প্রথম 4 pop → [1,1,2,3]

Sort → [1,1,2,3] ✅

🔹 Complexity

Heap build: O(n log n) (কারণ সব element push হচ্ছে heap এ)

Pop k elements: O(k log n)

Sort final array: O(k log k)
👉 Overall: O(n log n)

✅ এই solution accepted হচ্ছে কারণ এটি distance ভিত্তিক closest element বের করার জন্য perfect method। 


Full Code:
------------


  class Solution
 {
public:

 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int>v;
       for(int i=0;i<arr.size();i++)
       {
        int j=abs(arr[i]-x);
        pq.push({j,arr[i]});
        /*if(pq.size()>k)
        {
            pq.pop();
        }
        */
       }
       int count=0;
       while(!pq.empty()&&count<k)
       {
        int top1=pq.top().second;

       v.push_back(top1);
       pq.pop();
       count++;
       if(count==k) break;
       }
       sort(v.begin(),v.end());
       return v;
    }
};
