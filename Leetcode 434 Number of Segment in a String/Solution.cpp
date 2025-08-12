class Solution 
{
public:
    int countSegments(string s) 
    {
       
        vector<string>words;
        stringstream ss(s);
        while(ss>>s)
        {
          words.push_back(s);
        }
        int ans=words.size();
        return ans;
    }
};
