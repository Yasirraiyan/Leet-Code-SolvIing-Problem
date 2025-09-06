#include<algorithm>
using namespace std;
class Solution 
{
public:

    int minOperations(vector<int>& nums, int k) 
    {
        int count=0;
      priority_queue<long long, vector<long long>, greater<long long>> minHeap;
      for(int i=0;i<nums.size();i++)
      {
        minHeap.push(nums[i]);
      }
      while(!minHeap.empty()&&minHeap.size()>=2&&minHeap.top()<k)
      {
        int top1=minHeap.top();
        minHeap.pop();
        int top2=minHeap.top();
        minHeap.pop();
       // long long x=(std::min(top1,top2))*2+std    long long x = min(top1,top2) * 2 + max(top1,top2);::max(top1,top2);
      long long x = std::min<long long>(top1, top2) * 2 + std::max<long long>(top1, top2);
        minHeap.push(x);
        count++;
        
      }
      return count;
    }
};
