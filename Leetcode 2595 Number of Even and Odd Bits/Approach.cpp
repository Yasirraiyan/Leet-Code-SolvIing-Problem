Amar 1 ta integer deya ase jar nam n.
  Amar ei n ke binary te niye amk bolse even index kotogula ar odd kotogula ta ber kore 1 ta array return korte.
ami duita array create kori ans r result.
  ans e rakhbo binary te convert er bit gula.
ar result e rakhbo even kotogula ar odd kotogula.
  First convert it binary:
---------------------------
  1 ta while loop chalai where n>0
  1 ta integer nei rem

rem=n%2;
ans e push kori rem
 ans.push_back(rem);
n=n/2 kori

Full while loop:
-----------------

  while(n>0)
        {
          int rem=n%2;
          ans.push_back(rem);
          n=n/2;
        }
amar lagbe even kotogula ar odd kotogula 
jodi arr[i]==1 hoy taile odd jodi arr[i]==0 hoy taile even
So, 1 st e duita variable nei even r odd ja initial 0.

1 ta for loop chalai i=0 to i<ans.size() porjonto ans array traverse kor
check if(ans[i]==1)
 mane odd(i%2!=0) mane index number odd and ans[i]==1 both condition then odd++;
so,
if((i%2!=0)&&(ans[i]==1))
          {
              odd++;
               
          }
so, odd++;
check for even;
first check 
 if(ans[i]==1)
  mane even (i%2==0) mane index number even and ans[i]==1 both condition then even++;
if((i%2==0)&&(ans[i]==1))
          {
                even++;
               
          }
amar chaise kotogula odd ar kotogula even tar value array akaare so,
result array te push kori even odd
so,
    result.push_back(even);
    result.push_back(odd);
return kori result.
  karon amar array chaise output.


Full code:
-----------

  class Solution
{
public:
    vector<int> evenOddBit(int n)
{
        vector<int>ans;
        int even=0;
        int odd=0;
        vector<int>result;
        while(n>0)
        {
          int rem=n%2;
          ans.push_back(rem);
          n=n/2;
        }
        for(int i=0;i<ans.size();i++)
        {
          if((i%2==0)&&(ans[i]==1))
          {
                even++;
               
          }
        if((i%2!=0)&&(ans[i]==1))
          {
                odd++;
               
        }
        }
    result.push_back(even);
    result.push_back(odd);
            return result;
    }
};
