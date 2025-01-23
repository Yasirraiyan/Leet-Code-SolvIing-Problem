Amar 3 ta integer ase a,b,c. Amar chaise kotogula triple ase.So,ami 1 ta variable akhbo count ja initial 0.
as amar array ase .So,amar 1 ta for loop chalaite hbe i=0 to n porjonto pura array traverse kori.
Amar j,k duita ase
so,aro 2 ta nested for loop chalabo mot 3 ta nested for loop
as i<j<k
so j=i+1 to n
and k=j+1 to n prjonto chalab
erpor condition check kor j
  if ((0 <= i) && (i < j) && (j < k) && (k < arr.size()))
                    {
                        if((abs(arr[i] - arr[j])<=a)&&(abs(arr[j] - arr[k])<=b)&&(abs(arr[i] - arr[k])<=c))
                          eitya true hoile count++ kori 

as amar koto gula triple ase ta chaise so ami protibar count++ kori
  return kori count.
