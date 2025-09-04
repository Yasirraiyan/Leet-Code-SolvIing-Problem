class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
     priority_queue<int>pq;
     for(int i=0;i<nums.size();i++)
     {
        pq.push(nums[i]);
     } 
     int count=0;
     long long score=0;
     while(!pq.empty()&&count<k)  
     {
         int top=pq.top();
         score+=top;
         pq.pop();
         count++;
         pq.push((top+2)/3);
         if(count==k)
         {
            break;
         }
     }
     return score;
    }
};
