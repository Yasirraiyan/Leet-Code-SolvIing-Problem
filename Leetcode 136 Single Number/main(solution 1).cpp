#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int count = 0;
        int result = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count == 1) {
                result = nums[i];
                break;
            }
        }
        return result;
    }
};
