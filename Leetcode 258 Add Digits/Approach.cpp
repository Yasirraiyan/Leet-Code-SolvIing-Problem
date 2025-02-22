Amar bolse 1 ta number er digit gula add korte jotokkhon na sum 1 digit e ashe.
  Exa:
-------
  n=38; sum=11=3+8;
abar n=11 hoye jabe so, sum=1+1=2;
return 2. Ans 2.
  So, first e 1 ta while loop nei jekhane 1 digit na hole jog hobe 
so while(n>9)  it is for 1 digit testing.
  ei while er moddhe 1 ta varaiable nei sum ja initial 0.
arekta while nei where n>0
  sum+=n%10;
n=n/10;
sum k ami num e assign kori karon 1 digit na hoya porjonto jog korbo 
38->11->2;
return kori num
karon sum er value last e num e assign korsi.


Full code:
-----------
  class Solution
{
public:
    int addDigits(int num)
{
    
        while(num>9)
        {
          int sum=0;
          while(num>0)
          {
            sum+=num%10;
             num=num/10;
          }
          num=sum;
        }
        return num;
    }
};
