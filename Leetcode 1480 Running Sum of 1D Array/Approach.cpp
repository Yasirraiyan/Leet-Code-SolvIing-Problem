Amar 1 ta array ase.Ei array er value gular proti index e previous value gular sum thakbe.

Exa:
nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
  So, ami 1 ta for loop chalai i=0 to i<nums.size() porjonto and i++ kori
  amar 0 th er sum 0 index e er age index nai
1 th e sum (0,1) ei 2 ta index er 
abr 2 nd e sum (0,1,2) ei 3 ta mane
 j=0 jokhon tokhon i calculate 0
  j=1 tokhon i calculate (0,1)
 mane j<=i
  nested for loop chalai j=0 to j<=i porjonto and j++ kori
  initial 1 ta variable nei sum ja initial 0.
1 st for loop er moddhe sum=0 kori karon first tarveeses e sum nibona nile pura array r sum ber hbe tokhn hbe na
2 nd  for loop o nested for loop e sum+=nums[j] kori 
As output array akare chaise tai 
1 st e 1 ta vector nei ans ete sum store korbo index wise'
  2 nd for loop er moddhe ans.push_back(sum) kiri
return kori ans.

Full Code:
-----------

  class Solution 
{
public:

    vector<int> runningSum(vector<int>& nums) 
    {
      vector<int>ans;
      int sum=0;
       for(int i=0;i<nums.size();i++)
       {
        sum=0;
        for(int j=0;j<=i;j++)
        {
            sum+=nums[j];
        }
        ans.push_back(sum);
       }
       return ans;
    }
};
