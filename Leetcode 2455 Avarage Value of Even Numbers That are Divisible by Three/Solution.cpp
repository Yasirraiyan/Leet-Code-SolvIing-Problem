#include<vector>
using namespace std;
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count=0;
        int sum=0;
        int avarage;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0&&nums[i]%3==0)
            {
                count++;
                sum+=nums[i];
                 
            }
        }
        cout<<count<<endl;
        cout<<sum<<endl;
        if (count > 0) 
        {
        avarage=((sum)/(count));
        }
        else
        avarage=0;

        return avarage;

    }
};
