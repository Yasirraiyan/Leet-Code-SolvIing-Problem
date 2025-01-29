Amar 1 ta array ase.
  and bolse pair of number koyta jeta mane |nums[i] - nums[j]| == k.
  and i<j
so, first e 1 ta for loop chalai i=0 to n porjonto
then as i<j
tai nested for loop chalai j=i+1 to n porjonto 
check condition 
          if(i<j)
                {
                    if(abs(nums[i]-nums[j])==k)
                    {
hoile count++;
first e 1ta varaible rakhi count ja initial 0 karon chaise koyta.
  return kori count.
