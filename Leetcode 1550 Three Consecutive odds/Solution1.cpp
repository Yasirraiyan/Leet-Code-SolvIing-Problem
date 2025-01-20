#include <vector>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool iscontain;
        for(int i=0;i<arr.size();i++)
        {
           
           if((arr[i]%2!=0)&&(arr[i+1]%2!=0)&&(arr[i+2]%2!=0))
           {
            iscontain= true;
          
           }
           else
           {
              iscontain= false;
           }
            
        }
       return iscontain;
    }
 
    };
but it is prb in runtime.So go solution2.cpp
