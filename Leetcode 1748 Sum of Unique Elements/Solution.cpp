class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int count=0;
       int sum=0;
          std::vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int count=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                     count++;
                }
            }
        
        if(count==1)
        {
            ans.push_back(nums[i]);
            sum+=nums[i];
        }
        }
        for(int val : ans) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        return sum;
    }
};
