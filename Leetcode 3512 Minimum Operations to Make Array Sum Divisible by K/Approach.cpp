Amar 1 ta array ase jar nam nums.1 ta int ase k.Eder sum k dia divisible kina Jodi divisible na hoy kotota operation lagbe divisible korte ta chaise

First e 1 ta function banai main function er baire sum ber korbo array r

So,
Helper Function:
----------------
  int findsum(vector<int>& nums)
 {
  int sum=0;
  for(int i=0;i<nums.size();i++)
  {
    sum+=nums[i];
  }
  return sum;
 }
main function e 
1 ta variable nei op ja initial 0.Eta diya calculate korbo koyta operation lage.
Hishaber subidhar jonno findsum() function call kore 1 ta variable nei jar nam a
So,
 int a=findsum(nums);
Jotokkhon na k diya divisible hoy totokkhon sum komabo
So,
barbar iterate tai while loop iterate kori jekhane a%k!=0
  check kori a ,k er soman na kina 
So,
    if(a!=k)
  jodi true hoy taile
a-- kori ba komai
operation barai 1 kore 
So,
  op++
  loop break er condition jodi divisible hoy 
So,
 if(a%k==0)
          {
            break;
          }
return kori op
karon chaise koyta operation

Main Function:
---------------
  int minOperations(vector<int>& nums, int k) 
    {
      int op=0;
      int a=findsum(nums);
      //while(findsum(nums)%k!=0)
      while(a%k!=0)
      {
          if(a!=k)
          {
            a--;
          }
          
          op++;
          if(a%k==0)
          {
            break;
          }
      }
      return op;
    }

Full Code:
-----------

  class Solution 
{
public:
 int findsum(vector<int>& nums)
 {
  int sum=0;
  for(int i=0;i<nums.size();i++)
  {
    sum+=nums[i];
  }
  return sum;
 }
    int minOperations(vector<int>& nums, int k) 
    {
      int op=0;
      int a=findsum(nums);
      //while(findsum(nums)%k!=0)
      while(a%k!=0)
      {
          if(a!=k)
          {
            a--;
          }
          
          op++;
          if(a%k==0)
          {
            break;
          }
      }
      return op;
    }
};
