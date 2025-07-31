class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans="";
        while(columnNumber>0)
            {
                int rem=columnNumber%26;
                
                if(rem==0)
                {
                    ans+='Z';
                    columnNumber=columnNumber/26-1;
                }
                else
                {
                    ans+=(rem-1+'A');
                
                columnNumber/=26;
            }
            }
        string result="";
        for(int i=ans.size()-1;i>=0;i--)
            {
                result+=ans[i];
            }
        return result;
    }
};
