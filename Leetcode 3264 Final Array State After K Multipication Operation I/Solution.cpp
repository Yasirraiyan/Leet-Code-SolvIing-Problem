class Solution
 {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
     {
        vector<int>v;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int j=0;j<nums.size();j++)
        {
            minHeap.push(nums[j]);
        }
        int count=0;
        while(!minHeap.empty()&&count<k)
        {
            int top=minHeap.top();
            minHeap.pop();
           long long x=1LL*top*multiplier;
            for(int i=0;i<nums.size();i++)
           {
            if(nums[i]==top)
            {
                nums[i]=x;
                break;
            }
           }
           count++;
           minHeap.push(x);
        }
        return nums;
    }
};
