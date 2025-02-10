Amar 1 ta integer ase num ja decimal 10 base.Eta ke ami nibo 7 base e.String akare return korbo.
1 st e 1 ta variable nei string type ja empty.
string ans=";
barbar 7 dia divide kore reminder nibo. 
As bar bar iterate so, while loop iterate korbo. jekhane num>0.  positive er jonno 
loop er moddhe num=num%7;
etake string convert to_string(num);
ans+=to_string(num);
loop theke ber hoye num=num/7;
 while(num>0)
       {
        rem=num%7;
       // ans+=to_string(rem);
        ans=to_string(rem)+ans;
        num=num/7;       
        } 

negative er jonno 
bool isNegative = num < 0;
    num = std::abs(num);
 if(isNegative)ans="-"+ans;
Full code together;
class Solution 
{
public:
    string convertToBase7(int num) 
{
       string ans="";
       int rem=0;
       if (num == 0) 
       return "0";

    bool isNegative = num < 0;
    num = std::abs(num);
   
    
       while(num>0)
       {
        rem=num%7;
       // ans+=to_string(rem);
        ans=to_string(rem)+ans;
        num=num/7;       
        } 
       if(isNegative)ans="-"+ans;
       
        return ans;
    }
};
   
    
