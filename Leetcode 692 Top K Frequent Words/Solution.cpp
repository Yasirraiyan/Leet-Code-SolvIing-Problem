class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
     {
        auto cmp = [](pair<int,string>& a, pair<int,string>& b)
        {
    if(a.first != b.first) return a.first < b.first; // frequency descending
    return a.second > b.second; // lexicographically ascending
};
       priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);
         unordered_map<string,int>freq;
         for(int i=0;i<words.size();i++)
         {
            freq[words[i]]++;
         }
         for(auto it:freq)
         {
            pq.push({it.second,it.first});
         }
         vector<string>v;
         int count=0;
         while(!pq.empty()&&count<k)
         {
             string choice=pq.top().second;
             pq.pop();
             v.push_back(choice);
             count++;
         }
return v;

    }
};
