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
        //ans+=to_string(rem);
        ans=to_string(rem)+ans;
        num=num/7;       
        } 
       if(isNegative)ans="-"+ans;
       
        return ans;
    }
};
