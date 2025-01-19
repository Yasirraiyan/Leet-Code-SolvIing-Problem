Amar 1 ta integer ase.Amar ans ber korbo oi integer er digit gular product ar sum er subtract.
Dhori 1 ta integer=234
  product=2*3*4=24;
 sum=2+3+4=9;
result=24-9=15
  exa 2
  n=4421
  sum=4+4+2+1=11;
  product=4*4*2*1=32;
  result=32-11=21;
n hoilo 1<=n<=10^5;
product long long type;
ami ekta variable nibo sum ja initial 0
aro 1 ta variable product ja initial 1;
sob digit add er product korbo so amr reminder lagbe again again 10 dia divide ar reminder lsgbe;
so ami ekta while loop nibo jekhane n>0
  er vitore operation
n=n%10;
sum+=n;
product*=n;
n=n/10;\
loop er baire aisha 
product-sum kori ja result variable e rakhi.
return kori result.
