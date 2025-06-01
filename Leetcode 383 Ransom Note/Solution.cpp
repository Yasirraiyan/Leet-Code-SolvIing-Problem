class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
       unordered_map<char,int>freq1;
       unordered_set<char>set1;
        unordered_map<char,int>freq2;
       for(int i=0;i<magazine.size();i++)
       {
        set1.insert(magazine[i]);
        freq1[magazine[i]]++;
       }
       for(int j=0;j<ransomNote.size();j++)
       {
        freq2[ransomNote[j]]++;
        if(set1.find(ransomNote[j])==set1.end())
        {
          return false;
        }
        else
        {
          if(freq2[ransomNote[j]]>freq1[ransomNote[j]])
          {
            return false;
          }
        }
       }
       return true;
    }
};
