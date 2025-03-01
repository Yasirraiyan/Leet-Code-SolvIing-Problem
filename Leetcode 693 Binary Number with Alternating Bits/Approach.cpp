Amar 1 ta integer deya ase n. Etake binary te niye dekhbo adjacent element alada kina.

First convert binary:
--------------------
  1 ta while loop chalai where (n>0) karon barabar divide kore reminder nibo jotokkhon na 0 na hoy
   1 ta integer nei rem=n%2;
1 ta vector array nei reserve jekhane ami bit store kori ba rem store kori,
  so,
  reserve.push_back(rem);
n=n/2;

Check alternating:
-------------------
  Eta mane porpor dui adjacent alada kina.
  First e 1 ta variable nei bool alternate ja initial true;
1 ta for loop chalai i=0 to i<reserve.size() porjonto and i++;
if(reserve[i]==reserve[i+1])
{
alternating =false;
  break;
}
false check karon loop theke quick exit. RunTime komabo.break karon hoilo loop theke quick exit.
  return kori alternating;


Full Code:
------------
class Solution 
{
public:
    bool hasAlternatingBits(int n) 
{
        vector<int>reserve;
        //bool alternating=false;
        bool alternating=true;
        while(n>0)
        {
          int rem=n%2;
          reserve.push_back(rem);
          n=n/2;
        }
        for(int i=0;i<reserve.size()-1;i++)
        {
          if(reserve[i]==reserve[i+1])
          {
            alternating= false;
            break;
          }
          
        }
        return alternating;
    }
};
  
