Amar 1 ta array ase nums. Amar 1 ta integer ase target.Amar chaise ei array ke sort kore jotogula index e target er equal value ase sob index chaise array akare.

So, first e ami 1 ta array create kori vector ans.
  ami sort kori given array nums k
by the below code:
------------------
     sort(nums.begin(),nums.end());
1 ta for loop chalai i=0 to i<nums.size() porjonto i++ kori Eta diye nums array traverse kori
check kori kono value target er equal kina,
So,
 if(nums[i]==target)
 true hoile ans e push kori i. Karon amr chaise index jar moddhe jei number ase ta target er equal.
so,
  ans.push_back(i);

The code of if:
---------------
  if(nums[i]==target)
          {
            ans.push_back(i);
          }
The Code of for loop with if:
-----------------------------
  for(int i=0;i<nums.size();i++)
        {
          if(nums[i]==target)
          {
            ans.push_back(i);
          }
        }
return kori ans.

Full Code:
------------

  #include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]==target)
          {
            ans.push_back(i);
          }
        }
        return ans;
    }
};
