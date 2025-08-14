ধাপে ধাপে চিন্তার ধারা

১. প্রশ্নটি বুঝে নেওয়া:

তোমাকে একটি সংখ্যা n দেওয়া আছে।

তোমাকে এমন সবচেয়ে ছোট সংখ্যা >= n খুঁজতে হবে যা prime এবং palindrome।

Prime: ১ ব্যতীত কেবল ১ এবং নিজেই divisor আছে।

Palindrome: সংখ্যা উল্টে পড়লেও একই থাকে।

কনস্ট্রেইন্ট: n <= 10^8 এবং উত্তর সর্বদা [2, 2*10^8] এর মধ্যে আছে।

২. কোডের helper ফাংশনগুলো:

a) reverse(int n)
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


এই ফাংশন একটি সংখ্যার উল্টো সংখ্যা দেয়।

উদাহরণ: n = 123 → rev = 321।

b) CheckPalindrome(int n)
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


সংখ্যা প্যালিনড্রোম কিনা তা চেক করে।

যদি n == reverse(n) হয় → true।

c) CheckPrime(int n)
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


Prime চেকের লজিক:

2-এর নিচের সংখ্যা prime নয়।

2 prime।

জোড় সংখ্যা prime নয়।

এরপর ৩ থেকে √n পর্যন্ত odd numbers দিয়ে চেক।

এটা efficient কারণ even numbers বাদ দিয়ে computation কমানো হয়েছে।

মূল ফাংশন: primePalindrome(int n)
ধাপ ১: ছোট prime-palindrome চেক করা
if(n <= 2) return 2;
if(n <= 3) return 3;
if(n <= 5) return 5;
if(n <= 7) return 7;
if(n <= 11) return 11;  


২, ৩, ৫, ৭, ১১ হলো ছোট prime-palindrome।

এগুলো আলাদাভাবে handle করা হয়েছে।

ধাপ ২: যদি n নিজেই prime এবং palindrome হয়
if(CheckPrime(n)&&CheckPalindrome(n)) return n;


উদাহরণ: n=7 → এটি return হবে।

ধাপ ৩: odd numbers থেকে loop চালানো
int org=n;
if(org % 2 == 0) org++;


যেহেতু prime number ২ ব্যতীত সব odd, তাই even হলে ১ যোগ করা।

ধাপ ৪: মূল loop
while(true)
{
    int len = 0;
    int tmp = org;
    while(tmp > 0) { tmp /= 10; len++; }


len = সংখ্যার digits সংখ্যা।

    if(len % 2 == 0) 
    {
        org = pow(10, len) + 1; // jump to next odd-length palindrome
        continue;
    }


Even-length palindrome number: except 11, prime হতে পারে না।

তাই যদি even-length হয়, সরাসরি পরের odd-length palindrome এ jump করা।

উদাহরণ: n=100 → next odd-length start = 101

    if(CheckPrime(org)&&CheckPalindrome(org))
        return org;


org যদি prime এবং palindrome হয় → return।

    org+=2;
    if(org > 200000000) break;


পরবর্তী odd number চেক।

2*10^8 পর্যন্ত check করা।

কেন কোড accepted হয়

Small edge cases (2,3,5,7,11) handle করা হয়েছে।

Prime এবং palindrome check করার helper function আছে।

Even-length numbers skip করা হয়েছে → দ্রুত computation।

10^8 limit এর মধ্যে সব valid answer নিশ্চিত আছে।

টেস্ট কেসের উদাহরণ

Input: n=6

৬ নিজেই prime নয়।

৭ odd এবং prime, palindrome → return 7

Input: n=8

next odd = 9 → not prime

11 → prime এবং palindrome → return 11

Input: n=13

odd loop: 13, 15, 17, 19, ... → সব odd prime কিন্তু palindrome নয়

101 → prime এবং palindrome → return 101

✅ সারসংক্ষেপে:

ছোট prime-palindrome handle করা

n prime-palindrome হলে return করা

only odd numbers loop

even-length skip করা

prime + palindrome check → return


Full Code:
----------

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
