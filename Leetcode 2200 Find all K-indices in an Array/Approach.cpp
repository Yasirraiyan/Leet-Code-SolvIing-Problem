Amar bolse array ase 0 indexed. Amar |i - j| <= k and nums[j] == key. eta mane erokom kisu index ase.Oi jinish er array return korbo.
  So,as array return korbo first amar 1 ta vector array create korte hbe. jar nam result.
  std::vector<int> result; 
Erpor as |i - j| <= k and nums[j] == key.
  1 ta loop chalai for loop pura array traverse korbo i=0 to n porjonto
then arekta loop chalai j=0 to n porjonto.
check kori 
 if((abs(i-j)<=k)&&(nums[j]==key)) 
jodi true hoy taile kori 
result.push_back(i);
the condition is
if((abs(i-j)<=k)&&(nums[j]==key))
                {
                  result.push_back(i);
                  break;
                }
return kori result.
