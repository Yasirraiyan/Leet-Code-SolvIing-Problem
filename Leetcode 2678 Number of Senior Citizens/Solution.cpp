class Solution 
{
public:
  string get(string s)
  {
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(i==11||i==12)
        {
            ans+=s[i];
            //break;
        }
    }
    return ans;
  }
    int countSeniors(vector<string>& details) 
    {
        vector<int>ans;
        for(int j=0;j<details.size();j++)
        {
           ans.push_back(stoi(get(details[j])));
        }
        int count=0;
        for(int k=0;k<ans.size();k++)
        {
            if(ans[k]>60)
            {
                count++;
            }
        }
        return count;

    }
};
