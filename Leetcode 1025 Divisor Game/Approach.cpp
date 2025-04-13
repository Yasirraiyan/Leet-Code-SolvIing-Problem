Amr qn e test case n=2 hoile true;
ar n=3 hoile false;
So,
  1 st e 1 ta variable nai win test er jonno
  bool win ja initial false;
as n=2 hoile true mane n even hoile true
  n=3 hoile false mane n odd hoile false;
So,
  Even test 2 dia divide e rem 0 kina .0 hoile true
  So,
   if(n%2==0)
        {
          win=true;
        }
Test for odd because initial win =false tai opposite check
  return kori win;

Full Code:
-----------
  class Solution 
{
public:
    bool divisorGame(int n) 
    {
       bool win=false;
          if(n%2==0)
        {
          win=true;
        }
       return win;
    }
};

