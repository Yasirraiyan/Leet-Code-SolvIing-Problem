Amar 1 ta array ase 0 based.
  Amar 1 ta rray build korte hbe jar nam ans jekhane 
ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
  1 st e 1 ta vector array  create kori jar nam ans.
       std::vector<int> ans; 
1 ta for looop chalai i=0 to n porjonto given array ba nums namer array r upor.
  check kori
if( 0 <= i < nums.length )
  jodi true hoy push kori ans e nums[nums[i]]
 if (0 <= i && i < nums.size()) {
                ans.push_back(nums[nums[i]]);
            }
array chaise output
 tai return kori ans.
