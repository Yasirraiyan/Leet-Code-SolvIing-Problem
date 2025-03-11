Amar 1 ta array ase words ja string er array.1 ta string ase pref.
  Amar lagbe ei array r string gular koto gulay prefix paoa jay tar count.

  First e ami 1 ta helper function banai main function er baire prefix ase kina ta find er jonno ja bool type
ekhane duita parameter pass kori string s, string p 
1 ta variable nei ans=" " ja string type etay s er character jog korbo p er equal check er jonno. 1ta bool variable nei prefix ja initial false.Eta dia check korbo prefix kina
1 ta loop chalai for i=0 to i<s.size() porjonto string traverse kori i++ kori
  ans+=s[i] kori
loop er moddhe check kori ans==p kina hoile break dei ete runtime kome na dile aro jog korbe result sothik pabo na
and prefix=true kori
return kori prefix.

Helper Function:
----------------
  bool findprefix(string s,string p)
{
  bool prefix=false;
  string ans="";
  for(int i=0;i<s.size();i++)
  {
       ans+=s[i];
       if(ans==p)
       {
        prefix=true;
        break;
       }

  }
  return prefix;
}

Ekhon main function e 1 ta variable nei count ja initial 0. Karon chaise koytay prefix ase
1 ta for loop chalai j=0 to j<words.size() porjonto j++ kori
  check kori condition helper function call kore 
 if(findprefix(words[j],pref))
          {
            count++;
          }
count ++ kori
  return kori count;

Main Function:
---------------

  
    int prefixCount(vector<string>& words, string pref) 
    {
        int count=0;
        for(int j=0;j<words.size();j++)
        {
          if(findprefix(words[j],pref))
          {
            count++;
          }
        }
        return count;
    }

  Full Code:
  ----------

  class Solution 
{
public:
bool findprefix(string s,string p)
{
  bool prefix=false;
  string ans="";
  for(int i=0;i<s.size();i++)
  {
       ans+=s[i];
       if(ans==p)
       {
        prefix=true;
        break;
       }

  }
  return prefix;
}
    int prefixCount(vector<string>& words, string pref) 
    {
        int count=0;
        for(int j=0;j<words.size();j++)
        {
          if(findprefix(words[j],pref))
          {
            count++;
          }
        }
        return count;
    }
};
