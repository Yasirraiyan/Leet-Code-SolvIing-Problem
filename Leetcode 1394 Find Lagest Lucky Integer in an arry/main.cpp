#include<vector>
class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        int count = 0;
        int result=-1;
        
        for(int i = 0; i < arr.size(); i++) {
            count = 0;  // Reset count for each element
            for(int j = 0; j < arr.size(); j++) {
                if(arr[i] == arr[j]) {
                    count++;
                }
            }
            if(count == arr[i]) {
                
                //return count; // Keep track of the highest lucky number }
            
            if(arr[i]>result || result==-1)
            {
                result=arr[i];
            }
        }
        }
        //return count;
        return result;
    }
};
