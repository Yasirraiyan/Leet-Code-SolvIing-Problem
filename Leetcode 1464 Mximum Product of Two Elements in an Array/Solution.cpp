#include<vector>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
    int max_product=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(j!=i)
                {
                  int   product=(nums[i]-1)*(nums[j]-1);
                   max_product = std::max(max_product, product);
                 
                   
                }
             
            }
           
        }
       return max_product;
      
    }
   
    
};
