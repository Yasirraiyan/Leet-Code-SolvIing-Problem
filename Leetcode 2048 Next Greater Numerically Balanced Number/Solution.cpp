class Solution 
{
public:
    bool HasZero(int n)
    {
        bool haszero=false;
        while(n>0)
            {
                int digit=n%10;
                if(digit==0)
                {
                    haszero=true;
                    break;
                }
                n=n/10;
            }
        return haszero;
    }
    bool Balanced(int n)
    {
        if(HasZero(n)) return false;
        vector<int>v;
        while(n>0)
            {
                int rem=n%10;
                if(rem==0) return false;
                v.push_back(rem);
                n=n/10;
            }
        bool balanced=true;
        unordered_map<int,int>freq;
        for(int i=0;i<v.size();i++)
            {
                freq[v[i]]++;
            }
        for(auto it:freq)
            {
                if(it.first!=it.second)

                {
                    balanced=false;
                    break;
                }
            }

return balanced;   
    }
    int nextBeautifulNumber(int n)
    {
        int ans;
        for(int j=n+1;j<=1224444;j++)
            {
                
                if(Balanced(j))
                {
                    ans=j;
                    break;
                }
            }
        return ans;
    }
};
