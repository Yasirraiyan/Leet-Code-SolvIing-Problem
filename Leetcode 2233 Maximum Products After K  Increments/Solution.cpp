class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
         priority_queue<int, vector<int>, greater<int>> minHeap;;
             const int MOD = 1e9 + 7;
        for(int j=0;j<nums.size();j++)
        {
            minHeap.push(nums[j]);
        }
        long long pd=1;
        while(k>0)
        {
            int top=minHeap.top();
            minHeap.pop();
            top++;
            minHeap.push(top);
            k--;
        }
        while(!minHeap.empty())
        {
            int top=minHeap.top();
            minHeap.pop();
           pd=(pd*top)%MOD;
        }
        return (int)pd;
        
    }
};
