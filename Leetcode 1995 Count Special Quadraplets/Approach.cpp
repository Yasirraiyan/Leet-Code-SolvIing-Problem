Amar check korte hbe nums[a]+nums[b]+nums[c]=nums[d] kina 
so,ami 4 ta nested for loop chalabo.
  As a<b<c<d
So. 1st for loop chalai a=0 to a<nums porjonto
2nd nested for chalai b=a+1 to b<nums porjonto
3rd nested for chalai c=b+1 to c<nums porjonto
4th nested for chalai d=c+1 to d<nums porjonto
then condition check
if((a<b)&&(b<c)&&(c<d)&&(d<nums.size()))
nested if chalai aro 1ta condition check 
  if(nums[a]+nums[b]+nums[c]==nums[d])
jodi true hoy
jehetu amar kotogula chaise so,[initial count=0] amar kotogula chaise tai.
count++;
return korbo count.
