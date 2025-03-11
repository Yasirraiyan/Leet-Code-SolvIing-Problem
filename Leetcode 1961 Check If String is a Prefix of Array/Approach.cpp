Amar 1 ta array ase string er jar nam words.1 ta string ase s.Amar check korte hbe array r sob index er string add kore words er same kina .hoile true return nai false return.

So, 1 st 1 ta variable nei prefix ja bool type ja initial false.Eta dia test korbo prefix kina. 1 ta variable nei ans string type ja "" aron etate array r value jog kore word er sathe check korbo same kina
  1 ta loop chalai for i=0 to i<word.size() porjonto i++ kori array traverse kori
  ans+=word[i] kori
check kori same kina same hoile prefix=true kori
so,
 if(ans==s)
        {
             prefix=true;
           break;
        }
break dei quick exit from loop ei jonno ete runtime kome
  return kori prefix.

Full Code:
---------
  class Solution 
{
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        string ans="";
        bool prefix=false;
        for(int i=0;i<words.size();i++)
        {
          ans+=words[i];
          if(ans==s)
        {
             prefix=true;
           break;
        }
        }
       // if(ans==s)
       // {
            // prefix=true;
      //  }
        return prefix;
    }
};

  
