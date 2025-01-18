#include <vector>
class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false;
            }
            if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
            // Early exit if both increasing and decreasing are false
            if (!increasing && !decreasing) {
                return false;
            }
        }
        return increasing || decreasing;
    }
};
