Amar 1 ta 0-indexed array ase jar nam nums.1 ta int ase jar nam target.Ekhane bolse koto gula pair ase jader sum hoilo target theke choto.
  Bolse 0 <= i < j < n and nums[i] + nums[j] < target.
  As bolse kotogula pair tai ami 1 st e 1 ta variable nei jar nam count ja initial 0.
1 ta for loop chalai i=0 to n porjonto pura array traverse kori
nested for loop chalai j=i+1 to n porjonto as i<j<n
check kori condition 
if((nums[i]+nums[j])<target)
   true hoile count++ kori
  return kori count.
