class Solution 
{
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_map<string,int>freq;
        for(int i=0;i<paths.size();i++)
        {
          for(int j=0;j<paths[i].size();j++)
          {
            freq[paths[i][j]]++;
    }
        }
        string dest="";
        for(auto it:freq)
        {
          if(it.second==1)
          {
             for(int i=0;i<paths.size();i++)
        {
          for(int j=0;j<paths[i].size();j++)
          {
            if(paths[i][j]==it.first&&j==paths[i].size()-1)
            {
             dest+=it.first;
            }
          }
          }
        }
        }
        return dest;
    }
};
