Amar 2 ta pointer ase low,high amr ei [low,high] range er moddhe kotgula syymmetric int ase ta chaise.

Symmetric int:
---------------
  Symmetric int hoilo oi integer jar 1 st half of digit er sum last half of digit er sum er equal
  Exa:
---------
  n=1230
  digit 4 ta half of digit =4/2=2
  first half of digits =1,2; sum=1+2=3
  last half of digits=3,0; sum=3+0=3
  same tai true return kori
Kintu amr 1 ta range deya ase eder moddhe kotogula int symmetric tar count chaise
First e 1 ta helper function banai main function er baire bool symmetric(int n) eta diye test korbo symmetric kina
tai 1 st e 1 ta variable nei bool issymmetric ja initial false
  1 ta vector nei reserve ete int er digit gula store korbo
1 ta while loop chalai where n>0 karon digit lagbe barbar iterate koro n%10
  int rem=n%10;
reserve.push_back(rem) kori
kori
n=n/10 kori
  as divide 2 equal part
tai size ba digit number even hoy
odd hoile false
  tai 2 diya divide kore reminder check kori 0 kina 0 hoile even naile odd
if(reserve.size() % 2 != 0)
  odd 
    return false;
sum ber korbo first half ar second half er
binary serch er moto mid ber kori
2 ta pointer nei high,low
  array:[1,2,3,4] array size=4 index:0,1,2,3
                  low index =0
    high index=3=4-1=array.size()-1
  mid=(low+high)/2
  sum ber kori first half (from index 0 to index 2)
   1 ta loop chalai for from i=0 to i<=mid;i++ kori  ekhane sum1+=reserve[i] kori
  2 ta variable nei sum1,sum2 jara initial 0
  sum1 first half er sum
 sum2 second half er sum
aro 1 ta alada for loop chalai j=mid+1 to j<arr.size() porjonto j++ kori(from index 3) as size 4 baki index=3=2+1=mid+1 j<arr.size() j<4 mani 3 porjonto
second half er sum ber kori
sum2+=resetve[j] kori
check kori 2 ta sum same kina 
hoile 
issmmetric=true kori'
return kori issmetric
odd digit count hoy taile equal part e divide impossible 
so,
odd er jono test j reserve.size() odd kina karon odd digit hoile tar size same karon digit joto array size toto
So,
test 2 ta divide rem 0 kina jodi 0 na hoy taile odd so,issymmetric=false;
So,
  condition is:
-----------------
  if (reserve.size() % 2 != 0) 
  {
     return false;
   }
Helper Function:
--------------------
  bool symmetric(int n)
{
  bool issymmetric=false;
  vector<int>reserve;
  while(n>0)
  {
    int rem=n%10;
    reserve.push_back(rem);
    n=n/10;
  }
  if (reserve.size() % 2 != 0) 
  {
     return false;
   }
  int low=0;
  int high=reserve.size()-1;
  int mid=(low+high)/2;
  int sum1=0;
  int sum2=0;
  for(int i=0;i<=mid;i++)
  {
    sum1+=reserve[i];
  }
  for(int j=mid+1;j<reserve.size();j++)
  {
    sum2+=reserve[j];
  }
  if(sum1==sum2)
  {
    issymmetric=true;
  }
return issymmetric;
}
Main Function:
-----------------
  as ekta range ase [low,high] 
  tai ekta for loop chalai k=low to k<=high porjonto k++ kori range traverse kori
chaise koyta symmetric tai initial 1 ta variable nei count ja initial 0
loop er moddhe function call kore test kori function e i pathai
So,
condition:
if(symmetric(k))
  hoile count++ kori

  Loop Code:
--------------
  for(int k=low;k<=high;k++)
        {
          if(symmetric(k))
          {
            count++;
          }
        }
return kori count

Main Function:
---------------

  int countSymmetricIntegers(int low, int high)
     {
        int count=0;
        for(int k=low;k<=high;k++)
        {
          if(symmetric(k))
          {
            count++;
          }
        }
        return count;
    }

Full Code:
------------

  class Solution 
{
public:
bool symmetric(int n)
{
  bool issymmetric=false;
  vector<int>reserve;
  while(n>0)
  {
    int rem=n%10;
    reserve.push_back(rem);
    n=n/10;
  }
  if (reserve.size() % 2 != 0) 
  {
     return false;
   }
  int low=0;
  int high=reserve.size()-1;
  int mid=(low+high)/2;
  int sum1=0;
  int sum2=0;
  for(int i=0;i<=mid;i++)
  {
    sum1+=reserve[i];
  }
  for(int j=mid+1;j<reserve.size();j++)
  {
    sum2+=reserve[j];
  }
  if(sum1==sum2)
  {
    issymmetric=true;
  }
return issymmetric;
}
    int countSymmetricIntegers(int low, int high)
     {
        int count=0;
        for(int k=low;k<=high;k++)
        {
          if(symmetric(k))
          {
            count++;
          }
        }
        return count;
    }
};
  

  

