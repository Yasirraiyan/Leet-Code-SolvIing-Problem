Amar 1 ta array ase jar nam nums.Dui index (i,j)
Condition
abs(i - j) >= indexDifference, and
abs(nums[i] - nums[j]) >= valueDifference
  Make array return korte bolse
(i,j) equal hoileo acceptable.
So, first e ami 1 ta vector array create kori jar nam ans.
  Karon amake array return korte bolse.
  1 ta for loop chalai i=0 to n porjonto pura array traverse kori.
nested for chalai j=0 to n porjonto eta dia compare kori array er prottekke. bolse i,j equal hote pare. tai nested for chalai j=0 hte 
  Condition check
if (((abs(i - j)) >= indexDifference) && (abs(nums[i] - nums[j]) >= valueDifference))  
indexdifference,valuedifferewnce qu te dea ase.
  condition true hoile
ans.push_back() kori (i,j) karon amr oi duita index chaise 
return kori ans.
