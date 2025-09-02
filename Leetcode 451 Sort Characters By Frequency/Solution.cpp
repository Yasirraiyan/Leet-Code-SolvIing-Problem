class Solution 
{
public:
    string frequencySort(string s) 
    {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>freq;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        for(auto it:freq)
        {
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty())
        {
            char a=pq.top().second;
            int x=pq.top().first;
            pq.pop();
     ans.append(x,a);
        }
        return ans;
    }
};
