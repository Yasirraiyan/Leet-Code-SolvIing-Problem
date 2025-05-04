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
        for(int i=0;i<reserve.size();i++)
        {
          for(int j=i+1;j<reserve.size();j++)
          {
            if(i!=j)
            {
              if(reserve[i]==reserve[j])
              {
                isuniqueoccurance=false;
              }
            }
          }
        }
        return isuniqueoccurance;
    }
};
