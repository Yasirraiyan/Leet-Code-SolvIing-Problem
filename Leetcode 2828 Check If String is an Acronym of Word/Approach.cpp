Amar 1 ta array ase string er 1 ta string ase s.Amar check korte hb ei array er sob index e je string gula ase tader 1 st letter diye genarated string r acronym same kina .Same hoile true. Naile false.

First e 1 ta helper function banai main function er baire string generatestring(string a) eta diya string er first mane 0th character diye banai 
1 ta variable nei string ans ja initial empty or ""
1 ta loop chalai for ja i=0 to i<s.size() porjonto
ans+=s[0] kori
break dei 
karon sudhu first character nibo break na dile sob nibe

 return kori ans.

Helper Function:
-----------------

  string generatestring(string a)
   {
    string ans="";
    for(int i=0;i<a.size();i++)
    {
      ans+=a[0];
      break;
    }
    return ans;
   }

Main Function e 1 ta variable nei bool acronym ja initial false.Eta diya test korbo acronym kina
1 ta for loop chalai j=0 to j<words.size() porjonto j++ kori
  pura array traverse kori
1 ta variable nei string reserve ja initial empty etay 1st character gula diye generated string rakhbo
reserve+=words[j] kori
Check kori acronym ba s er same kina
 So,
   if(reserve==s)
      {
        isacronym=true;
      }
Same hoile acronym true kori
return kori acronym

Main Function:
---------------

  bool isAcronym(vector<string>& words, string s) 
    {
      bool isacronym=false;
      string reserve="";
      for(int j=0;j<words.size();j++)
      {
        reserve+=generatestring(words[j]);
      }
      if(reserve==s)
      {
        isacronym=true;
      }
      return isacronym;
    }

Full Code:
-----------

  class Solution 
{
public:
  
   string generatestring(string a)
   {
    string ans="";
    for(int i=0;i<a.size();i++)
    {
      ans+=a[0];
      break;
    }
    return ans;
   }
    bool isAcronym(vector<string>& words, string s) 
    {
      bool isacronym=false;
      string reserve="";
      for(int j=0;j<words.size();j++)
      {
        reserve+=generatestring(words[j]);
      }
      if(reserve==s)
      {
        isacronym=true;
      }
      return isacronym;
    }
};
