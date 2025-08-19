1 ta sentence ase jekhane , space capital small letter ase
Convert all capital to small remove space and remove non alpha numeric character
So,
loop for chalai test kori if diye j
alphanumeric kina so, isalnum() diye test for character
test not space 
genarate string
then reverse generate string
reverse ar generated same or not same hole true naile false

So,
Code:
-------------

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
