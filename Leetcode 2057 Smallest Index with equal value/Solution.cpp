class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int smallindex=-1;
        for(int i=0;i<nums.size();i++)
        {
            if((i % 10)==nums[i])
            {
                if(smallindex==-1||i<smallindex)
                {
                  smallindex=i;
                }
            }
        }
        return smallindex;
    }
};
