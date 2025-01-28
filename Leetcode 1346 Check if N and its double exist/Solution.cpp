#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool exist = false; // Initialize exist as false
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                if((i != j)) {
                    if((0 <= i) && (j < arr.size())) {
                        if(arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]) {
                            exist = true;
                        }
                    }
                }
            }
        }
        return exist;
    }
};
