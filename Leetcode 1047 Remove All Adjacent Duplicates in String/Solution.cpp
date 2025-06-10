class Solution 
{
public:
    string removeDuplicates(string s) 
{
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
          if(!st.empty())
           {  
          if(s[i]==st.top())
          {
            st.pop();
          }
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
        while(!st.empty())
        {
          ans+=st.top();
          st.pop();
        }
         string result="";
         for(int j=ans.size()-1;j>=0;j--)
         {
          result+=ans[j];
         }
        return result;
    }
};
