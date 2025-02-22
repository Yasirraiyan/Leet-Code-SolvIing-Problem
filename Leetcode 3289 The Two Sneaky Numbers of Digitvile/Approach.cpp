Amar 1 ta array ase jar nam nums. Ei array te sob number 1 bar kore ase. Amar 1 ta array return korte bolse jei value gula repeted tader.
So, first e 1 ta array create kori vector karon amr chaise array jar nam ans.
  1 ta for loop chlai i=0 to i<nums.size() porjonto. Pura array traverse kor.
Nested for loop chalai j=i+1 to j<nums.size() porjonto.Check kori same element ase kina. Nijersathe nije compare korbo na.
  check different index.
if(i!=j)
  check repeated 
if(nums[i]==nums[j])
jodi true hoy 
  ans.push_back(nums[i]);
return kori ans.
purata 
if(i!=j)
            {
              if(nums[i]==nums[j])
              {
                ans.push_back(nums[i]);
              }
            }
Full code:
----------


  class Solution 
{
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
{
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
          for(int j=i+1;j<nums.size();j++)
          {
            if(i!=j)
            {
              if(nums[i]==nums[j])
              {
                ans.push_back(nums[i]);
              }
            }
          }
        }
        return ans;
    }
};
