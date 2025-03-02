Amar 1 ta array ase jar nam nums.Jokhon number even hbe tokhon oi number k replace korbo 0 dia.Ar jokhon number odd hbe tokhon oi number k replace korbo 1 dia.
  Then take sort korbo.
  Example:
----------
  arr=[0,1,1,0]
  sorted array=[0,0,1,1]
output sorted array.

  First e  1 ta vector array create kori ans. Etate even r odd gula check kore 0,1 push korbo. Ete amr sorting easy hbe.
  1 ta for loop chalai i=0 to i<nums.size() porjonto i++ kori Evabe array traverse korbo.

  Check even:
-------------
  if(nums[i]%2==0)
          {
            ans.push_back(0);
          }
mane even hle 0 push kori.

  Check Odd:
------------

  if(nums[i]%2!=0)
          {
            ans.push_back(1);
          }
mane even hle 1 push kori.

  Sorting the ans array:
------------------------

  std::sort(ans.begin(),ans.end());

return kori ans.
