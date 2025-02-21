Amar 1 ta array ase nums.Amar XOR korte hbe jara twice ba tar beshi ase.
So,
  1 tz for loop chali i=0 i<n porjonto array traverse kori.
  Nested for chalai j=i+1 ;j<nums.size() porjonto karon nijer sathe nije bad.
Check alada index
 if(nums[i]==nums[j])
                    {
                        count++;
                          ans.push_back(nums[i]);
                    }
aro 1 ta for loop chalai k=0;k<ans.size();k++ kori
  ans array traverse kori
xor kor
 sum^=ans[k];
         for(int k=0;k<ans.size();k++)
        {
              sum^=ans[k];
        }
return kori sum.

  Full code:
------------
  class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int count=0;
        vector<int>ans;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(i!=j)
                {
                    if(nums[i]==nums[j])
                    {
                        count++;
                          ans.push_back(nums[i]);
                    }
                  //  if(count==2)
                  //  {
                  //      ans.push_back(nums[i]);
                  //  }
                }
            }
        }
        for(int k=0;k<ans.size();k++)
        {
              sum^=ans[k];
        }
        return sum;
    }
};
