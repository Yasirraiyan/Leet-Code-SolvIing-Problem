class Solution
 {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int>pp(nums.size(),1);
        int p=1;
        pp[0]=1;
        //pp[1]=nums[1];
        for(int i=1;i<nums.size();i++)
        {
          pp[i]=pp[i-1]*nums[i-1];
        }
        vector<int>sp(nums.size(),1);
        sp[nums.size()-1]=1;
        for(int j=nums.size()-2;j>=0;j--)
        {
          sp[j]=sp[j+1]*nums[j+1];
        }
        vector<int>ans(nums.size());
       
        for(int k=0;k<nums.size();k++)
        {
          ans[k]=pp[k]*sp[k];
        }
        return ans;
}
};
