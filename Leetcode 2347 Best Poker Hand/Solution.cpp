class Solution 
{
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) 
    {
       string ans="";
       unordered_map<int,int>freq1;
       unordered_map<char,int>freq2;
       for(int i=0;i<suits.size();i++)
       {
        freq2[suits[i]]++;
       }
       for(int j=0;j<ranks.size();j++)
       {
        freq1[ranks[j]]++;
       }
       for(auto it1:freq2)
       {
        if(it1.second==5)
        {
          ans+="Flush";
        }
       }
       for(auto it2:freq1)
       {
          if(it2.second>=3)
         {
          ans="Three of a Kind";
         }
         else if(it2.second==2 && ans!="Three of a Kind")
         {
          ans="Pair";
         }
        
         
       }
         if(ans == "") 
         {
          ans = "High Card";
         }
        return ans;
    }
};
