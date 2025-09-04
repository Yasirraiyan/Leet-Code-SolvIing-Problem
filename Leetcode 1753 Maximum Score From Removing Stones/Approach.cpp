Problem Understanding (Question থেকে approach ধরার চিন্তা)

আমাদের কাছে তিনটি pile আছে: a, b, c।

প্রতি turn-এ আমরা দুটি non-empty pile থেকে ১ stone করে তুলব এবং score 1 বাড়বে।

Game stops হবে যখন কমপক্ষে দুটি pile empty হবে।

Maximum score চাই।

Important insight:

সবসময় সবচেয়ে বড় দুইটা pile থেকে stone তোলা optimal।

তাই, priority_queue (max-heap) ব্যবহার করলে সহজে দুইটা largest pile বের করা যায়।

Solution approach thought process

Piles গুলো max-heap এ push করব: pq.push(a), pq.push(b), pq.push(c)।

Max-heap আমাদের দুইটা বড় pile সহজে দেবে।

Loop চালাবো যতক্ষণ pq.size() >= 2।

pq.size() < 2 মানে আর move সম্ভব না।

প্রতি iteration এ:

Top 2 elements pop করব → largest 2 piles।

Score++।

দুটোর value কমাবো 1 করে।

যদি value > 0, আবার pq তে push করব।

Loop শেষ হলে score return করব।

Code Line by Line Explanation
priority_queue<int> pq;
pq.push(a);
pq.push(b);
pq.push(c);


তিনটি pile pq তে push করি। max-heap automatically largest first রাখে।

int score = 0;
while(pq.size() >= 2)


যতক্ষণ দুইটা non-empty pile আছে, loop চলবে।

int top1 = pq.top(); pq.pop();
int top2 = pq.top(); pq.pop();
score++;
top1 -= 1;
top2 -= 1;
if(top1 > 0) pq.push(top1);
if(top2 > 0) pq.push(top2);


Top 2 largest piles pop করি।

Score 1 বাড়াই।

দুটো pile থেকে 1 stone কমাই।

যদি pile empty না হয়, আবার push করি।

return score;


সব শেষ, maximum score return।

Step by Step Test Case Example (a=2, b=4, c=6)

Initial pq: [6,4,2]

Pop top2: 6,4 → score=1 → push back 5,3 → pq=[5,3,2]

Pop top2: 5,3 → score=2 → push back 4,2 → pq=[4,2,2]

Pop top2: 4,2 → score=3 → push back 3,1 → pq=[3,2,1]

Pop top2: 3,2 → score=4 → push back 2,1 → pq=[2,1,1]

Pop top2: 2,1 → score=5 → push back 1,0 → pq=[1,1]

Pop top2: 1,1 → score=6 → push back 0,0 → pq=[]

Score = 6 → Correct

✅ Key takeaways:

Max-heap ensures always two largest piles selected → optimal score.

Loop stops automatically when fewer than 2 piles remain.

Score increment per move guarantees maximum possible.

Full Code:
--------

  class Solution 
{
public:
    int maximumScore(int a, int b, int c) 
    {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int score=0;
        while(/*!pq.empty()*/pq.size()>=2)
        {
            if(pq.size() < 2) break;
            if(pq.size()>=2)
            {
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            score++;
            top1-=1;
            top2-=1;
            if(top1>0)
            
                pq.push(top1);
                if(top2>0)
                pq.push(top2);
            
            }
            /*if(top1==0&&top2==0)
            {
                break;
            }
            */
        }
        return score;
    }
};
