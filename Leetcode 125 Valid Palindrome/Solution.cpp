class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        string a="";
        bool test=false;
        for(int i=0;i<s.size();i++)
            {
                if(isalnum(s[i]))
                {
                    a+=tolower(s[i]);
                }
            }
        string v="";
        for(int j=a.size()-1;j>=0;j--)
            {
            v+=tolower(a[j]);
            }
        
        if(a==v)
        {
            test=true;
        }
        return test;
    }
};
