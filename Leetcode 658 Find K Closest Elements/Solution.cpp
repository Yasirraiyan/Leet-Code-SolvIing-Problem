class Solution
 {
public:

 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int>v;
       for(int i=0;i<arr.size();i++)
       {
        int j=abs(arr[i]-x);
        pq.push({j,arr[i]});
        /*if(pq.size()>k)
        {
            pq.pop();
        }
        */
       }
       int count=0;
       while(!pq.empty()&&count<k)
       {
        int top1=pq.top().second;

       v.push_back(top1);
       pq.pop();
       count++;
       if(count==k) break;
       }
       sort(v.begin(),v.end());
       return v;
    }
};
