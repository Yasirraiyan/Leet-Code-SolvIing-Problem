class Solution
{
public:
    int titleToNumber(string columnTitle) 
    {
        int ans=0;
    
        for(int i=0;i<columnTitle.size();i++)
            {
                ans+=pow(26,columnTitle.size()-i-1)*(tolower(columnTitle[i])-'a'+1);
            }
        return ans;
            
    }
};
