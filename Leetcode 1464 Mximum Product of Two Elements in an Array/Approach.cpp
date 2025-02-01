Amar 1 ta int er array ase jar nam nums.
  amake 2 ta different indices nite bolse
and maximum product chaise.
  So, 1st e ami 1 ta variable nei max_product ja initial 0. [Eta nibo karon product er sathe max_product compare kore max_product return korbo].
  1 ta for loop chalai i=0 to n porjonto pura array traverse korte.
Nested for loop chalai j=i+1 to n porjonto karron different index chaisev j=0 hole nijer sathe compare korbe.
  Test ensure fulfil korar jonno 1 ta condition chack koi j j ar i non-equal kina 
so,
if(j!=i)
  jodi true hoy tobe product calculate kori
       int   product=(nums[i]-1)*(nums[j]-1);
jaron chaise maximum value of (nums[i]-1)*(nums[j]-1).

as maximum value chaise tai maximum calculate kori std::max dia and max_product update kori.
  
eta holo
 max_product = std::max(max_product, product);


last return kori  max_product
return  max_product;
karon chaise max_product.
