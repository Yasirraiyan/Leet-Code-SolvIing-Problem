#include<vector>
#include <algorithm>  // for std::max
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int distance;
        int max_distance=0;
        for(int i=0;i<colors.size();i++)
        {
            for(int j=i+1;j<colors.size();j++)
            {
                if(colors[i]!=colors[j])
                {
                   distance=abs(i-j);
                    max_distance = std::max(max_distance, distance);
                }
            }
        }
        return max_distance;
    }
};
