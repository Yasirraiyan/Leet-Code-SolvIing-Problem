Amar 1 ta array ase words ja string er.2 ta pointer ase left right. Amar lagbe ei [left,right] range er moddhe kyta string vowel string.

Vowel String:
--------------
  Ei string hoilo jara suru hoise vowel die and sesh hoise vowel die
1 ta function banai bool type findvowel(string s) vowel test er jonoo. 1 ta variable nei bool vowel ja initial false.
Check condition for start 
  if((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
Check condition for end
if(s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' || s[s.size() - 1] == 'u'))

By Merging Tgem:
----------------
Finally:
----------
if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
    (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' || s[s.size() - 1] == 'u'))
 hoile find =true kori
 so,
  if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
    (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' || s[s.size() - 1] == 'u'))
     find=true;
    }
return kori find;

Helper Function is:
-----------------------

 bool findvowel(string s)
  {
    bool find=false;
    for(int i=0;i<s.size();i++)
    {
     if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
    (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' || s[s.size() - 1] == 'u'))
     find=true;
    }
     return find;
    }


Main Function e 
1 ta for loop chalai j=left to j<=right ;j++ kori [left,right] er moddhe chaise
initial variable nei count ja initial 0 karon chaise koyta 
loop er moddhe if dei er moddhe function clall kor
count++ kor
  return kori count;

Main Function:
---------------

    int vowelStrings(vector<string>& words, int left, int right) 
    {
        int count=0;
        for(int j=left;j<=right;j++)
        {
          if(findvowel(words[j]))
          {
            count++;
          }
        }
        return count;
     
    }

Full Code:
-------------

  class Solution 
{
public:
  bool findvowel(string s)
  {
    bool find=false;
    for(int i=0;i<s.size();i++)
    {
     if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
    (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' || s[s.size() - 1] == 'u'))
     find=true;
    }
     return find;
    }
   // return find;

  
   
    int vowelStrings(vector<string>& words, int left, int right) 
    {
        int count=0;
        for(int j=left;j<=right;j++)
        {
          if(findvowel(words[j]))
          {
            count++;
          }
        }
        return count;
     
    }
};
