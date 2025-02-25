Amar 1 ta array ase mountain.array r element peak hbe jodi left & right both  neighbouring element theke oi elment boro hoy tader index chaise array akare.
So, Ami first e 1 ta condition dei jodi array r size 3 theke less hoy taile empty vector return 
So,
 if(mountain.size()<3)
       {
          return ans;
       } 
1 ta for loop chalai i=1 theke i<mountain.size()-1 porjonto i++ kori. // Karon i=0 hole -1 hoy impossible.
  check neighbour element
 if((mountain[i]>mountain[i+1])&&(mountain[i]>mountain[i-1]))
        {
          ans.push_back(i);  //karon amar chaise index .
        }

return kori ans.
