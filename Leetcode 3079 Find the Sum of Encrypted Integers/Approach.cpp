Amar 1 ta array ase amar array r protita element er encrypted integer er sum lagbe
Exa:
------
  int n=57
  largest digit is:7
  So,
  Encrypted integer of 57 is:77
  Mane sob digit gula k largest digit diye replace kori
So,
First e ami 1 ta function create kori encrypted integer ber korbo
1 ta while loop chalai jekhane n>0
  digit=n%10
  kori 
  n=n/10
  kori
  1 ta vector nei reserve digit rakhbo 'tai
    reserve.push_back(rem);kori
Loop is:
-----------

    while(n>0)
    {
      int rem=n%10;
      reserve.push_back(rem);
      n=n/10;
    }
largest digit ba max ber kori tai
initial int max=reseerve[0]
1 ta for loop chalai i=1 to i<n porjonto
    if(reserve[i]>max)
      {
        max=reserve[i];
      }
kori
i=1 karon i=0 initial max onnogula check
Runtime kome
Sob value max dia change kori
tai 
alada for loop chalai j=0 to j<reserve.size() porjonto and j++ kori
  and
 reserve[j]=max; kori
loop code:
----------

  for(int j=0;j<reserve.size();j++)
    {
      reserve[j]=max;
    }
sum ber kori
1 ta for loop chalai k=0 to k<reserve.size() porjonto k++ kori
  encrypted ber korew sum kori
Exa:
-----
  n=48 
  digit =[4,8]
  48=4x10^1+8x10^0
  i=0 nums[i]=4
  size =2 
  1=2-0-1=2-i-1=nums.size()-i-1
  4x10^1=nums[i]*pow(10,nums.size()-i-1) kori
Tai
 sum+=reserve[k]*pow(10,reserve.size()-k-1);
kori
Loop is:
--------

   int sum=0;
    for(int k=0;k<reserve.size();k++)
    {
      sum+=reserve[k]*pow(10,reserve.size()-k-1);
    }
Sum chaise
return sum kori

Helper Function:
-------------------

  int findencrypted(int n)
  {
    vector<int>reserve;
    vector<int>encrypt;
    while(n>0)
    {
      int rem=n%10;
      reserve.push_back(rem);
      n=n/10;
    }
    int max=reserve[0];
    for(int i=1;i<reserve.size();i++)
    {
      if(reserve[i]>max)
      {
        max=reserve[i];
      }
    }
    for(int j=0;j<reserve.size();j++)
    {
      reserve[j]=max;
    }
    int sum=0;
    for(int k=0;k<reserve.size();k++)
    {
      sum+=reserve[k]*pow(10,reserve.size()-k-1);
    }
    return sum;
  }
Main Function:
---------------
  1 ta value rakhi result ja initial 0
eta dia encrypted integer er sum nibo
1 ta for loop chalai m=0 to m<nums.size() porjonto m++ kori array traverse kori
Encrypted function call kori
for(int m=0;m<nums.size();m++)
        {
          result+=findencrypted(nums[m]);
        }
return kori result.

  Full Code:
----------------

  class Solution 
{
public:
  int findencrypted(int n)
  {
    vector<int>reserve;
    vector<int>encrypt;
    while(n>0)
    {
      int rem=n%10;
      reserve.push_back(rem);
      n=n/10;
    }
    int max=reserve[0];
    for(int i=1;i<reserve.size();i++)
    {
      if(reserve[i]>max)
      {
        max=reserve[i];
      }
    }
    for(int j=0;j<reserve.size();j++)
    {
      reserve[j]=max;
    }
    int sum=0;
    for(int k=0;k<reserve.size();k++)
    {
      sum+=reserve[k]*pow(10,reserve.size()-k-1);
    }
    return sum;
  }
    int sumOfEncryptedInt(vector<int>& nums) 
    {
        int result=0;
        for(int m=0;m<nums.size();m++)
        {
          result+=findencrypted(nums[m]);
        }
        return result;
    }
};
