Amar 2 ta integer ase n ar start.
  AMke 1 ta array define korte bolse nums.
  So, 1st e 1 ta vector array create kori jar nam nums.
  vector<int>nums;
iniial sum rakhi 0.
as [0,n] er moddhe amake XOR tai 1 ta for loop chalai i=0 to i<n porjonto
sob number chai tai
nums e push kori start+2*i; karron proti index =Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length. bole dise
  nums.push_back(start+2*i);

for(int i=0;i<n;i=i+1)
        {
          nums.push_back(start+2*i);
        }
nums XOR er jonno array define complete jar nam nums.
  Ekhon bitwise XOR start korbo
aro 1 ta for loop chalai int j=0 to nums.size() porjontto  nums arrray r upor
sum er sathe XOR kori
 sum^=nums[j];

for(int j=0;j<nums.size();j++)
        {
           sum^=nums[j];
        }
as sum chase ans .return kori sum.
