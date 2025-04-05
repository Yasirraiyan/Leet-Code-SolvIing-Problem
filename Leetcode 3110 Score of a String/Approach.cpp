Amar 1 ta string ase amar ei string sob character gular ASCII valuer difference er sum lagbe.
Exa:
-----
  Input: s = "hello"

Output: 13

Explanation:

The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

  Ami first e 1 ta variable nei sum ja initial 0.Eta diye ami sum ber korbo
1 ta for loop chalai i=0  to i<s.size()-1 porjonto i++ kori string traverse kori
i<s.size()-1 karon bound er moddhe jodi string size 4 hoy i<3 porjonto jokhon i=4 hbe bound out hbe string 4 size e index [0,3]
ami 
ASCII value  calculate kori string er character er int(s[i]) diye eta built in eta diye jekono character er ASCII value pawa jay C++ e

differnce chaise absolute man
So,
  sum+=abs(int(s[i+1])-int(s[i]))

   return kori sum.
