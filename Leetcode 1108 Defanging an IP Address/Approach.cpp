Amar 1 ta IP address ase string akare.Amar jokhon IP address e "." pabo takey "[.]" diye change korbo.

So,
  1 ta string nei ans ja initial empty;
So,
   string ans="";
1 ta for loop chalai i=0 to i<str.size() porjonto i++ kori string traverse kori
Check character "."
  So,
   if(address[i]=='.')
  true hoile
ans+="[.]" kori
As, 
  Eta soho pura string chaise 
Means:
------
  Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
  So,
  1 ta else dibo baki character jog er jonno like "255"
  So,
     {
            ans+=address[i];
          }
Full Condition:
---------------

 if(address[i]=='.')
          {
           ans+="[.]";
          }
          else
          {
            ans+=address[i];
          }
With Loop:
----------

for(int i=0;i<address.size();i++)
        {
          //ans+=address[i];
          if(address[i]=='.')
          {
           ans+="[.]";
          }
          else
          {
            ans+=address[i];
          }
        }
return korbo ans

Full Code:
----------

  class Solution 
{
public:
    string defangIPaddr(string address) 
    {
      string ans="";
        for(int i=0;i<address.size();i++)
        {
          //ans+=address[i];
          if(address[i]=='.')
          {
           ans+="[.]";
          }
          else
          {
            ans+=address[i];
          }
        }
        return ans;
    }
};
