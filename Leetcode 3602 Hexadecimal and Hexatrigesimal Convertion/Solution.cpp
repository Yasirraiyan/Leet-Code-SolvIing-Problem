class Solution {
public:
 string hexdec(int n)
 {
    string ans="";
    while(n>0)
    {
      int rem=n%16;
      if(rem<10)
      {
        ans+=to_string(rem);
      }
      if(rem>=10&&rem<=15)
      {
        ans+=char('A'+(rem-10));
      }
      n=n/16;
    }
    reverse(ans.begin(), ans.end());
    return ans;
 }
 string hextri(int n)
 {
   string ans="";
    while(n>0)
    {
      int rem=n%36;
      if(rem<10)
      {
        ans+=to_string(rem);
      }
      if(rem>=10&&rem<=35)
      {
        ans+=char('A'+(rem-10));
      }
      n=n/36;
    }
    reverse(ans.begin(), ans.end());
    return ans;
 }
    string concatHex36(int n) 
    {
        long long a=n*n;
        long long b=n*n*n;
        string s1=hexdec(a);
        string s2=hextri(b);
        string ans=s1+s2;
        return ans;
    }
};
