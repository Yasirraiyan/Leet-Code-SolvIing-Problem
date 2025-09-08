class Solution 
{
public:
    int largestInteger(int num) 
    {
        priority_queue<int>maxHeap1;
        priority_queue<int>maxHeap2;
        vector<int>v;
        int i=0;
        while(num>0)
        {
            int digit=num%10;
            if(digit%2==0)
            {
                maxHeap2.push(digit);
            }
            else
            {
                maxHeap1.push(digit);
            }
            v.push_back(digit);
            num/=10;
        }
            reverse(v.begin(), v.end());
        vector<int>vv(v.size());
        while(i<v.size())
        {
           if(v[i]%2!=0)
           {
             int top1=maxHeap1.top();
             vv[i]=top1;
             maxHeap1.pop();
            
           }
           else
           {
            int top2=maxHeap2.top();
            vv[i]=top2;
            maxHeap2.pop();
           
            
           }
           i++;
        }
        int ans=0;
        for(int j=0;j<vv.size();j++)
        {
           // ans+=vv[j]*pow(10,vv.size()-j-1);
           ans=ans*10+vv[j];
        }
        return ans;
    }
};
