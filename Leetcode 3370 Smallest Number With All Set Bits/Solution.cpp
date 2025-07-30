class Solution 
{
public:
  bool HasSetBitAll(int n)
  {
    bool has=true;
    while(n>0)
    {
      int rem=n%2;
      if(rem==0)
      {
        has=false;
        break;
      }
      n=n/2;
    }
    return has;
  }
    int smallestNumber(int n)
     {
      int ans;
      if(HasSetBitAll(n)) return n;
      while(!HasSetBitAll(n))
            {
              n++;
            }
        return n;
    }
};
