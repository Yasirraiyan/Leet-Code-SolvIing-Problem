Amar 1 ta integer ase. Amar ei integer er digit er sum lagbe but eikhane condition hoilo
Exa:
-----
  n=521;
sum=(+5)+(-2)+(+1)=4;
n=111
  sum=(+1) + (-1) + (+1) = 1.
   n = 886996
  sum= (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.

  Tar mane 1st digit (+),2nd digit(-),3rd digit(+),4th digit(-) erokom
Tar mane bujha jay odd position (+)
                   even position (-)
Approach:
---------
  So, 1 st e ami ekta array nei reserve ete ami digit store korbo,
  1 ta variable nei sum ja initial 0. Ete sum store korbo.
  
  Digit calculate:
--------------------
  1 ta while loop chalai jekhane n>0 , 1 ta int variable nei rem where rem=n%10;
reserve e push kori rem;
reserve.push_back(rem);
n=n/10 kori
  1 ta for loop chalai i=0 to i<reserve.size() porjonto and i++ kori Ete vector array traverse kori

  
Check Odd Position:
-------------------
  if(i%2!=0) 2 diye divide e rem 0 na hole odd
  then 
  sum+=reserve[i]; Karon odd position er sign(+)

  Check Even Position:
-----------------------
  if(i%2==0) 2 diye divide e rem 0  hole odd
  then 
  sum+=(-1)*reserve[i]; Karon odd position er sign(-)

  return kori sum.

-------------------
