Amar 1 ta integer ase n .Amar n sonkhok character er string form korte hbe.Same character o thakte pare multiple o thakte pare.But shobar count odd hbe
 as odd 
n jodi odd hoy taile n sonkhok same character n=7 hoy 7 ta a
n jodi even hoy taile (n-1) sonkhok a 1 ta b n=8 hoy taile 7 ta a 1 ta b .Taile proti character odd count hoilo

n sonkhok a ba character form er jonno
return(n,'a') korbo
eta n sonkhok a er string generate kore
 n-1 sonkhok a 1 ta b hoile
return(n-1,'a')+"b";
hbe
Odd Code:
---------
  if(n%2!=0)
         {
          return string(n,'a');
         }
Even er jonno direct else:
-----------------------------
  else
         {
          return string(n-1,'a')+"b";
         }

Full Code:
----------

  class Solution 
{
public:
    string generateTheString(int n) 
    {
         if(n%2!=0)
         {
          return string(n,'a');
         }
        else
         {
          return string(n-1,'a')+"b";
         }
    }
};
