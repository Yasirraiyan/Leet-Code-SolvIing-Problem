class Solution 
{
public:
    long long pickGifts(vector<int>& gifts, int k) 
{
        priority_queue<int,vector<int>,less<int>>maxHeap;
        for(int i=0;i<gifts.size();i++)
        {
            maxHeap.push(gifts[i]);
        }
       long long result=0;
       int count=0;
       while(count<k&&!maxHeap.empty())
       {
        int top=maxHeap.top();
        int a=sqrt(top);
        //result+=a;
        maxHeap.pop();
         maxHeap.push(a);
        count++;
       }
       while(!maxHeap.empty())
       {
        int top=maxHeap.top();
        result+=top;
        maxHeap.pop();
       }
return result;
    }
};
