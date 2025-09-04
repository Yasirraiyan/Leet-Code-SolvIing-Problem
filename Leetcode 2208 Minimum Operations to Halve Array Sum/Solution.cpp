class Solution 
{
public:
double findSum(priority_queue<double>pq)
{
    double sum=0.0;
    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}
    int halveArray(vector<int>& nums) 
    {
         priority_queue<double>pq;
         for(int k=0;k<nums.size();k++)
        {
            pq.push(nums[k]);
        }
       double Sum=findSum(pq);
        
        int count=0;
        double targetSum=Sum/2.0;
        while(Sum>targetSum)
        {
            double top=pq.top();
            pq.pop();
          
          double x=top/2.0;
           pq.push(x);
             count++;
           Sum-=x;
           
           if(Sum<=Sum/2)
           break;

        }
        return count;
    }
};
