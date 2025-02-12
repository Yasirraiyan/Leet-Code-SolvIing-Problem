Amar 2 ta integer ase a,b amar ei dui integer er common factor  kotogula ta chaise.
1 ta for loop chlai i=1 to i<=a porjonto 
  duita array create kori arr1,arr2 vector arr1 tar moddhe rakhbo a er factor.arr2 er moddhe rakhbo b er factor.
check kor
 if(a%i==0)
  true hoy
arr1.push_back(i);
alada for loop chalai not nested
j=1 to j<=b porjonto
 if(b%j==0)
  true hoy
arr2.push_back(j);
1 ta for loop chalai k=0 to k<arr1.size() porjonto arr1 traverse kori
nested for loop chalai m=0 to m<arr2.size() porjonto arr2 traverse kori
check condition same value kina 
if(arr1[k]==arr2[m])
jdi same hoy ba true hoy
count++ kori
  chaise count koyta common
return kori count.
  chaise common factor er count.
