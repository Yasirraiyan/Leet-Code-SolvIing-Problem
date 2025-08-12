class Solution 
{
public:
bool CheckLate(string s)
{
  bool check=false;
  if(s.size()>=3)
  {
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L')
      {
        check=true;
        break;
      }
    }
  }
  return check;
}
    bool checkRecord(string s) 
    {
        bool check=false;
        int l=0;
        int a=0;
        for(int i=0;i<s.size();i++)
        {
          if(s[i]=='A')
          {
            a++;
          }
          
        }
        if(a<2&&!CheckLate(s))
        {
          check=true;
        }
        return check;
    }
};
