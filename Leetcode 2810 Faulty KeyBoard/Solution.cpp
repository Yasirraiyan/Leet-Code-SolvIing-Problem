class Solution 
{
public:
  string reverse(string s)
  {
    string ans="";
    for(int i=s.size()-1;i>=0;i--)
    {
      ans+=s[i];
    }
    return ans;
  }
    string finalString(string s) 
    {
        string final="";
        for(int j=0;j<s.size();j++)
        {
          //final+=s[j];
          if(s[j]=='i')
          {
            final=reverse(final);
          }
          else
          {
            final+=s[j];
          }
        }
        return final;
    }
};
