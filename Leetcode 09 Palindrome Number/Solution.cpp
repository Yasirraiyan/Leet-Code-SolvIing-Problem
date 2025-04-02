#include<string>
#include<iostream>
using namespace std;
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
       string ans1=to_string(x);
       string ans2="";
       bool check=false;
       for(int i=ans1.size()-1;i>=0;i--)
       {
        ans2+=ans1[i];
       }
       if(ans1==ans2)
       {
        check=true;
       }
       return check;
    }
};
