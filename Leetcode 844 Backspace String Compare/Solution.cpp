#include<stack>
#include<vector>
class Solution 
{
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char>st1;
        stack<char>st2;
      vector<char>reserve1;
      vector<char>reserve2;
      bool isequal=false;
      for(int i=0;i<s.size();i++)
      {
        reserve1.push_back(s[i]);
      }
      for(int j=0;j<t.size();j++)
      {
            reserve2.push_back(t[j]);
      }
      for(int k=0;k<reserve1.size();k++)
      {
        if(reserve1[k]=='#')
        {
          if(!st1.empty())
          {

          
          st1.pop();
          }
        }
        else
        {
          st1.push(reserve1[k]);
        }
      }
      for(int m=0;m<reserve2.size();m++)
      {
        if(reserve2[m]=='#')
        {
          if(!st2.empty())
          {

          
          st2.pop();
          }
        }
         else
        {
          st2.push(reserve2[m]);
        }
      }
      string s1="";
      string s2="";
      while(!st1.empty())
      {
        s1+=st1.top();
        st1.pop();
      }
      while(!st2.empty())
      {
        s2+=st2.top();
        st2.pop();
      }
      if(s1==s2)
      {
           isequal=true;
      }
      return isequal;
    }
};
