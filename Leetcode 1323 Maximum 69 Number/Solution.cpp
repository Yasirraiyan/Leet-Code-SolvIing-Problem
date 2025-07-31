class Solution 
{
public:
    int maximum69Number (int num)
    {
        string s=to_string(num);
        string ss;
        for(int i=0;i<s.size();i++)
            {
                if(s[i]=='6')
                {
                    s[i]='9';
                    break;
                }
                
            }
        int ans=0;
        for(int j=0;j<s.size();j++)
            {
                ans+=(s[j]-'0')*pow(10,s.size()-j-1);
            }
        return ans;
    }
};
