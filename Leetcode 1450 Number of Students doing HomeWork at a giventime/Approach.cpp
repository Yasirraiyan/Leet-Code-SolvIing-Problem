Amar 2 ta array ase starttime ar endtime.1 ta variable ase query time.
  amar lagbe kotogula student ei time e kaj complete korte pare.
  So, first e 1 ta variable nei count ja initial 0.
  1 ta for loop chalai i=0 to startime porjonto 1st array traverse kori
nested for loop chalai j=0 to endtime porjonto 2nd array traverse kori
1 ta variable nei needtime koto time lage 
calculate kori 
if(i==j)
            {
                  needTime=endTime[j]-startTime[i];
            }
i=j karon ith student er jth time jokhon i=j;
bound check
 if (queryTime >= startTime[i] && queryTime <= endTime[i])
         {
            count++;
         }
return kori count.
