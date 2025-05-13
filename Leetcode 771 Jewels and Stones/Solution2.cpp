class Solution 
{
public:
    int numJewelsInStones(string jewels, string stones) 
    {
       unordered_map<char,int>freq;
       int count=0;
       for(int i=0;i<stones.size();i++)
       {
        freq[stones[i]]++;
       }
       for(int j=0;j<jewels.size();j++)
       {
        for(auto it:freq)
        {
          if(it.first==jewels[j])
          {
              count+=it.second;
          }
        }
       }
       return count;
    }
};
