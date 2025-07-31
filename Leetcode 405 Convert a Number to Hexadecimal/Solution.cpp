class Solution 
{
public:
    string toHex(int num)
    {
        if(num==0) return "0";
        string ans="";
        unsigned int n=num;
        while(n>0)
            {
                int rem=n%16;
                if(rem<10)
                {
                ans+=to_string(rem);
                }
                if(rem>9&&rem<16)
                {
                    ans+=char('a'+rem-10);
                }
                n/=16;
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
