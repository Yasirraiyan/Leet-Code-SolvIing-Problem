class Solution
{
  public:
    int numberOfSpecialChars(string s) 
    {
      vector<char>v1;
      vector<char>v2;
    
      for(int i=0;i<s.size();i++)
      {
        if(isupper(s[i]))
        {
          v1.push_back(s[i]);
        }
        if(islower(s[i]))
        {
          v2.push_back(s[i]);
        }
      }
      unordered_set<char>set1;
      vector<char>v3;
      for(int j=0;j<v1.size();j++)
      {
        set1.insert(v1[j]);
      }
      for(int k=0;k<v2.size();k++)
      {
        if(set1.find(toupper(v2[k]))!=set1.end())
        {
                 v3.push_back(v2[k]);
        }
      }
      unordered_map<char,int>freq;
      for(int i=0;i<v3.size();i++)
      {
        freq[v3[i]]++;
      }
      vector<char>result;
      for(auto it:freq)
      {
        result.push_back(it.first);
      }
      int ans=result.size();
      return ans;
    }
};
