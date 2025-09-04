Problem Understanding (How to think about it)

Question summary:

আমরা পাই piles নামে stones-এর array।

আমাদের k বার operation করতে হবে।

Operation: piles[i] -= floor(piles[i]/2)

একই pile-এ multiple times apply করতে পারি।

Goal: Apply k operations such that total stones remaining minimum হয়।

Observation:

Minimum total পাওয়ার জন্য largest pile থেকে stones কমানো সবথেকে effective।

তাই আমরা চাই largest number প্রতি step-এ choose করি।

Maximum-heap (priority queue) ব্যবহার করলে আমরা সহজে largest pile পাই।

Approach / Solution Thinking

Largest pile খুঁজে বের করি।

Operation apply করি (floor division): pile -= pile/2

Updated pile আবার heap-এ push করি।

এই process k times repeat করি।

শেষ পর্যন্ত heap-এ যত stones আছে সব add করি → answer।

Line-by-line explanation
priority_queue<int> pq;


Max heap বানাচ্ছে। C++ priority_queue default max heap।

সব সময় largest element টপে থাকবে।

for(int j=0; j<piles.size(); j++) {
    pq.push(piles[j]);
}


সব pile heap-এ push।

উদাহরণ: piles = [5,4,9] → heap = [9,5,4] (largest always on top)

int count = 0;
int ans = 0;


count → কত operation করেছি।

ans → শেষ পর্যন্ত total stones।

while(!pq.empty() && count < k) {
    int top = pq.top();  // largest pile
    pq.pop();            // remove it from heap
    count++;             // 1 operation done

    int x = top - (top/2);  // remove floor(top/2) stones
    pq.push(x);             // push updated pile back
}


Example walkthrough:

piles = [5,4,9], k=2

Step 1:

Largest pile = 9

Remove floor(9/2)=4 → new pile = 9-4=5

Heap after push: [5,5,4]

Step 2:

Largest pile = 5

Remove floor(5/2)=2 → new pile = 3

Heap after push: [5,4,3]

Done k=2 operations.

while(!pq.empty()) {
    int top = pq.top();
    ans += top;
    pq.pop();
}


সব remaining stones add করে answer বের করছি।

Heap: [5,4,3] → total = 5+4+3=12

return ans;


Final answer return।

Key Idea (Why it works)

Largest pile থেকে stones কমানো maximum reduction দেয়।

Heap (priority_queue) ব্যবহার করে আমরা efficiently largest pile pick করতে পারি O(log n) per operation।

Total complexity: O(n + k*log n)

n = initial piles push

k operations each heap pop/push = log n

✅ Test case brief explanation

Example 1:

Input: [5,4,9], k=2

Step1: choose 9 → 5 → [5,4,5]

Step2: choose 5 → 3 → [3,4,5]

Total = 12 ✅

Example 2:

Input: [4,3,6,7], k=3

Step1: choose 7 → 4 → [4,3,6,4]

Step2: choose 6 → 3 → [4,3,4,3]

Step3: choose 4 → 2 → [2,3,4,3]

Total = 12 ✅ 

  Full Code:
---------

  class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int j=0;j<piles.size();j++)
        {
            pq.push(piles[j]);
        }
        int count=0;
        int ans=0;
        while(!pq.empty()&&count<k)
        {
            int top=pq.top();
            //ans+=top;
            pq.pop();
            count++;
             //if(count==k) break;

            int x=top-(top/2);
            pq.push(x);
           
        }
       
       while(!pq.empty())
       {
            int top=pq.top();
            ans+=top;
            pq.pop();
       }
        return ans;
    }
};
