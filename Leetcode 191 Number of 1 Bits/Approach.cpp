Amar 1 ta integer ase. Amar lagbe oi integer e kotogula 1 ase binary te neyar por.Eta k bola jay Hamming Weight.
  So, 1 st e binary te nibo.
  Tai 1 ta while loop chalai where n>0
   1 ta integer nei rem 
rem=n%2;
Hishaber subidhar jonnoi 1 ta vector<int>ans array nei jetay rem store kori.
so,
  ans.push_back(rem);
n=n/2 kori.

Full while loop:
----------------

   while(n>0)
        {
          int rem=n%2;
          ans.push_back(rem);
          n=n/2;
        }
Then ei array ans er upor 1 ta for loop chalai i=0 to i<ans.size() porjonto i++ kori
  check kori jodi 1 pai taile weight count kori tai 1st e 1 ta variable nei int tye hw ja initial 0.
if(ans[i]==1)
          {
            hw++;
          }

return kori hw.
  
Full for loop:
--------------

   for(int i=0;i<ans.size();i++)
        {
          if(ans[i]==1)
          {
            hw++;
          }

        }
return hw.

  Full code:
-------------

  class Solution 
{
public:
    int hammingWeight(int n) 
{
      vector<int> ans;
      int hw=0;
        while(n>0)
        {
          int rem=n%2;
          ans.push_back(rem);
          n=n/2;
        }
        for(int i=0;i<ans.size();i++)
        {
          if(ans[i]==1)
          {
            hw++;
          }

        }
        return hw;
    }
};

  
