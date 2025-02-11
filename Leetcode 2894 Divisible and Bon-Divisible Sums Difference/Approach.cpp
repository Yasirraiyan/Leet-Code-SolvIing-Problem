Amar 2 ta integer ase m,n. n hoilo [1,n] er moddhe number. m hoilo ekta integer ja dia test korbo divisible non divisible.Amar lagbe  divisible and non divisible sum difference.
So, 1 ta for loop chalai i=1 to i<=n porjonto. Duita variable nei sum1,sum2 both are 0 initially.sum1 hoilo jara non-divisible tader sum.sum2 hoilo jara divisible tader sum.
  for loop er vitor check kori
if(i%m!=0) true hoile non divisible so, sum1+=i;
Aro 1 ta condition check
if(i%m==0) true hoile  divisible so, sum2+=i;
1 ta variable nei result jar moddhe duitar difference(non divisible, divisible er difference) store korbo.
  So,
   result=sum1-sum2;
return kori result;
