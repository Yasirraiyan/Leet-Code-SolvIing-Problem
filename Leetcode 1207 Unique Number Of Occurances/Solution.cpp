class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int>freq;
        bool isuniqueoccurance=true;
        vector<int>reserve;
        for(int i=0;i<arr.size();i++)
        {
          freq[arr[i]]++;
        }
        for(auto it:freq)
        {
         reserve.push_back(it.second);
        }
        for(int j=0;j<reserve.size();j++)
        {
          for(int k=j+1;k<reserve.size();k++)
          {
            if(k!=j)
            {
              if(reserve[k]==reserve[j])
              {
                isuniqueoccurance=false;
              }
            }
          }
        }
        return isuniqueoccurance;
    }
};
