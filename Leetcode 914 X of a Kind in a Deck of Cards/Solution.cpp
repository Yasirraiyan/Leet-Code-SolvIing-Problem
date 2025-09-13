class Solution 
{
    int findGCD(int a,int b)
    {
        while(b!=0)
        {
            int temp=b;
           b=a%b;
          a=temp;
        }
        return a;
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        unordered_map<int,int>freq;
        for(int i=0;i<deck.size();i++)
        {
            freq[deck[i]]++;
        }
        vector<int>v;
        bool canpartitioned=false;
        for(auto it:freq)
        {
            v.push_back(it.second);
        }
        int gcd=v[0];
        for(int j=1;j<v.size();j++)
        {
            gcd=findGCD(gcd,v[j]);
        }
        if(gcd>1)
        {
            canpartitioned=true;
        }
   return canpartitioned;
    }
};
