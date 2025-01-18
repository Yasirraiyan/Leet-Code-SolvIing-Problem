#include <vector>
class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                int count = 1; // Start counting from the current 1
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] == 1) {
                        count++;
                    } else {
                        break;
                    }
                }
                maxCount = std::max(maxCount, count);
                i += count - 1; // Skip counted 1s to optimize
            }
        }

        return maxCount;
    }
};
