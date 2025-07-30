class Solution 
{
public:
long long product(int n)
{
  long long p=1;
  while(n>0)
   {
    int digit=n%10;
    p*=digit;
    n=n/10;
   }
   return p;
}
 bool test(int n,int t)
 {
   
   bool test=false;
  long long p=product(n);
   
   if(p%t==0)
   {
        test=true;
   }
return test;
 }
    int smallestNumber(int n, int t) 
    {
       
      if(test(n,t)) return n;
      while(!test(n,t))
      {
          n++;
          if(test(n,t)) break;

      }
      return n;
    }
};
