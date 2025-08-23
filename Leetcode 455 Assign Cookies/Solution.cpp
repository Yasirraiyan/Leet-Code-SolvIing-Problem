class Solution
 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int count=0;
        while(i<g.size()&&j<s.size())
        {
            if(s[j]>=g[i])
            {
                g[i]=s[j];
                   i++;
                   j++;
                count++;
            }
            else
            {
                j++;
            }
        }
        return i;
    }
};
