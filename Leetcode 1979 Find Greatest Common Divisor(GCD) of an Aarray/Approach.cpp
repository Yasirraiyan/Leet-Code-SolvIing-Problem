Amar 1 ta array ase.Ei array minimum and maximum number er GCD chaise.
  So, 1 st e 1 ta function banai Calculate GCD parameter a,b 
int gcd(int a, int b) 
{ 
  while (b != 0)
    { 
      int temp = b;
      b = a % b;
      a = temp; 
    }
  return a; 

}
Explain:
---------
  অবশ্যই! চল আমরা ৩ এবং ৬ এর ক্ষেত্রে প্রোগ্রামটি কীভাবে কাজ করে দেখি।

প্রথমে প্রোগ্রামটি দুইটি সংখ্যা ইনপুট হিসেবে নেয়, এখানে num1 = 3 এবং num2 = 6.

এরপর gcd ফাংশনটি কল করা হয়।

ধাপ ১:
a = 3, b = 6

temp = 6

b = 3 % 6 মানে b = 3

a = 6

ধাপ ২:
a = 6, b = 3

temp = 3

b = 6 % 3 মানে b = 0

a = 3

ধাপ ৩:
a = 3, b = 0

এখানে b = 0 হয়ে গেলে লুপটি থেমে যায় এবং a = 3 রিটার্ন করা হয়, যা ৩ এবং ৬ এর GCD।

তাহলে, GCD of 3 এবং 6 হল 3।

আশা করি ব্যাখ্যাটি সহায়ক হয়েছে! 😊
  Then array traverse er jonno 1 ta for loop chalai i==0 to n porjonto.
  initial max dhori nums[0] 
min dhori nums[0]
check 
if( nums[i>max)
{
max=nums[i];
}
check
if(nums[i]<min)
{
  min=nums[i];
} Function call kori
GCD(max,min);
