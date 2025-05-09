class Solution 
{
public:
    int distributeCandies(vector<int>& candyType) 
    {
        unordered_map<int,int>freq;
        for(int i=0;i<candyType.size();i++)
        {
          freq[candyType[i]]++;
        }
        vector<int>reserve;
        for(auto it:freq)
        {
         reserve.push_back(it.first);
        }
        int m=reserve.size();
        int n=candyType.size();
        int ans=min(m,n/2);
        return ans;
    }
};
