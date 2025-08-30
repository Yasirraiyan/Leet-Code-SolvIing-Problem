class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int count=0;
        int idx=0;
        int sum=0;
        int it=idx;
        for(int i=it;i<cost.size();i++)
        {
            int a=cost[i];
            int b=0;
            int free=0;
           
            if(i+1<cost.size())
            {
          b=cost[i+1];
            }
            if(i+2<cost.size())
            {
            free=cost[i+2];
            }
            sum+=a+b;
            idx=i+2;
            if(i+3<cost.size())
            {
            it=i+3;
            }
            i+=2;
           

        }
        return sum;
    }
};
