#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool iscontain = false; // Initialize iscontain to false
        for (int i = 0; i < arr.size(); i++) {
            if (i + 2 < arr.size() && // Ensure the indices are within bounds
                (arr[i] % 2 != 0) && (arr[i + 1] % 2 != 0) && (arr[i + 2] % 2 != 0)) {
                iscontain = true;
                break; // Exit loop if condition is met
            } else {
                iscontain = false;
            }
        }
        return iscontain;
    }
};
