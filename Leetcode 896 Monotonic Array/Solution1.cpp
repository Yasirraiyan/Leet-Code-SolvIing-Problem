#include <vector>
class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        bool monotone = true; // Initialize to true
        bool increasing = false;
        bool decreasing = false;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i <= j) {
                    if ((nums[i] <= nums[j])) {
                        increasing = true;
                        decreasing = false;
                        monotone = increasing;
                    }
                    if (nums[i] >= nums[j]) {
                        decreasing = true;
                        increasing = false;
                        monotone = decreasing;
                    }
                    // New condition to handle cases where both increasing and decreasing
                    if (!increasing && !decreasing) {
                return false;
            }
                }
            }
        }
        return monotone;
    }
};
 
