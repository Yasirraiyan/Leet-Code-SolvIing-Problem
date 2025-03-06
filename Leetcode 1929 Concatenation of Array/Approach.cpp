Amar 1 ta array ase jar nam nums.Amake 1 ta ans array create korte bola hoise 2n length er.
  where 
  1.ans[i] == nums[i] and
  2.ans[i + n] == nums[i] 
for ths codition(0 <= i < n (0-indexed).)

So, ami first e 1 ta vector array create kori ans ja 2*n length er.
So,
 vector<int> ans(2 * nums.size());

1 ta for loop chalai i=0 to i<nums.size() porjonto and i++ kori Etar maddhome pura nums array traverse kori.
  As amar bolse:
  1.ans[i] == nums[i] and
  2.ans[i + n] == nums[i]
so,
  loop er moddhe perform kori operation
ans[i]=nums[i];
ans[i+nums.size()]=nums[i];

return kori ans.

