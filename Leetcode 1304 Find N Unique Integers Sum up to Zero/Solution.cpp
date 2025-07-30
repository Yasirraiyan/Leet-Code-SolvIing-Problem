class Solution 
{
public:
    int findsum(vector<int>&v)
    {
        int sum=0;
        for(int j=0;j<v.size();j++)
            {
                sum+=v[j];
            }
        return sum;
    }
    vector<int> sumZero(int n) {
        vector<int>v;
        if(n%2!=0) v.push_back(0);
        int sum=0;
        for(int i=1;i<=n/2;i++)
            {
                v.push_back(i);
                v.push_back(-i);
                sum=findsum(v);
                if(v.size()==n&&sum==0)
                {
                    break;
                }
            }
        return v;
    }
};
