class Solution 
{
public:
    string removeKdigits(string num, int k) 
    {
        stack<char>st;
          if (num.empty()) return "0";

        st.push(num[0]);
        int count=0;
        for(int i=1;i<num.size();i++)
        {
           while(!st.empty()&&k>0&&st.top()>num[i])
           {
            char top=st.top();
          /*  if(top-'0'<num[i]-'0')
            {
              st.pop();
            }
            */
            st.pop();
            
            k--;
           }
          
              st.push(num[i]);
            
        }
        string s="";
        while(k>0&&!st.empty())
        {
          char topp=st.top();
          //s+=topp;
          st.pop();
          k--;
        }
        while(!st.empty())
        {
          s+=st.top();
          st.pop();
        }
        string ans="";
        for(int j=s.size()-1;j>=0;j--)
       {
        ans+=s[j];
       }
       int pos = 0;
        while (pos < ans.size() && ans[pos] == '0') {
            pos++;
        }
        ans = ans.substr(pos);

        if (ans.empty()) return "0";

        return ans;
    }
      
    
};
