#include<vector>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
       //double count=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            double count=0;
    
            for(int j=0;j<n;j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                }
            }
            double  count2=count/n;
            if(count2>0.25)
            {
                return arr[i];
            }
        }
        return -1;
    }
};
