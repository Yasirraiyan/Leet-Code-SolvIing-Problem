Amar 1 ta array ase amar ei element gula r moddhe jara 3 dia divisible na tader count lagbe

So, 1 ta variable nei count ja initial 0.Eta dia operation count korbo.
 1 ta for loop chalai i=0 to i<arr.size() porjonto i++ kori
  check 3 dia divisible na na hoile add  korba 1 tai
  
if(nums[i]%3!=0)
          {
          nums[i]=nums[i]+1;
            count++;
          }

  chaise number of operation 
return kori count.

Full Code:
------------

class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
      int count=0;
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]%3!=0)
          {
          nums[i]=nums[i]+1;
            count++;
          }
        }
        return count;
    }
};
