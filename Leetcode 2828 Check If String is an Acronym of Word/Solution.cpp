class Solution 
{
public:
  
   string generatestring(string a)
   {
    string ans="";
    for(int i=0;i<a.size();i++)
    {
      ans+=a[0];
      break;
    }
    return ans;
   }
    bool isAcronym(vector<string>& words, string s) 
    {
      bool isacronym=false;
      string reserve="";
      for(int j=0;j<words.size();j++)
      {
        reserve+=generatestring(words[j]);
      }
      if(reserve==s)
      {
        isacronym=true;
      }
      return isacronym;
    }
};
