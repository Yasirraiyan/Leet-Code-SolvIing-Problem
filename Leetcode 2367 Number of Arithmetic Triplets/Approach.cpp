Amar 1 ta array dise.
  and lagbe kotgula ase.
  condition i<j<k
first e 1ta variable nei count ja initial 0 hishab kori kotogula
for loop chalai first pura array traverse kor i=0 to n porjont
as i<j
tai nested for chalai j=i+1 to n porjonto
as j<k
tai aro 1 ta nested for chalai k=j+1 to n porjonto
Den check kori
if(i<j)&&(j<k)&&(i<k)&&)(k<nums)
nested if chalai 
je
if((nums[j]-nums[i]==diff)&&(nums[k]-nums[j]==diff))
// (k<nums) karon jeno bound na saray jay
true hoy count++ kori;
return count;
amar chaise kotogula tai 
