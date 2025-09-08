class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int count=0;
        for(int i=0;i<mat.size();i++)
        {
            count = 0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                {
                    count++;
                }
            }
            pq.push({count,i});
            
        }
        int countt=0;
        vector<int>v;
        while(countt<k&&!pq.empty())
        {
            int top=pq.top().second;
            v.push_back(top);
            pq.pop();
            countt++;
        }
        return v;
    }
};
