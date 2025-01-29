Amar 1 ta array ase.
  amr unique element er sum r oi unique element er array chise
so,
for check unique element first e ami 1 ta variable rakhi count ja initial 0;
vector array create kori ans name er. karon array chaise;
1 st e 1 ta for loop chalai i=0 to n porjonto
er moddhe count=0 kori   //karon 1st traverse e kisu jeno count na kore
  ami 1 ta nested for loop chalai j=0 to n porjonto  //j=0 because in 1 st for loop i set the value of variable count==0;
if check kori 
 if(count==1)
            {
                sum+=nums[i];
                ans.push_back(nums[i]);
            }

count==1 hole 
  sum er sathe add kori
and ans e push kori oi index value mane nums[i];
pura array chai 
tai 1 ta for chalai ans array er upor print kori ans.
   for(int val : ans) {
            std::cout << val << " ";
        }
return kori ans.
