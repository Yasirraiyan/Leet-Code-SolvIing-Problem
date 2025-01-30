#include <vector>

class Solution {
public:
    std::vector<int> buildArray(std::vector<int>& nums) {
        std::vector<int> ans; 
        for (int i = 0; i < nums.size(); i++) {
            if (0 <= i && i < nums.size()) {
                ans.push_back(nums[nums[i]]);
            }
        }
        return ans;
    }
};
