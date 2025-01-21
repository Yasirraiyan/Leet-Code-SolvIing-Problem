Amar 1 ta prices array ase.prices[i] hoilo ith item er price.Discount tokhon paba jokhon j>i and prices[j[<=prices[i].Return answer array.
Exa
\Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
  Amar ekhane check kori index no 2>1 so j>i
  and prices[j]=prices[i]-prices[j]
as j=2 i= 1 so,j=i+1;
Ami 1 ta for loop chalai i=0 to i<=n porjonto array traverse kori
aro 1 ta nested for loop chalai j=i+1 to j<=n porjonto
check kori 
if(j>i) kina ei hoilei to parbo 1st theke 2nd bad dite and nested if check if(prices[i]>=prices[j]) kina true hoile 
 2nd index value mane price[j]=price[i]-price[j];
return kori price
