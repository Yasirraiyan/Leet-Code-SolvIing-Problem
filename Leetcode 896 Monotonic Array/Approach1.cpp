Ammar 1ta array ase.Eta monotonic hbe jodi increasing decresing dui order ei thake.
  Kintu condition for all i<=j
  incresing if nums[i]<=nums[j]
decreasing if nums[i]>nums[j] hoy.
  Taile ami 1 ta loop chalai 
for loop from i=0 to i<n;i++ porjonto for taking the array input;
then nested aro 1 ta for loop chalai from j=0 to j<n;j++ porjonto karon eta die check korbo array protita index.
  check kori 
if(nums[i]<=nums[j])
so,decreasing=false;
increasing=true;
monotone=incresing=true;
aro 1 ta check kori 
if(nums[i]>=nums[j])
  so,increasing=false;
decresing=true;
monotone=decresing=true;
aro 1ta condition dei 
increasing decreasing na hoy taile monotone=false;
so,
  if(!increasing&&!decreasing)
  monotone=false;
return monotone;
eta 1 ta solution approach.
  kintu eta te prb ase karon nested loop timecomplexity O(n^2);
tai time exceed.So,i give another solution for reducing time complexity.So go file Approach2.cpp
