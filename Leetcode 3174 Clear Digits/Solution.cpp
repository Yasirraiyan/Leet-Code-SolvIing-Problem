class Solution 
{
public:
    string clearDigits(string s) 
{
      stack<char>st;
      string ans="";
      string result="";
      for(int i=0;i<s.size();i++)
      {
        if(isdigit(s[i]))
        {
            if (!st.empty()) 
            {
            st.pop();
            }
        }
        else
        {
            st.push(s[i]);
        }
      }
      while(!st.empty())
      {
        ans+=st.top();
        st.pop();
      }
      for(int j=ans.size()-1;j>=0;j--)
      {
        result+=ans[j];
      }
      return result;
    }
};
