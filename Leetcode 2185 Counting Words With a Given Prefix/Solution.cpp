class Solution 
{
public:
bool findprefix(string s,string p)
{
  bool prefix=false;
  string ans="";
  for(int i=0;i<s.size();i++)
  {
       ans+=s[i];
       if(ans==p)
       {
        prefix=true;
        break;
       }

  }
  return prefix;
}
    int prefixCount(vector<string>& words, string pref) 
    {
        int count=0;
        for(int j=0;j<words.size();j++)
        {
          if(findprefix(words[j],pref))
          {
            count++;
          }
        }
        return count;
    }
};
