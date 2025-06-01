class Solution {
public:
    bool isAnagram(string s, string t) 
    {
      bool check=false;
      unordered_map<char,int>freq1;
      unordered_map<char,int>freq2;
      unordered_set<char>set1;
       unordered_set<char>set2;
       if (s.size() != t.size()) return false;
       for(int i=0;i<s.size();i++)
       {
        freq1[s[i]]++;
        set1.insert(s[i]);
       }
        for(int j=0;j<t.size();j++)
       {
        freq2[t[j]]++;
        set2.insert(t[j]);
       }
       for(int k=0;k<s.size();k++)
       {
         if(set2.find(s[k])==set2.end())
         {
          return false;
         }
         if((set2.find(s[k])!=set2.end())||(set1.find(t[k])!=set1.end()))
         {
            if((freq1[s[k]]!=freq2[s[k]])||(freq1[t[k]]!=freq2[t[k]]))
          {
           // check=false;
          //  break;
          return false;
          }
          else
          {
            check=true;
          }
         }
       }
       return check;

    }
};
