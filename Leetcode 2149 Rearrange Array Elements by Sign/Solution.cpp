class Solution
 {
public:
    vector<int> rearrangeArray(vector<int>& nums)
     {
       int i=0;
       int j=1;
       vector<int>v(nums.size(),0);
       for(int k=0;k<nums.size();k++)
       {
        if(nums[k]>0)
        {
            v[i]=nums[k];
            i+=2;
        }
        if(nums[k]<0)
        {
            if(j<nums.size())
            {
            v[j]=nums[k];
            j+=2;
            }
        }
        
       }
      
       return v;

     }
};
