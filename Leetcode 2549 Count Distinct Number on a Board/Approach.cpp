Amar input jokhon 5 tokhon output 4
Amar input jokhon 3 tokhon output 2
Jokhon 1 tokhon output 1
4=5-1=n-1
2=3-1=n-1
if(n>1)
  return n-1;
else
  return n;
Full Code:
----------

  #include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:
    int distinctIntegers(int n) 
    {
      if(n==1)
      {
        return n;
      }
      else
     return n-1;
      }
    
};
