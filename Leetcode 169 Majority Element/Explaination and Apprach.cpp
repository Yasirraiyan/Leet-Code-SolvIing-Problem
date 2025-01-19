Amar 1 ta array ase. Jetar size n.  Amar lagbe majority element mane konta beshi ase.
Ekhn 1 ta condition ase etar jonno j
Jei element (n/2) time er beshi ase Oi element return korbo.
1 ta variable rakhi count array r element koybar ase hishab korar jonno ja initial 0;
  Ami first e 1 ta for loop chalai n=0 to n porjonto eita dia pura array traverse kori
Aro 1 ta nested for loop chaalain j=0 to n porjonto.
  Check kori condition j 
if(arr[i]==arr[j]) mane jodi appear hoy
taile count++ kori.
  Erpor condition check kori j count ki (n/2) er beshi kina mane
if(count>n/2) jodi true hoy 
return korbo arr[i] mane oi index er value 
karon output chaise array index er value.
