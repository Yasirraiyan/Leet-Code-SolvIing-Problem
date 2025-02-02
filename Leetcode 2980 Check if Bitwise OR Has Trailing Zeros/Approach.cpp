Check korte hbe bitwise OR er trailing zero mani laste 0 ase kina.
  Amar 1 ta array ase.1ta variable nei result ja initial 0.
first e 1 ta for loop chalai i=0 to n porjonto pura array traverse kori
nested for chalai 
j=i+1 to n porjonto karon nijer sathe nibo na
check kori j same index na 
if(i!=j)
  result er sathe OR kori
result|=nums[i]
trailing zero check 
  if((result&1)==0)
        {
              return true;
        }
naile 
return false;
