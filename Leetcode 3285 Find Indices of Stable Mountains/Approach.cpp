Amar 1 ta array ase height . 1 ta int ase threshold. Amar moutain stable hbe jodi height threshold theke beshi hoy shei index chaise array akare.

1 ta vector create kori ans.Chaise array index er 
1 ta for loop chalai i=1 to i<n porjonyo i++ kori
karon array traverse kori
as ager index check ja treshold theke beshi 
check i-1 index er man
if(height[i-1]>threshold)
  chaise index tai
ans.push_back(i);
kori 
i=1 karo i-1=0 ja exist kore
jodi i=0 theke traverse kori taile i-1=-1 ja exist kore na C++ e runtime error hbe 
tai i=1 theke for loop iterate kori
return kori ans.

Full Code:
------------

  #include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:
    vector<int> stableMountains(vector<int>& height, int threshold) 
    {
        vector<int>ans;
        for(int i=1;i<height.size();i++)
        {
          if(height[i-1]>threshold)
          {
            ans.push_back(i);
          }
        }
        return ans;
    }
};
