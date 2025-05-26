class Solution 
{
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map<string,int>freq;
        string ans="";
        for(int i=0;i<arr.size();i++)
        {
          freq[arr[i]]++;
        }
        vector<string>reserve;
        for(int i=0;i<arr.size();i++)
        {
         // if(it.second==1)
          if(freq[arr[i]]==1)
          {
            reserve.push_back(arr[i]);
          }
        }
        for(int j=0;j<reserve.size();j++)
        {
          if(j==k-1&&k <= reserve.size())
          {
              ans=reserve[j];
              
          }
        }
        return ans;
    }
};
