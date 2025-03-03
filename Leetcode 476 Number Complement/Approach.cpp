Amar 1 ta integer ase n.Amake ei integer k binary convert kore tar complement ber kore oi complement k integer e convert kore return korte hbe.

So, 1 st e 2 ta vector array nei reserve ans reserve e binary te convert kore 0,1 mane rem push korbo.
  ans e reserve er upor for loop chalaya condition check 
 if(reserve[i]==1)
          {
            convert.push_back(0);
          }
          if(reserve[i]==0)
          {
            convert.push_back(1);
          }
mane 0 hoile 1 push and 1 hoile 0 push.
  1 ta variable nei int type er jar nam result ja initia 0.Eta nibo karon etate comolemented binary r decimal value rakhbo.


  Binary to decimal:
--------------------
  Mathemetically:
-----------------
  (101)2=1x2^0+0X2^1+1x2^2=1+0+4=5;
common formula:
---------------
  result+=pow(2,j)*ans[j];
return  kori result.
