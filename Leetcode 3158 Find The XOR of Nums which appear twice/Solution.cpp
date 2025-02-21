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
