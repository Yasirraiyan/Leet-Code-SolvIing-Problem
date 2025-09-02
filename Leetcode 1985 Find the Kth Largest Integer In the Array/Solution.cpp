class Solution 
{
public:
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        auto cmp=[](const string &a,const string &b)
        {
            if(a.size()!=b.size()) return a.size()<b.size();
            return a<b;
        };
        priority_queue<string,vector<string>,decltype(cmp)>pq(cmp);
        for(int j=0;j<nums.size();j++)
        {
            pq.push(nums[j]);
        }
        int count=0;
        string ans="";
        while(!pq.empty()&&count<k)
        {
           ans=pq.top();
            pq.pop();
            count++;
            if(count==k)
            {
               return ans;
            }
        }
return ans;
    }
};
