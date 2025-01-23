#include <cmath>
#include <vector>
#include<algorithm>
class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        if (arr.size() < 2) {
            return false;
        }
std::sort(arr.begin(), arr.end()); // Sort the array to easily check for a progression
        int diff = arr[1] - arr[0];
        for (int i = 1; i < arr.size()-1; i++) {
            if (arr[i + 1] - arr[i] !=diff) {
                return false;
            }
        }
        
        return true;
    }
};
