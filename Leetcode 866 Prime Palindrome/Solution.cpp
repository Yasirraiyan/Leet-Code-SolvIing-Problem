class Solution 
{
public:
int reverse(int n)
{
    int rev=0;
    while(n>0)
    {
        rev=rev*10+n%10;
        n/=10;
    }
    return rev;
}
bool CheckPalindrome(int n)
{
    bool check=false;
    int a=reverse(n);
    if(a==n)
    {
        check=true;
    }
    return check;
}
bool CheckPrime(int n)
{
    if(n<2) return false;
    if(n==2) return true;
       if(n % 2 == 0) return false;
    bool prime=true;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        {
            prime=false;
            break;
        }
    }
    return prime;
}
    int primePalindrome(int n) 
    {
         if(n <= 2) return 2;
    if(n <= 3) return 3;
    if(n <= 5) return 5;
    if(n <= 7) return 7;
    if(n <= 11) return 11;  
        if(CheckPrime(n)&&CheckPalindrome(n)) return n;
           int org=n;
        if(org % 2 == 0) org++;
        int ans=-1;
     
       while(true)
       {
         int len = 0;
        int tmp = org;
        while(tmp > 0) { tmp /= 10; len++; }
        if(len % 2 == 0) 
        {
            org = pow(10, len) + 1; // jump to next odd-length palindrome
            continue;
        }
        
        if(CheckPrime(org)&&CheckPalindrome(org))
      
      return org;
        org+=2;
         if(org > 200000000) break;
       }
       return -1;
    }
};
