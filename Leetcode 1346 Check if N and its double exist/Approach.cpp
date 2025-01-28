Ami 1ta variable nei exist .Jeta dia test korbo.j ase kina. 
  1 ta for loop chalai i=0 to n porjonto full array traaverse kori
nested for chalai j=i+1 to n porjonto nijer sathe check dorkar nai tai j=i+1
  and bolse i!=j tai and bolse 0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 check 
if((i != j)) {
                    if((0 <= i) && (j < arr.size())) {
                        if(arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]) {
                            exist = true;
                        }
                    }
naile false
