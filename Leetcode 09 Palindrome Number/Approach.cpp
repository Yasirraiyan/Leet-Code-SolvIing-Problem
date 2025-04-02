Amar 1 ta number ase int x.Eta palindrome kina check korbo
1 ta string ba number palindrome jokhon er reverse same hoy agertar
ami first e int x ke string a nei 1 ta string e rakhi
 string ans1=to_string(x);
aro 1 ta string nei reverese rakhbo ans2 ja initial empty
 string ans2="";
1 ta variable nei bool palindrome ja initial false.Eta diye test korbo palindrome kina.
reverse kori
string 5 character hoy index:[0,1,2,3,4]
array size =5;
reverse order :[4,3,2,1,0]
4=5-1 =array.size()-1 theke i>=0;i-- protibar 1 kome
  1 ta for loop chali i=array.size()-1 theke i>=0 porjonto && i-- kori
  ans2+=arr[i] kori
check kori same kina 
if(ans1==ans2)
hoile true
 check=true;
return kori check

Full Code:
----------

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
