class Solution 
{
public:
    int maxNumOfMarkedIndices(vector<int>& nums) 
    {
        int i=0;
        int j=1;
        int count=0;
        vector<int>v;
        sort(nums.begin(),nums.end());
        while(i<nums.size()/2&&j<nums.size())
        {
                 if(2*nums[i]<=nums[j])
                 {
                    v.push_back(i);
                    v.push_back(j);
                    i++;
                    count+=2;
                    j++;
                   
                 }
                 else
                 {
                    j++;
                 }
              
        }
        return count;
    }
};
