class Solution 
{
public:
    bool isSubsequence(string s, string t)
     {
        int low=0;
        int high=0;
        bool is=false;
        string generates="";
        while(low<s.size()&&high<t.size())
        {
            if(s[low]==t[high])
            {
               generates+=t[high];
               low++;
               
            }
            
           high++;
           
            
        }
        if(generates==s)
        {
            is=true;
        }
        return is;
    }
};
