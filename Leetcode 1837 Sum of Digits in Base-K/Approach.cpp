Amar 1 ta integer ase n 10 base 1 ta integer ase k jeta te k base e converet korbo 10 baser integer n k
n base convert korte hole n dia oi number divide kore reminder nei jottokkho vagfol 0 num 0 na ase totokkhon kori
So, 1 ta while loop nei jekhane n>0 bar bar kori
1 ta variable nei sum ja initail 0. chaise sum;
sum+=num%k;
num=num/k while loop e
return kori sum.
  class Solution {
public:
    int sumBase(int n, int k) {
        int sum=0;
        while(n>0)
        {
            sum+=n%k;
            n=n/k;

        }
       // n=n/k;
        return sum;
    }
};
while loop 
while(n>0)
        {
            sum+=n%k;
            n=n/k;

        }
