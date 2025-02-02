Amar 1 ta array ase jar nam operations.Amar operation korar pore finaal result chaise.
  So, 1st e 1 ta variable nei result ja initial 0.
  1 ta for loop chalai i=0 to n porjonto pura array traverse korte.
check kori condition for this (++X and X++ increments the value of the variable X by 1.)
 if(operations[i]=="X++"|| operations[i]=="++X")
            {
                result++;
            }
aro 1 ta  check kori condition for this (--X and X-- decrements the value of the variable X by 1.)
if(operations[i]=="--X"||operations[i]=="X--")
            {
                result--;
            }
as result chaise tai return kori result.
