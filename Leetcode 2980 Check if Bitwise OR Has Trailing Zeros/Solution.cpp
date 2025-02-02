class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
       // int result=0;
        bool type;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(i!=j)
                {
            int result=nums[i]|nums[j];
            if((result&1)==0)
        {
              return true;
        }
                }
            }
        }
    
        
        
      return false;
    }
};
