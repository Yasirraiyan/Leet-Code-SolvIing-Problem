class Solution 
{
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        vector<int>v;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int j=0;j<nums.size();j++)
        {
            minHeap.push(nums[j]);
        }
        while(!minHeap.empty()&&minHeap.size()>=2)
        {
            int top1=minHeap.top();
             
            minHeap.pop();
            int top2=minHeap.top();
            minHeap.pop();
              v.push_back(top2);
               v.push_back(top1);
          

        }
        return v;
    }
};
