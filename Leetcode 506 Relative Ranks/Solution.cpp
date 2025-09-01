class Solution 
{
public:
    vector<string> findRelativeRanks(vector<int>& score)
     {
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
            if(count == 1) ans[idx] = "Gold Medal";
            else if(count == 2) ans[idx] = "Silver Medal";
            else if(count == 3) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(count);
            count++;
        }
       
        return ans;
    }
};
