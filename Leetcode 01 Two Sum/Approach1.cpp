Amar 1 ta array ase nums. 1 ta integer ase target. Amar chiase ei array r kon man gula add korle target er equal hoy oi man er index chaise array akare.
  As array akare chaise so ami 1 ta vector create kori jar nam ans.
1 ta for loop chalai i=0 to i<nums.size() porjonto pura array traverse kori.
  nested for loop chalai j=i+1 ;j<nums.size() porjonto j=i+1 karon same index nibo na
check kori index same na;
if(i!=j)
  true hoile check
if(nums[i]+nums[j]==target)
  ans.push_back(i);
ans.push_back(j);
return kori ans.
  
