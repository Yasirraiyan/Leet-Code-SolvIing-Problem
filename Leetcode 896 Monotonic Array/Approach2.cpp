Ei solution e time complexity komabo;
so, 1 ta for loop chalai i=0 to i<=n
  and check condition
if(arr[i]>=arr[i-1])
decreasing=false;
increasing=true;
monotone=true=increasing.
  another condition
if(arr[i]<=arr[i-1])
decreasing=true;
increasing=false;
monotone=true=decreasing;
else
jodi kono condition na hoy
monotone=false;
return monotone;
as i iterate 1 for loop time complexity reduced it is O(n) from O(n^2)
then accepted;
