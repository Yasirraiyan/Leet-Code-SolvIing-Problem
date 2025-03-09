Amar  1 ta array ase jar nam words.Eta string er array.
  1 ta string palindrome hbe jodi ei string k reverse order e sajale jodi same hoy taile palindrome hbe.

  Ami First e 1 ta helper function banai bool palindrome(string s) eta dia test korbo j palindrome kina.
  1 ta variable nei bool palindrome ja initial false;
duita variable nei string ans1 =""
aro 1 ta nei string ans2=""
  ans1 e nibo pura string forword e traverse kore jog kori
1 ta for loop chalai i=0 i<s.size() porjonto i++ kori
  forward e jog kori ans1 er sathe 
ans1+=s[i];

This Code:
-----------
  for(int i=0;i<s.size();i++)
    {
      ans1+=s[i];
    }
reverse er jonno j=s.size()-1 theke j>=0  and j-- kori 
  reverse e karon 1
   [1,2,3,4,5] hoile index=[0,1,2,3,4]
reverese 
[5,4,3,2,1] holie index=[4,3,2,1,0] 1 kore kome tai j-- and chalabo j>=0 porjonto tai

This Code for reverse:
--------------------------
    for(int j=s.size()-1;j>=0;j--)
    {
      ans2+=s[j];
    }
Check for palindrome:
---------------------
  Same hoile true 
  naile false
  So,
    if(ans1==ans2)
    {
      palindrome=true;
    }
return palindrome.

  Helper function is:
---------------------
   bool palindrome(string s)
  {
    bool palindrome=false;
    string ans1="";
    string ans2="";
    for(int i=0;i<s.size();i++)
    {
      ans1+=s[i];
    }
     for(int j=s.size()-1;j>=0;j--)
    {
      ans2+=s[j];
    }
    if(ans1==ans2)
    {
      palindrome=true;
    }
    return palindrome;
  }
Main functon e 1 ta array vector nei reserve etay palindromic alada kori 
1 ta for loop chalai k=0 to k<word.size() porjonto k++ kori
  check palindrome tai if er moddhe function call kori
 if(palindrome(words[k]))
            {
              reserve.push_back(words[k]);
            }
hoile reserve e push kori words[k] mane palindromic gula
And chaise first ta 
tai aro 1 ta for loop chalai m=0 to m<reserve.size() porjonto m++ kori reserve traverse kori
as reserve e sob palindrome 
tai
result=reserve[m] kori karon chaise string ta mane index e reserver man


   break dei karon first chaise paile break'
ar jabe na
return kori result

Main Function Code:
--------------------

  string firstPalindrome(vector<string>& words) 
    {
      vector<string>reserve;
      string result="";
        for(int k=0;k<words.size();k++)
        {
            if(palindrome(words[k]))
            {
              reserve.push_back(words[k]);
            }
        }
        for(int m=0;m<reserve.size();m++)
        {
          result=reserve[m];
          break;
        }
        return result;
    }

Full Code:
----------
  class Solution 
{
public:
  bool palindrome(string s)
  {
    bool palindrome=false;
    string ans1="";
    string ans2="";
    for(int i=0;i<s.size();i++)
    {
      ans1+=s[i];
    }
     for(int j=s.size()-1;j>=0;j--)
    {
      ans2+=s[j];
    }
    if(ans1==ans2)
    {
      palindrome=true;
    }
    return palindrome;
  }
    string firstPalindrome(vector<string>& words) 
    {
      vector<string>reserve;
      string result="";
        for(int k=0;k<words.size();k++)
        {
            if(palindrome(words[k]))
            {
              reserve.push_back(words[k]);
            }
        }
        for(int m=0;m<reserve.size();m++)
        {
          result=reserve[m];
          break;
        }
        return result;
    }
};

