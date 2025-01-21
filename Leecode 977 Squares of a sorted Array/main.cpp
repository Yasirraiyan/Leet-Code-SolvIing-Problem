#include <iostream>
 #include <vector>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]*nums[i];
        }
        std::cout << "Squared array: "; 
        for (int i = 0; i < nums.size(); ++i)
         { 
            std::cout << nums[i] << " ";
         }
         std::cout << std::endl;
         for(int i=0;i<nums.size();i++)
         {
           if (i < nums.size() - 1 && nums[i] > nums[i + 1])
            {
                int temp = nums[i + 1];
                nums[i+1]=nums[i];
                nums[i] = temp;
              if (i != 0) 
              { 
                 i -= 2; 
                
              }
            }
         }
         std::cout << "Sorted squared array: "; 
         for (int i = 0; i < nums.size(); ++i) 
         { 
            
            std::cout << nums[i] << " "; 
         } 
        std::cout << std::endl;
         return nums;
    }

};
