Amar 1 ta array ase. Amar chaise Ei array  r element gular sum. And Element er digt er sum er difference.
  Example;
arr=[11,45]
  element sum=11+45=56;
digit sum=1+1+4+5=11;
difference=45-11=34
  return korbo 34
  1 st e 1 ta function banai alada kore main function er baire.kono number er digit er sum er jonno 
Function e int rem=n%10;
int sum=0;
sum+=rem;
while(n>0)
  return sum;

    int digitsum(int n)
{
    int sum1=0;
    while(n>0)
    {
        sum1+=n%10;
        n=n/10;
    }
    return sum1;
}
main function e 
1 ta for loop chalai i=0 to i<n porjonto array traverse kori
array r sum er jonno 1 ta variable nei int sum2 ja initial 0.
  loop er moddhe sum2+=nums[i];
eita hoilo array r element sum
Digit sum er joono aro 1 ta alada for loop chalai i=0 to i<n porjonto
1 ta variable nei sum3 ja initial 0.Etate digit sum store kori digitsum function call kori
  for(int i=0;i<nums.size();i++)
        {
          sum3+=digitsum(nums[i]);
        }
result nei digitsum ar element sum er difference er modulas
   result=abs(sum2-sum3);
return kori result.

  Full code:
#include<vector>
#include<iostream>
#include<cmath>
class Solution {
public:
int digitsum(int n)
{
    int sum1=0;
    while(n>0)
    {
        sum1+=n%10;
        n=n/10;
    }
    return sum1;
}
    int differenceOfSum(vector<int>& nums) 
    {
        int sum2=0;
        int sum3=0;
        int result;
        for(int i=0;i<nums.size();i++)
        {
            sum2+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
          sum3+=digitsum(nums[i]);
        }
        result=abs(sum2-sum3);
        return result;
    }
};
