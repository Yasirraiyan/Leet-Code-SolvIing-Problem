Amar 1 ta circle ase ei circle k kotogula equal part  e divide kora jay ta chaise
Test Case :
-----------
  if n=4 hoy 
  4=2+2 
  2-1 ta 
  2- 1 ta 
  total 2 ta 2=4/2
if n=3 hoy
  3=1+1+1
  3 ta 1 ja equal 3=3
total 3 ta 
if n==1 hoy
  equal part e vag possible na tai 0
1 ta variable nei ans ja dia return nkorbo
Ekta condition if (n==1) 
 ans= 0;
n jodi 1 er beshi hoy if(n>1)
 n jodi even hoy
taile 
n/2 part 
 So,
  condition
     if(n%2==0)
        {
          ans=n/2;
        }
n jodi odd hoy 
taile 
n part
So,
 if(n%2!=0)
        {
          ans=n;
        }
Era hbe jodi n>1 hoy
  So,
   if(n>1)
      {

      
        if(n%2==0)
        {
          ans=n/2;
        }
        if(n%2!=0)
        {
          ans=n;
        }
      }
return kori ans;

Full Code:
-----------

  class Solution 
{
public:
    int numberOfCuts(int n) 
    {
      int ans;
      if(n==1)
      {
        ans=0;
      }
      if(n>1)
      {

      
        if(n%2==0)
        {
          ans=n/2;
        }
        if(n%2!=0)
        {
          ans=n;
        }
      }
        return ans;
    }
};
