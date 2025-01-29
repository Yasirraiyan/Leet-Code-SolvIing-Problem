Amar 1 ta array ase 0-indexed.
  condition
  0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.
first count variabl rakhi ja initial 0 karon chaise kototi.
So, first e 1 ta for loop chalai i=0 to n porjonto pura array traverse kori
as i<j
nested for loop chalia j=i+1 to  n porjonto.
then check kori 
if((0<=i)&&(i<j)&&(j<nums.size())) // it is for   0 <= i < j < n;
nested if chalai
 if((nums[i]==nums[j])&&((i*j)%k==0)) // it is for nums[i] == nums[j] and (i * j) is divisible by k.
true hoy
count++;
return count.

