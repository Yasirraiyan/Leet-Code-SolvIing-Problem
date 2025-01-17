Amar 1 ta integer ase.Eta harshad hobe jodi etar digit er addition die oi digit divide kora jay no remandiar.
  So
  At first i consider a variable sum which is initially 0;
First i iterate a while loop whre x>0
  then x=x%10;
every time
sum+=x;
then x=x/10;
check condition
if(x%sum==0)
  return sum; [Because if x=18 the digit sum is=9 then x%sum=18%9==0 answer is 9 which is digit sum so return sum];
else 
  return -1;[Because if x=23 digit sum is 5.Now, 23%5!=0 answer is -1; so,check condition if(x%sum!=0) so return -1];
  
