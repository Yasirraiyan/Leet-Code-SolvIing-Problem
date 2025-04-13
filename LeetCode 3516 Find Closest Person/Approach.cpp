Amar 3 ta integer ase x,y,z
  2 ta person ase a,b
  amar both person z e pouchate chay
amar z er sathe x,y er diff lagbe
check korbo kar kom 
jodi a er kom hoy taile 1 return 
jodi b er kom hoy taile 2 return 
jodi equal hoy taile 0 return

So,
  first e
abs(z-x) nei int a te rakhi
abs(z-y) nei int b te rakhi 
So,
  int a=abs(z-x);
        int b=abs(z-y);
1 ta variable nei ans 
eta diya result rakhgbo compare e
jodi a,b equal hoy taile ans=0  return korte bolse 
So,
 if(a==b)
        {
          ans=0;
        }
Jodi a age jay b pore jay mane a<b hoy taile 1 return 
So,
 if(a<b)
        {
          ans=1;
        }
ei duita na hole 2 return 
So,
   else
        {
           ans=2;
        }
return ans


Full Code:
----------
  class Solution 
{
public:
    int findClosest(int x, int y, int z) 
    {
        int a=abs(z-x);
        int b=abs(z-y);
        int ans;
        if(a<b)
        {
          ans=1;
        }
        else if(a==b)
        {
            ans=0;
        }
        else
        {
           ans=2;
        }
        return ans;
    }
};
