প্রশ্নটি বোঝা:

তোমাকে একটি integer array score দেওয়া আছে, যেখানে score[i] হলো i-th athlete এর score।

1st highest score → "Gold Medal"

2nd highest score → "Silver Medal"

3rd highest score → "Bronze Medal"

4th এবং তার পরের স্থান → placement number (string হিসেবে)

আমাদের কাজ: প্রতিটি athlete এর score অনুযায়ী তাদের rank assign করা।

Step 1: Approach চিন্তা করা

যদি আমরা sequentially score গুলোর rank বের করতে চাই, তবে আমরা চাইবো:

উচ্চ score গুলো আগে পড়ি।

তাই sorting বা max-heap (priority_queue) ব্যবহার করতে পারি।

score এর original index মনে রাখতে হবে।

কারণ output array-তে প্রতিটি athlete এর original index অনুযায়ী rank দিতে হবে।

Test Case Consider করা:

score = [10, 3, 8, 9, 4]

Sorted descending: [10, 9, 8, 4, 3]

Original indices: [0, 3, 2, 4, 1]

Rank assignment:

Score	Original Index	Rank
10	0	Gold Medal
9	3	Silver Medal
8	2	Bronze Medal
4	4	4
3	1	5
Step 2: Approach কেন এইটা ব্যবহার করা হয়েছে

আমরা priority_queue ব্যবহার করেছি কারণ এটি সর্বোচ্চ element কে O(log n) সময়ের মধ্যে access করতে দেয়।

আমরা score কে index সহ encode করেছি: score*100000 + index

যেটার মানে: heap sorting হবে score অনুযায়ী, কিন্তু আমরা original index বের করতে পারবো index = top % 100000।

এখানে 100000 ব্যবহার করা হয়েছে কারণ constraint অনুযায়ী score[i] < 10^5।

কেন heap / priority_queue ব্যবহার করা সুবিধাজনক:

সরাসরি descending order এর জন্য sort করতে হবে না।

original index ও rank mapping সহজ।

Step 3: কোডের logic line by line
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        priority_queue<long long> pq;

        // Score গুলো push করা index সহ
        for(int i=0;i<score.size();i++)
        {
            pq.push((long long)score[i]*100000 + i);
        }

        vector<string> ans(score.size());
        int count = 1;

        // heap থেকে score বের করা
        while(!pq.empty())
        {
           long long top = pq.top();
           pq.pop();
           int idx = top % 100000; // original index বের করা
           
           // rank assign করা
           if(count == 1) ans[idx] = "Gold Medal";
           else if(count == 2) ans[idx] = "Silver Medal";
           else if(count == 3) ans[idx] = "Bronze Medal";
           else ans[idx] = to_string(count);
           
           count++;
        }
       
        return ans;
    }
};

Step 4: Test by Test Case
Input: [10, 3, 8, 9, 4]

Heap push:
10*100000+0 = 1000000
3*100000+1 = 300001
8*100000+2 = 800002
9*100000+3 = 900003
4*100000+4 = 400004

Heap এর descending order: [1000000, 900003, 800002, 400004, 300001]

Pop করে assign rank:

Pop	idx	Rank
1000000	0	Gold Medal
900003	3	Silver Medal
800002	2	Bronze Medal
400004	4	4
300001	1	5

✅ Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]

Step 5: Summary / How to Think

Question পড়ে বোঝো highest score এর rank কি হবে।

Athlete এর original index রাখতে হবে, কারণ output array original order অনুসারে হবে।

Use priority_queue বা sort descending, heap ভালো কারণ insert O(log n) এবং index save করা সহজ।

Test case step-by-step চেষ্টা করো যাতে index & rank mapping বোঝা যায়।


Full Code:
-----------

  class Solution 
{
public:
    vector<string> findRelativeRanks(vector<int>& score)
     {
        //sort(score.begin(),score.end());
        //reverse(score.begin(),score.end());
        priority_queue<long long>pq;
        for(int i=0;i<score.size();i++)
        {
            if(pq.size()<score.size())
            {
            pq.push((long long)score[i]*100000+i);
            }
           else if(score[i]>pq.top()/100000)
            {
                pq.pop();
                pq.push(score[i]*100000+i);
            }
        }
        vector<string>ans(score.size());
         int count=1;
        while(!pq.empty())
        {
           long long top=pq.top();
           pq.pop();
            int idx = top % 100000;
            //result.push_back(top);
           
            if(count == 1) ans[idx] = "Gold Medal";
            else if(count == 2) ans[idx] = "Silver Medal";
            else if(count == 3) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(count);
            count++;
        }
       
        return ans;
    }
};
