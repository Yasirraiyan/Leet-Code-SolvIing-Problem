#include<stack>
class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char>st;
        bool isvalid=true;
    
        for(int i=0;i<s.size();i++)
        {
          if(s[i]=='('||(s[i]=='{')||(s[i]=='['))
          {
            st.push(s[i]);
          }
    else if (!st.empty()&&((s[i] == ')' && st.top() == '(') ||(s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))) 
    {
       st.pop();
    }
    else
    {
    isvalid=false;
     break;
   }
   }
  if(!st.empty())
    {
     isvalid=false;
     }
       return isvalid;
    }
};
