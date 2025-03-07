Amar 1 ta array ase .1 ta integer ase k.Amar array r number gula k binaary te convert kore kotogula 1 ase ta calculate korbo.Check korbo oi array r value gular binary 
te 1 er count k er equal kina.Jodi equal hoy oi index er value i gula add kore return korbo.
  Approach:
------------
  First e 1 ta helper function banai 1 ta number er binary te 1 kotogula ta count er jonno
ei function e 1 ta while loop chalai jekhane n>0
  1 ta variable nei rem ja n%2 eta nibo 1 count er jonno
check kori condition rem ==1 kina hoile count++ kori
  return kori count.
  Helper function is:
----------------------
  int findsetbit(int n)
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

Main Function er kaj:
--------------------
  1 ta variable nei int sum ja initial 0.
  1 ta vector array nei reserve ete oi number rakbo jader binary te 1 er count k er soman
  
    As amar 1 ta array ase tai ami 1 ta loop chalai for i=0 to i<arr.size() porjonto and i++ kori
    Tai er moddhe findsetbit(i) call kori check kori k er equal kina .Karon amr chaise index er binary te 1 k efr equal kina
  hoile reserve e push kori nums[i]
  Aro 1 ta loop chalai for j=0 to j<reserve.size() porjonto j++ kori
  sum+=reserve[j] kori
  return kori sum.
Main Function:
-------------------
  int sumIndicesWithKSetBits(vector<int>& nums, int k) 
    {
        vector<int>reserve;
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
          if(findsetbit(i)==k)
          {
            reserve.push_back(nums[i]);
          }
        }
        for(int j=0;j<reserve.size();j++)
        {
          result+=reserve[j];
        }
        return result;
    }

Full Code:
-----------

  #include<vector>
class Solution 
{
public:
 int findsetbit(int n)
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
    int sumIndicesWithKSetBits(vector<int>& nums, int k) 
    {
        vector<int>reserve;
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
          if(findsetbit(i)==k)
          {
            reserve.push_back(nums[i]);
          }
        }
        for(int j=0;j<reserve.size();j++)
        {
          result+=reserve[j];
        }
        return result;
    }
};
  
