Amar 1 ta integer ase n.Amar 1 ta array return korte bolse jei array r index e man thakbe 1 to n porjonto prottek number k binary te nile koyta 1 ase tar count.

So, At First I convert n to binary & count the number of 1 in the binary representation:
-----------------------------------------------------------------------------------------

  Ei jonno ami first e 1 ta function banai countbit(int n) jar parameter n ja int type. 1 ta variable nei rem ja int type. Karon ami reminder push korbo karon binary te reminder nei bit hishabe.
1 ta while loop chalai where (n>0) because 0 na hoya porjonto positive number erv upor 2 dia divide korte thakbo. 1 ta variable nei rem ja int type karon rem e bit store korbo. Ete rem 1 kina check easy hbe.

1 koyta ase ta count er jonno 1 ta variable nei count ja initial 0.
while loop er moddhe
  int rem=n%2 kori and protibar n=n/2 kori.Check kori rem == 1 kina karon amar 1 count kora lagbe binary represntation e.
 1ta condition dei
  if(rem==1) hoile count++ kori. Loop er moddhe n=n/2 kori 
return kori count.

function for countbit(int n):
-----------------------------

int countbit(int n)
   {
    int count=0;
    while(n>0)
    {

    
    int rem=n%2;
    if(rem==1)
    {
      count++;
    }
    n=n/2;
    }
    return count;
   }

Erpor Main Function er kaj:
----------------------------

Main function e 1 ta vector array nei ans. Karon amr chaise array akare.
0 to n porjonto sob number er binary te 1 koyta ase ta array akare chaise.
So, 1 ta for loop chalai i=0 to i<=n porjonto i++ kori'
function countbit(int n) call kore vector array te push kor.
return kori ans.


loop to push in array r code:
-----------------------------

 vector<int>ans;
       for(int i=0;i<=n;i++)
       {
        ans.push_back(countbit(i));
       }

Main Function:
---------------
vector<int> countBits(int n) 
    {
        
       vector<int>ans;
       for(int i=0;i<=n;i++)
       {
        ans.push_back(countbit(i));
       }
       return ans;
    }

Full Code:
----------
class Solution 
{
public:
   int countbit(int n)
   {
    int count=0;
    while(n>0)
    {

    
    int rem=n%2;
    if(rem==1)
    {
      count++;
    }
    n=n/2;
    }
    return count;
   }
    vector<int> countBits(int n) 
    {
        
       vector<int>ans;
       for(int i=0;i<=n;i++)
       {
        ans.push_back(countbit(i));
       }
       return ans;
    }
};
  
