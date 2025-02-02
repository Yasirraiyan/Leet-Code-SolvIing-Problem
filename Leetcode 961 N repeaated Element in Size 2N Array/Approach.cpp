As repeated.Tai repeat hoise kina ta check korbo count variable die.Initially count=0;
if(count>1) taile repetaed
1 ta vector array create kori jar nam ans. Eta korbo jodi repeated pai taile ans e push korbo.
  1 ta for loop chalai i=0 to n porjonto
nested for chalai j=i+1 to n porjonto
j=i+1 kintu j=0 na karon j=0 hole nijer sathe nije compare korbe taile hbe na
check kori and also check if(i!=j) eta dia ensure kori same index na
if(nums[i]=nums[j]) kiuna jodi true hoy taile count++ kori
  and ans array te push kori oi value means nums[i]
 if(nums[i]==nums[j])
                {
                  ans.push_back(nums[i]);
                }
and count++ kori
  check anskhali mane empty kina
jodi na hoy
taile index value return kor
 if(!ans.empty())
        {
            return ans[0];
        }
else
  return -1;
