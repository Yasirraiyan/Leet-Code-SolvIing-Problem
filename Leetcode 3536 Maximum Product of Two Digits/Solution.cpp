class Solution 
{
public:
    int maxProduct(int n)
    {
        if(n<10) return 0;
        vector<int>p;
        vector<int>d;
        while(n>0)
            {
                int digit=n%10;
                d.push_back(digit);
                n=n/10;
            }
        reverse(d.begin(),d.end());
        if(d.size()<2)return 0;
        for(int i=0;i<d.size();i++)
            {
                for(int j=i+1;j<d.size();j++)
                    
                {
                p.push_back(d[i]*d[j]);
                }
            }
    
        int maxv=p[0];
        for(int j=1;j<p.size();j++)
            {
                if(p[j]>maxv)
                {
                    maxv=p[j];
                }
            }
        return maxv;
    }
};
