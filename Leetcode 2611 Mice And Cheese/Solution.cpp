class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int sum2=0;
        for(int i=0;i<reward2.size();i++)
        {
            sum2+=reward2[i];
        }
        vector<int>v(reward1.size(),0);
        for(int j=0;j<reward1.size();j++)
        {
            v[j]=reward1[j]-reward2[j];
        }
        priority_queue<int>pq;
        for(int j=0;j<v.size();j++)
        {
            pq.push(v[j]);
        }
        int sum1=0;
        int count=0;
        while(count<k&&!pq.empty())
        {
           int top=pq.top();
           sum1+=top;
           pq.pop();
           count++;
          

        }
        int total=sum1+sum2;
        return total;

    }
};
