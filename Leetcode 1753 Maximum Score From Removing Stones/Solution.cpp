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
