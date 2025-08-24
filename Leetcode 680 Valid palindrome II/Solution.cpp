class Solution
 {
public:
 bool Palindrome(string a)
 {
    bool test=false;
    string b="";
    for(int j=a.size()-1;j>=0;j--)
    {
        b+=a[j];
    }
    if(a==b)
    {
        test=true;
    }
    return test;
 }
    bool validPalindrome(string s)
     {
        if(Palindrome(s)) return true;
        int low=0;
        int high=s.size()-1;
        if(!Palindrome(s))
        {
            while(low<high)
            {
                if(s[low]==s[high])
                {
                    low++;
                    high--;
                }
                  else
                 {
                  string a = s.substr(low+1, high-low);    // skip left
                string b = s.substr(low, high-low);     
                if(Palindrome(a)||Palindrome(b)) return true;
                else
                return false; 
            }
        }
        }
        return true;
    }
};
