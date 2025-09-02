class Solution 
{
public:
int minimumOperations(vector<int>& nums)
     {
        int count=0;
       priority_queue<int,vector<int>,greater<int>>minHeap;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]!=0)
        {
            minHeap.push(nums[i]);
        }
       }
       while(!minHeap.empty())
       {
        int top=minHeap.top();
        minHeap.pop();
        while(!minHeap.empty()&&minHeap.top()==top)
       {
  minHeap.pop();
       }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0&&top>0)
            {
            nums[i]=nums[i]-top;
            }
           
        }
        count++;
       }
       return count;
    }
};
