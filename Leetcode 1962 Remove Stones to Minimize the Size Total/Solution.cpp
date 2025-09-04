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
