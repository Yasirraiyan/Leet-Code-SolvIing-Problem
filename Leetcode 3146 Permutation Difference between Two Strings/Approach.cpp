Amar 2 ta string ase s ar t
Amar lagbe oi index gular sum jader moddhe jei character ase s,t e common
initial 1 ta variable nei result ja initial 0.karon chaise sum eta te add kore sum store korbo
 1 ta for loop chalai i=0 to i<s.size() porjonto i++ kori s traverse kori
  nested for loop chalai j=0 to j<t.size() porjonto j++ kori t traverse kori
  check kori same character
  if(s[i]==t[j])
 true hoile 
    result+=abs(j-i); karon chaise index er difference er sum
kori
return kori sum.
