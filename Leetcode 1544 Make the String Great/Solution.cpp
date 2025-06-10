class Solution 
{
public:
    string makeGood(string s) 
    {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
        if(!st.empty())
        {

        
          if((toupper(st.top()))==toupper(s[i])&&st.top()!=s[i])
          {
            st.pop();
          }
          else
          {
            st.push(s[i]);
          }
        }
          else
          {
            st.push(s[i]);
          }
          
        }
        string ans="";
        while(!st.empty())
        {
          ans+=st.top();
          st.pop();
          if(st.empty())
          {
            break;
          }
        }
        string result="";
        for(int j=ans.size()-1;j>=0;j--)
        {
          result+=ans[j];
        }
        return result;
    }
};
