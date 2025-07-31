class Solution
{
public:
    string convert(int n,int k)
    {
        string s="";
        while(n>0)
            {
                int rem=n%k;
                s+=to_string(rem);
                n/=k;
            }
        return s;
    }
    bool TestPalindrome(string s)
    {
        string rev="";
        bool ispalindrome=false;
    for(int i=s.size()-1;i>=0;i--)
        {
            rev+=s[i];
        }
        if(s==rev)
        {
            ispalindrome=true;
        }
        return ispalindrome;
    }
    bool isStrictlyPalindromic(int n)
    {
        bool isstrictlypalindrome=true;
        string a=to_string(n);
        for(int k=2;k<=n-2;k++)
            {
                string c=convert(n,k);
                if(TestPalindrome(c)==false)
                {
                    isstrictlypalindrome=false;
                    break;
                }
            }
        return isstrictlypalindrome;
    }
};
