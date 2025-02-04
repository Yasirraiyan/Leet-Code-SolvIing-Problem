class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0;
        int neg=0;
        int result;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                pos++;
            }
             if(nums[i]<0)
            {
                neg++;
            }
        }
        if(pos>neg)
        {
            result=pos;
        }
         if(pos<neg)
        {
            result=neg;
        }
        return result;
    }
};
