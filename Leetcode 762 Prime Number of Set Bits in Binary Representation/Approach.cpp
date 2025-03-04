Amar 2 ta pointer deya ase left right. 1 ta range [left,right].Amar chaise  ei range er sob number binary te convert korbo.Proti number er set bits mane 1 koyta ase ta
count korbo.Ekhon ei count ta ki prime kina ta check korte bolse.True hoile count korbo koyta ei condition meet kore.Tar calculation chaise.

So,
  At first set bit 1 ta number er binary te koyta 1 ase ta count koro.
  Ei jonno 1 ta function banai alada count bits name.
  Ei function e 1 ta variable nei count ja initial 0.Eita  nisi karon ami 1 koyta ase ta count korte chai.
  First binary convert er jonno 1 ta while loop chalai jekhane n>0.karon bar bar iterate korbo jotokkhon na 0 hoy. 1 ta variable nei int rem ete reminder ba binary r bit store kori.Ekhane rem=n%2; karon binary te 
2 dia divide kore rem nei bit hishabe. check kori rem 1 kina.
  if(rem==1) taile count++ kori.loop er baire n=n/2 kori.
  return kori count.
Count bits Function:
---------------------
  int countbits(int n)
{
    vector<int>reserve;
    int count=0;
    while(n>0)
    {
        int rem=n%2;
      if(rem==1)
      {
        count++;
      }
        n=n/2;
    }
    return count;
}

Prime Check er jonno 1 ta function banai alada bool isprime(int n). Initial 1 ta variable nei bool isprime ja initial true.Eta dia primekina test ensure kori.
Eikhane ami 1 ta loop chalai i=2 to i*i<=n porjont and i++ kori.Karon prime shuru 2 theke.Ar 1 and oi number chara onno number dia divide e rem 0 hole prime na mane 
isprime=false;
As initial isprime=true.Tai opposite ba false er jonno condition test kori.Jodi n ,i  dia vag korle 
reminder 0 hoy taile false.Eta mane if(n%i==0) hole isprime=false;Eta hole break dibo karon quick exit from loop from reduce runtime.Naile true.
  return kori isprime.
  Jodi n 2 theke small hoy mane n=1 hoy taile prime na so isprime=false. if(n<2)
  So,
code is for the function bool is prime(int n):
------------------------------------------------
  
  bool isprime(int n)
{
    bool isprime=true;
    if(n<2)
    {
        isprime=false;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
           isprime=false;
           break;
        }
    }
    return isprime;
}

Ekhon main function er kaj:
---------------------------
Amar 2 ta pointer ase left, right for range [left,right] it is for count prime number of set bits within range.1 ta vector array nei result etate ami bit er count
rakhbo. countbits() function call korbo. and result e push kori.1 ta variable nei count ja initial 0.Eta dia bit count kori jara prime tader.

So, The Code Is:
-----------------

  for(int j=left;j<=right;j++)
        {
           result.push_back(countbits(j));
        }

Ekhon bit count prime kina ta test korar jonno aro 1 ta for loop chalai k=0 to k<result.size() porjonto and k++ kori.Ekhane prime test korbo j count er man prime kina.
  So, Condition is:
---------------------
  if(isprime(result[k]))
  jodi true hoy taile count++ kori

  return kori count.

Full Code:
----------

  int countbits(int n)
{
    vector<int>reserve;
    int count=0;
    while(n>0)
    {
        int rem=n%2;
      if(rem==1)
      {
        count++;
      }
        n=n/2;
    }
    return count;
}
bool isprime(int n)
{
    bool isprime=true;
    if(n<2)
    {
        isprime=false;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
           isprime=false;
           break;
        }
    }
    return isprime;
}
class Solution 
{
public:
    int countPrimeSetBits(int left, int right)
     {
        vector<int> result;
        int count=0;
        for(int j=left;j<=right;j++)
        {
           result.push_back(countbits(j));
        }
       for(int k=0;k<result.size();k++)
       {
        if(isprime(result[k]))
        {
            count++;
        }
       }
        return count;
    }
};
