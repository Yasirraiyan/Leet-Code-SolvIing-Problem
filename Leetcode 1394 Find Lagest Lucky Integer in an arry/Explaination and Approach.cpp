Amar 1 ta array ase.Amar lagbe largest lucky integer.
  Lucky integer hoilo jei member ta array te sobche beshi ase.
  jemon 
  exa:[2,2,3,4]
  lucky 2
  2 ase 2 bar so frequency 2. as equal value an frequency it is lucky
exa2:[1,2,2,3,3,3]
  lucky 1,2,3 karon 3 ase 3 bar,1 ase 1 bar,2 ase 2 bar.so,frequency of 3 is 3,2 is 2 and 1 is 1 .as equal frequency and value (3,2,1) all so all are lucky.
  But largest lucky is 3.
  Karon 1,2,3 er moddhe 3 boro.tai outpu 3.
exa3:[2,2,2,3,3]
  output -1.
    Karon lucky nai. 2 er frequency 3 not match.3 er frequency 2.not match.tai output -1.

  Approach:
  Ami first e ekta for loop chalai i=0 to n porjont.karon rray traverse kori
arekta chalai nested for j=0 to n porjonto check korbo sob elemment
arr[i]==arr[j]
  mile taile ase count++;
jehetu largest bolse
tai kon array[i] boro ta check kori
if(arr[i]>result || result==-1)
            {
                result=arr[i];
            }
result=-1 jodi na thake
return kori result.
  
